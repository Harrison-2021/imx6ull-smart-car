#include"onewire.h"

void ds18b20_pin_init() {
    IOMUXC_SW_MUX_CTL_PAD_GPIO5_IO02 &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_GPIO5_IO02 |= (0x5 << 0);
}

//master read direction
void ds18b20_pin_input() {
    GPIO5->GDIR &= ~(1 << 2);
}

// master write direction
void ds18b20_pin_output() {
    GPIO5->GDIR |= (1 << 2);
}


// master write level
void ds18b20_write_level(uint8_t level) {
    GPIO5->DR &= ~(1 << 2);
    GPIO5->DR |= (level << 2);
}

// master read level
uint8_t ds18b20_read_level() {
    uint8_t level;
    level = GPIO5->PSR & (1 << 2);
    return level ? 1 : 0;
}

// master detecter slave
int ds18b20_detect() {
    uint8_t level;
    // simulate Resistor pullup
    ds18b20_pin_init();
    ds18b20_pin_output();
    ds18b20_write_level(ONEWIRE_HIGH); // 默认上拉电阻将总线拉高
    gpt_delay_us(10);

    // bus master pulling low minimum 480us(至少480)
    ds18b20_write_level(ONEWIRE_LOW);
    gpt_delay_us(700);

    // releases the bus,and goes into receive mode (RX)
    // simulate Resistor pullup
    ds18b20_write_level(ONEWIRE_HIGH);
    ds18b20_pin_input();

    // wait slave detects this rising edge(15us-60us) and pull low 60us-240us
    gpt_delay_us(70);
    level = ds18b20_read_level();
	// 读取需要一点时间，读取完毕，再判断
    gpt_delay_us(200);
    if(level) {
        uart_printf("master detect failed!\r\n");
        return -1;
    } else {
        uart_printf("mastet detect succeed!\r\n");
    }
    return 0;
}

// master write 1 bit to ds18b20
void ds18b20_write_bit(uint8_t bit) {   
    if(bit){ // write 1 
        ds18b20_pin_output();
        ds18b20_write_level(ONEWIRE_LOW);
        gpt_delay_us(1); // within 15 us
        ds18b20_pin_input(); // released bus
        gpt_delay_us(70);// wait slave samples[15-60]
    } else { // write 0
        ds18b20_pin_output();
        ds18b20_write_level(ONEWIRE_LOW);
        gpt_delay_us(80);     // at least 60us
        ds18b20_pin_input(); // released bus
        gpt_delay_us(15); // wait slave samples[15-60]
    }
}

uint8_t ds18b20_read_bit() {
    uint8_t bit;
	// 主机拉低至少1us启动读取时隙
    ds18b20_pin_output();
    ds18b20_write_level(ONEWIRE_LOW);
    gpt_delay_us(5); // pulling the 1-Wire bus low for minimum of 1us
    ds18b20_pin_input(); // released bus
    
    gpt_delay_us(3); // master sample within 15us  
    bit = ds18b20_read_level();
    
    gpt_delay_us(60); // read next bit,读取时隙的持续时间必须至少为60us

    return bit;
}

void ds18b20_write_byte(uint8_t data) {
    uint8_t i;
    uint8_t bit;
    for(i = 0; i < 8; i++) {
        bit = data & 1;
        ds18b20_write_bit(bit);
        data = data >> 1;
    }
}

uint8_t ds18b20_read_byte() {
    uint8_t data = 0; 
    uint8_t i;
    uint8_t bit;
    for(i = 0; i < 8; i++) {
        bit = ds18b20_read_bit();
        data = data | (bit << i);
    }
    return data;
}


// test read command
void ds18b20_read_id() {
    int i; // 注意不能定义成uint8_t，否则递减时，0减1成255，永远循环下去
    uint8_t ret;
    uint8_t id[8];

    // master detect slave
    ret = ds18b20_detect();
    if(ret < 0) {
        return;
    } 
    //write read command
    ds18b20_write_byte(READ_ROM);
   
    for(i = 0; i < 8; i++) {
        // uart_printf("%d ",i);
        id[i] = ds18b20_read_byte();
    }
    uart_printf("ID : H-L: ");
   
    for(i = 7; i >= 0; i--) {
        uart_printf("%x ",id[i]);
    }
    uart_printf("\r\n");
    uart_printf("ID : L-H: ");
    for(i = 0; i < 8; i++) {
        uart_printf("%x ",id[i]);
    }
    uart_printf("\r\n");
}

void ds18b20_read_temperature() {
    int ret;
    uint8_t data[2];
    uint16_t temperature;
    uint8_t  low4bit;
    uint8_t  interger;
    uint8_t  temp[2];

    ret = ds18b20_detect();
    if(ret < 0){
        return;
    }
    ds18b20_write_byte(SKIP_ROM);//skip rom-主设备同时寻址所有从设备（ds18b20）
    ds18b20_write_byte(CONVERT_T);//转换命令
    
    gpt_delay_sec(1);// wait salve sample temperature

    ret = ds18b20_detect();
    if(ret < 0){
        return;
    }
    ds18b20_write_byte(SKIP_ROM);//skip rom
    ds18b20_write_byte(READ_SCR);//读取 SCRATCHPAD 

    data[0] = ds18b20_read_byte(); // low 8 bit
    data[1] = ds18b20_read_byte(); // high 8 bit

    uart_printf("Temp H:%x,Temp L:%x\r\n",data[1],data[0]);
    temperature = *((uint16_t *)data);

    low4bit  = temperature & 0xf; // [3-0]:decimal
    interger = temperature >> 4;  // [11-4]:interger
    if(interger & 0x80){//1000 0000 -负数，储存的是补码，需要换算成原码
        temperature = ~temperature + 1; // 最高符号位不参与换成10进制，因此可以直接取反加1
        temp[1] = temperature >> 4;
        temp[0] = temperature & 0xf; 

        //0.0625 x 10000 = 625-小数转为整数输出，eg.0001->0.0625->625
        uart_printf("temperature:-%d.%04d\r\n",temp[1],625 * temp[0]);
    }else{
        temp[1] = interger;
        temp[0] = low4bit;
        uart_printf("temperature:%d.%04d\r\n",temp[1],625 * temp[0]);
    }

    return;
}

void ds18b20_test() {
    while(1) {
        ds18b20_read_id();
        ds18b20_read_temperature();
        gpt_delay_sec(1);
    }
}

