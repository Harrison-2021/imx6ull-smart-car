# 1. 项目描述
- 本项目旨在对IMX6ull芯片常见外设进行学习和实验，了解其电路原理，工作原理与软件控制方式。
# 2. 模块介绍
## [1. GPIO-LED实验](https://github.com/Harrison-2021/imx6ull-smart-car/blob/main/nodes/1.GPIO-LED%E5%AE%9E%E9%AA%8C.md)

- IOMUX控制器特点;
- GPIO控制原理（管脚电平触发）与操作。

## [2. GPT定时器实验](https://github.com/Harrison-2021/imx6ull-smart-car/blob/main/nodes/2.GPT%E5%AE%9A%E6%97%B6%E5%99%A8%E5%AE%9E%E9%AA%8C.md)

- GPT工作原理（计数器，比较器）；
- GPT操作（时钟源，工作模式，延时设定）。

## [3. PWM控制蜂鸣器](https://github.com/Harrison-2021/imx6ull-smart-car/blob/main/nodes/3.PWM%E6%8E%A7%E5%88%B6%E8%9C%82%E9%B8%A3%E5%99%A8.md)

- PWM定义(占空比，频率）与工作原理；
- PWM驱动蜂鸣器工作过程。

## [4. UART串口通信](https://github.com/Harrison-2021/imx6ull-smart-car/blob/main/nodes/4.UART%E4%B8%B2%E5%8F%A3%E9%80%9A%E4%BF%A1.md)

- 常见串口通信电平标准（TTL, RS232, RS485, RS422）与协议；
- UART原理（并行与串行，同步与异步）与UART编程。

## [5. GIC中断控制器](https://github.com/Harrison-2021/imx6ull-smart-car/blob/main/nodes/5.%E6%8C%89%E9%94%AE%E4%B8%AD%E6%96%AD%E6%8E%A7%E5%88%B6%EF%BC%88GIC%EF%BC%89.md)

- 熟悉中断原理（ARM核中断处理过程）；
- GIC中断控制器的构成（中断类型，中断分发器，CPU接口单元）、中断分组、中断优先级、中断状态；
- GIC控制器响应IRQ编程（控制器初始化，中断函数注册，ARM核使能IRQ)。

## [6. ADC控制器采集电压信号](https://github.com/Harrison-2021/imx6ull-smart-car/blob/main/nodes/6.ADC%E6%8E%A7%E5%88%B6.md)

- ADC基本原理；
- ADC控制器操作（初始化，自校验，通道选择，中断处理）。

## [7. WDOG 看门狗使用](https://github.com/Harrison-2021/imx6ull-smart-car/blob/main/nodes/7.WDOG%E7%9C%8B%E9%97%A8%E7%8B%97%E5%AE%9E%E9%AA%8C.md)

- WDOC看门狗设计原理；
- WDOC操作使用（初始化，设置超时时间，喂狗操作）。

## [8. RTC时间获取](https://github.com/Harrison-2021/imx6ull-smart-car/blob/main/nodes/8.RTC%E6%97%B6%E9%97%B4%E8%8E%B7%E5%8F%96.md)

- RTC功能特点；
- 芯片供电系统(SNVS_HP,SNVS_LP); 
- RTC时间获取以及alarm中断的操作过程。

## [9. IIC通信1-GPIO模拟时序](https://github.com/Harrison-2021/imx6ull-smart-car/blob/main/nodes/9.IIC%E6%80%BB%E7%BA%BF%E9%80%9A%E4%BF%A11-GPIO%E6%A8%A1%E6%8B%9F.md)

- IIC总线特点，信号类型（开始信号，结束信号，响应信号）数据传输格式；
- GPIO模拟IIC时序读取LTR-553ALS-WA光环境传感器数据。

## [10. IIC通信2-SOC内置IIC控制器](https://github.com/Harrison-2021/imx6ull-smart-car/blob/main/nodes/10.IIC%E9%80%9A%E4%BF%A12-SOC%E5%86%85%E7%BD%AEIIC%E6%8E%A7%E5%88%B6%E5%99%A8.md)

- IIC控制器特点（仲裁，初始化，产生开始、终止、再次开始、清除中断状态等）；
- 使用iIC控制器读取LTR-553ALS-WA光环境传感器数据。

## [11. SPI总线通信](https://github.com/Harrison-2021/imx6ull-smart-car/blob/main/nodes/11.SPI%E6%80%BB%E7%BA%BF%E9%80%9A%E4%BF%A1.md)

