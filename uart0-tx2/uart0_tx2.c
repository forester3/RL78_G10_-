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

extern volatile uint16_t systick;
extern int8_t uart0_cpy( char *, uint8_t );

#define LED1    (P0_bit.no2)

int main(void)
{
    uint8_t n = 0;

    while(1)
    {
        if( n == 0 )
        {
            if( uart0_cpy( "three\r\n", 7 ) > 0 )
            {
                n++;
            }
        }
        else if( n == 1 )
        {
            if( uart0_cpy( "TWO\r\n", 5 ) > 0 )
            {
                n++;
            }
        }
        else if( n == 2 )
        {
            if( uart0_cpy( "1", 1 ) > 0 )
            {
                n++;
            }
        }
        else if( n == 3 )
        {
            if( uart0_cpy( "\r\nZero\r\n", 8 ) > 0 )
            {
                n++;
            }
        }
        else if( n == 4 )
        {
            if( uart0_cpy( "Go! RL78/G10 AE-R5F10Y47ASP...\r\n", 32 ) > 0 )
            {
                n++;
            }
        }

        if( systick >= 25)
        {
            if( ( LED1 == 0 ) && ( n == 5 ) )
            {
                n = 0;
            }

            LED1 = 1;
        }
        else
        {
            LED1 = 0;
        }
    }
    return 0;
}