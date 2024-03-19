#ifndef _LCD_H
#define _LCD_H

#include "imx6ull.h"
#include "gpt.h"
#include "uart.h"
#include "picture_rgb888.h"
#include "picture_rgb565.h"

#define LCD_WIDTH  480
#define LCD_HEIGHT 272
#define RGB888_PIX_BITS 24
#define RGB565_PIX_BITS 16

typedef struct
{
    uint16_t panelWidth;  /*!< Display panel width, pixels per line. */
    uint16_t panelHeight; /*!< Display panel height, how many lines per panel. */
    uint8_t hpw;          /*!< HSYNC pulse width. */
    uint8_t hfp;          /*!< Horizontal front porch. */
    uint8_t hbp;          /*!< Horizontal back porch. */
    uint8_t vpw;          /*!< VSYNC pulse width. */
    uint8_t vfp;          /*!< Vrtical front porch. */
    uint8_t vbp;          /*!< Vertical back porch. */
    uint8_t vsync_pol;    /*Default 0 active low during VSYNC_PULSE_WIDTH time*/
    uint8_t hsync_pol;    /*Default 0 active low during HSYNC_PULSE_WIDTH time*/
    uint8_t dotclk_pol;   /*Default is data launched at negative edge of DOTCLK and 
                           captured at positive edge.*/
    uint8_t enable_pol;   /*Default 0 active low during valid data transfer on each 
                           horizontal line.*/
} elcdif_rgb_parm_t;


void lcd_gpio_init();
void lcd_clock_init();
void lcd_ctrl_init(uint32_t pix_bits);
void lcd_timing_init(const elcdif_rgb_parm_t *parm);
void lcd_framebuffer_add_init(uint32_t framebuffer_addr);
void lcd_clear_screen();
void lcd_rgb888_init();
void lcd_rgb888_test();
void lcd_rgb888_picture_display(void);

#endif