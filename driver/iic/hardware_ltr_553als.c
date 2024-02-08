#include"iic.h"

/* init iic pin and controller*/
void hardware_ltr_553als_init() {
    iic1_pin_init();
    iic_con_init(I2C1);
}

/* write register*/
void hardware_ltr_5553als_write_register(uint8_t regaddr, uint8_t regvl) {
    uint8_t tx_buf[] = {regaddr, regvl};
    // 1.start signal
    iic_con_start(I2C1);

    // 2.write slave address + write bit
    // auto wait ACK(interrupt)
    iic_con_send_slave_addr(I2C1, LTC_ADR_WRITE);

    // 3.write register addr and command
    iic_con_send_data(I2C1, tx_buf, sizeof(tx_buf));
   
    // 4.stop signal
    iic_con_stop(I2C1);

}

/* read register*/
uint8_t hardware_ltr_5553als_read_register(uint8_t regaddr) {
    uint8_t tx_buf[] = {regaddr};
    uint8_t rx_buf[1];
    // 1.start signal
    iic_con_start(I2C1);

    // 2.write slave address + write bit
    // auto wait ACK(interrupt)
    iic_con_send_slave_addr(I2C1, LTC_ADR_WRITE);

    // 3.write register addr and command
    iic_con_send_data(I2C1, tx_buf, sizeof(tx_buf));

    // 4.restart
    iic_con_restart(I2C1);

    // 5.write slave addr + read bit
    iic_con_send_slave_addr(I2C1, LTC_ADR_READ);

    // 6.read data
    iic_con_read_data(I2C1, rx_buf, sizeof(rx_buf));

    // 7.stop signal
    iic_con_stop(I2C1);

    return rx_buf[0];
}

/* 测试读取光传感器厂家ID*/
void hardware_read_ltr_553als_manufac_id() {
    uint8_t manufac_id;
    // init
    hardware_ltr_553als_init();

    // read id
    manufac_id = hardware_ltr_5553als_read_register(LTC_MANUFAC_ADR);
    uart_printf("manufac ID : %#x\r\n",manufac_id);
}

/* 测试读取接近传感器数据*/
void hardware_read_ltc_553als_ps_data() {
    uint16_t ps_data;
    uint8_t data[2];
    hardware_ltr_553als_init();
    // active mode
    hardware_ltr_5553als_write_register(LTC_PS_REG_ADR, 0x3);
    gpt_delay_ms(10);

    // read data from two register
    data[0] = hardware_ltr_5553als_read_register(LTC_PS_DATA0_REG_ADR);
    gpt_delay_ms(10); // wait ack
    data[1] = hardware_ltr_5553als_read_register(LTC_PS_DATA1_REG_ADR);
    gpt_delay_ms(10); // wait ack

    // join data
    ps_data = ((data[1] & 0x7) << 8) | data[0];
    uart_printf("ps data : %d\r\n",ps_data);
}

/* 测试读取光线传感器数据*/
void hardware_read_ltc_553als_als_data() {
    uint8_t low;
    uint8_t high;
    uint16_t channel[2];
    // init
    hardware_ltr_553als_init();
    // active
    hardware_ltr_5553als_write_register(LTC_ALS_REG_ADR, 0x1);
    gpt_delay_ms(10);

    // read data,ch1 first,ch2 second
    low = hardware_ltr_5553als_read_register(LTC_ALS_CH1_DATA0_REG_ADR);
    gpt_delay_ms(10); // wait ack
    high = hardware_ltr_5553als_read_register(LTC_ALS_CH1_DATA1_REG_ADR);
    gpt_delay_ms(10); // wait ack
    channel[1] = (high << 8) | low;
    uart_printf("CH1 DATA : %d\r\n", channel[1]);

    low = hardware_ltr_5553als_read_register(LTC_ALS_CH0_DATA0_REG_ADR);
    gpt_delay_ms(10); // wait ack
    high = hardware_ltr_5553als_read_register(LTC_ALS_CH0_DATA1_REG_ADR);
    gpt_delay_ms(10); // wait ack
    channel[0] = (high << 8) | low;
    uart_printf("CH0 DATA : %d\r\n", channel[0]);
}

void hardware_iic_test() {
    while(1) {
        hardware_read_ltr_553als_manufac_id();
        hardware_read_ltc_553als_ps_data();
        hardware_read_ltc_553als_als_data();
        gpt_delay_sec(1);
    }
}
