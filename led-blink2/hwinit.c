/*
 *          hwinit.c
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

#include "iodefine.h"
#include "iodefine_ext.h"

#define WDTON       (0 << 4)    //  WDT counter disable
#define WDCS        (7 << 1)    //  3799msMIN overflow
#define WDSTBYON    (0)         //  At HALT/STOP mode, WDT counter disable   
#define OPTION0     (0xE0 | WDTON | WDCS | WDSTBYON)

#define PORTSELB    (1 << 4)         //  enable /RESET input
#define SPORS       (0 << 2)         //  4.2V reset
#define OPTION1     (0xE3 | PORTSELB | SPORS)

#define FRQSEL      (1)             //  20MHz, fmain
#define OPTION2     (0xF8 | FRQSEL)

#define OCDENSET    (0 << 7)            //  disable on chip debug
#define OPTION3     (0x05 | OCDENSET)

const unsigned char Option_Bytes[]  __attribute__ ((section (".option_bytes"))) = {
	OPTION0, OPTION1, OPTION2, OPTION3
};

#define	CMC_EXT_RESONATOR_OVER_10M	(0x41)		//	use external resonator over 10MHz
#define	CSC_WORK_FMX_FIN			(0x00)		//	work fmx and fin
#define	CSC_WORK_FMX_ONLY			(0x01)		//	work fmx only
#define	OSCT_OVER_272_CYCLE			(0x80)		//	
#define	OSCT_OVER_528_CYCLE			(0xC0)		//	
#define	OSTS_528_CYCLE				(0x01)		//	
#define	MCM0_FMAIN_SET_FMX			(1)			//  fmain is set to fmx

void InitFmx(void)
{
	CMC = CMC_EXT_RESONATOR_OVER_10M;
	OSTS = OSTS_528_CYCLE;
	CSC = CSC_WORK_FMX_FIN;						//	fmx start

	while(OSTC < OSCT_OVER_528_CYCLE)
	{
	};

	MCM0 = MCM0_FMAIN_SET_FMX;
	CSC = CSC_WORK_FMX_ONLY;					//	fin stop
}

#define PRS0_FCLK					(0x0)		// 	CK0x = flck
#define PRS0_FLCK1024				(0x0A)		//	CK0x = flck/1024
#define	TPS0_FCLK_FCLK1024			((PRS0_FCLK << 4) | PRS0_FLCK1024)	//	CK01=fclk, CK00=fclk/1024
#define	TMR00H_CK00_STS0			(0x00)		//	CK00, soft trigger start only
#define	TMR00L_FEG_ITTM_INTO		(0x00)		// 	falling edge, interval timer mode, intterupt occur

void InitTimer0(void)
{
	TPS0 = TPS0_FCLK_FCLK1024;
	TMR00H = TMR00H_CK00_STS0;
	TMR00L = TMR00L_FEG_ITTM_INTO;
	TDR00H = 0xFF;
	TDR00L = 0xFF;
}

void HardwareSetup(void)
{
	InitFmx();

	TAU0EN = 1;

	InitTimer0();

	PMC0_bit.no2 = PM_CTRL_BIT_DIGITAL;
    PM0_bit.no2 = PORT_MODE_BIT_OUTPUT;
}                                                                   
