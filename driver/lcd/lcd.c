#include "lcd.h"

uint32_t framebuffer_32[LCD_HEIGHT][LCD_WIDTH]; // 默认32位，实际可以为RGB565，RGB888
uint16_t framebuffer_16[LCD_HEIGHT][LCD_WIDTH];

void lcd_gpio_init() {
    volatile uint32_t *p;

    IOMUXC_SW_MUX_CTL_PAD_LCD_CLK &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_LCD_ENABLE &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_LCD_HSYNC &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_LCD_VSYNC &= ~(0xf << 0);

    /*LCD_DATA0 ~ LCD_DATA23*/
    for(p = IOMUXC_SW_MUX_CTL_PAD_LCD_DATA0_ADDR;
        p <= IOMUXC_SW_MUX_CTL_PAD_LCD_DATA23_ADDR; p++) {
            *p &= ~(0xf << 0);
    }
}

void lcd_clock_init() {
    /* 1.设置输出PLL高频率，Fref默认14MHz
    PLL output frequency = Fref * (DIV_SELECT + NUM/DENOM)
                    = 24MHZ * DIV_SELECT
                    = 24MHZ * 28
                    = 672MHZ

    DIV_SELECT = 28
    NUM        = 0
    DENOM      = 0

    ENABLE          [13   ]  1 Enalbe PLL output of CCM_ANALOG_PLL_VIDEO
    DIV_SELECT      [6 - 0]  his field controls the PLL loop divider. 
                             Valid range for DIV_SELECT divider value: 27~54
    */
    CCM_ANALOG->PLL_VIDEO &= ~(0x7f << 0);
    CCM_ANALOG->PLL_VIDEO |= (28 << 0) | (1 << 13);
    CCM_ANALOG->PLL_VIDEO_DENOM = 0;
    CCM_ANALOG->PLL_VIDEO_NUM = 0;

    /* 2.PLL分频:PLL最终输出频率
    POST_DIV_SELECT     = 4
    VIDEO_DIV           = 1
    最终得到的频率如下：
    PLL5—MAIN-CLOK      = 672MHZ/4/1=168MHZ

    POST_DIV_SELECT [20–19]  00 — Divide by 4 of PLL_VIDEO
    VIDEO_DIV       [31–30]  00 divide by 1 (Default) 0f MISC2n
    */
    CCM_ANALOG->PLL_VIDEO &= ~(0x3 << 19);
    CCM_ANALOG->MISC2 &= ~(0x3 << 30);


    /* 3.设置两个LCD管脚选择器和两个LCD频率分频器
    LCDIF1_PRED = 6
    LCDIF1_PODF = 3
    LCD_CLK     = 168MHZ / 6 / 3 = 9MHZ

    LCDIF1_PRE_CLK_SEL  [17–15]  010 derive clock from PLL5
    LCDIF1_CLK_SEL      [11-9 ]  000 derive clock from divided pre-muxed LCDIF1 clock
    LCDIF1_PRED         [14–12]  101 divide by 6
    LCDIF1_PODF         [25–23]  010 divide by 3
    */
    CCM->CSCDR2 &= ~(0x7 << 15);
    CCM->CSCDR2 |=  (0x2 << 15);
    CCM->CSCDR2 &= ~(0x7 << 9);
    CCM->CSCDR2 &= ~(0x7 << 12);
    CCM->CSCDR2 |=  (0x5 << 12);
    CCM->CBCMR  &= ~(0x7 << 23);
    CCM->CBCMR  |=  (0x2 << 23);

}

