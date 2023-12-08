#ifndef _IMX6ULL_HEAD_H
#define _IMX6ULL_HEAD_H

#include <stdint.h>

/*CCM Clock Multiplexer Register*/
#define CCM_CCSR   *((volatile unsigned int *)0x20C400C)
#define CCM_CSCMR2 *((volatile unsigned int *)0x20C4020)

/*CCM Clock Gating Register*/
#define CCM_CCGR0 *((volatile unsigned int *)0x20C4068)
#define CCM_CCGR1 *((volatile unsigned int *)0x20C406C)
#define CCM_CCGR2 *((volatile unsigned int *)0x20C4070)
#define CCM_CCGR3 *((volatile unsigned int *)0x20C4074)
#define CCM_CCGR4 *((volatile unsigned int *)0x20C4078)
#define CCM_CCGR5 *((volatile unsigned int *)0x20C407C)
#define CCM_CCGR6 *((volatile unsigned int *)0x20C4080)

/*GPIO MUX  Register*/
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 *((volatile unsigned int *)0x20E0068)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO05 *((volatile unsigned int *)0x20E0070)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO08 *((volatile unsigned int *)0x20E007C)
// touch screen reset pin
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO09 *((volatile unsigned int *)0x20E0080)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO16 *((volatile unsigned int *)0x20E0084)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO17 *((volatile unsigned int *)0x20E0088)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO18 *((volatile unsigned int *)0x20E008C)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO19 *((volatile unsigned int *)0x20E0090)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO20 *((volatile unsigned int *)0x20E0094)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO21 *((volatile unsigned int *)0x20E0098)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO22 *((volatile unsigned int *)0x20E009C)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO23 *((volatile unsigned int *)0x20E00A0)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO24 *((volatile unsigned int *)0x20E00A4)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO25 *((volatile unsigned int *)0x20E00A8)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO26 *((volatile unsigned int *)0x20E00AC)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO27 *((volatile unsigned int *)0x20E00B0)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO28 *((volatile unsigned int *)0x20E00B4)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO29 *((volatile unsigned int *)0x20E00B8)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO30 *((volatile unsigned int *)0x20E00BC)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO31 *((volatile unsigned int *)0x20E00C0)

#define IOMUXC_SW_MUX_CTL_PAD_GPIO5_IO02 *((volatile unsigned int *)0x2290010)
// touch screen interrupt pin
#define IOMUXC_SW_MUX_CTL_PAD_GPIO5_IO09 *((volatile unsigned int *)0x229002C)

#define IOMUXC_SW_MUX_CTL_PAD_GPIO2_IO08 *((volatile unsigned int *)0x20E00E4)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO2_IO09 *((volatile unsigned int *)0x20E00E8)

// 0011 ALT3 — Select mux mode: ALT3 mux port: ECSPI4_SCLK of instance: ecspi4
#define IOMUXC_SW_MUX_CTL_PAD_GPIO2_IO12 *((volatile unsigned int *)0x20E00F4)

// 0011 ALT3 — Select mux mode: ALT3 mux port: ECSPI4_MOSI of instance: ecspi4
#define IOMUXC_SW_MUX_CTL_PAD_GPIO2_IO13 *((volatile unsigned int *)0x20E00F8)

// 0011 ALT3 — Select mux mode: ALT3 mux port: ECSPI4_MISO of instance: ecspi4
#define IOMUXC_SW_MUX_CTL_PAD_GPIO2_IO14 *((volatile unsigned int *)0x20E00FC)

// 0011 ALT3 — Select mux mode: ALT3 mux port: ECSPI4_SS0 of instance: ecspi4
// 0101 ALT5 — Select mux mode: ALT5 mux port: GPIO2_IO15 of instance: gpio2
#define IOMUXC_SW_MUX_CTL_PAD_GPIO2_IO15 *((volatile unsigned int *)0x20E00100)

/*GPIO PAD Functional Register*/
#define IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO08 *((volatile unsigned int *)0x20E0308)
#define IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO09 *((volatile unsigned int *)0x20E030C)
#define IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO26 *((volatile unsigned int *)0x20E0338)
#define IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO27 *((volatile unsigned int *)0x20E033C)

// UART6 Tx
#define IOMUXC_SW_PAD_CTL_PAD_GPIO2_IO08 *((volatile unsigned int *)0x20E0370)
// UART6 Rx
#define IOMUXC_SW_PAD_CTL_PAD_GPIO2_IO09 *((volatile unsigned int *)0x20E0374)

/*IOMUXC_SELECT_INPUT*/
#define IOMUXC_I2C2_SCL_SELECT_INPUT *((volatile unsigned int *)0x20E05AC)
#define IOMUXC_I2C2_SDA_SELECT_INPUT *((volatile unsigned int *)0x20E05B0)

#define IOMUXC_UART6_RX_DATA_SELECT_INPUT *((volatile unsigned int *)0x20E064C)
#define IOMUXC_UART2_RX_DATA_SELECT_INPUT *((volatile unsigned int *)0x20E062C)

/*LCD GPIO*/
#define IOMUXC_SW_MUX_CTL_PAD_LCD_CLK *((volatile unsigned int *)0x20E0104)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_ENABLE *((volatile unsigned int *)0x20E0108)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_HSYNC *((volatile unsigned int *)0x20E010C)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_VSYNC *((volatile unsigned int *)0x20E0110)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_RESET *((volatile unsigned int *)0x20E0114)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DATA0_ADDR ((volatile unsigned int *)0x20E0118)
// LCD_DATA1 ...... LCD_DATA22
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DATA23_ADDR ((volatile unsigned int *)0x20E0174)

#define IOMUXC_SW_PAD_CTL_PAD_LCD_START ((volatile unsigned int *)0x20E0390)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_END ((volatile unsigned int *)0x20E0400)

/*CSI GPIO*/
#define IOMUXC_SW_MUX_CTL_PAD_CSI_MCLK *((volatile unsigned int *)0x20E01D4)
#define IOMUXC_SW_MUX_CTL_PAD_CSI_PIXCLK *((volatile unsigned int *)0x20E01D8)
#define IOMUXC_SW_MUX_CTL_PAD_CSI_VSYNC *((volatile unsigned int *)0x20E01DC)
#define IOMUXC_SW_MUX_CTL_PAD_CSI_HSYNC *((volatile unsigned int *)0x20E01E0)
#define IOMUXC_SW_MUX_CTL_PAD_CSI_DATA_START ((volatile unsigned int *)0x20E01E4)
#define IOMUXC_SW_MUX_CTL_PAD_CSI_DATA_END ((volatile unsigned int *)0x20E0200)
#define IOMUXC_CSI_PIXCLK_SELECT_INPUT *((volatile unsigned int *)0x20E0528)
#define IOMUXC_CSI_DATA02_SELECT_INPUT *((volatile unsigned int *)0x020E04C4)
#define IOMUXC_CSI_DATA03_SELECT_INPUT *((volatile unsigned int *)0x020E04C8)
#define IOMUXC_CSI_DATA04_SELECT_INPUT *((volatile unsigned int *)0x020E04D8)
#define IOMUXC_CSI_DATA05_SELECT_INPUT *((volatile unsigned int *)0x020E04CC)
#define IOMUXC_CSI_DATA06_SELECT_INPUT *((volatile unsigned int *)0x020E04DC)
#define IOMUXC_CSI_DATA07_SELECT_INPUT *((volatile unsigned int *)0x020E04E0)
#define IOMUXC_CSI_DATA08_SELECT_INPUT *((volatile unsigned int *)0x020E04E4)
#define IOMUXC_CSI_DATA09_SELECT_INPUT *((volatile unsigned int *)0x020E04E8)

/*GPIO Config Register*/
#define GPIO1_DR *((volatile unsigned int *)0x209C000)
#define GPIO1_GDIR *((volatile unsigned int *)0x209C004)
#define GPIO1_PSR *((volatile unsigned int *)0x209C008)

#define __IO

/** GPIO - Register Layout Typedef */
typedef struct
{
      __IO uint32_t DR;       /**< GPIO data register, offset: 0x0 */
      __IO uint32_t GDIR;     /**< GPIO direction register, offset: 0x4 */
      __IO uint32_t PSR;      /**< GPIO pad status register, offset: 0x8 */
      __IO uint32_t ICR1;     /**< GPIO interrupt configuration register1, offset: 0xC */
      __IO uint32_t ICR2;     /**< GPIO interrupt configuration register2, offset: 0x10 */
      __IO uint32_t IMR;      /**< GPIO interrupt mask register, offset: 0x14 */
      __IO uint32_t ISR;      /**< GPIO interrupt status register, offset: 0x18 */
      __IO uint32_t EDGE_SEL; /**< GPIO edge select register, offset: 0x1C */
} GPIO_Type;

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIO1 base address */
#define GPIO1_BASE (0x209C000u)
/** Peripheral GPIO1 base pointer */
#define GPIO1 ((GPIO_Type *)GPIO1_BASE)
/** Peripheral GPIO2 base address */
#define GPIO2_BASE (0x20A0000u)
/** Peripheral GPIO2 base pointer */
#define GPIO2 ((GPIO_Type *)GPIO2_BASE)
/** Peripheral GPIO3 base address */
#define GPIO3_BASE (0x20A4000u)
/** Peripheral GPIO3 base pointer */
#define GPIO3 ((GPIO_Type *)GPIO3_BASE)
/** Peripheral GPIO4 base address */
#define GPIO4_BASE (0x20A8000u)
/** Peripheral GPIO4 base pointer */
#define GPIO4 ((GPIO_Type *)GPIO4_BASE)
/** Peripheral GPIO5 base address */
#define GPIO5_BASE (0x20AC000u)
/** Peripheral GPIO5 base pointer */
#define GPIO5 ((GPIO_Type *)GPIO5_BASE)

