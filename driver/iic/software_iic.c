#include "imx6ull.h"

typedef unsigned char uint8;

#define     SDA_OUT_MODE()    do{GPIO1->GDIR |= (1 << 29);}while(0)
#define     SCL_OUT_MODE()    do{GPIO1->GDIR |= (1 << 28);}while(0)
#define     SDA_IN_MODE()     do{GPIO1->GDIR &= ~(1 << 29);}while(0)

#define     SDA_INPUT_LEVEL()        ((GPIO1->DR & (1 << 29)) ? 1 : 0)  
#define     SDA_OUTPUT_LEVEL(LEVEL)  do{GPIO1->DR &= ~(1 << 29);GPIO1->DR |= (LEVEL << 29);}while(0)
#define     SCL_OUTPUT_LEVEL(LEVEL)  do{GPIO1->DR &= ~(1 << 28);GPIO1->DR |= (LEVEL << 28);}while(0)

#define     HIGH        1
#define     LOW         0

//GPIO口模拟IIC的延时函数
static void IIC_delay(int time)
{
    int i;

    for(i = 0;i < 50 * time;i ++)
    {

    }

    return;
}

void software_iic_init()
{
    //设置管脚为GPIO功能
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO28 &= ~(0xf << 0);//SCL
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO28 |=  (0x5 << 0);

    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO29 &= ~(0xf << 0);//SDA
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO29 |=  (0x5 << 0);

    IIC_delay(1);

    return;
}

/*IIC START:SCL = 1,SDA = 1->0*/
void software_iic_start()
{
    //SDA/SCL 输出模式
    SDA_OUT_MODE();
    SCL_OUT_MODE();

    //开始的时候，SDA和SCL都是高电平状态
    SDA_OUTPUT_LEVEL(HIGH);
    SCL_OUTPUT_LEVEL(HIGH);

    IIC_delay(1);

    //在SCL为高电平状态时，SDA从高变成低，产生开始信号
    SDA_OUTPUT_LEVEL(LOW);
    IIC_delay(1);

    return;
}

/*IIC STOP:SCL = 1,SDA = 0->1*/
void software_iic_stop()
{
    //SDA/SCL 输出模式
    SDA_OUT_MODE();
    SCL_OUT_MODE();

    //此时将SCL拉低，让为了让SDA可以改变电平状态，产生结束信号
    SCL_OUTPUT_LEVEL(LOW);
    SDA_OUTPUT_LEVEL(LOW);
    IIC_delay(1);
    
    //SCL为高电平时，SDA从低到高，产生结束信号
    SCL_OUTPUT_LEVEL(HIGH);
    IIC_delay(1);
    SDA_OUTPUT_LEVEL(HIGH);
    IIC_delay(1);

    return;
}

/*Write 1 Byte to IIC*/
void software_iic_write_byte(uint8 data)
{
    int level;
    uint8 loop;

    //SDA为输出模式
    SDA_OUT_MODE();

    //SCL 为低电平，以便改变SDA上面的数据
    SCL_OUTPUT_LEVEL(LOW);

    for(loop = 8;loop > 0;loop --)
    {
        //先发送最高位,在SCL高电平时,SDA必须保持稳定
        level = (data >> 7) & 1;
        SDA_OUTPUT_LEVEL(level);
        SCL_OUTPUT_LEVEL(HIGH);
        IIC_delay(1);

        //SCL为低电平时，SDA可以任意改变
        SCL_OUTPUT_LEVEL(LOW);
        //低位向高位移动
        data <<= 1;//data = data << 1
        IIC_delay(1);
    }

    return;
}

/*Read 1 byte from IIC*/
uint8 software_iic_read_byte()
{
    uint8 loop;
    uint8 value = 0;

    //SDA为输入模式
    SDA_IN_MODE();

    //SCL 为低电平，以便改变SDA上面的数据
    SCL_OUTPUT_LEVEL(LOW);
    IIC_delay(1);

    for(loop = 8; loop > 0;loop --)
    {
        SCL_OUTPUT_LEVEL(HIGH);
        IIC_delay(1);

        value <<= 1;
        //读取1位数据
        value |= SDA_INPUT_LEVEL();

        SCL_OUTPUT_LEVEL(LOW);
        IIC_delay(1);
    }

    return value;
}

/*主机向从机发送ACK*/
void software_iic_send_ack()
{
    SDA_OUT_MODE();

    //SCL为低电平期间，数据允许改变
    SCL_OUTPUT_LEVEL(LOW); 
    //拉低SDA线，产生ACK信号
    SDA_OUTPUT_LEVEL(LOW); 
    IIC_delay(1);

    //SCL高电平期间，SDA保持稳定，从机读取SDA线上的状态
    SCL_OUTPUT_LEVEL(HIGH);
    IIC_delay(1);

    return;
}

/*主机向从机发送NACK*/
void software_iic_send_nack(void)
{
    SDA_OUT_MODE();

    SCL_OUTPUT_LEVEL(LOW);
    SDA_OUTPUT_LEVEL(HIGH);
    IIC_delay(1);

    //SCL为高电平期间，SDA也为高，此时主机不向从机发送ACK，
    //此时从机就知道，主机是不想接受数据了
    SCL_OUTPUT_LEVEL(HIGH); 
    IIC_delay(1);

    return;
}

/*等待从机给主机的应答信号
 *
 *0  : 成功
 *-1 : 超时，失败
 */
uint8 software_iic_wait_ack()
{
    uint8 ret;
    uint8 time_out = 0;

    //SDA设为输入模式
    SDA_IN_MODE();

    SCL_OUTPUT_LEVEL(LOW);
    IIC_delay(1);

    //SCL为高电平期间，读取SDA的值
    SCL_OUTPUT_LEVEL(HIGH);
    IIC_delay(1);

    do{
        if(time_out >50)
        {
            software_iic_stop();
            return -1;
        }

        //读取SDA状态
        ret = SDA_INPUT_LEVEL();
        IIC_delay(1);
        time_out ++;
    }while(ret);

    return 0;
}