/*
support 16bit pix  RGB565
support 24bit pix  RGB888
*/
void lcd_ctrl_init(uint32_t pix_bits) {
    /*1.Reset lcd block
     SFTRST [31]  When set to one, it forces a block level reset.
                  This bit must be set to zero to enable normal operation of the eLCDIF
    */
    LCDIF->CTRL |= (1 << 31);
    gpt_delay_ms(500);
    LCDIF->CTRL = 0;

    /*2.模式设置
     BYPASS_COUNT [19] must be 1 in DOTCLK modes of operation.
     DOTCLK_MODE  [17] Set this bit to 1 to make the hardware go into the DOTCLK mode
     INPUT_DATA_SWIZZLE [15–14] 0x0 NO_SWAP — No byte swapping.(Little endian)
     CSC_DATA_SWIZZLE   [13–12] 0x0 NO_SWAP — No byte swapping.(Little endian)
     LCD_DATABUS_WIDTH  [11–10] 0x3 24_BIT — 24-bit data bus mode.
     WORD_LENGTH        [ 9–8 ] 0x0 16_BIT — Input data is 16 bits per pixel
                                0x3 24_BIT — Input data is 24 bits per pixel.

     DATA_FORMAT_16_BIT [3    ] When this bit is 0 and WORD_LENGTH = 0,
                                it implies that the 16-bit data is in RGB565 format.
                                When WORD_LENGTH is not 0, this bit does not care.
     MASTER             [5    ] Set this bit to make the eLCDIF act as a bus master.
     DATA_FORMAT_24_BIT [1    ] 0x0 ALL_24_BITS_VALID — Data input to the block is 
                                in 24 bpp format, such that all RGB 888 data is
                                contained in 24 bits.  
    */
    LCDIF->CTRL |= (1 << 19) | (1 << 17) | (0x3 << 10) | (1 << 5);
    if(pix_bits == 24){
        LCDIF->CTRL |= (0x3 << 8);
    }

   /*3.RGB格式设置
     BYTE_PACKING_FORMAT [19–16]
     In the 16-bit mode, a 16-bit half-word is valid only if adjacent bits [1:0] 
     or [3:2] or both are 1.
     For example, set the bit field value to 0x7 if the display data is arranged 
     in the 24-bit unpacked format (A-R-G-B where A value does not have be transmitted).
    */
    LCDIF->CTRL1 &= ~(0xf << 16);
    if(pix_bits == 24){
        LCDIF->CTRL1 |= (0x7 << 16);
    }else if(pix_bits == 16){
        LCDIF->CTRL1 |= (0xf << 16);
    }

   /*4.因硬件连线方便，需要设置位BGR顺序
      ODD_LINE_PATTERN  [18–16] 0x5 BGR —
      EVEN_LINE_PATTERN [14–12] 0x5 BGR —
    */
    LCDIF->CTRL2 &= ~(0x7 << 16);
    LCDIF->CTRL2 |=  (0x5 << 16);
    LCDIF->CTRL2 &= ~(0x7 << 12);
    LCDIF->CTRL2 |=  (0x5 << 12);
  
}

void lcd_timing_init(const elcdif_rgb_parm_t *parm) {
    /* 1.VDCTRL0控制器设置： DOTCLK模式使能、极性设置、帧同步单位设置、帧激活脉冲宽度设置
    VSYNC_OEB      [29] Should be set to 0 in the DOTCLK mode.
    ENABLE_PRESENT [28] Setting this bit to 1 will make the hardware generate the 
                        ENABLE signal in the DOTCLK mode,
    VSYNC_POL      [27] Default 0 active low during VSYNC_PULSE_WIDTH time
    HSYNC_POL      [26] Default 0 active low during HSYNC_PULSE_WIDTH time
    DOTCLK_POL     [25] Default is data launched at negative edge of DOTCLK 
                        and captured at positive edge，默认上升沿采集，写1翻转
    ENABLE_POL     [24] Default 0 active low during valid data transfer on 
                        each horizontal line.默认低电平有效
    VSYNC_PERIOD_UNIT      [21] Set it to 1 to count in terms of complete 
                                horizontal lines.帧同步周期的单位设定
    VSYNC_PULSE_WIDTH_UNIT [20] Set it to 1 to count in terms of complete 
                                horizontal lines. 帧同步的脉冲宽度的单位

    VSYNC_PULSE_WIDTH      [17:0] VPW:Number of units for which VSYNC signal is active.
    */
    LCDIF->VDCTRL0 = (0 << 29) | (1 << 28) | (1 << 21) | (1 << 20)
                    |(parm->vsync_pol << 27) | (parm->hsync_pol << 26)
                    |(parm->dotclk_pol << 25)| (parm->enable_pol << 24)
                    |(parm->vpw << 0) ;

    /*2.分辨率设置
    V_COUNT [31-16] Number of horizontal lines per frame which contain valid data.
    H_COUNT [15-0 ] Total valid data (pixels) in each horizontal line.
    */
    LCDIF->TRANSFER_COUNT = (parm->panelHeight << 16) | (parm->panelWidth << 0);

    /*3.帧同步周期
    Total number of units between two positive or two negative edges of the VSYNC signal.
    */
    LCDIF->VDCTRL1 = (parm->vpw + parm->vbp + parm->vfp + parm->panelHeight);

    /*4.行同步周期与行等待脉冲宽度设定
     HSYNC_PULSE_WIDTH [31–18] Number of DISPLAY CLOCK (pix_clk) cycles for 
                               which HSYNC signal is active：行激活脉冲宽度
     HSYNC_PERIOD      [17-0] Total number of DISPLAY CLOCK (pix_clk) cycles 
                              between two positive or two negative edges of the 
                              HSYNC signal.即，要将行数据放在低17位
    */
    LCDIF->VDCTRL2 = (parm->hpw << 18) 
                    |(parm->hpw + parm->hbp + parm->hfp + parm->panelWidth);

    /*5.设定帧等待总宽度与行等待总宽度
     HORIZONTAL_WAIT_CNT  [27–16]  wait for this number of clocks
                                  before the moving picture information begins.

     VERTICAL_WAIT_CNT    [15-0] it accounts for the vertical back porch lines
                                 plus the number of horizontal lines before the moving 
                                 picture begins. The unit for this parameter is 
                                 inherently the same as the VSYNC_PERIOD_UNIT.
    */ 
    LCDIF->VDCTRL3 = ((parm->hpw + parm->hbp) << 16) | ((parm->vpw + parm->vbp) << 0);               

    /*6.打开同步开关与行有效位设置
    SYNC_SIGNALS_ON [18] Set this field to 1 if the LCD controller requires that 
                         the VSYNC or VSYNC/HSYNC/DOTCLK control signals should
                         be active（同步时钟是否打开）
    DOTCLK_H_VALID_DATA_CNT [17-0] Total number of DISPLAY CLOCK (pix_clk)
    cycles on each horizontal line that carry valid data in DOTCLK mode.
    */
    LCDIF->VDCTRL4 = (1 << 18) | (parm->panelWidth << 0);
}

