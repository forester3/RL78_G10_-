/*
 *          led_blink2.c
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

#define LED1    (P0_bit.no2)
#define TIMER_CONT_VALUE_100MS		(31249)	//	0.1*20000000/64-1

int main(void)
{
    uint8_t n, m;
    uint8_t h, l;
    uint16_t timer;

    while(1)
    {
        for( n = 0x30; n <= 0x37; n++ )
        {
            TS00 = 1;           //  timer start
            SDR00L = n;

            if(n & 0x04)    LED1 = 1;
            else            LED1 = 0;
    
            for( m = 0; m < 255; m++ )
            {
                NOP();
            }
            do
            {
                l = TCR00L;
                h = TCR00H;
                timer = ((uint16_t)h << 8) + l;
            }
		    while(timer > UINT16_MAX-TIMER_CONT_VALUE_100MS);

            TT00 = 1;           //  timer stop
        }
    }

    return 0;
}