/*GPT Config Register*/
typedef struct
{
      unsigned int CR;
      unsigned int PR;
      unsigned int SR;
      unsigned int IR;
      unsigned int OCR1;
      unsigned int OCR2;
      unsigned int OCR3;
      unsigned int ICR1;
      unsigned int ICR2;
      unsigned int CNT;
} GPT_Type;

#define GPT1 ((volatile GPT_Type *)0x2098000)
#define GPT2 ((volatile GPT_Type *)0x20E8000)

/*Uart Config Register*/
/** UART - Register Layout Typedef */
typedef struct
{
      uint32_t URXD; /**< UART Receiver Register, offset: 0x0 */
      uint8_t RESERVED_0[60];
      uint32_t UTXD; /**< UART Transmitter Register, offset: 0x40 */
      uint8_t RESERVED_1[60];
      uint32_t UCR1;  /**< UART Control Register 1, offset: 0x80 */
      uint32_t UCR2;  /**< UART Control Register 2, offset: 0x84 */
      uint32_t UCR3;  /**< UART Control Register 3, offset: 0x88 */
      uint32_t UCR4;  /**< UART Control Register 4, offset: 0x8C */
      uint32_t UFCR;  /**< UART FIFO Control Register, offset: 0x90 */
      uint32_t USR1;  /**< UART Status Register 1, offset: 0x94 */
      uint32_t USR2;  /**< UART Status Register 2, offset: 0x98 */
      uint32_t UESC;  /**< UART Escape Character Register, offset: 0x9C */
      uint32_t UTIM;  /**< UART Escape Timer Register, offset: 0xA0 */
      uint32_t UBIR;  /**< UART BRM Incremental Register, offset: 0xA4 */
      uint32_t UBMR;  /**< UART BRM Modulator Register, offset: 0xA8 */
      uint32_t UBRC;  /**< UART Baud Rate Count Register, offset: 0xAC */
      uint32_t ONEMS; /**< UART One Millisecond Register, offset: 0xB0 */
      uint32_t UTS;   /**< UART Test Register, offset: 0xB4 */
      uint32_t UMCR;  /**< UART RS-485 Mode Control Register, offset: 0xB8 */
} UART_Type;

/** Peripheral UART1 base address */
#define UART1_BASE (0x2020000u)
/** Peripheral UART1 base pointer */
#define UART1 ((UART_Type *)UART1_BASE)
/** Peripheral UART2 base address */
#define UART2_BASE (0x21E8000u)
/** Peripheral UART2 base pointer */
#define UART2 ((UART_Type *)UART2_BASE)
/** Peripheral UART3 base address */
#define UART3_BASE (0x21EC000u)
/** Peripheral UART3 base pointer */
#define UART3 ((UART_Type *)UART3_BASE)
/** Peripheral UART4 base address */
#define UART4_BASE (0x21F0000u)
/** Peripheral UART4 base pointer */
#define UART4 ((UART_Type *)UART4_BASE)
/** Peripheral UART5 base address */
#define UART5_BASE (0x21F4000u)
/** Peripheral UART5 base pointer */
#define UART5 ((UART_Type *)UART5_BASE)
/** Peripheral UART6 base address */
#define UART6_BASE (0x21FC000u)
/** Peripheral UART6 base pointer */
#define UART6 ((UART_Type *)UART6_BASE)
/** Peripheral UART7 base address */
#define UART7_BASE (0x2018000u)
/** Peripheral UART7 base pointer */
#define UART7 ((UART_Type *)UART7_BASE)
/** Peripheral UART8 base address */
#define UART8_BASE (0x2288000u)
/** Peripheral UART8 base pointer */
#define UART8

/*Interrupt*/
/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 160 /**< Number of interrupts in the Vector table */

