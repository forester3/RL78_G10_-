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
#define TIMER_CONT_VALUE_500MS		(9765)	//	.5*20000000/1024

int main(void)
{
    uint8_t led = 0;
    uint8_t h, l;
    uint16_t timer;

    while(1)
    {
        TS00 = 1;           //  timer start
        do
        {
            l = TCR00L;
            h = TCR00H;
            timer = ((uint16_t)h << 8) + l;
        }
		while(timer > UINT16_MAX-TIMER_CONT_VALUE_500MS);

        TT00 = 1;           //  timer stop

        if( led == 0 )
        {
            led = 1;
            LED1 = 1;
        }
        else
        {
            led = 0;
            LED1 = 0;
        }
    }

    return 0;
}
