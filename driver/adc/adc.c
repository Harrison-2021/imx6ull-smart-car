#include"imx6ull.h"
#include"adc.h"
#include"uart.h"
#include"gpt.h"

void adc_init() {
    /*1. ADC GPIO*/
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO05 &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO05 |= (0x5 << 0);

    /*2.Enable clock*/
    CCM_CCGR1 |= (0x3 << 16);

    /*3.set ADC : mode, clock source*/
    ADC1->CFG = (1 << 0) | (0x2 << 2);
}

/*4.adc auto calibration*/
int adc_auto_calibration() {
    /*
        1. CAL [7] CAL begins the calibration sequence when set.
    */
    ADC1->GC = (1 << 7);
    /*
       The ADC_GS[CALF] bit must be checked to
       determine the result of the calibration sequence.
       2.在自检中，检查检查是否正常，直到自检完成，ADC_GS[CALF]位自动清空
    */
    while(ADC1->GC & (1 << 7)) {
        if(ADC1->GS & (1 << 1)) {
            uart_printf("ADC calibration fail!\r\n");
            return -1;
        }
    }
   // 3.自检完成，ADC1->GS也清空，如果没有清空，自检也遇到了问题
    if(ADC1->GS & (1 << 1)) {
        uart_printf("ADC calibration fail!\r\n");
        return -1;
    }
   /*
        The COCO0 flag will also set at the completion
        of a Calibration and Test sequence.
    */
    if((ADC1->HS & (1 << 0)) == 0) {
        uart_printf("ADC calibration fail!\r\n");
        return -1;
    }

    uart_printf("ADC calibration success!\r\n");

    return 0;
}

void adc_channel_start(int channel) {
    /*
        ADCH [4:0]   Input Channel Select
        AIEN [7  ] 1 Conversion complete interrupt enabled
    */
   ADC1->HC[0] = (channel << 0) | (1 << 7);
}

int adc_interrupt_handler(int id) {
    uint32_t adc_mv;
    uint32_t adc_val;

    adc_val = ADC1->R[0] & 0xfff;
    adc_mv = (adc_val * 3300) / 4096;

    uart_printf("adc_value:%d , %dmv\r\n",adc_val,adc_mv);

    //start adc
    adc_channel_start(5);

    gpt_delay_sec(1);

    return 0;
}

void adc_test() {
    adc_init();
    int res = adc_auto_calibration();
    if(res < 0) return;

    //register adc interrupt
    request_irq(ADC1_IRQn,adc_interrupt_handler);
    enable_irq();

    // start adc
    adc_channel_start(5);
}