#ifndef _FLEXCAN_H
#define _FLEXCAN_H

#include "imx6ull.h"
#include "gpt.h"
#include "uart.h"
#include "interrupt.h"

#define TX_MB_INDEX 8
#define RX_MB_INDEX 9

typedef struct {
    int index; // MB索引，0-63
    int id;
    int size;
    int word0;
    int word1;
}mb_data_t;


void flexcan_gpio_init();
void flexcan_clock_init();
void flexcan_can_init(CAN_Type *base); 
void flexcan_freeze_enable(CAN_Type *base);
void flexcan_freeze_disable(CAN_Type *base);
void flexcan_sample_bitRate_init(CAN_Type *base);
void flexcan_tx_MB_config(CAN_Type *base, mb_data_t *mb);
void flexcan_rx_MB_config(CAN_Type *base, int index, int id);
void flexcan_send_data(CAN_Type *base, int id, uint8_t *buf, int size);
int flexcan_recv_data(CAN_Type *base, int id, uint8_t *buf, int size);
void flexcan_loopback_enable(CAN_Type *base);
void flexcan_loopback_disable(CAN_Type *base);
void flexcan_loopback_test();
void flexcan_interrupt_init(CAN_Type *base, int mb_index);
int flexcan_interrupt_handler(int id);
void flexcan_normal_test();
#endif