typedef enum IRQn
{
      /* Auxiliary constants */
      NotAvail_IRQn = -128, /**< Not available device specific interrupt */

      /* Core interrupts */
      Software0_IRQn = 0,           /**< Cortex-A7 Software Generated Interrupt 0 */
      Software1_IRQn = 1,           /**< Cortex-A7 Software Generated Interrupt 1 */
      Software2_IRQn = 2,           /**< Cortex-A7 Software Generated Interrupt 2 */
      Software3_IRQn = 3,           /**< Cortex-A7 Software Generated Interrupt 3 */
      Software4_IRQn = 4,           /**< Cortex-A7 Software Generated Interrupt 4 */
      Software5_IRQn = 5,           /**< Cortex-A7 Software Generated Interrupt 5 */
      Software6_IRQn = 6,           /**< Cortex-A7 Software Generated Interrupt 6 */
      Software7_IRQn = 7,           /**< Cortex-A7 Software Generated Interrupt 7 */
      Software8_IRQn = 8,           /**< Cortex-A7 Software Generated Interrupt 8 */
      Software9_IRQn = 9,           /**< Cortex-A7 Software Generated Interrupt 9 */
      Software10_IRQn = 10,         /**< Cortex-A7 Software Generated Interrupt 10 */
      Software11_IRQn = 11,         /**< Cortex-A7 Software Generated Interrupt 11 */
      Software12_IRQn = 12,         /**< Cortex-A7 Software Generated Interrupt 12 */
      Software13_IRQn = 13,         /**< Cortex-A7 Software Generated Interrupt 13 */
      Software14_IRQn = 14,         /**< Cortex-A7 Software Generated Interrupt 14 */
      Software15_IRQn = 15,         /**< Cortex-A7 Software Generated Interrupt 15 */
      VirtualMaintenance_IRQn = 25, /**< Cortex-A7 Virtual Maintenance Interrupt */
      HypervisorTimer_IRQn = 26,    /**< Cortex-A7 Hypervisor Timer Interrupt */
      VirtualTimer_IRQn = 27,       /**< Cortex-A7 Virtual Timer Interrupt */
      LegacyFastInt_IRQn = 28,      /**< Cortex-A7 Legacy nFIQ signal Interrupt */
      SecurePhyTimer_IRQn = 29,     /**< Cortex-A7 Secure Physical Timer Interrupt */
      NonSecurePhyTimer_IRQn = 30,  /**< Cortex-A7 Non-secure Physical Timer Interrupt */
      LegacyIRQ_IRQn = 31,          /**< Cortex-A7 Legacy nIRQ Interrupt */

      /* Device specific interrupts */
      IOMUXC_IRQn = 32,                /**< General Purpose Register 1 from IOMUXC. Used to notify cores on exception condition while boot. */
      DAP_IRQn = 33,                   /**< Debug Access Port interrupt request. */
      SDMA_IRQn = 34,                  /**< SDMA interrupt request from all channels. */
      TSC_IRQn = 35,                   /**< TSC interrupt. */
      SNVS_IRQn = 36,                  /**< Logic OR of SNVS_LP and SNVS_HP interrupts. */
      LCDIF_IRQn = 37,                 /**< LCDIF sync interrupt. */
      RNGB_IRQn = 38,                  /**< RNGB interrupt. */
      CSI_IRQn = 39,                   /**< CMOS Sensor Interface interrupt request. */
      PXP_IRQ0_IRQn = 40,              /**< PXP interrupt pxp_irq_0. */
      SCTR_IRQ0_IRQn = 41,             /**< SCTR compare interrupt ipi_int[0]. */
      SCTR_IRQ1_IRQn = 42,             /**< SCTR compare interrupt ipi_int[1]. */
      WDOG3_IRQn = 43,                 /**< WDOG3 timer reset interrupt request. */
      Reserved44_IRQn = 44,            /**< Reserved */
      APBH_IRQn = 45,                  /**< DMA Logical OR of APBH DMA channels 0-3 completion and error interrupts. */
      WEIM_IRQn = 46,                  /**< WEIM interrupt request. */
      RAWNAND_BCH_IRQn = 47,           /**< BCH operation complete interrupt. */
      RAWNAND_GPMI_IRQn = 48,          /**< GPMI operation timeout error interrupt. */
      UART6_IRQn = 49,                 /**< UART6 interrupt request. */
      PXP_IRQ1_IRQn = 50,              /**< PXP interrupt pxp_irq_1. */
      SNVS_Consolidated_IRQn = 51,     /**< SNVS consolidated interrupt. */
      SNVS_Security_IRQn = 52,         /**< SNVS security interrupt. */
      CSU_IRQn = 53,                   /**< CSU interrupt request 1. Indicates to the processor that one or more alarm inputs were asserted. */
      USDHC1_IRQn = 54,                /**< USDHC1 (Enhanced SDHC) interrupt request. */
      USDHC2_IRQn = 55,                /**< USDHC2 (Enhanced SDHC) interrupt request. */
      SAI3_RX_IRQn = 56,               /**< SAI3 interrupt ipi_int_sai_rx. */
      SAI3_TX_IRQn = 57,               /**< SAI3 interrupt ipi_int_sai_tx. */
      UART1_IRQn = 58,                 /**< UART1 interrupt request. */
      UART2_IRQn = 59,                 /**< UART2 interrupt request. */
      UART3_IRQn = 60,                 /**< UART3 interrupt request. */
      UART4_IRQn = 61,                 /**< UART4 interrupt request. */
      UART5_IRQn = 62,                 /**< UART5 interrupt request. */
      eCSPI1_IRQn = 63,                /**< eCSPI1 interrupt request. */
      eCSPI2_IRQn = 64,                /**< eCSPI2 interrupt request. */
      eCSPI3_IRQn = 65,                /**< eCSPI3 interrupt request. */
      eCSPI4_IRQn = 66,                /**< eCSPI4 interrupt request. */
      I2C4_IRQn = 67,                  /**< I2C4 interrupt request. */
      I2C1_IRQn = 68,                  /**< I2C1 interrupt request. */
      I2C2_IRQn = 69,                  /**< I2C2 interrupt request. */
      I2C3_IRQn = 70,                  /**< I2C3 interrupt request. */
      UART7_IRQn = 71,                 /**< UART-7 ORed interrupt. */
      UART8_IRQn = 72,                 /**< UART-8 ORed interrupt. */
      Reserved73_IRQn = 73,            /**< Reserved */
      USB_OTG2_IRQn = 74,              /**< USBO2 USB OTG2 */
      USB_OTG1_IRQn = 75,              /**< USBO2 USB OTG1 */
      USB_PHY1_IRQn = 76,              /**< UTMI0 interrupt request. */
      USB_PHY2_IRQn = 77,              /**< UTMI1 interrupt request. */
      DCP_IRQ_IRQn = 78,               /**< DCP interrupt request dcp_irq. */
      DCP_VMI_IRQ_IRQn = 79,           /**< DCP interrupt request dcp_vmi_irq. */
      DCP_SEC_IRQ_IRQn = 80,           /**< DCP interrupt request secure_irq. */
      TEMPMON_IRQn = 81,               /**< Temperature Monitor Temperature Sensor (temperature greater than threshold) interrupt request. */
      ASRC_IRQn = 82,                  /**< ASRC interrupt request. */
      ESAI_IRQn = 83,                  /**< ESAI interrupt request. */
      SPDIF_IRQn = 84,                 /**< SPDIF interrupt. */
      Reserved85_IRQn = 85,            /**< Reserved */
      PMU_IRQ1_IRQn = 86,              /**< Brown-out event on either the 1.1, 2.5 or 3.0 regulators. */
      GPT1_IRQn = 87,                  /**< Logical OR of GPT1 rollover interrupt line, input capture 1 and 2 lines, output compare 1, 2, and 3 interrupt lines. */
      EPIT1_IRQn = 88,                 /**< EPIT1 output compare interrupt. */
      EPIT2_IRQn = 89,                 /**< EPIT2 output compare interrupt. */
      GPIO1_INT7_IRQn = 90,            /**< INT7 interrupt request. */
      GPIO1_INT6_IRQn = 91,            /**< INT6 interrupt request. */
      GPIO1_INT5_IRQn = 92,            /**< INT5 interrupt request. */
      GPIO1_INT4_IRQn = 93,            /**< INT4 interrupt request. */
      GPIO1_INT3_IRQn = 94,            /**< INT3 interrupt request. */
      GPIO1_INT2_IRQn = 95,            /**< INT2 interrupt request. */
      GPIO1_INT1_IRQn = 96,            /**< INT1 interrupt request. */
      GPIO1_INT0_IRQn = 97,            /**< INT0 interrupt request. */
      GPIO1_Combined_0_15_IRQn = 98,   /**< Combined interrupt indication for GPIO1 signals 0 - 15. */
      GPIO1_Combined_16_31_IRQn = 99,  /**< Combined interrupt indication for GPIO1 signals 16 - 31. */
      GPIO2_Combined_0_15_IRQn = 100,  /**< Combined interrupt indication for GPIO2 signals 0 - 15. */
      GPIO2_Combined_16_31_IRQn = 101, /**< Combined interrupt indication for GPIO2 signals 16 - 31. */
      GPIO3_Combined_0_15_IRQn = 102,  /**< Combined interrupt indication for GPIO3 signals 0 - 15. */
      GPIO3_Combined_16_31_IRQn = 103, /**< Combined interrupt indication for GPIO3 signals 16 - 31. */
      GPIO4_Combined_0_15_IRQn = 104,  /**< Combined interrupt indication for GPIO4 signals 0 - 15. */
      GPIO4_Combined_16_31_IRQn = 105, /**< Combined interrupt indication for GPIO4 signals 16 - 31. */
      GPIO5_Combined_0_15_IRQn = 106,  /**< Combined interrupt indication for GPIO5 signals 0 - 15. */
      GPIO5_Combined_16_31_IRQn = 107, /**< Combined interrupt indication for GPIO5 signals 16 - 31. */
      Reserved108_IRQn = 108,          /**< Reserved */
      Reserved109_IRQn = 109,          /**< Reserved */
      Reserved110_IRQn = 110,          /**< Reserved */
      Reserved111_IRQn = 111,          /**< Reserved */
      WDOG1_IRQn = 112,                /**< WDOG1 timer reset interrupt request. */
      WDOG2_IRQn = 113,                /**< WDOG2 timer reset interrupt request. */
      KPP_IRQn = 114,                  /**< Key Pad interrupt request. */
      PWM1_IRQn = 115,                 /**< hasRegInstance(`PWM1`)?`Cumulative interrupt line for PWM1. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts.`:`Reserved`) */
      PWM2_IRQn = 116,                 /**< hasRegInstance(`PWM2`)?`Cumulative interrupt line for PWM2. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts.`:`Reserved`) */
      PWM3_IRQn = 117,                 /**< hasRegInstance(`PWM3`)?`Cumulative interrupt line for PWM3. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts.`:`Reserved`) */
      PWM4_IRQn = 118,                 /**< hasRegInstance(`PWM4`)?`Cumulative interrupt line for PWM4. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts.`:`Reserved`) */
      CCM_IRQ1_IRQn = 119,             /**< CCM interrupt request ipi_int_1. */
      CCM_IRQ2_IRQn = 120,             /**< CCM interrupt request ipi_int_2. */
      GPC_IRQn = 121,                  /**< GPC interrupt request 1. */
      Reserved122_IRQn = 122,          /**< Reserved */
      SRC_IRQn = 123,                  /**< SRC interrupt request src_ipi_int_1. */
      Reserved124_IRQn = 124,          /**< Reserved */
      Reserved125_IRQn = 125,          /**< Reserved */
      CPU_PerformanceUnit_IRQn = 126,  /**< Performance Unit interrupt ~ipi_pmu_irq_b. */
      CPU_CTI_Trigger_IRQn = 127,      /**< CTI trigger outputs interrupt ~ipi_cti_irq_b. */
      SRC_Combined_IRQn = 128,         /**< Combined CPU wdog interrupts (4x) out of SRC. */
      SAI1_IRQn = 129,                 /**< SAI1 interrupt request. */
      SAI2_IRQn = 130,                 /**< SAI2 interrupt request. */
      Reserved131_IRQn = 131,          /**< Reserved */
      ADC1_IRQn = 132,                 /**< ADC1 interrupt request. */
      ADC_5HC_IRQn = 133,              /**< ADC_5HC interrupt request. */
      Reserved134_IRQn = 134,          /**< Reserved */
      Reserved135_IRQn = 135,          /**< Reserved */
      SJC_IRQn = 136,                  /**< SJC interrupt from General Purpose register. */
      CAAM_Job_Ring0_IRQn = 137,       /**< CAAM job ring 0 interrupt ipi_caam_irq0. */
      CAAM_Job_Ring1_IRQn = 138,       /**< CAAM job ring 1 interrupt ipi_caam_irq1. */
      QSPI_IRQn = 139,                 /**< QSPI1 interrupt request ipi_int_ored. */
      TZASC_IRQn = 140,                /**< TZASC (PL380) interrupt request. */
      GPT2_IRQn = 141,                 /**< Logical OR of GPT2 rollover interrupt line, input capture 1 and 2 lines, output compare 1, 2 and 3 interrupt lines. */
      CAN1_IRQn = 142,                 /**< Combined interrupt of ini_int_busoff,ini_int_error,ipi_int_mbor,ipi_int_txwarning and ipi_int_waken */
      CAN2_IRQn = 143,                 /**< Combined interrupt of ini_int_busoff,ini_int_error,ipi_int_mbor,ipi_int_txwarning and ipi_int_waken */
      Reserved144_IRQn = 144,          /**< Reserved */
      Reserved145_IRQn = 145,          /**< Reserved */
      PWM5_IRQn = 146,                 /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line */
      PWM6_IRQn = 147,                 /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line */
      PWM7_IRQn = 148,                 /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line */
      PWM8_IRQn = 149,                 /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line */
      ENET1_IRQn = 150,                /**< ENET1 interrupt */
      ENET1_1588_IRQn = 151,           /**< ENET1 1588 Timer interrupt [synchronous] request. */
      ENET2_IRQn = 152,                /**< ENET2 interrupt */
      ENET2_1588_IRQn = 153,           /**< MAC 0 1588 Timer interrupt [synchronous] request. */
      Reserved154_IRQn = 154,          /**< Reserved */
      Reserved155_IRQn = 155,          /**< Reserved */
      Reserved156_IRQn = 156,          /**< Reserved */
      Reserved157_IRQn = 157,          /**< Reserved */
      Reserved158_IRQn = 158,          /**< Reserved */
      PMU_IRQ2_IRQn = 159              /**< Brown-out event on either core, gpu or soc regulators. */
} IRQn_Type;