- SPI总线特点(主从机连接方式，数据传输方式）；
- SPI时序；
- SPI控制器特点；
- SPI回环测试。

## [12. 1-wire单总线通信](https://github.com/Harrison-2021/imx6ull-smart-car/blob/main/nodes/12.1-wire%E5%8D%95%E6%80%BB%E7%BA%BF%E9%80%9A%E4%BF%A1.md)

- 单总线通信特点；
- DS18B20操作过程（主设备探测与读写）与操作时序（初始化序列，写入时序，读取时序）；
- 主设备通过1-wire总线读取DS18B20的ID和采集的温度。

## [13. CAN通信](https://github.com/Harrison-2021/imx6ull-smart-car/blob/main/nodes/13.CAN%E9%80%9A%E4%BF%A1.md)

- CAN通信特点（差分信号，线与机制）；
- CAN通信协议（一帧数据格式，位序与字节序，仲裁机制，位填充机制，错误帧（分类，格式)；错误状态转换（主动错误，被动错误，总线关闭），过载帧，帧间隔）；
- CAN采样点与波特率（位时间）；
- FlexCAN控制器特点（工作模式，时钟信号，缓冲区数据结构，发送与接收过程，协议时间）；
- 使用FlexCAN控制器实现数据收发；
- CAN 盒与CANTest使用。

## [14. LCD屏控制](https://github.com/Harrison-2021/imx6ull-smart-car/blob/main/nodes/14.LCD%E5%B1%8F%E6%8E%A7%E5%88%B6.md)

- LCD屏工作原理；分类；常用接口（RGB接口，MCU接口，VGA，HDMI，IIC/SPI）；
- RGB与YUV格式（YUV采样方式）;
    RGB接口时序；LCD控制器特点（DOTCLK接口，时钟信号）；
- LCD RGB 接口操作（清屏，RGB888/RGB656图片显示）。

## [15. Camera控制](https://github.com/Harrison-2021/imx6ull-smart-car/blob/main/nodes/15.Camera%E6%8E%A7%E5%88%B6.md)



## [16. 触摸屏控制]()

# 3.项目展示

## 1. 按键控制LED灯
![请添加图片描述](https://img-blog.csdnimg.cn/direct/10b5382476a44da5aff16e3cf343d4d2.gif)

## 2. GPT定时器控制LED灯闪烁时间
![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/ae63afdf8ec44d10acfc7628a4c23248.gif)

## 3. PWM控制蜂鸣器波形

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/14e0e0b9e272433b97a224bf1ab92db4.gif)

## 4. UART 串口通信

### UART接受与发送

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/ca8a73d465ee4431af7522c80af41c85.gif)

### 自定义printf函数实现

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/14b440ee3fa34d1ba4cb4ee10d08a2f7.png)

## 5. GIC中断控制器响应按键中断请求

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/3c98318087a94cf9bc32dbb5826f51fc.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/1b91e989b506425aa8bafa2cfd155a1d.gif)

## 6. ADC控制器采集电压信号

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/6999b5d54d3f4087b3f6d9f16f95600e.png)

## [7. WDOG 看门狗使用]()

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/9f6be27460a449d093637c7d065c5aaa.png)

## [8. RTC时间获取]()

### RTC时间获取

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/273cc01c104b4ece8c284bbb264c80a9.png)

### alarm中断触发

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/273cc01c104b4ece8c284bbb264c80a9.png)

## [9. IIC通信1-GPIO模拟时序]()

### 1. 读光环境传感器ID

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/a9fa6a20e8504afaa3aa641f590533af.png)

### 2. 读取接近传感器数据

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/10b1d0a27fd046cfaef5a8037ce1e656.png)

### 3. 读取光线传感器数据

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/64a27f81f7d342e98569c4ba8719aed4.png)

## [10. IIC通信2-SOC内置IIC控制器]()

### 1. 测试读取传感器ID

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/f84a563aae264afb855d0cc1494d6413.png)

### 2. 测试读取接近传感器与光线传感器值

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/cf7c0ee7f31547a09eba492a64a4be36.png)

## [11. SPI总线通信]()

```c
void spi_test() {
    uint8_t data;
    uint8_t ch;

    spi_pin_init();
    spi_con_init();
    // 因使用软件GPIO口选择片选信号，通道可以随便选取，如果使用spi控制器，通道要与片选管脚对应
	// 极性与相位，本例只是测试，可以随便选取，实际中要与从设备匹配
    spi_channel_config(0,0,0);
    
    while(1){
        for(ch = 'a';ch <= 'z'; ch ++){
            // 在一个片选信号周期传输数据
            spi_cs_start();
            data = spi_transfer(ch);
            spi_cs_stop();
            uart_printf("%c\r\n",data);
            gpt_delay_ms(500);
        }
    }
}
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/8e3546002c8b4848899fe1aaf64269e5.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/145e85a87ab3478f8fb93cf47da33553.png)

## [12. 1-wire单总线通信]()

### 1. 读取DS1B20的ID

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/58e104c5ada048d7a2f89e3c9a4cf96b.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/75402a221b2a47edaffc669979287d70.png)

### 2. 读取DS1B20采集的温度

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/e80f16e4e4144e548b0cb196a9945486.png)

## [13. CAN通信]()

### 1. 回环测试

#### Loopback Enable/Disable

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/a68302198e1b4ec69af2aad4a8680535.png)

```c
void flexcan_loopback_enable(CAN_Type *base) {
    /* 1.进入冻结模式，控制进行设置 */
    flexcan_freeze_enable(base);

    /* 2.回环模式开启 
    LPB  [12] 1 Loop Back enabled
              0 Loop Back disabled
    */
    base->CTRL1 |= (1 << 12);

    /* 3.解冻 */
    flexcan_freeze_disable(base);
}

