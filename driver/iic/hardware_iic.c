#include "imx6ull.h"

void iic1_pin_init2(void)
{   
    //SCL
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO28 &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO28 |=  (0x2 << 0);
    
    //SDA
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO29 &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO29 |=  (0x2 << 0);

    return;
}

void iic_con_init2(I2C_Type *base)
{
    /*i2c disabled*/
    base->I2CR &= ~(1 << 7);

    /*
    *I2C SCL = 100KHZ
    *IPG CLK = 66MHZ = 66000KHZ
    *    DIV = 660
    */
    base->IFDR = 0x15;

    /*Enable I2C*/
    base->I2CR |= (1 << 7);
    
    return;
}

void iic_con_send_start(I2C_Type *base)
{
    /*Clear Interrupt,IIC start work*/
    base->I2SR &= ~(1 << 1);

    /*
      MSTA [5]  Changing MSTA from 0 to 1 signals a Start 
                on the bus and selects Master mode.
    */
    base->I2CR &= ~(1 << 5);
    base->I2CR |= (1 << 5);

    return;
}

void iic_con_send_repeat_start(I2C_Type *base)
{
    /*Clear Interrupt,IIC start work*/
    base->I2SR &= ~(1 << 1);

    /*
     RSTA [2] 1 Generates a Repeated Start condition
    */
   base->I2CR |= (1 << 2);

   return;
}

void iic_con_send_slave_addr2(I2C_Type *base,uint8_t slave_rw)
{
    int flag;

    /*Master Transmit Mode*/
    base->I2CR |= (1 << 4);

    /*Send data*/
    base->I2DR = slave_rw;

    /*Wait One byte transfer is completed*/
    do{
        flag = base->I2SR & (1 << 1);
    }while(!flag);

    /*Clear Interrupt,IIC start work*/
    base->I2SR &= ~(1 << 1);

    return;
}

void iic_con_send_stop(I2C_Type *base)
{
    gpt_delay_ms(10);
    
    /*Clear Interrupt,IIC start work*/
    base->I2SR &= ~(1 << 1);

    /*
      MSTA [5]  Changing MSTA from 1 to 0 generates a Stop 
                and selects Slave mode
    */
    base->I2CR |= (1 << 5);
    base->I2CR &= ~(1 << 5);

    return;
}

void iic_con_send_data2(I2C_Type *base,uint8_t *buf,uint32_t size)
{
    int i;
    int flag;

    /*Master Transmit Mode*/
    base->I2CR |= (1 << 4);

    for(i = 0;i < size;i ++){
        /*Send data*/
        base->I2DR = buf[i];

        /*Wait One byte transfer is completed*/
        do{
            flag = base->I2SR & (1 << 1);
        }while(!flag);

        /*Clear Interrupt,IIC start work*/
        base->I2SR &= ~(1 << 1);
    }

    return;
}

void iic_con_read_data2(I2C_Type *base,uint8_t *buf,uint32_t size)
{
    int i;
    int flag;
    uint8_t dumy;

    /*
     TXAK [3] 0 An acknowledge signal is sent
     MTX  [4] 0 Receive.
    */
    base->I2CR &= ~((1 << 4) | (1 << 3));

    /*Dumy data*/
    dumy = base->I2DR;

    for(i = 0;i < size;i ++){

        if(i == size - 1){
           /*
            * TXAK [3] 1 No acknowledge signal response is sent
            */
            base->I2CR |= (1 << 3);
        }
        
        /*Wait One byte transfer is completed*/
        do{
            flag = base->I2SR & (1 << 1);
        }while(!flag);

        buf[i] = base->I2DR;
        
        /*Clear Interrupt,IIC start work*/
        base->I2SR &= ~(1 << 1);
    }

    return;
}