#define __IM volatile const /* 只读 */
#define __OM volatile       /* 只写 */
#define __IOM volatile      /* 读写 */

/*
 * GIC寄存器描述结构体，
 * GIC分为分发器端和CPU接口端
 */
typedef struct
{
      uint32_t RESERVED0[1024];
      __IOM uint32_t D_CTLR; /*!< Offset: 0x1000 (R/W) Distributor Control Register */
      __IM uint32_t D_TYPER; /*!< Offset: 0x1004 (R/ )  Interrupt Controller Type Register */
      __IM uint32_t D_IIDR;  /*!< Offset: 0x1008 (R/ )  Distributor Implementer Identification Register */
      uint32_t RESERVED1[29];
      __IOM uint32_t D_IGROUPR[16]; /*!< Offset: 0x1080 - 0x0BC (R/W) Interrupt Group Registers */
      uint32_t RESERVED2[16];
      __IOM uint32_t D_ISENABLER[16]; /*!< Offset: 0x1100 - 0x13C (R/W) Interrupt Set-Enable Registers */
      uint32_t RESERVED3[16];
      __IOM uint32_t D_ICENABLER[16]; /*!< Offset: 0x1180 - 0x1BC (R/W) Interrupt Clear-Enable Registers */
      uint32_t RESERVED4[16];
      __IOM uint32_t D_ISPENDR[16]; /*!< Offset: 0x1200 - 0x23C (R/W) Interrupt Set-Pending Registers */
      uint32_t RESERVED5[16];
      __IOM uint32_t D_ICPENDR[16]; /*!< Offset: 0x1280 - 0x2BC (R/W) Interrupt Clear-Pending Registers */
      uint32_t RESERVED6[16];
      __IOM uint32_t D_ISACTIVER[16]; /*!< Offset: 0x1300 - 0x33C (R/W) Interrupt Set-Active Registers */
      uint32_t RESERVED7[16];
      __IOM uint32_t D_ICACTIVER[16]; /*!< Offset: 0x1380 - 0x3BC (R/W) Interrupt Clear-Active Registers */
      uint32_t RESERVED8[16];
      __IOM uint8_t D_IPRIORITYR[512]; /*!< Offset: 0x1400 - 0x5FC (R/W) Interrupt Priority Registers */
      uint32_t RESERVED9[128];
      __IOM uint8_t D_ITARGETSR[512]; /*!< Offset: 0x1800 - 0x9FC (R/W) Interrupt Targets Registers */
      uint32_t RESERVED10[128];
      __IOM uint32_t D_ICFGR[32]; /*!< Offset: 0x1C00 - 0xC7C (R/W) Interrupt configuration registers */
      uint32_t RESERVED11[32];
      __IM uint32_t D_PPISR;     /*!< Offset: 0x1D00 (R/ ) Private Peripheral Interrupt Status Register */
      __IM uint32_t D_SPISR[15]; /*!< Offset: 0x1D04 - 0xD3C (R/ ) Shared Peripheral Interrupt Status Registers */
      uint32_t RESERVED12[112];
      __OM uint32_t D_SGIR; /*!< Offset: 0x1F00 ( /W) Software Generated Interrupt Register */
      uint32_t RESERVED13[3];
      __IOM uint8_t D_CPENDSGIR[16]; /*!< Offset: 0x1F10 - 0xF1C (R/W) SGI Clear-Pending Registers */
      __IOM uint8_t D_SPENDSGIR[16]; /*!< Offset: 0x1F20 - 0xF2C (R/W) SGI Set-Pending Registers */
      uint32_t RESERVED14[40];
      __IM uint32_t D_PIDR4; /*!< Offset: 0x1FD0 (R/ ) Peripheral ID4 Register */
      __IM uint32_t D_PIDR5; /*!< Offset: 0x1FD4 (R/ ) Peripheral ID5 Register */
      __IM uint32_t D_PIDR6; /*!< Offset: 0x1FD8 (R/ ) Peripheral ID6 Register */
      __IM uint32_t D_PIDR7; /*!< Offset: 0x1FDC (R/ ) Peripheral ID7 Register */
      __IM uint32_t D_PIDR0; /*!< Offset: 0x1FE0 (R/ ) Peripheral ID0 Register */
      __IM uint32_t D_PIDR1; /*!< Offset: 0x1FE4 (R/ ) Peripheral ID1 Register */
      __IM uint32_t D_PIDR2; /*!< Offset: 0x1FE8 (R/ ) Peripheral ID2 Register */
      __IM uint32_t D_PIDR3; /*!< Offset: 0x1FEC (R/ ) Peripheral ID3 Register */
      __IM uint32_t D_CIDR0; /*!< Offset: 0x1FF0 (R/ ) Component ID0 Register */
      __IM uint32_t D_CIDR1; /*!< Offset: 0x1FF4 (R/ ) Component ID1 Register */
      __IM uint32_t D_CIDR2; /*!< Offset: 0x1FF8 (R/ ) Component ID2 Register */
      __IM uint32_t D_CIDR3; /*!< Offset: 0x1FFC (R/ ) Component ID3 Register */

      __IOM uint32_t C_CTLR;  /*!< Offset: 0x2000 (R/W) CPU Interface Control Register */
      __IOM uint32_t C_PMR;   /*!< Offset: 0x2004 (R/W) Interrupt Priority Mask Register */
      __IOM uint32_t C_BPR;   /*!< Offset: 0x2008 (R/W) Binary Point Register */
      __IM uint32_t C_IAR;    /*!< Offset: 0x200C (R/ ) Interrupt Acknowledge Register */
      __OM uint32_t C_EOIR;   /*!< Offset: 0x2010 ( /W) End Of Interrupt Register */
      __IM uint32_t C_RPR;    /*!< Offset: 0x2014 (R/ ) Running Priority Register */
      __IM uint32_t C_HPPIR;  /*!< Offset: 0x2018 (R/ ) Highest Priority Pending Interrupt Register */
      __IOM uint32_t C_ABPR;  /*!< Offset: 0x201C (R/W) Aliased Binary Point Register */
      __IM uint32_t C_AIAR;   /*!< Offset: 0x2020 (R/ ) Aliased Interrupt Acknowledge Register */
      __OM uint32_t C_AEOIR;  /*!< Offset: 0x2024 ( /W) Aliased End Of Interrupt Register */
      __IM uint32_t C_AHPPIR; /*!< Offset: 0x2028 (R/ ) Aliased Highest Priority Pending Interrupt Register */
      uint32_t RESERVED15[41];
      __IOM uint32_t C_APR0; /*!< Offset: 0x20D0 (R/W) Active Priority Register */
      uint32_t RESERVED16[3];
      __IOM uint32_t C_NSAPR0; /*!< Offset: 0x20E0 (R/W) Non-secure Active Priority Register */
      uint32_t RESERVED17[6];
      __IM uint32_t C_IIDR; /*!< Offset: 0x20FC (R/ ) CPU Interface Identification Register */
      uint32_t RESERVED18[960];
      __OM uint32_t C_DIR; /*!< Offset: 0x3000 ( /W) Deactivate Interrupt Register */
} GIC_Type;

