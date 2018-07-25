/*
 *              uart.c
 * @brief 	    UART0 intterupt transmit
 * @author 	    forester3
 * @date 	    25/July/2018
 * @details 	R5F10Y47ASP-RL78/G10 UART0 intterupt transmit
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

#include "interrupt_handlers.h"
#include "iodefine.h"
#include "iodefine_ext.h"

#define PRS0_FCLK4					(0x2)		// 	CK0x = flck/4
#define	SPS0_FCLK4_FCLK4			((PRS0_FCLK4 << 4) | PRS0_FCLK4)	//	CK01=fclk/4, CK00=fclk/4
#define SMR00H_CK00_SWTRG			(0x00)		//	CK00, software trigger only
#define SMR00L_UART_TC				(0x22)		//	UART mode, trans complete INT
#define SMR00L_UART_BE				(0x23)		//	UART mode, buffer empty INT
#define SCR00H_TX_NOP				(0x80)		//	tx only, non parity
#define SCR00L_LSBF_STB1_8			(0x97)		//	lsb first, 1stop bit, 8bit
#define SO0_SOUT1_SOUT0				(0x00)		//	serial out 0 & 1
#define SOL0_NON_INV				(0x00)		//	Non-inverted


void InitUart0(void)
{
	SPS0 = SPS0_FCLK4_FCLK4;
	SMR00H = SMR00H_CK00_SWTRG;
	SMR00L = SMR00L_UART_BE;
	SCR00H = SCR00H_TX_NOP;
	SCR00L = SCR00L_LSBF_STB1_8;
	SDR00H = (64 << 1);							//	38400bps (@fclk/4)
//	SIR00 = 0x07;								//  error flag clear
	SO0 = SO0_SOUT1_SOUT0;
	SOL0 = SOL0_NON_INV;									
	SOE00 = 1;									//	serial output enable
  	PMC0_bit.no0 = PM_CTRL_BIT_DIGITAL;         //  TXD0 digital
	P0_bit.no0 = 1;								//	TXD0 
  	PM0_bit.no0 = PORT_MODE_BIT_OUTPUT;         //  TXD0 digital out
	SS00 = 1;									//	TXD0 standby
    
}

#define TX_BUFFER_SIZE              (32)
static uint8_t tx_buf[TX_BUFFER_SIZE];
static volatile uint8_t tx_len = 0;

void INT_ST0 (void)
{
    if( tx_len > 0 )
    {
        SDR00L = tx_buf[--tx_len];
    }
}

int8_t uart0_cpy( char *src, uint8_t n )
{
    int8_t  i;
    char *s = src + 1;

    if( (tx_len > 0 ) || (n > TX_BUFFER_SIZE) || (n == 0) )
    {
        return( -1 );
    }

    for( i = 1; i <= n; i++ )
    {
        tx_buf[n-i] = *s;
        s++;
    }

    tx_len = n;
    SDR00L = *src;

    return( n );
}