void lcd_framebuffer_add_init(uint32_t framebuffer_addr) {
    LCDIF->CUR_BUF = framebuffer_addr;
    LCDIF->NEXT_BUF = framebuffer_addr;
}

void lcd_enable(void) {
    /*
    When this bit is set by software, the eLCDIF will begin transferring data 
    between the SoC and the display.This bit must remain set until the operation
    is complete.
    */
    LCDIF->CTRL |= (1 << 0);
}

void lcd_clear_screen() {
    int i, j;
    int index;
    uint32_t pix[] = {0xff0000, 0x00ff00, 0x0000ff};//R G B

    for(i = 0; i < LCD_HEIGHT; i++) {
        index = 0; // 处理每列前先清空index
        for(j = 0; j < LCD_WIDTH; j++) {
            if(j == 160 || j == 320) index++;
            framebuffer_32[i][j] = pix[index];
        }
    }
}

void lcd_rgb888_init() {
    elcdif_rgb_parm_t lcd_parm = {
        .panelWidth  = LCD_WIDTH,
        .panelHeight = LCD_HEIGHT,
        .hpw         = 41,
        .hfp         = 2,
        .hbp         = 2,
        .vpw         = 10,
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
    lcd_framebuffer_add_init((uint32_t)framebuffer_32);
    lcd_clear_screen(); //初始化时就进行清屏工作
    lcd_enable();
}

void lcd_rgb888_test() {
    lcd_rgb888_init();
    while(1) {
    //    lcd_clear_screen();
        lcd_rgb888_picture_display();
    }
}

void lcd_rgb888_picture_display(void) {
    int i,j;
    uint32_t pix;
    uint8_t *p = (uint8_t *)gImage_picture_rgb888;

    for(i = 0;i < LCD_HEIGHT;i ++){
        for(j = 0;j < LCD_WIDTH;j ++){
            pix = (p[0] << 16) | (p[1] << 8) | (p[2] << 0);
            framebuffer_32[i][j] = pix;
            p += 3;
        }
    }
}

void lcd_rgb565_init(void) {
    elcdif_rgb_parm_t lcd_parm = {
        .panelWidth  = LCD_WIDTH,
        .panelHeight = LCD_HEIGHT,
        .hpw         = 41,
        .hfp         = 2,
        .hbp         = 2,
        .vpw         = 10,
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
    lcd_framebuffer_add_init((uint32_t)framebuffer_16);
    lcd_enable();

    return;
}

void lcd_rgb565_picture_display(void) {
    int i,j;
    uint16_t pix;
    uint8_t *p = (uint8_t *)gImage_picture_rgb565;

    for(i = 0;i < LCD_HEIGHT;i ++){
        for(j = 0;j < LCD_WIDTH;j ++){
            pix = (p[0] << 8) | (p[1] << 0);
            framebuffer_16[i][j] = pix;
            p += 2;
        }
    }

}


void lcd_rgb565_test(void)
{    
    lcd_rgb565_init();

    while(1){
        lcd_rgb565_picture_display();
    }

    return;
}