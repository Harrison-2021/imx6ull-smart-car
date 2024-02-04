#include"iic.h"
//GPIO口模拟IIC的延时函数
static void IIC_delay(int time) {
    int i;

    for(i = 0;i < 50 * time;i ++)
    {

    }

    return;
}

// 1.初始化管脚工作模式
void iic_init() {
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO28 &= ~(0xf << 0); // SCL
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO28 |= (0x5 << 0);

    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO29 &= ~(0xf << 0); // SDL
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO29 |= (0x5 << 0);

    IIC_delay(1);
}

// 2.产生IIC开始信号
// SCL = 1, SDA = 1->0
void iic_start() {
    // SDA,SCL OUT MODE
    SDA_OUT_MODE();
    SCL_OUT_MODE();

    // SDA,SCL HIGH
    SDA_OUTPUT_LEVEL(HIGH);
    SCL_OUTPUT_LEVEL(HIGH);

    IIC_delay(1);

    // SDA->LOW
    SDA_OUTPUT_LEVEL(LOW);
    IIC_delay(1);

}

// 3.产生IIC停止信号
// SCL = 1, SDA = 0->1
void iic_stop() {
    SDA_OUT_MODE();
    SCL_OUT_MODE();

    //此时将SCL拉低，让为了让SDA可以改变电平状态，产生结束信号
    SDA_OUTPUT_LEVEL(LOW);
    SCL_OUTPUT_LEVEL(LOW);
    IIC_delay(1);

    SCL_OUTPUT_LEVEL(HIGH);
    IIC_delay(1);
    SDA_OUTPUT_LEVEL(HIGH);
    IIC_delay(1);

}

// 4.IIC总线写数据
/*Write 1 Byte to IIC*/
void iic_write_byte(uint8_t data) {

    // SDA为输出模式
    SDA_OUT_MODE();

    // SCL 为低电平，以便改变SDA上面的数据
    SCL_OUTPUT_LEVEL(LOW);

    //先发送最高位,在SCL高电平时,SDA必须保持稳定
    uint8_t i;
    uint8_t level;
    for(i = 8; i > 0; i--) {
        level = (data >> 7) & 1;
        SDA_OUTPUT_LEVEL(level);
        SCL_OUTPUT_LEVEL(HIGH);
        IIC_delay(1);

        //SCL为低电平时，SDA可以任意改变
        SCL_OUTPUT_LEVEL(LOW);

        //低位向高位移动
        data <<= 1;
        IIC_delay(1);
    }
}

/*Read 1 byte from IIC*/
uint8_t iic_read_byte() {
    // SDA为输入模式
    SDA_IN_MODE();

    // SCL 为低电平，以便改变SDA上面的数据
    SCL_OUTPUT_LEVEL(LOW);
    IIC_delay(1); // 等待SDL写数据

    uint8_t value = 0;
    uint8_t i;
    for(i = 8; i > 0; i--) {
        SCL_OUTPUT_LEVEL(HIGH);// 在高电平时读
        IIC_delay(1);

        value <<= 1;
        value |= SDA_INPUT_LEVEL();

        SCL_OUTPUT_LEVEL(LOW);
        IIC_delay(1);
    }
    return value;
}

/*主机向从机发送ACK*/
void iic_send_ack() {
    SDA_OUT_MODE();

    //SCL为低电平期间，数据允许改变
    SCL_OUTPUT_LEVEL(LOW);

    //拉低SDA线，产生ACK信号
    SDA_OUTPUT_LEVEL(LOW);
    IIC_delay(1);

    //SCL高电平期间，SDA保持稳定，从机读取SDA线上的状态
    SCL_OUTPUT_LEVEL(HIGH);
    IIC_delay(1);
}

/*主机向从机发送NACK*/
 void iic_send_nack() {
    SDA_OUT_MODE();

    SCL_OUTPUT_LEVEL(LOW);
    SDA_OUTPUT_LEVEL(HIGH);
    IIC_delay(1);

    //SCL为高电平期间，SDA也为高，此时主机不向从机发送ACK
    //，此时从机就知道，主机是不想接受数据了
    SCL_OUTPUT_LEVEL(HIGH);
    IIC_delay(1);
}

/*等待从机给主机的应答信号
*
 *0  : 成功
*-1 : 超时，失败
*/
uint8_t iic_wait_ack() {
    uint8_t ret;
    uint8_t time_out = 0;

    SDA_IN_MODE();

    SCL_OUTPUT_LEVEL(LOW);
    IIC_delay(1);

    SCL_OUTPUT_LEVEL(HIGH);
    IIC_delay(1);

    do {
        if(time_out > 50) {
            iic_stop();
            return -1;
        }
        
        ret = SDA_INPUT_LEVEL();
        IIC_delay(1);
        time_out++;
    } while(ret);
    return 0;
}