#define GIC_BASE (0x00A00000)
/** Peripheral UART6 base pointer */
#define GIC ((GIC_Type *)GIC_BASE)

/** ADC - Register Layout Typedef */
typedef struct {
  __IO uint32_t HC[1];/**< Control register, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t HS;  /**< Status register, offset: 0x8 */
  __IO uint32_t R[1];/**< Data result register, array offset: 0xC, array step: 0x4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CFG; /**< Configuration register, offset: 0x14 */
  __IO uint32_t GC;  /**< General control register, offset: 0x18 */
  __IO uint32_t GS;  /**< General status register, offset: 0x1C */
  __IO uint32_t CV;  /**< Compare value register, offset: 0x20 */
  __IO uint32_t OFS; /**< Offset correction value register, offset: 0x24 */
  __IO uint32_t CAL; /**< Calibration value register, offset: 0x28 */
} ADC_Type;

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC1 base address */
#define ADC1_BASE  (0x2198000u)
/** Peripheral ADC1 base pointer */
#define ADC1       ((ADC_Type *)ADC1_BASE)

/** PWM - Register Layout Typedef */
typedef struct
{
      __IO uint32_t PWMCR;  /**< PWM Control Register, offset: 0x0 */
      __IO uint32_t PWMSR;  /**< PWM Status Register, offset: 0x4 */
      __IO uint32_t PWMIR;  /**< PWM Interrupt Register, offset: 0x8 */
      __IO uint32_t PWMSAR; /**< PWM Sample Register, offset: 0xC */
      __IO uint32_t PWMPR;  /**< PWM Period Register, offset: 0x10 */
      __IO uint32_t PWMCNR; /**< PWM Counter Register, offset: 0x14 */
} PWM_Type;

/* PWM - Peripheral instance base addresses */
/** Peripheral PWM1 base address */
#define PWM1_BASE (0x2080000u)
/** Peripheral PWM1 base pointer */
#define PWM1 ((PWM_Type *)PWM1_BASE)
/** Peripheral PWM2 base address */
#define PWM2_BASE (0x2084000u)
/** Peripheral PWM2 base pointer */
#define PWM2 ((PWM_Type *)PWM2_BASE)
/** Peripheral PWM3 base address */
#define PWM3_BASE (0x2088000u)
/** Peripheral PWM3 base pointer */
#define PWM3 ((PWM_Type *)PWM3_BASE)
/** Peripheral PWM4 base address */
#define PWM4_BASE (0x208C000u)
/** Peripheral PWM4 base pointer */
#define PWM4 ((PWM_Type *)PWM4_BASE)
/** Peripheral PWM5 base address */
#define PWM5_BASE (0x20F0000u)
/** Peripheral PWM5 base pointer */
#define PWM5 ((PWM_Type *)PWM5_BASE)
/** Peripheral PWM6 base address */
#define PWM6_BASE (0x20F4000u)
/** Peripheral PWM6 base pointer */
#define PWM6 ((PWM_Type *)PWM6_BASE)
/** Peripheral PWM7 base address */
#define PWM7_BASE (0x20F8000u)
/** Peripheral PWM7 base pointer */
#define PWM7 ((PWM_Type *)PWM7_BASE)
/** Peripheral PWM8 base address */
#define PWM8_BASE (0x20FC000u)
/** Peripheral PWM8 base pointer */
#define PWM8 ((PWM_Type *)PWM8_BASE)

/* ----------------------------------------------------------------------------
   -- SNVS Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/*!
 * @addtogroup SNVS_Peripheral_Access_Layer SNVS Peripheral Access Layer
 * @{
 */

/** SNVS - Register Layout Typedef */
typedef struct
{
      __IO uint32_t HPLR;   /**< SNVS_HP Lock register, offset: 0x0 */
      __IO uint32_t HPCOMR; /**< SNVS_HP Command register, offset: 0x4 */
      __IO uint32_t HPCR;   /**< SNVS_HP Control register, offset: 0x8 */
      uint8_t RESERVED_0[8];
      __IO uint32_t HPSR; /**< SNVS_HP Status register, offset: 0x14 */
      uint8_t RESERVED_1[12];
      __IO uint32_t HPRTCMR; /**< SNVS_HP Real-Time Counter MSB Register, offset: 0x24 */
      __IO uint32_t HPRTCLR; /**< SNVS_HP Real-Time Counter LSB Register, offset: 0x28 */
      __IO uint32_t HPTAMR;  /**< SNVS_HP Time Alarm MSB Register, offset: 0x2C */
      __IO uint32_t HPTALR;  /**< SNVS_HP Time Alarm LSB Register, offset: 0x30 */
      __IO uint32_t LPLR;    /**< SNVS_LP Lock Register, offset: 0x34 */
      __IO uint32_t LPCR;    /**< SNVS_LP Control Register, offset: 0x38 */
      uint8_t RESERVED_2[16];
      __IO uint32_t LPSR; /**< SNVS_LP Status Register, offset: 0x4C */
      uint8_t RESERVED_3[12];
      __IO uint32_t LPSMCMR; /**< SNVS_LP Secure Monotonic Counter MSB Register, offset: 0x5C */
      __IO uint32_t LPSMCLR; /**< SNVS_LP Secure Monotonic Counter LSB Register, offset: 0x60 */
      uint8_t RESERVED_4[4];
      __IO uint32_t LPGPR; /**< SNVS_LP General-Purpose Register, offset: 0x68 */
      uint8_t RESERVED_5[2956];
      __IO uint32_t HPVIDR1; /**< SNVS_HP Version ID Register 1, offset: 0xBF8 */
      __IO uint32_t HPVIDR2; /**< SNVS_HP Version ID Register 2, offset: 0xBFC */
} SNVS_Type;

/* SNVS - Peripheral instance base addresses */
/** Peripheral SNVS base address */
#define SNVS_BASE (0x20CC000u)
/** Peripheral SNVS base pointer */
#define SNVS ((SNVS_Type *)SNVS_BASE)

/** SRC - Register Layout Typedef */
typedef struct
{
      __IO uint32_t SCR;   /**< SRC Control Register, offset: 0x0 */
      __IO uint32_t SBMR1; /**< SRC Boot Mode Register 1, offset: 0x4 */
      __IO uint32_t SRSR;  /**< SRC Reset Status Register, offset: 0x8 */
      uint8_t RESERVED_0[8];
      __IO uint32_t SISR; /**< SRC Interrupt Status Register, offset: 0x14 */
      uint8_t RESERVED_1[4];
      __IO uint32_t SBMR2;   /**< SRC Boot Mode Register 2, offset: 0x1C */
      __IO uint32_t GPR[10]; /**< SRC General Purpose Register 1..SRC General Purpose Register 10, array offset: 0x20, array step: 0x4 */
} SRC_Type;

/* SRC - Peripheral instance base addresses */
/** Peripheral SRC base address */
#define SRC_BASE (0x20D8000u)
/** Peripheral SRC base pointer */
#define SRC ((SRC_Type *)SRC_BASE)

/** WDOG - Register Layout Typedef */
typedef struct
{
      __IO uint16_t WCR;  /**< Watchdog Control Register, offset: 0x0 */
      __IO uint16_t WSR;  /**< Watchdog Service Register, offset: 0x2 */
      __IO uint16_t WRSR; /**< Watchdog Reset Status Register, offset: 0x4 */
      __IO uint16_t WICR; /**< Watchdog Interrupt Control Register, offset: 0x6 */
      __IO uint16_t WMCR; /**< Watchdog Miscellaneous Control Register, offset: 0x8 */
} WDOG_Type;

/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG1 base address */
#define WDOG1_BASE (0x20BC000u)
/** Peripheral WDOG1 base pointer */
#define WDOG1 ((WDOG_Type *)WDOG1_BASE)
/** Peripheral WDOG2 base address */
#define WDOG2_BASE (0x20C0000u)
/** Peripheral WDOG2 base pointer */
#define WDOG2 ((WDOG_Type *)WDOG2_BASE)
/** Peripheral WDOG3 base address */
#define WDOG3_BASE (0x21E4000u)
/** Peripheral WDOG3 base pointer */
#define WDOG3 ((WDOG_Type *)WDOG3_BASE)

/** I2C - Register Layout Typedef */
typedef struct
{
      __IO uint16_t IADR; /**< I2C Address Register, offset: 0x0 */
      uint8_t RESERVED_0[2];
      __IO uint16_t IFDR; /**< I2C Frequency Divider Register, offset: 0x4 */
      uint8_t RESERVED_1[2];
      __IO uint16_t I2CR; /**< I2C Control Register, offset: 0x8 */
      uint8_t RESERVED_2[2];
      __IO uint16_t I2SR; /**< I2C Status Register, offset: 0xC */
      uint8_t RESERVED_3[2];
      __IO uint16_t I2DR; /**< I2C Data I/O Register, offset: 0x10 */
} I2C_Type;

