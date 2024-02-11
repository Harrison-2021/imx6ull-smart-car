#ifndef _SPI_H
#define _SPI_H
#include "imx6ull.h"
#include "gpt.h"
#include "uart.h"

void spi_pin_init();
void spi_con_init();
void spi_channel_config(uint8_t channel, uint8_t phase, uint8_t pol);
uint8_t spi_transfer(uint8_t tx_data);
void spi_cs_start();
void spi_cs_stop();
void spi_test();
#endif