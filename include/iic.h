#ifndef _IIC_H
#define _IIC_H
#include"imx6ull.h"
#include"gpt.h"
#include"uart.h"

#define I2C_SDA 29
#define I2C_SCL 28

#define HIGH  1
#define LOW   0

#define LTC_ADR_WRITE 0x46
#define LTC_ADR_READ  0x47

#define LTC_MANUFAC_ADR 0x87

#define LTC_PS_REG_ADR 0x81
#define LTC_PS_DATA0_REG_ADR 0x8D
#define LTC_PS_DATA1_REG_ADR 0x8E

#define LTC_ALS_REG_ADR 0x80
#define LTC_ALS_CH1_DATA0_REG_ADR 0x88
#define LTC_ALS_CH1_DATA1_REG_ADR 0x89
#define LTC_ALS_CH0_DATA0_REG_ADR 0x8A
#define LTC_ALS_CH0_DATA1_REG_ADR 0x8B

#define SDA_OUT_MODE() do{GPIO1->GDIR |= (1 << I2C_SDA);}while(0)
#define SCL_OUT_MODE() do{GPIO1->GDIR |= (1 << I2C_SCL);}while(0)
#define SDA_IN_MODE()  do{GPIO1->GDIR &= ~(1 << I2C_SDA);}while(0)

#define SDA_INPUT_LEVEL() ((GPIO1->DR & (1 << I2C_SDA)) ? 1 : 0)
#define SDA_OUTPUT_LEVEL(LEVEL) do{GPIO1->DR &= ~(1 << I2C_SDA);\
        GPIO1->DR |= (LEVEL << I2C_SDA);}while(0)
#define SCL_OUTPUT_LEVEL(LEVEL) do{GPIO1->DR &= ~(1 << I2C_SCL);\
        GPIO1->DR |= (LEVEL << I2C_SCL);}while(0)
// iic.c
void iic_init();
static void IIC_delay(int time);
void iic_start();
void iic_stop();
void iic_write_byte(uint8_t data);
uint8_t iic_read_byte();
void iic_send_ack();
void iic_send_nack();
uint8_t iic_wait_ack();

// software_ltr_553als
void iic_write_register(uint8_t regaddr,uint8_t regval);
uint8_t iic_read_register(uint8_t regaddr);
void read_ltr_553als_manufac_id();
void read_ltc_553als_ps_data();
void read_ltc_553als_als_data();
void iic_test();

// i2con.c
void iic1_pin_init();
void iic_con_init(I2C_Type* base);
void iic_con_start(I2C_Type* base);
void iic_con_restart(I2C_Type* base);
void iic_con_send_slave_addr(I2C_Type* base, uint8_t slave_rw);
void iic_con_stop(I2C_Type* base);
void iic_con_send_data(I2C_Type* base, uint8_t* buf, uint32_t size);
void iic_con_read_data(I2C_Type* base, uint8_t* buf, uint32_t size);

// hardware_ltr_553als
void hardware_ltr_553als_init();
void hardware_ltr_5553als_write_register(uint8_t regaddr, uint8_t regvl);
uint8_t hardware_ltr_5553als_read_register(uint8_t regaddr);
void hardware_read_ltr_553als_manufac_id();
void hardware_read_ltc_553als_ps_data();
void hardware_read_ltc_553als_als_data();

void hardware_iic_test();
#endif