/* I2C - Peripheral instance base addresses */
/** Peripheral I2C1 base address */
#define I2C1_BASE (0x21A0000u)
/** Peripheral I2C1 base pointer */
#define I2C1 ((I2C_Type *)I2C1_BASE)
/** Peripheral I2C2 base address */
#define I2C2_BASE (0x21A4000u)
/** Peripheral I2C2 base pointer */
#define I2C2 ((I2C_Type *)I2C2_BASE)
/** Peripheral I2C3 base address */
#define I2C3_BASE (0x21A8000u)
/** Peripheral I2C3 base pointer */
#define I2C3 ((I2C_Type *)I2C3_BASE)
/** Peripheral I2C4 base address */
#define I2C4_BASE (0x21F8000u)
/** Peripheral I2C4 base pointer */
#define I2C4 ((I2C_Type *)I2C4_BASE)

/** ECSPI - Register Layout Typedef */
typedef struct
{
      __IO uint32_t RXDATA;    /**< Receive Data Register, offset: 0x0 */
      __IO uint32_t TXDATA;    /**< Transmit Data Register, offset: 0x4 */
      __IO uint32_t CONREG;    /**< Control Register, offset: 0x8 */
      __IO uint32_t CONFIGREG; /**< Config Register, offset: 0xC */
      __IO uint32_t INTREG;    /**< Interrupt Control Register, offset: 0x10 */
      __IO uint32_t DMAREG;    /**< DMA Control Register, offset: 0x14 */
      __IO uint32_t STATREG;   /**< Status Register, offset: 0x18 */
      __IO uint32_t PERIODREG; /**< Sample Period Control Register, offset: 0x1C */
      __IO uint32_t TESTREG;   /**< Test Control Register, offset: 0x20 */
      uint8_t RESERVED_0[28];
      __IO uint32_t MSGDATA; /**< Message Data Register, offset: 0x40 */
} ECSPI_Type;

/* ECSPI - Peripheral instance base addresses */
/** Peripheral ECSPI1 base address */
#define ECSPI1_BASE (0x2008000u)
/** Peripheral ECSPI1 base pointer */
#define ECSPI1 ((ECSPI_Type *)ECSPI1_BASE)
/** Peripheral ECSPI2 base address */
#define ECSPI2_BASE (0x200C000u)
/** Peripheral ECSPI2 base pointer */
#define ECSPI2 ((ECSPI_Type *)ECSPI2_BASE)
/** Peripheral ECSPI3 base address */
#define ECSPI3_BASE (0x2010000u)
/** Peripheral ECSPI3 base pointer */
#define ECSPI3 ((ECSPI_Type *)ECSPI3_BASE)
/** Peripheral ECSPI4 base address */
#define ECSPI4_BASE (0x2014000u)
/** Peripheral ECSPI4 base pointer */
#define ECSPI4 ((ECSPI_Type *)ECSPI4_BASE)

/* ----------------------------------------------------------------------------
   -- CAN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Peripheral_Access_Layer CAN Peripheral Access Layer
 * @{
 */

/** CAN - Register Layout Typedef */
typedef struct
{
      __IO uint32_t MCR;   /**< Module Configuration Register, offset: 0x0 */
      __IO uint32_t CTRL1; /**< Control 1 Register, offset: 0x4 */
      __IO uint32_t TIMER; /**< Free Running Timer Register, offset: 0x8 */
      uint8_t RESERVED_0[4];
      __IO uint32_t RXMGMASK; /**< Rx Mailboxes Global Mask Register, offset: 0x10 */
      __IO uint32_t RX14MASK; /**< Rx Buffer 14 Mask Register, offset: 0x14 */
      __IO uint32_t RX15MASK; /**< Rx Buffer 15 Mask Register, offset: 0x18 */
      __IO uint32_t ECR;      /**< Error Counter Register, offset: 0x1C */
      __IO uint32_t ESR1;     /**< Error and Status 1 Register, offset: 0x20 */
      __IO uint32_t IMASK2;   /**< Interrupt Masks 2 Register, offset: 0x24 */
      __IO uint32_t IMASK1;   /**< Interrupt Masks 1 Register, offset: 0x28 */
      __IO uint32_t IFLAG2;   /**< Interrupt Flags 2 Register, offset: 0x2C */
      __IO uint32_t IFLAG1;   /**< Interrupt Flags 1 Register, offset: 0x30 */
      __IO uint32_t CTRL2;    /**< Control 2 Register, offset: 0x34 */
      __IO uint32_t ESR2;     /**< Error and Status 2 Register, offset: 0x38 */
      uint8_t RESERVED_1[8];
      __IO uint32_t CRCR;     /**< CRC Register, offset: 0x44 */
      __IO uint32_t RXFGMASK; /**< Rx FIFO Global Mask Register, offset: 0x48 */
      __IO uint32_t RXFIR;    /**< Rx FIFO Information Register, offset: 0x4C */
      uint8_t RESERVED_2[48];
      struct
      {                          /* offset: 0x80, array step: 0x10 */
            __IO uint32_t CS;    /**< Message Buffer 0 CS Register..Message Buffer 63 CS Register, array offset: 0x80, array step: 0x10 */
            __IO uint32_t ID;    /**< Message Buffer 0 ID Register..Message Buffer 63 ID Register, array offset: 0x84, array step: 0x10 */
            __IO uint32_t WORD0; /**< Message Buffer 0 WORD0 Register..Message Buffer 63 WORD0 Register, array offset: 0x88, array step: 0x10 */
            __IO uint32_t WORD1; /**< Message Buffer 0 WORD1 Register..Message Buffer 63 WORD1 Register, array offset: 0x8C, array step: 0x10 */
      } MB[64];
      uint8_t RESERVED_3[1024];
      __IO uint32_t RXIMR[64]; /**< Rx Individual Mask Registers, array offset: 0x880, array step: 0x4 */
      uint8_t RESERVED_4[96];
      __IO uint32_t GFWR; /**< Glitch Filter Width Registers, offset: 0x9E0 */
} CAN_Type;

/** Peripheral CAN1 base address */
#define CAN1_BASE (0x2090000u)
/** Peripheral CAN1 base pointer */
#define CAN1 ((CAN_Type *)CAN1_BASE)
/** Peripheral CAN2 base address */
#define CAN2_BASE (0x2094000u)
/** Peripheral CAN2 base pointer */
#define CAN2 ((CAN_Type *)CAN2_BASE)

/* ----------------------------------------------------------------------------
   -- CCM_ANALOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_ANALOG_Peripheral_Access_Layer CCM_ANALOG Peripheral Access Layer
 * @{
 */

