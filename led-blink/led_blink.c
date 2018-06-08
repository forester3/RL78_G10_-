/*
 *          led_blink.c
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

void wait()
{
	NOP();
}

#define LED1    (P0_bit.no2)

int main(void)
{
    uint8_t led = 0;

    while(1)
    {
		for(uint32_t i = 0; i < 353356; ++i)
        {
			wait();
		}
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