void flexcan_loopback_disable(CAN_Type *base) {
    /* 1.进入冻结模式，控制进行设置 */
    flexcan_freeze_enable(base);

    /* 2.回环模式开启 
    LPB  [12] 1 Loop Back enabled
              0 Loop Back disabled
    */
    base->CTRL1 &= ~(1 << 12);

    /* 3.解冻 */
    flexcan_freeze_disable(base);
}
```

#### 测试代码

```c
void flexcan_loopback_test() {
    int size = 0;
    uint8_t rx_buf[8];
    uint8_t tx_buf[ ] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};

    flexcan_gpio_init();
    flexcan_clock_init();
    // flexcan_can_init(CAN2);
    // flexcan_freeze_enable(CAN2);
    // flexcan_freeze_disable(CAN2);
    flexcan_sample_bitRate_init(CAN2); // 注意，采样率和波特率要设置
    flexcan_loopback_enable(CAN2);

    flexcan_rx_MB_config(CAN2, RX_MB_INDEX, 0x233);

    int i, j;
    while(1) {
        for(i = 0; i < sizeof(tx_buf); i++) {
            // 回环测试的id，发送与接受一定要相同
            flexcan_send_data(CAN2, 0x233, tx_buf, i + 1); 
            uart_printf("flexcan send data ok\r\n");
            size = flexcan_recv_data(CAN2,0x233,rx_buf,sizeof(rx_buf));
            uart_printf("can rx: ");
            for(j = 0;j < size;j ++){
                uart_printf("%x ",rx_buf[j]);
            }
            uart_printf("\r\n");
            gpt_delay_ms(500);
        }
    }
}
```

#### 结果展示

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/5642a4ba79d940c1aa8c69a3544ac861.png)

### 2. CAN节点测试

#### 中断初始化

```c
void flexcan_interrupt_init(CAN_Type *base, int mb_index) {
    /*Enable flexcan interrupt*/
    if(mb_index < 32) {
        base->IMASK1 |= (1 << (mb_index));
    } else {
        base->IMASK2 |= (1 << (mb_index - 32));
    }
    /* 注册中断 */
    request_irq(CAN2_IRQn, flexcan_interrupt_handler);
    /* arm使能中断 */
    enable_irq();
}

/* 注意，此id是中断号，不是报文id */
int flexcan_interrupt_handler(int id) {
    int j, size;
    uint8_t rx_buf[8];

    /* 发送和接受到数据后，会产生中断，在中断函数中打印接收的数据 */
    size = flexcan_recv_data(CAN2, 0x120, rx_buf, sizeof(rx_buf));
    uart_printf("can rx:");
    for(j = 0;j < size;j ++){
        uart_printf("%x ",rx_buf[j]);
    }
    uart_printf("\r\n");
}
```

#### 测试代码

```c
void flexcan_normal_test() {
    int i;
    int j;
    uint8_t tx_buf[ ] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};

    flexcan_gpio_init();
    flexcan_clock_init();
    flexcan_sample_bitRate_init(CAN2);
    flexcan_loopback_disable(CAN2);
    flexcan_interrupt_init(CAN2,RX_MB_INDEX);

    /*MB9 for rx*/
    flexcan_rx_MB_config(CAN2,RX_MB_INDEX,0x120);

    while(1){
        for(i = 0;i < sizeof(tx_buf);i ++){
            flexcan_send_data(CAN2,0x230,tx_buf,i + 1);
            // uart_printf("flexcan send data ok\r\n");
     
            gpt_delay_ms(1000);
        }
    }
}
```

#### 结果展示

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/2b3622b3289a4c60babb75dc1f0bd3f4.png)

## [14. LCD屏控制]()

### 1.清屏功能

> 注意，`6ull的lcd控制器内部没有DMA,无法将内存中的显存连续传入LCD屏中，因此，需要持续刷新`
>
> <font color=red>**当然，也可以使用mmap将LCD的framebuffer显存映射到用户区，这样直接操作用户空间，可以直接改变硬件的内存，无需将用户区的内存数据刷新到硬件内存中**</font>

```c
#define RGB888_PIX_BITS 24

