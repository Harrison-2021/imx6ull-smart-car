#ifndef _ONEWIRE_H
#define _ONEWIRE_H
#include"imx6ull.h"
#include"uart.h"
#include"gpt.h"

#define DS18B20_HIGH_LEVEL 1
#define DS18B20_LOW_LEVEL  0
#define ONEWIRE_HIGH 1
#define ONEWIRE_LOW  0
#define READ_ROM 0x33
#define SKIP_ROM 0xcc
#define CONVERT_T 0x44
#define READ_SCR 0xbe

void ds18b20_pin_init();
void ds18b20_pin_input();
void ds18b20_pin_output();
void ds18b20_write_level(uint8_t level);
uint8_t ds18b20_read_level();
int ds18b20_detect();
void ds18b20_write_bit(uint8_t bit);
uint8_t ds18b20_read_bit();
void ds18b20_write_byte(uint8_t data);
void ds18b20_read_id();

#endif