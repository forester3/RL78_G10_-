/*
 *          timer.c
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
/**
* @file     timer.c
* @brief 	timer related function
* @author 	forester3
* @date 	7/July/2018
* @details 	R5F10Y47ASP-RL78/G10 timer functions
*/
#include "interrupt_handlers.h"
#include <stdint.h>
#include "iodefine.h"
#include "iodefine_ext.h"

#define PRS0_FCLK					(0x0)		// 	CK0x = fclk
#define PRS0_FCLK2                  (0x1)       //  CK0x = fclk/2
#define PRS0_FCLK4                  (0x2)       //  CK0x = fclk/4
#define PRS0_FCLK8                  (0x3)       //  CK0x = fclk/8
#define PRS0_FCLK16                 (0x4)       //  CK0x = fclk/16
#define PRS0_FCLK32                 (0x5)       //  CK0x = fclk/32
#define	TPS0_FCLK_FCLK2			    ((PRS0_FCLK << 4) | PRS0_FCLK2)	    //	CK01=fclk, CK00=fclk/2
#define	TPS0_FCLK4_FCLK8			((PRS0_FCLK4 << 4) | PRS0_FCLK8)	//	CK01=fclk/4, CK00=fclk/8
#define	TPS0_FCLK16_FCLK32			((PRS0_FCLK16 << 4) | PRS0_FCLK32)	//	CK01=fclk/16, CK00=fclk/32
#define	TMR00H_CK00_STS0			(0x00)		//	CK00, soft trigger start only
#define TMR00H_CK01_STS0            (0x80)      //  CK01, soft trigger start only
#define	TMR00L_FEG_ITTM_INTO		(0x00)		// 	falling edge, interval timer mode, intterupt occur
#define TDR00_1MS_FCLK              (20000-1)
#define TDR00_3MS_FCLK              (60000-1)
#define TDR00_4MS_FLCK2             (40000-1)
#define TDR00_6MS_FCLK2             (60000-1)
#define TDR00_8MS_FCLK4             (40000-1)
#define TDR00_10MS_FCLK4            (50000-1)
#define TDR00_12MS_FCLK4            (60000-1)
#define TDR00_15MS_FCLK8            (37500-1)
#define TDR00_25MS_FCLK8            (62500-1)
#define TDR00_30MS_FLCK16           (37500-1)
#define TDR00_50MS_FLCK16           (62500-1)

/**
* @fn uint8_t InitTimer0_us(uint16_t tim)
* @brief At timer0, set interval timer in microseconds
* @param[in] tm(interval_time) [us]
* @return sint8_t -1:Argument out of range, 0:init OK
* @details 
*/
int8_t InitTimer0_us(uint16_t tm)
{
	uint8_t prs;

    if( tm > 52000 )
        return -1;
    else if( tm >= 26000 )
    {
        prs = PRS0_FCLK16;
 		tm = (uint16_t)((uint32_t)tm * 5 / 4 - 1);
	}
	else if( tm >= 13000 )
	{
        prs = PRS0_FCLK8;
 		tm = (uint16_t)((uint32_t)tm * 5 / 2 - 1);
	}
	else if( tm >= 6500 )
	{
        prs = PRS0_FCLK4;
 		tm = tm * 5  - 1;
	}
	else if( tm >= 3250 )
	{
        prs = PRS0_FCLK2;
 		tm = tm * 10  - 1;
	}
	else
	{
        prs = PRS0_FCLK;
 		tm = tm * 20  - 1;
	}
    TPS0 = (TPS0 & 0xF0) + prs;
	TMR00H = TMR00H_CK00_STS0;
	TMR00L = TMR00L_FEG_ITTM_INTO;
	TDR00H = (uint8_t)((tm & 0xFF00) >> 8);
	TDR00L = (uint8_t)(tm & 0x00FF);

	return 0;
}

volatile uint16_t systick;

void INT_TM00 (void)
{
    systick++;
}