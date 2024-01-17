#ifndef _DATETIME_HEAD_H
#define _DATETIME_HEAD_H

#include <stdint.h>

#define SECONDS_IN_A_DAY (86400U)
#define SECONDS_IN_A_HOUR (3600U)
#define SECONDS_IN_A_MINUTE (60U)
#define DAYS_IN_A_YEAR (365U)
#define YEAR_RANGE_START (1970U)
#define YEAR_RANGE_END (2099U)

/*! @brief Structure is used to hold the date and time */
typedef struct rtc_datetime
{
    uint16_t year;  /*!< Range from 1970 to 2099.*/
    uint8_t month;  /*!< Range from 1 to 12.*/
    uint8_t day;    /*!< Range from 1 to 31 (depending on month).*/
    uint8_t hour;   /*!< Range from 0 to 23.*/
    uint8_t minute; /*!< Range from 0 to 59.*/
    uint8_t second; /*!< Range from 0 to 59.*/
}rtc_datetime_t;

extern uint32_t convert_datetime_to_seconds(const rtc_datetime_t *datetime);
extern void convert_seconds_to_datetime(uint32_t seconds, rtc_datetime_t *datetime);
#endif