/** CCM_ANALOG - Register Layout Typedef */
typedef struct
{
      __IO uint32_t PLL_ARM;      /**< Analog ARM PLL control Register, offset: 0x0 */
      __IO uint32_t PLL_ARM_SET;  /**< Analog ARM PLL control Register, offset: 0x4 */
      __IO uint32_t PLL_ARM_CLR;  /**< Analog ARM PLL control Register, offset: 0x8 */
      __IO uint32_t PLL_ARM_TOG;  /**< Analog ARM PLL control Register, offset: 0xC */
      __IO uint32_t PLL_USB1;     /**< Analog USB1 480MHz PLL Control Register, offset: 0x10 */
      __IO uint32_t PLL_USB1_SET; /**< Analog USB1 480MHz PLL Control Register, offset: 0x14 */
      __IO uint32_t PLL_USB1_CLR; /**< Analog USB1 480MHz PLL Control Register, offset: 0x18 */
      __IO uint32_t PLL_USB1_TOG; /**< Analog USB1 480MHz PLL Control Register, offset: 0x1C */
      __IO uint32_t PLL_USB2;     /**< Analog USB2 480MHz PLL Control Register, offset: 0x20 */
      __IO uint32_t PLL_USB2_SET; /**< Analog USB2 480MHz PLL Control Register, offset: 0x24 */
      __IO uint32_t PLL_USB2_CLR; /**< Analog USB2 480MHz PLL Control Register, offset: 0x28 */
      __IO uint32_t PLL_USB2_TOG; /**< Analog USB2 480MHz PLL Control Register, offset: 0x2C */
      __IO uint32_t PLL_SYS;      /**< Analog System PLL Control Register, offset: 0x30 */
      __IO uint32_t PLL_SYS_SET;  /**< Analog System PLL Control Register, offset: 0x34 */
      __IO uint32_t PLL_SYS_CLR;  /**< Analog System PLL Control Register, offset: 0x38 */
      __IO uint32_t PLL_SYS_TOG;  /**< Analog System PLL Control Register, offset: 0x3C */
      __IO uint32_t PLL_SYS_SS;   /**< 528MHz System PLL Spread Spectrum Register, offset: 0x40 */
      uint8_t RESERVED_0[12];
      __IO uint32_t PLL_SYS_NUM; /**< Numerator of 528MHz System PLL Fractional Loop Divider Register, offset: 0x50 */
      uint8_t RESERVED_1[12];
      __IO uint32_t PLL_SYS_DENOM; /**< Denominator of 528MHz System PLL Fractional Loop Divider Register, offset: 0x60 */
      uint8_t RESERVED_2[12];
      __IO uint32_t PLL_AUDIO;     /**< Analog Audio PLL control Register, offset: 0x70 */
      __IO uint32_t PLL_AUDIO_SET; /**< Analog Audio PLL control Register, offset: 0x74 */
      __IO uint32_t PLL_AUDIO_CLR; /**< Analog Audio PLL control Register, offset: 0x78 */
      __IO uint32_t PLL_AUDIO_TOG; /**< Analog Audio PLL control Register, offset: 0x7C */
      __IO uint32_t PLL_AUDIO_NUM; /**< Numerator of Audio PLL Fractional Loop Divider Register, offset: 0x80 */
      uint8_t RESERVED_3[12];
      __IO uint32_t PLL_AUDIO_DENOM; /**< Denominator of Audio PLL Fractional Loop Divider Register, offset: 0x90 */
      uint8_t RESERVED_4[12];
      __IO uint32_t PLL_VIDEO;     /**< Analog Video PLL control Register, offset: 0xA0 */
      __IO uint32_t PLL_VIDEO_SET; /**< Analog Video PLL control Register, offset: 0xA4 */
      __IO uint32_t PLL_VIDEO_CLR; /**< Analog Video PLL control Register, offset: 0xA8 */
      __IO uint32_t PLL_VIDEO_TOG; /**< Analog Video PLL control Register, offset: 0xAC */
      __IO uint32_t PLL_VIDEO_NUM; /**< Numerator of Video PLL Fractional Loop Divider Register, offset: 0xB0 */
      uint8_t RESERVED_5[12];
      __IO uint32_t PLL_VIDEO_DENOM; /**< Denominator of Video PLL Fractional Loop Divider Register, offset: 0xC0 */
      uint8_t RESERVED_6[28];
      __IO uint32_t PLL_ENET;     /**< Analog ENET PLL Control Register, offset: 0xE0 */
      __IO uint32_t PLL_ENET_SET; /**< Analog ENET PLL Control Register, offset: 0xE4 */
      __IO uint32_t PLL_ENET_CLR; /**< Analog ENET PLL Control Register, offset: 0xE8 */
      __IO uint32_t PLL_ENET_TOG; /**< Analog ENET PLL Control Register, offset: 0xEC */
      __IO uint32_t PFD_480;      /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF0 */
      __IO uint32_t PFD_480_SET;  /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF4 */
      __IO uint32_t PFD_480_CLR;  /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF8 */
      __IO uint32_t PFD_480_TOG;  /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xFC */
      __IO uint32_t PFD_528;      /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x100 */
      __IO uint32_t PFD_528_SET;  /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x104 */
      __IO uint32_t PFD_528_CLR;  /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x108 */
      __IO uint32_t PFD_528_TOG;  /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x10C */
      uint8_t RESERVED_7[64];
      __IO uint32_t MISC0;     /**< Miscellaneous Register 0, offset: 0x150 */
      __IO uint32_t MISC0_SET; /**< Miscellaneous Register 0, offset: 0x154 */
      __IO uint32_t MISC0_CLR; /**< Miscellaneous Register 0, offset: 0x158 */
      __IO uint32_t MISC0_TOG; /**< Miscellaneous Register 0, offset: 0x15C */
      __IO uint32_t MISC1;     /**< Miscellaneous Register 1, offset: 0x160 */
      __IO uint32_t MISC1_SET; /**< Miscellaneous Register 1, offset: 0x164 */
      __IO uint32_t MISC1_CLR; /**< Miscellaneous Register 1, offset: 0x168 */
      __IO uint32_t MISC1_TOG; /**< Miscellaneous Register 1, offset: 0x16C */
      __IO uint32_t MISC2;     /**< Miscellaneous Register 2, offset: 0x170 */
      __IO uint32_t MISC2_SET; /**< Miscellaneous Register 2, offset: 0x174 */
      __IO uint32_t MISC2_CLR; /**< Miscellaneous Register 2, offset: 0x178 */
      __IO uint32_t MISC2_TOG; /**< Miscellaneous Register 2, offset: 0x17C */
} CCM_ANALOG_Type;

/* CCM_ANALOG - Peripheral instance base addresses */
/** Peripheral CCM_ANALOG base address */
#define CCM_ANALOG_BASE (0x20C8000u)
/** Peripheral CCM_ANALOG base pointer */
#define CCM_ANALOG ((CCM_ANALOG_Type *)CCM_ANALOG_BASE)

/* ----------------------------------------------------------------------------
   -- CCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Peripheral_Access_Layer CCM Peripheral Access Layer
 * @{
 */

/** CCM - Register Layout Typedef */
typedef struct
{
      __IO uint32_t CCR;     /**< CCM Control Register, offset: 0x0 */
      __IO uint32_t CCDR;    /**< CCM Control Divider Register, offset: 0x4 */
      __IO uint32_t CSR;     /**< CCM Status Register, offset: 0x8 */
      __IO uint32_t CCSR;    /**< CCM Clock Switcher Register, offset: 0xC */
      __IO uint32_t CACRR;   /**< CCM Arm Clock Root Register, offset: 0x10 */
      __IO uint32_t CBCDR;   /**< CCM Bus Clock Divider Register, offset: 0x14 */
      __IO uint32_t CBCMR;   /**< CCM Bus Clock Multiplexer Register, offset: 0x18 */
      __IO uint32_t CSCMR1;  /**< CCM Serial Clock Multiplexer Register 1, offset: 0x1C */
      __IO uint32_t CSCMR2;  /**< CCM Serial Clock Multiplexer Register 2, offset: 0x20 */
      __IO uint32_t CSCDR1;  /**< CCM Serial Clock Divider Register 1, offset: 0x24 */
      __IO uint32_t CS1CDR;  /**< CCM SAI1 Clock Divider Register, offset: 0x28 */
      __IO uint32_t CS2CDR;  /**< CCM SAI2 Clock Divider Register, offset: 0x2C */
      __IO uint32_t CDCDR;   /**< CCM D1 Clock Divider Register, offset: 0x30 */
      __IO uint32_t CHSCCDR; /**< CCM HSC Clock Divider Register, offset: 0x34 */
      __IO uint32_t CSCDR2;  /**< CCM Serial Clock Divider Register 2, offset: 0x38 */
      __IO uint32_t CSCDR3;  /**< CCM Serial Clock Divider Register 3, offset: 0x3C */
      uint8_t RESERVED_0[8];
      __IO uint32_t CDHIPR; /**< CCM Divider Handshake In-Process Register, offset: 0x48 */
      uint8_t RESERVED_1[8];
      __IO uint32_t CLPCR; /**< CCM Low Power Control Register, offset: 0x54 */
      __IO uint32_t CISR;  /**< CCM Interrupt Status Register, offset: 0x58 */
      __IO uint32_t CIMR;  /**< CCM Interrupt Mask Register, offset: 0x5C */
      __IO uint32_t CCOSR; /**< CCM Clock Output Source Register, offset: 0x60 */
      __IO uint32_t CGPR;  /**< CCM General Purpose Register, offset: 0x64 */
      __IO uint32_t CCGR0; /**< CCM Clock Gating Register 0, offset: 0x68 */
      __IO uint32_t CCGR1; /**< CCM Clock Gating Register 1, offset: 0x6C */
      __IO uint32_t CCGR2; /**< CCM Clock Gating Register 2, offset: 0x70 */
      __IO uint32_t CCGR3; /**< CCM Clock Gating Register 3, offset: 0x74 */
      __IO uint32_t CCGR4; /**< CCM Clock Gating Register 4, offset: 0x78 */
      __IO uint32_t CCGR5; /**< CCM Clock Gating Register 5, offset: 0x7C */
      __IO uint32_t CCGR6; /**< CCM Clock Gating Register 6, offset: 0x80 */
      uint8_t RESERVED_2[4];
      __IO uint32_t CMEOR; /**< CCM Module Enable Overide Register, offset: 0x88 */
} CCM_Type;

/* CCM - Peripheral instance base addresses */
/** Peripheral CCM base address */
#define CCM_BASE (0x20C4000u)
/** Peripheral CCM base pointer */
#define CCM ((CCM_Type *)CCM_BASE)

