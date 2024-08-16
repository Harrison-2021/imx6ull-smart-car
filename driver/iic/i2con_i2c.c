#include"iic.h"

/* iic_pin_init*/
void iic1_pin_init() {
    // SCL
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO28 &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO28 |= (0x2 << 0);

    // SDA
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO29 &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO29 |= (0x2 << 0);

}

/* iic_control init*/
void iic_con_init(I2C_Type* base) {
    // I2C not enable
    base->I2CR &= ~(1 << 7);

    /* target: <400kHZ, ~= 100KHZ
       clocks : 66MHZ --> div:660
    */
    // base->IFDR &= ~(0x1f << 0);
    // base->IFDR |= (0x15 << 0);
    // 15-6:read-only,always has the value 0
    base->IFDR = 0x15;  

    // I2C enable
    base->I2CR |= (1 << 7);
}

/* iic_control start signal*/
void iic_con_start(I2C_Type* base) {
    // clear interrupt, 防止中断期间，无法执行开始信号
    base->I2SR &= ~(1 << 1);

    // start signal,from 0 to 1
    base->I2CR &= ~(1 << 5);
    base->I2CR |= (1 << 5);
}

/* iic_control restart signal*/
void iic_con_restart(I2C_Type* base) {
    // clear interrupt, 防止中断期间，无法执行开始信号
    base->I2SR &= ~(1 << 1);

    // start signal
    base->I2CR |= (1 << 2);
}

/* send slave addr + write/read*/ 
void iic_con_send_slave_addr(I2C_Type* base, uint8_t slave_rw) {
    int flag = 0;
    //master transmit mode
    base->I2CR |= (1 << 4);
    // send data
    base->I2DR = slave_rw;

    // check send finish
    do {
        flag = base->I2SR & (1 << 1);
    } while(!flag);

    // clear interrupt
    base->I2SR &= ~(1 << 1);
    
}

/* send stop signal*/
void iic_con_stop(I2C_Type* base) {
    // 延时一点时间，等待NACK/ACK信号完成，才能停止
    gpt_delay_ms(10);
    // clear interrupt
    base->I2SR &= ~(1 << 1);
    // stop signal:from 1 to 0
    base->I2CR |= (1 << 5);
    base->I2CR &= ~(1 << 5);
}

/* send data*/
void iic_con_send_data(I2C_Type* base, uint8_t* buf, uint32_t size) {
    int i;
    int flag = 0;
    // master transmit mode
    base->I2CR |= (1 << 4);

    for(i = 0; i < size; i++) {
        // send data
        base->I2DR = buf[i];

        // check send finish(receive success)-通过中断确定从机是否发送ACK,决定是否继续发送
        do {
            flag = base->I2SR & (1 << 1);
        } while(!flag);

        // clear interrupt, iic start work
        base->I2SR &= ~(1 << 1);
    }
}

/* read data*/
void iic_con_read_data(I2C_Type* base, uint8_t* buf, uint32_t size) {
    int i;
    int flag = 0;
    uint8_t dummy;

    // mode : receive
    // ACK is sent(auto)
    base->I2CR &= ~((1 << 4) | (1 << 3));

    // dummy data -需要先读取寄存器，触发寄存器放入数据
    dummy = base->I2DR;

    for(i = 0; i < size; i++) {
        if(i == size -1) base->I2CR |= (1 << 3); // 读取最后字节前，自动发NACK=寄存器操作
        // wait one byte transfer is completed
        do {
            flag = base->I2SR & (1 << 1);
        } while(!flag);
        // read data
        buf[i] = base->I2DR;
        // clear interrupt, iic start work
        base->I2SR &= ~(1 << 1);
    }
}