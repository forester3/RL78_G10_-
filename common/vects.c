//3.5.4.27550                                                                      
/************************************************************************/
/* Header file generated from device file:                              */
/*    DR5F10Y47.DVF                                                     */
/*    E1.03a (2016/10/17)                                               */
/*    Copyright(C) 2016 Renesas                                         */
/*    update 2018 forester3                                             */
/*      move option bytes to hwinit.c                                   */
/* Tool Version: 3.5.4                                                  */
/* Date Generated: 2016/11/01                                           */
/************************************************************************/
#include "interrupt_handlers.h"

extern void PowerON_Reset (void);

const unsigned char Security_Id[]  __attribute__ ((section (".security_id"))) = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define VEC          __attribute__ ((section (".vec")))
const void *HardwareVectors[] VEC = {
	// Address 0x0
	PowerON_Reset,
	// Secure for Debugging
	(void*)0xFFFF
};

#define VECT_SECT          __attribute__ ((section (".vects")))
const void *Vectors[] VECT_SECT = {
	//INT_WDTI (0x4)
	INT_WDTI,
	//INT_P0 (0x6)
	INT_P0,
	//INT_P1 (0x8)
	INT_P1,
	//INT_CSI00/INT_IIC00/INT_ST0 (0xA)
	INT_ST0,
	//INT_CSI01/INT_SR0 (0xC)
	INT_SR0,
	//INT_SRE0 (0xE)
	INT_SRE0,
	//INT_TM01H (0x10)
	INT_TM01H,
	//INT_TM00 (0x12)
	INT_TM00,
	//INT_TM01 (0x14)
	INT_TM01,
	//INT_AD (0x16)
	INT_AD,
	//INT_KR (0x18)
	INT_KR,
	//INT_P2 (0x1A)
	INT_P2,
	//INT_P3 (0x1C)
	INT_P3,
	//INT_TM03H (0x1E)
	INT_TM03H,
	//INT_IICA0 (0x20)
	INT_IICA0,
	//INT_TM02 (0x22)
	INT_TM02,
	//INT_TM03 (0x24)
	INT_TM03,
	//INT_IT (0x26)
	INT_IT,
	//INT_CMP0 (0x28)
	INT_CMP0,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	//INT_BRK_I (0x7E)
	INT_BRK_I,
};