/** LCDIF - Register Layout Typedef */
typedef struct
{
      __IO uint32_t CTRL;           /**< eLCDIF General Control Register, offset: 0x0 */
      __IO uint32_t CTRL_SET;       /**< eLCDIF General Control Register, offset: 0x4 */
      __IO uint32_t CTRL_CLR;       /**< eLCDIF General Control Register, offset: 0x8 */
      __IO uint32_t CTRL_TOG;       /**< eLCDIF General Control Register, offset: 0xC */
      __IO uint32_t CTRL1;          /**< eLCDIF General Control1 Register, offset: 0x10 */
      __IO uint32_t CTRL1_SET;      /**< eLCDIF General Control1 Register, offset: 0x14 */
      __IO uint32_t CTRL1_CLR;      /**< eLCDIF General Control1 Register, offset: 0x18 */
      __IO uint32_t CTRL1_TOG;      /**< eLCDIF General Control1 Register, offset: 0x1C */
      __IO uint32_t CTRL2;          /**< eLCDIF General Control2 Register, offset: 0x20 */
      __IO uint32_t CTRL2_SET;      /**< eLCDIF General Control2 Register, offset: 0x24 */
      __IO uint32_t CTRL2_CLR;      /**< eLCDIF General Control2 Register, offset: 0x28 */
      __IO uint32_t CTRL2_TOG;      /**< eLCDIF General Control2 Register, offset: 0x2C */
      __IO uint32_t TRANSFER_COUNT; /**< eLCDIF Horizontal and Vertical Valid Data Count Register, offset: 0x30 */
      uint8_t RESERVED_0[12];
      __IO uint32_t CUR_BUF; /**< LCD Interface Current Buffer Address Register, offset: 0x40 */
      uint8_t RESERVED_1[12];
      __IO uint32_t NEXT_BUF; /**< LCD Interface Next Buffer Address Register, offset: 0x50 */
      uint8_t RESERVED_2[12];
      __IO uint32_t TIMING; /**< LCD Interface Timing Register, offset: 0x60 */
      uint8_t RESERVED_3[12];
      __IO uint32_t VDCTRL0;     /**< eLCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x70 */
      __IO uint32_t VDCTRL0_SET; /**< eLCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x74 */
      __IO uint32_t VDCTRL0_CLR; /**< eLCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x78 */
      __IO uint32_t VDCTRL0_TOG; /**< eLCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x7C */
      __IO uint32_t VDCTRL1;     /**< eLCDIF VSYNC Mode and Dotclk Mode Control Register1, offset: 0x80 */
      uint8_t RESERVED_4[12];
      __IO uint32_t VDCTRL2; /**< LCDIF VSYNC Mode and Dotclk Mode Control Register2, offset: 0x90 */
      uint8_t RESERVED_5[12];
      __IO uint32_t VDCTRL3; /**< eLCDIF VSYNC Mode and Dotclk Mode Control Register3, offset: 0xA0 */
      uint8_t RESERVED_6[12];
      __IO uint32_t VDCTRL4; /**< eLCDIF VSYNC Mode and Dotclk Mode Control Register4, offset: 0xB0 */
      uint8_t RESERVED_7[12];
      __IO uint32_t DVICTRL0; /**< Digital Video Interface Control0 Register, offset: 0xC0 */
      uint8_t RESERVED_8[12];
      __IO uint32_t DVICTRL1; /**< Digital Video Interface Control1 Register, offset: 0xD0 */
      uint8_t RESERVED_9[12];
      __IO uint32_t DVICTRL2; /**< Digital Video Interface Control2 Register, offset: 0xE0 */
      uint8_t RESERVED_10[12];
      __IO uint32_t DVICTRL3; /**< Digital Video Interface Control3 Register, offset: 0xF0 */
      uint8_t RESERVED_11[12];
      __IO uint32_t DVICTRL4; /**< Digital Video Interface Control4 Register, offset: 0x100 */
      uint8_t RESERVED_12[12];
      __IO uint32_t CSC_COEFF0; /**< RGB to YCbCr 4:2:2 CSC Coefficient0 Register, offset: 0x110 */
      uint8_t RESERVED_13[12];
      __IO uint32_t CSC_COEFF1; /**< RGB to YCbCr 4:2:2 CSC Coefficient1 Register, offset: 0x120 */
      uint8_t RESERVED_14[12];
      __IO uint32_t CSC_COEFF2; /**< RGB to YCbCr 4:2:2 CSC Coefficent2 Register, offset: 0x130 */
      uint8_t RESERVED_15[12];
      __IO uint32_t CSC_COEFF3; /**< RGB to YCbCr 4:2:2 CSC Coefficient3 Register, offset: 0x140 */
      uint8_t RESERVED_16[12];
      __IO uint32_t CSC_COEFF4; /**< RGB to YCbCr 4:2:2 CSC Coefficient4 Register, offset: 0x150 */
      uint8_t RESERVED_17[12];
      __IO uint32_t CSC_OFFSET; /**< RGB to YCbCr 4:2:2 CSC Offset Register, offset: 0x160 */
      uint8_t RESERVED_18[12];
      __IO uint32_t CSC_LIMIT; /**< RGB to YCbCr 4:2:2 CSC Limit Register, offset: 0x170 */
      uint8_t RESERVED_19[12];
      __IO uint32_t DATA; /**< LCD Interface Data Register, offset: 0x180 */
      uint8_t RESERVED_20[12];
      __IO uint32_t BM_ERROR_STAT; /**< Bus Master Error Status Register, offset: 0x190 */
      uint8_t RESERVED_21[12];
      __IO uint32_t CRC_STAT; /**< CRC Status Register, offset: 0x1A0 */
      uint8_t RESERVED_22[12];
      __IO uint32_t STAT; /**< LCD Interface Status Register, offset: 0x1B0 */
      uint8_t RESERVED_23[76];
      __IO uint32_t THRES; /**< eLCDIF Threshold Register, offset: 0x200 */
      uint8_t RESERVED_24[12];
      __IO uint32_t AS_CTRL; /**< eLCDIF AS Buffer Control Register, offset: 0x210 */
      uint8_t RESERVED_25[12];
      __IO uint32_t AS_BUF; /**< Alpha Surface Buffer Pointer, offset: 0x220 */
      uint8_t RESERVED_26[12];
      __IO uint32_t AS_NEXT_BUF; /**< , offset: 0x230 */
      uint8_t RESERVED_27[12];
      __IO uint32_t AS_CLRKEYLOW; /**< eLCDIF Overlay Color Key Low, offset: 0x240 */
      uint8_t RESERVED_28[12];
      __IO uint32_t AS_CLRKEYHIGH; /**< eLCDIF Overlay Color Key High, offset: 0x250 */
      uint8_t RESERVED_29[12];
      __IO uint32_t SYNC_DELAY; /**< LCD working insync mode with CSI for VSYNC delay, offset: 0x260 */
} LCDIF_Type;

/* LCDIF - Peripheral instance base addresses */
/** Peripheral LCDIF base address */
#define LCDIF_BASE (0x21C8000u)
/** Peripheral LCDIF base pointer */
#define LCDIF ((LCDIF_Type *)LCDIF_BASE)

/** CSI - Register Layout Typedef */
typedef struct
{
      __IO uint32_t CSICR1;      /**< CSI Control Register 1, offset: 0x0 */
      __IO uint32_t CSICR2;      /**< CSI Control Register 2, offset: 0x4 */
      __IO uint32_t CSICR3;      /**< CSI Control Register 3, offset: 0x8 */
      __IO uint32_t CSISTATFIFO; /**< CSI Statistic FIFO Register, offset: 0xC */
      __IO uint32_t CSIRFIFO;    /**< CSI RX FIFO Register, offset: 0x10 */
      __IO uint32_t CSIRXCNT;    /**< CSI RX Count Register, offset: 0x14 */
      __IO uint32_t CSISR;       /**< CSI Status Register, offset: 0x18 */
      uint8_t RESERVED_0[4];
      __IO uint32_t CSIDMASA_STATFIFO; /**< CSI DMA Start Address Register - for STATFIFO, offset: 0x20 */
      __IO uint32_t CSIDMATS_STATFIFO; /**< CSI DMA Transfer Size Register - for STATFIFO, offset: 0x24 */
      __IO uint32_t CSIDMASA_FB1;      /**< CSI DMA Start Address Register - for Frame Buffer1, offset: 0x28 */
      __IO uint32_t CSIDMASA_FB2;      /**< CSI DMA Transfer Size Register - for Frame Buffer2, offset: 0x2C */
      __IO uint32_t CSIFBUF_PARA;      /**< CSI Frame Buffer Parameter Register, offset: 0x30 */
      __IO uint32_t CSIIMAG_PARA;      /**< CSI Image Parameter Register, offset: 0x34 */
      uint8_t RESERVED_1[16];
      __IO uint32_t CSICR18; /**< CSI Control Register 18, offset: 0x48 */
      __IO uint32_t CSICR19; /**< CSI Control Register 19, offset: 0x4C */
} CSI_Type;

/* CSI - Peripheral instance base addresses */
/** Peripheral CSI base address */
#define CSI_BASE (0x21C4000u)
/** Peripheral CSI base pointer */
#define CSI ((CSI_Type *)CSI_BASE)

#endif