void lcd_rgb888_init(void)
{
    elcdif_rgb_parm_t lcd_parm = {
        .panelWidth  = LCD_WIDTH,
        .panelHeight = LCD_HEIGHT,
        .hsw         = 41,
        .hfp         = 2,
        .hbp         = 2,
        .vsw         = 10,
        .vfp         = 2,
        .vbp         = 2,
        .vsync_pol   = 0,
        .hsync_pol   = 0,
        .dotclk_pol  = 1,
        .enable_pol  = 1,
    };

    lcd_gpio_init();
    lcd_clock_init();
    lcd_ctrl_init(RGB888_PIX_BITS);
    lcd_timing_init(&lcd_parm);
    lcd_framebuffer_addr_init((uint32_t)framebuffer_32);
    lcd_clear_screen();
    lcd_enable();

    return;
}

void lcd_test(void)
{    
    lcd_rgb888_init();

    while(1){
       lcd_clear_screen();
    }

    return;
}

```

#### 结果展示

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/89a85184b6294794b13095bf6e00b95e.png)

### 2.RGB888图片显示

> 1.先将图片转位二进制格式
>
> ![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/0deaafa494f942d78d4e02a25f17af2e.png)

```c
#include "picture.h"

#define RGB888_PIX_BITS 24

void lcd_rgb888_init(void)
{
    elcdif_rgb_parm_t lcd_parm = {
        .panelWidth  = LCD_WIDTH,
        .panelHeight = LCD_HEIGHT,
        .hsw         = 41,
        .hfp         = 2,
        .hbp         = 2,
        .vsw         = 10,
        .vfp         = 2,
        .vbp         = 2,
        .vsync_pol   = 0,
        .hsync_pol   = 0,
        .dotclk_pol  = 1,
        .enable_pol  = 1,
    };

    lcd_gpio_init();
    lcd_clock_init();
    lcd_ctrl_init(RGB888_PIX_BITS);
    lcd_timing_init(&lcd_parm);
    lcd_framebuffer_addr_init((uint32_t)framebuffer_32);
    lcd_clear_screen();
    lcd_enable();

    return;
}

void lcd_rgb888_picture_display(void)
{
    int i,j;
    uint32_t pix;
    uint8_t *p = (uint8_t *)gImage_picture;

    for(i = 0;i < LCD_HEIGHT;i ++){
        for(j = 0;j < LCD_WIDTH;j ++){
            pix = (p[0] << 16) | (p[1] << 8) | (p[2] << 0);
            framebuffer_32[i][j] = pix;
            p += 3;
        }
    }

    return;
}

void lcd_rgb888_test(void)
{    
    lcd_rgb888_init();

    while(1){
        lcd_rgb888_picture_display();
       //lcd_clear_screen();
    }

    return;
}

```

#### 结果展示

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/5081c97e6c49443b9a674730e8e101c8.png)

### 3.RGB565图片显示

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/7e13f5bed68d428a9459bf9433f681a2.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/be62ee3194ae4a9fb463be0d51542e0a.png)

```c
#include "picture.h"

#define RGB565_PIX_BITS 16

uint16_t framebuffer_16[LCD_HEIGHT][LCD_WIDTH];

void lcd_rgb565_init(void)
{
    elcdif_rgb_parm_t lcd_parm = {
        .panelWidth  = LCD_WIDTH,
        .panelHeight = LCD_HEIGHT,
        .hsw         = 41,
        .hfp         = 2,
        .hbp         = 2,
        .vsw         = 10,
        .vfp         = 2,
        .vbp         = 2,
        .vsync_pol   = 0,
        .hsync_pol   = 0,
        .dotclk_pol  = 1,
        .enable_pol  = 1,
    };

    lcd_gpio_init();
    lcd_clock_init();
    lcd_ctrl_init(RGB565_PIX_BITS);
    lcd_timing_init(&lcd_parm);
    lcd_framebuffer_addr_init((uint32_t)framebuffer_16);
    lcd_enable();

    return;
}

void lcd_rgb565_picture_display(void)
{
    int i,j;
    uint16_t pix;
    uint8_t *p = (uint8_t *)gImage_picture;

    for(i = 0;i < LCD_HEIGHT;i ++){
        for(j = 0;j < LCD_WIDTH;j ++){
            pix = (p[0] << 8) | (p[1] << 0);
            framebuffer_16[i][j] = pix;
            p += 2;
        }
    }

    return;
}


void lcd_rgb565_test(void)
{    
    lcd_rgb565_init();

    while(1){
        lcd_rgb565_picture_display();
    }

    return;
}

```

#### 结果展示

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/5081c97e6c49443b9a674730e8e101c8.png)

## [15. Camera控制]()



## [16. 触摸屏控制]()
