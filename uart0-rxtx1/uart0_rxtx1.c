/*
 * @file        uart0_tx2.c
 * @brief 	    project main routine
 * @date 	    25/July/2018
 * @details 	R5F10Y47ASP-RL78/G10 UART0 intterupt transmit main routine
 *
 *  Copyright (c) 2018 forester3
 *      https://github.com/forester3
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include <stdint.h>
#include "iodefine.h"
#include "iodefine_ext.h"

#define LED1            (P0_bit.no2)
#define SYSTICK_100MS   (5)

extern volatile uint16_t systick;
extern volatile uint8_t rx_len;
extern char rx_buf[];
extern int8_t uart0_cpy( char *, uint8_t );

const char HEX_ASC[] = "0123456789ABCDEF";
uint16_t rx_tick;
uint8_t rx_len_lst = 0;
char str[24];
char hex[3];

char *u8toStrHex( char *s, uint8_t x )
{
    s[0] = HEX_ASC[((x & 0xF0) >> 4)];
    s[1] = HEX_ASC[x & 0x0F];
    s[2] = '\0';

    return( s );
}

void ustrcpy( char *dst, const char *src )
{
    while( (*dst++ = *src++) != '\0' )
    {
    }
}

void ustrncat( char *dst, const char *src, uint8_t size )
{
    while( *dst != '\0' )
    {
        dst++;
    }
    for( ; size > 0; size-- )
    {
        *dst++ = *src++;
    }
    *dst = '\0';
}

uint8_t ustrlen( const char *str )
{
    uint8_t len = 0;

    while( *str++ != '\0' )
    {
        len++;
    }
    return( len );
}

int main(void)
{
    LED1 = 1;
    while(1)
    {
        if( rx_len != rx_len_lst )
        {
            rx_tick = systick + SYSTICK_100MS;
            rx_len_lst = rx_len;
            LED1 = 0;
        }
        else if( (LED1 == 0) && (rx_tick == systick) )
        {
            ustrcpy( str, ":" );
            SRMK0 =  1;                     //  DI();
            ustrncat( str, u8toStrHex( hex, rx_len), 2 );
            ustrncat( str, ":", 1 );

            if( rx_len != 0xff )
            {
                ustrncat( str, rx_buf, rx_len );
                ustrncat( str, "\r\n", 2 );
                uart0_cpy( str, rx_len + 6 );
            }
            else
            {
                ustrncat( str, "\r\n", 2 );
                uart0_cpy( str, 6 );
            }
            rx_len_lst = 0;
            rx_len = 0;
            SRMK0 = 0;                      //  EI();
            
            LED1 = 1;
        }
    }
    return 0;
}