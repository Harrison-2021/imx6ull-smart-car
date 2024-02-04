#include"iic.h"

/*GPIO模拟iic向LTR-553ALS-WA传感器从机的指定寄存器写数据*/
void iic_write_register(uint8_t regaddr,uint8_t regval) {
    // start signal
    iic_start();

    // slave address + write bit
    iic_write_byte(LTC_ADR_WRITE);

    // wait slave ack
    uint8_t res = iic_wait_ack();
    if(res < 0) {
        uart_printf("write slave address fault!\r\n");
        return;
    }

    // register address
    iic_write_byte(regaddr);
    res = iic_wait_ack();
    if(res < 0) {
        uart_printf("write register address fault!\r\n");
        return;
    }

    // register command
    iic_write_byte(regval);
    res = iic_wait_ack();
    if(res < 0) {
        uart_printf("write register command fault!\r\n");
        return;
    }

    // stop signal
    iic_stop();
}

/*GPIO模拟iic向LTR-553ALS-WA传感器从机的指定寄存器读数据*/
uint8_t iic_read_register(uint8_t regaddr) {
    uint8_t regval;
    uint8_t  res;
    // 1.start signal
    iic_start();

    // 2.slave addr + write
    iic_write_byte(LTC_ADR_WRITE);

    // 3.wait ack
    res = iic_wait_ack();
    if(res < 0) {
        uart_printf("write slave address fault!\r\n");
        return;
    }
    // 4.register address
    iic_write_byte(regaddr);

    // 5.wait slave ack
    res = iic_wait_ack();
    if(res < 0) {
        uart_printf("write register address fault!\r\n");
        return;
    }
    // 6.restart 
    iic_start();

    // 7.slave addr + read
    iic_write_byte(LTC_ADR_READ);

    // 8.wait slave ack
    res = iic_wait_ack();

    if(res < 0) {
        uart_printf("write slave address fault!\r\n");
        return;
    }
    // 9.read register command
    regval = iic_read_byte();
 
    // 10.host send nack to slave 
    iic_send_nack();
 
    // 11.stop signal
    iic_stop();
    // software_iic_stop();

    return regval;
}


/* 测试读取光传感器厂家ID*/
void read_ltr_553als_manufac_id() {
    uint8_t manufac_id;
    iic_init();
   
    manufac_id = iic_read_register(LTC_MANUFAC_ADR);
    uart_printf("manufac ID : %#x\r\n",manufac_id);
}

/* 测试读取接近传感器数据*/
void read_ltc_553als_ps_data() {
    uint16_t ps_data;
    uint8_t data[2];
    iic_init();
    // active mode
    iic_write_register(LTC_PS_REG_ADR, 0x3);
    gpt_delay_ms(10);

    // read data from two register
    data[0] = iic_read_register(LTC_PS_DATA0_REG_ADR);
    data[1] = iic_read_register(LTC_PS_DATA1_REG_ADR);
    // join data
    ps_data = ((data[1] & 0x7) << 8) | data[0];
    uart_printf("ps data : %d\r\n",ps_data);
}

/* 测试读取光线传感器数据*/
void read_ltc_553als_als_data() {
    uint8_t low;
    uint8_t high;
    uint16_t channel[2];
    // init
    iic_init();
    // active
    iic_write_register(LTC_ALS_REG_ADR, 0x1);
    gpt_delay_ms(10);
    // read data,ch1 first,ch2 second
    low = iic_read_register(LTC_ALS_CH1_DATA0_REG_ADR);
    high = iic_read_register(LTC_ALS_CH1_DATA1_REG_ADR);
    channel[1] = (high << 8) | low;
    uart_printf("CH1 DATA : %d\r\n", channel[1]);

    low = iic_read_register(LTC_ALS_CH0_DATA0_REG_ADR);
    high = iic_read_register(LTC_ALS_CH0_DATA1_REG_ADR);
    channel[0] = (high << 8) | low;
    uart_printf("CH0 DATA : %d\r\n", channel[0]);
}
    
void iic_test() {
    while(1) {
        read_ltr_553als_manufac_id();
        read_ltc_553als_ps_data();
        read_ltc_553als_als_data();
        gpt_delay_sec(2);
    }
}