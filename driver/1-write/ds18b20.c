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
    ds18b20_write_level(ONEWIRE_HIGH);
    gpt_delay_us(10);

    // bus master pulling low minimum 480us
    ds18b20_write_level(ONEWIRE_LOW);
    gpt_delay_us(700);

    // releases the bus,and goes into receive mode (RX)
    // simulate Resistor pullup
    ds18b20_write_level(ONEWIRE_HIGH);
    ds18b20_pin_input();

    // wait slave detects this rising edge(15us-60us) and pull low 60us-240us
    gpt_delay_us(100);
    level = ds18b20_read_level();
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
// void ds18b20_write_bit(uint8_t bit) {
//     // write 1 
//     if(bit){
//         ds18b20_pin_output();
//         ds18b20_write_level(ONEWIRE_LOW);
//         gpt_delay_us(1); // within 15 us
//         ds18b20_pin_output(); // released bus
//         gpt_delay_us(50);// wait slave samples[15-60]
//     } else {
//         ds18b20_pin_output();
//         ds18b20_write_level(ONEWIRE_LOW);
//         gpt_delay_us(80);     // at least 60us
//         ds18b20_pin_output(); // released bus
//         gpt_delay_us(15); // wait slave samples[15-60]
//     }
// }

// uint8_t ds18b20_read_bit() {
//     uint8_t bit;
//     ds18b20_pin_output();
//     ds18b20_write_level(ONEWIRE_LOW);
//     gpt_delay_us(5); // pulling the 1-Wire bus low for minimum of 1us
//     ds18b20_pin_input(); // released bus
//     gpt_delay_us(3); // master sample within 15us
//     bit = ds18b20_read_level();
//     gpt_delay_us(60); // read next bit

//     return bit;
// }

void ds18b20_write_bit(uint8_t bit)
{
    if(bit){
        /*
        To generate a Write 1 time slot, after pulling the 1-Wire bus low, 
        the bus master must release the 1-Wire bus within 15us. 
        */
    //    uart_printf("test: bit = 1\r\n");
       ds18b20_pin_output();
       ds18b20_write_level(DS18B20_LOW_LEVEL);
       ds18b20_pin_input();
       gpt_delay_us(100);

    }else{
        /*
         To generate a Write 0 time slot, after pulling the 1-Wire bus low, 
         the bus master must continueto hold the bus low for the duration of 
         the time slot (at least 60us).
        */
        // uart_printf("test: bit = 0\r\n");
        ds18b20_pin_output();
        ds18b20_write_level(DS18B20_LOW_LEVEL);
        gpt_delay_us(100);
        ds18b20_pin_input();
        gpt_delay_us(60);
    }

    return;
}

uint8_t ds18b20_read_bit(void)
{
    uint8_t bit;

    /*
     A read time slot is initiated by the master device pulling 
     the 1-Wire bus low for a minimum of 1us and then releasing the bus .
    */
    ds18b20_pin_output();
    
    ds18b20_write_level(DS18B20_HIGH_LEVEL);
    gpt_delay_us(1);
    ds18b20_write_level(DS18B20_LOW_LEVEL);
    // gpt_delay_us(1);
    ds18b20_pin_input();
    gpt_delay_us(3);
    /*
      Outputdata from the DS18B20 is valid for 15us after the falling edge 
      that initiated the read time slot.
    */
    bit = ds18b20_read_level();
    gpt_delay_us(80);

    return bit;
}
void ds18b20_write_byte(uint8_t data)
{
    int i;
    int bit;

    for(i = 0;i < 8;i ++){
        bit = data & 1;
        // uart_printf("test1\r\n");
        ds18b20_write_bit(bit);
        // uart_printf("test2\r\n");
        data = data >> 1;
    }

    return;
}
uint8_t ds18b20_read_byte(void)
{
    int i;
    uint8_t bit;
    uint8_t data = 0;

    for(i = 0;i < 8;i ++){
        bit = ds18b20_read_bit();
        if(bit){
            //0000 0000
            data = data | (1 << i);
        }
    }

    return data; 
}

// void ds18b20_write_byte(uint8_t data) {
//     uint8_t i;
//     uint8_t bit;
//     for(i = 0; i < 8; i++) {
//         bit = data & 1;
//         ds18b20_write_bit(bit);
//         data = data >> 1;
//     }
// }

// uint8_t ds18b20_read_byte() {
//     uint8_t data = 0; 
//     uint8_t i;
//     uint8_t bit;
//     for(i = 0; i < 8; i++) {
//         bit = ds18b20_read_bit();
//         data = data | (bit << i);
//     }
//     return data;
// }

// test read command
void ds18b20_read_id() {
    uint8_t i;
    uint8_t ret;
    uint8_t id[8];

    // master detect slave
    ret = ds18b20_detect();
    if(ret < 0) {
        return;
    } 
    // write read command
    ds18b20_write_byte(READ_ROM);
    // uart_printf("test read:\r\n");
    for(i = 0; i < 8; i++) {
        id[i] = ds18b20_read_byte();
    }
    uart_printf("ID : H-L: ");
    for(i = 7; i >= 0; i--) {
        uart_printf("%x ",id[i]);
    }
    uart_printf("\r\n");
}

void read_ds18b20_id(void)
{
    int i;
    int ret;
    uint8_t id[8];

    ds18b20_pin_init();
    ret = ds18b20_detect();
    if(ret < 0){
        return;
    }
    ds18b20_write_byte(0x33);

    for(i = 0;i < 8;i ++){
        id[i] = ds18b20_read_byte();
    }

    uart_printf("H-L : ");
    for(i = 7;i >=0 ;i --){
        uart_printf("%x ",id[i]);
    }
    uart_printf("\r\n");

    uart_printf("L-H : ");
    for(i = 0;i < 8;i ++){
        uart_printf("%x ",id[i]);
    }
    uart_printf("\r\n");

    return;
}

void read_ds18b20_temperature(void)
{
    int ret;
    uint8_t data[2];
    uint16_t temperature;
    uint8_t  low4bit;
    uint8_t  interger;
    uint8_t  temp[2];

    ds18b20_pin_init();
    ret = ds18b20_detect();
    if(ret < 0){
        return;
    }
    ds18b20_write_byte(0xcc);//skip rom
    ds18b20_write_byte(0x44);//转换命令
    
    gpt_delay_sec(1);

    ds18b20_pin_init();
    ret = ds18b20_detect();
    if(ret < 0){
        return;
    }
    ds18b20_write_byte(0xcc);//skip rom
    ds18b20_write_byte(0xbe);//读取 SCRATCHPAD 

    data[0] = ds18b20_read_byte();
    data[1] = ds18b20_read_byte();

    uart_printf("Temp H:%x,Temp L:%x\r\n",data[1],data[0]);
    temperature = *((uint16_t *)data);

    low4bit  = temperature & 0xf;
    interger = temperature >> 4; 
    if(temperature & 0x80){//1000 0000
        temperature = ~temperature + 1
        temp[1] = temperature & 0xf;
        temp[0] = temperature >> 4; 

        //0.0625 x 10000 = 625
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
        read_ds18b20_id();
        gpt_delay_sec(1);
    }
}