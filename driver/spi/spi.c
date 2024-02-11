#include "spi.h"

void spi_pin_init() {

    //ALT3 mux port: ECSPI4_MISO of instance: ecspi4
    IOMUXC_SW_MUX_CTL_PAD_GPIO2_IO14 &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_GPIO2_IO14 |= (0x3 << 0);

    //ALT3 mux port: ECSPI4_MOSI of instance: ecspi4
    IOMUXC_SW_MUX_CTL_PAD_GPIO2_IO13 &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_GPIO2_IO13 |= (0x3 << 0);

    //ALT3 mux port: ECSPI4_SCLK of instance: ecspi4
    IOMUXC_SW_MUX_CTL_PAD_GPIO2_IO12 &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_GPIO2_IO12 |= (0x3 << 0);

    //ALT5 mux port: GPIO1_IO03 of instance:gpio1 for spi cs
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 &= ~(0xf << 0);
    // IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 |= (0x5 << 0);

}

void spi_con_init() {
    /*
     BURST_LENGTH [31-20]  0x007  A SPI burst contains the 8 LSB in a word.
     PRE_DIVIDER  [15-12]  0x09   SPI Pre Divider
     POST_DIVIDER [11-8 ]  0000   Divide by 1.
     SPI Clock = 60MHZ /PRE_DIVIDER/POST_DIVIDER
               = 60MHZ /(9 + 1)/2^0
               = 6MHZ

     SMC          [3   ]  1 Immediately starts a SPI burst when data is written in TXFIFO.
     EN           [0   ]  1 Enable the block.            
    */
    ECSPI4->CONREG = (0x7 << 20) | (0x9 << 12) | (0x0 << 8) | (1 << 3) | (1 << 0);

}

void spi_channel_config(uint8_t channel, uint8_t phase, uint8_t pol) {
    // ECSPI4:[19-18] channel 
    ECSPI4->CONREG &= ~(channel << 18);
    ECSPI4->CONREG |= (channel << 18);

    // ECSPI4:[7-4] mode select from channel
    ECSPI4->CONREG |= (1 << (channel + 4));

    // CONFIGREG:[7-4] polarity
    // CONFIGREG:[3-0] phase
    ECSPI4->CONFIGREG &= ~((1 << channel) | (1 << (channel + 4)));
    ECSPI4->CONFIGREG |= ((phase << channel) | (pol << (channel + 4)));
}

uint8_t spi_transfer(uint8_t tx_data) {
    int flag = 0;
    uint8_t rx_data;
    
    // write data
    ECSPI4->TXDATA = tx_data;
    // check write complete:写完成后，数据被传输走，缓冲区为空
    do {
        flag = ECSPI4->STATREG & (1 << 0);
    } while(!flag);

    // check read complete
    do {
        flag = ECSPI4->STATREG & (1 << 3);
    } while(!flag);

    rx_data = ECSPI4->RXDATA;
    return rx_data;
}

void spi_cs_start() {
    GPIO1->GDIR |= (1 << 3);
    GPIO1->DR &= ~(1 << 3);
}

void spi_cs_stop() {
    GPIO1->GDIR |= (1 << 3);
    GPIO1->DR |= (1 << 3);
}

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
            spi_cs_start();
            data = spi_transfer(ch);
            spi_cs_stop();
            uart_printf("%c\r\n",data);
            gpt_delay_ms(500);
        }
    }
}
