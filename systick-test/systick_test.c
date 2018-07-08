/*
 *          systick.c
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

extern int8_t InitTimer0_us( uint16_t t );
extern volatile uint16_t systick;

#define LED1    (P0_bit.no2)

int main(void)
{
    uint8_t n, m;
    uint8_t h, l;
    uint16_t loop = 10000;

    while(1)
    {
        for( n = 0; n <= 6; n++ )
        {
            if( n == 0 )
            {
                InitTimer0_us( 500 );
                loop = 200;
            }
            else if( n == 1 )
            {
                InitTimer0_us( 1000 );
                loop = 100;
            }
            else if( n == 2 )
            {
                InitTimer0_us( 2000 );
                loop = 50;
            }
            else if( n == 3 )
            {
                InitTimer0_us( 5000 );
                loop = 20;
            }
            else if( n == 4 )
            {
                InitTimer0_us( 10000 );
                loop = 10;
            }
            else if( n == 5 )
            {
                InitTimer0_us( 33333 );
                loop = 3;
            }
            else if( n == 6 )
            {
                InitTimer0_us( 50000 );
                loop = 2;
            }

            for( m = 0; m <= 9; m++ )
            {
                if( m >= 5 )    LED1 = 1;
                else            LED1 = 0;

                systick = 0;
                TS00 = 1;                   //  timer start
                EI();
                SDR00L = n + 0x30;

                while(1)                    //  timer wait
                {
                    if( systick >= loop )
                    {
                        TT00 = 1;           //  timer stop
                        DI();
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
