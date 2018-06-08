/*
 *          iodefine.h
 *
 *  update 2018 forester3
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
//3.5.4.27550                                                                      
/************************************************************************/
/* Header file generated from device file:                              */
/*    DR5F10Y47.DVF                                                     */
/*    E1.03a (2016/10/17)                                               */
/*    Copyright(C) 2016 Renesas                                         */
/* Tool Version: 3.5.4                                                  */
/* Date Generated: 2016/11/01                                           */
/************************************************************************/

#ifndef __INTRINSIC_FUNCTIONS
#define __INTRINSIC_FUNCTIONS

#define DI()    asm("di")
#define EI()    asm("ei")
#define HALT()  asm("halt")
#define NOP()   asm("nop")
#define STOP()  asm("stop")

#endif

#ifndef __IOREG_BIT_STRUCTURES
#define __IOREG_BIT_STRUCTURES
typedef struct {
	unsigned char no0 :1;
	unsigned char no1 :1;
	unsigned char no2 :1;
	unsigned char no3 :1;
	unsigned char no4 :1;
	unsigned char no5 :1;
	unsigned char no6 :1;
	unsigned char no7 :1;
} __BITS8;

#endif

#ifndef IODEFINE_H
#define IODEFINE_H

/*
 IO Registers
 */
union un_p0 {
	unsigned char p0;
	__BITS8 BIT;
};
union un_p4 {
	unsigned char p4;
	__BITS8 BIT;
};
union un_p12 {
	unsigned char p12;
	__BITS8 BIT;
};
union un_p13 {
	unsigned char p13;
	__BITS8 BIT;
};
union un_pm0 {
	unsigned char pm0;
	__BITS8 BIT;
};
union un_pm4 {
	unsigned char pm4;
	__BITS8 BIT;
};
union un_adm0 {
	unsigned char adm0;
	__BITS8 BIT;
};
union un_ads {
	unsigned char ads;
	__BITS8 BIT;
};
union un_krctl {
	unsigned char krctl;
	__BITS8 BIT;
};
union un_krm0 {
	unsigned char krm0;
	__BITS8 BIT;
};
union un_egp0 {
	unsigned char egp0;
	__BITS8 BIT;
};
union un_egn0 {
	unsigned char egn0;
	__BITS8 BIT;
};
union un_iics0 {
	unsigned char iics0;
	__BITS8 BIT;
};
union un_iicf0 {
	unsigned char iicf0;
	__BITS8 BIT;
};
union un_compmdr {
	unsigned char compmdr;
	__BITS8 BIT;
};
union un_compfir {
	unsigned char compfir;
	__BITS8 BIT;
};
union un_compocr {
	unsigned char compocr;
	__BITS8 BIT;
};
union un_csc {
	unsigned char csc;
	__BITS8 BIT;
};
union un_ostc {
	unsigned char ostc;
	__BITS8 BIT;
};
union un_ckc {
	unsigned char ckc;
	__BITS8 BIT;
};
union un_cks0 {
	unsigned char cks0;
	__BITS8 BIT;
};
union un_if0l {
	unsigned char if0l;
	__BITS8 BIT;
};
union un_if0h {
	unsigned char if0h;
	__BITS8 BIT;
};
union un_if1l {
	unsigned char if1l;
	__BITS8 BIT;
};
union un_mk0l {
	unsigned char mk0l;
	__BITS8 BIT;
};
union un_mk0h {
	unsigned char mk0h;
	__BITS8 BIT;
};
union un_mk1l {
	unsigned char mk1l;
	__BITS8 BIT;
};
union un_pr00l {
	unsigned char pr00l;
	__BITS8 BIT;
};
union un_pr00h {
	unsigned char pr00h;
	__BITS8 BIT;
};
union un_pr01l {
	unsigned char pr01l;
	__BITS8 BIT;
};
union un_pr10l {
	unsigned char pr10l;
	__BITS8 BIT;
};
union un_pr10h {
	unsigned char pr10h;
	__BITS8 BIT;
};
union un_pr11l {
	unsigned char pr11l;
	__BITS8 BIT;
};
union un_pmc {
	unsigned char pmc;
	__BITS8 BIT;
};

#define P0 (*(volatile union un_p0 *)0xFFF00).p0
#define P0_bit (*(volatile union un_p0 *)0xFFF00).BIT
#define P4 (*(volatile union un_p4 *)0xFFF04).p4
#define P4_bit (*(volatile union un_p4 *)0xFFF04).BIT
#define P12 (*(volatile union un_p12 *)0xFFF0C).p12
#define P12_bit (*(volatile union un_p12 *)0xFFF0C).BIT
#define P13 (*(volatile union un_p13 *)0xFFF0D).p13
#define P13_bit (*(volatile union un_p13 *)0xFFF0D).BIT
#define SDR00L (*(volatile unsigned char *)0xFFF10)
#define SIO00 (*(volatile unsigned char *)0xFFF10)
#define TXD0 (*(volatile unsigned char *)0xFFF10)
#define SDR00H (*(volatile unsigned char *)0xFFF11)
#define RXD0 (*(volatile unsigned char *)0xFFF12)
#define SDR01L (*(volatile unsigned char *)0xFFF12)
#define SIO01 (*(volatile unsigned char *)0xFFF12)
#define SDR01H (*(volatile unsigned char *)0xFFF13)
#define TDR00L (*(volatile unsigned char *)0xFFF18)
#define TDR00H (*(volatile unsigned char *)0xFFF19)
#define TDR01L (*(volatile unsigned char *)0xFFF1A)
#define TDR01H (*(volatile unsigned char *)0xFFF1B)
#define ADCRL (*(volatile unsigned char *)0xFFF1E)
#define ADCRH (*(volatile unsigned char *)0xFFF1F)

#define PM0 (*(volatile union un_pm0 *)0xFFF20).pm0
#define PM0_bit (*(volatile union un_pm0 *)0xFFF20).BIT
#define PM4 (*(volatile union un_pm4 *)0xFFF24).pm4
#define PM4_bit (*(volatile union un_pm4 *)0xFFF24).BIT

#define PORT_MODE_BIT_INPUT     (1)
#define PORT_MODE_BIT_OUTPUT    (0)

#define ADM0 (*(volatile union un_adm0 *)0xFFF30).adm0
#define ADM0_bit (*(volatile union un_adm0 *)0xFFF30).BIT
#define ADS (*(volatile union un_ads *)0xFFF31).ads
#define ADS_bit (*(volatile union un_ads *)0xFFF31).BIT
#define KRCTL (*(volatile union un_krctl *)0xFFF34).krctl
#define KRCTL_bit (*(volatile union un_krctl *)0xFFF34).BIT
#define KRF (*(volatile unsigned char *)0xFFF35)
#define KRM0 (*(volatile union un_krm0 *)0xFFF37).krm0
#define KRM0_bit (*(volatile union un_krm0 *)0xFFF37).BIT
#define EGP0 (*(volatile union un_egp0 *)0xFFF38).egp0
#define EGP0_bit (*(volatile union un_egp0 *)0xFFF38).BIT
#define EGN0 (*(volatile union un_egn0 *)0xFFF39).egn0
#define EGN0_bit (*(volatile union un_egn0 *)0xFFF39).BIT
#define IICA0 (*(volatile unsigned char *)0xFFF50)
#define IICS0 (*(volatile union un_iics0 *)0xFFF51).iics0
#define IICS0_bit (*(volatile union un_iics0 *)0xFFF51).BIT
#define IICF0 (*(volatile union un_iicf0 *)0xFFF52).iicf0
#define IICF0_bit (*(volatile union un_iicf0 *)0xFFF52).BIT
#define COMPMDR (*(volatile union un_compmdr *)0xFFF60).compmdr
#define COMPMDR_bit (*(volatile union un_compmdr *)0xFFF60).BIT
#define COMPFIR (*(volatile union un_compfir *)0xFFF61).compfir
#define COMPFIR_bit (*(volatile union un_compfir *)0xFFF61).BIT
#define COMPOCR (*(volatile union un_compocr *)0xFFF62).compocr
#define COMPOCR_bit (*(volatile union un_compocr *)0xFFF62).BIT
#define TDR02L (*(volatile unsigned char *)0xFFF64)
#define TDR02H (*(volatile unsigned char *)0xFFF65)
#define TDR03L (*(volatile unsigned char *)0xFFF66)
#define TDR03H (*(volatile unsigned char *)0xFFF67)
#define ITMCL (*(volatile unsigned char *)0xFFF90)
#define ITMCH (*(volatile unsigned char *)0xFFF91)
#define CMC (*(volatile unsigned char *)0xFFFA0)
#define CSC (*(volatile union un_csc *)0xFFFA1).csc
#define CSC_bit (*(volatile union un_csc *)0xFFFA1).BIT
#define OSTC (*(volatile union un_ostc *)0xFFFA2).ostc
#define OSTC_bit (*(volatile union un_ostc *)0xFFFA2).BIT
#define OSTS (*(volatile unsigned char *)0xFFFA3)
#define CKC (*(volatile union un_ckc *)0xFFFA4).ckc
#define CKC_bit (*(volatile union un_ckc *)0xFFFA4).BIT
#define CKS0 (*(volatile union un_cks0 *)0xFFFA5).cks0
#define CKS0_bit (*(volatile union un_cks0 *)0xFFFA5).BIT
#define RESF (*(volatile unsigned char *)0xFFFA8)
#define WDTE (*(volatile unsigned char *)0xFFFAB)
#define IF0L (*(volatile union un_if0l *)0xFFFE0).if0l
#define IF0L_bit (*(volatile union un_if0l *)0xFFFE0).BIT
#define IF0H (*(volatile union un_if0h *)0xFFFE1).if0h
#define IF0H_bit (*(volatile union un_if0h *)0xFFFE1).BIT
#define IF1L (*(volatile union un_if1l *)0xFFFE2).if1l
#define IF1L_bit (*(volatile union un_if1l *)0xFFFE2).BIT
#define MK0L (*(volatile union un_mk0l *)0xFFFE4).mk0l
#define MK0L_bit (*(volatile union un_mk0l *)0xFFFE4).BIT
#define MK0H (*(volatile union un_mk0h *)0xFFFE5).mk0h
#define MK0H_bit (*(volatile union un_mk0h *)0xFFFE5).BIT
#define MK1L (*(volatile union un_mk1l *)0xFFFE6).mk1l
#define MK1L_bit (*(volatile union un_mk1l *)0xFFFE6).BIT
#define PR00L (*(volatile union un_pr00l *)0xFFFE8).pr00l
#define PR00L_bit (*(volatile union un_pr00l *)0xFFFE8).BIT
#define PR00H (*(volatile union un_pr00h *)0xFFFE9).pr00h
#define PR00H_bit (*(volatile union un_pr00h *)0xFFFE9).BIT
#define PR01L (*(volatile union un_pr01l *)0xFFFEA).pr01l
#define PR01L_bit (*(volatile union un_pr01l *)0xFFFEA).BIT
#define PR10L (*(volatile union un_pr10l *)0xFFFEC).pr10l
#define PR10L_bit (*(volatile union un_pr10l *)0xFFFEC).BIT
#define PR10H (*(volatile union un_pr10h *)0xFFFED).pr10h
#define PR10H_bit (*(volatile union un_pr10h *)0xFFFED).BIT
#define PR11L (*(volatile union un_pr11l *)0xFFFEE).pr11l
#define PR11L_bit (*(volatile union un_pr11l *)0xFFFEE).BIT
#define PMC (*(volatile union un_pmc *)0xFFFFE).pmc
#define PMC_bit (*(volatile union un_pmc *)0xFFFFE).BIT

/*
 Sfr bits
 */
#define ADCE ADM0_bit.no0
#define ADCS ADM0_bit.no7
#define SPD0 IICS0_bit.no0
#define STD0 IICS0_bit.no1
#define ACKD0 IICS0_bit.no2
#define TRC0 IICS0_bit.no3
#define COI0 IICS0_bit.no4
#define EXC0 IICS0_bit.no5
#define ALD0 IICS0_bit.no6
#define MSTS0 IICS0_bit.no7
#define IICRSV0 IICF0_bit.no0
#define STCEN0 IICF0_bit.no1
#define IICBSY0 IICF0_bit.no6
#define STCF0 IICF0_bit.no7
#define C0ENB COMPMDR_bit.no0
#define C0MON COMPMDR_bit.no3
#define C0IE COMPOCR_bit.no0
#define C0OE COMPOCR_bit.no1
#define C0OP COMPOCR_bit.no2
#define SPDMD COMPOCR_bit.no7
#define HIOSTOP CSC_bit.no0
#define MSTOP CSC_bit.no7
#define MCM0 CKC_bit.no4
#define MCS CKC_bit.no5
#define PCLOE0 CKS0_bit.no7
#define WDTIIF IF0L_bit.no0
#define PIF0 IF0L_bit.no1
#define PIF1 IF0L_bit.no2
#define CSIIF00 IF0L_bit.no3
#define IICIF00 IF0L_bit.no3
#define STIF0 IF0L_bit.no3
#define CSIIF01 IF0L_bit.no4
#define SRIF0 IF0L_bit.no4
#define SREIF0 IF0L_bit.no5
#define TMIF01H IF0L_bit.no6
#define TMIF00 IF0L_bit.no7
#define TMIF01 IF0H_bit.no0
#define ADIF IF0H_bit.no1
#define KRIF IF0H_bit.no2
#define PIF2 IF0H_bit.no3
#define PIF3 IF0H_bit.no4
#define TMIF03H IF0H_bit.no5
#define IICAIF0 IF0H_bit.no6
#define TMIF02 IF0H_bit.no7
#define TMIF03 IF1L_bit.no0
#define ITIF IF1L_bit.no1
#define CMPIF0 IF1L_bit.no2
#define WDTIMK MK0L_bit.no0
#define PMK0 MK0L_bit.no1
#define PMK1 MK0L_bit.no2
#define CSIMK00 MK0L_bit.no3
#define IICMK00 MK0L_bit.no3
#define STMK0 MK0L_bit.no3
#define CSIMK01 MK0L_bit.no4
#define SRMK0 MK0L_bit.no4
#define SREMK0 MK0L_bit.no5
#define TMMK01H MK0L_bit.no6
#define TMMK00 MK0L_bit.no7
#define TMMK01 MK0H_bit.no0
#define ADMK MK0H_bit.no1
#define KRMK MK0H_bit.no2
#define PMK2 MK0H_bit.no3
#define PMK3 MK0H_bit.no4
#define TMMK03H MK0H_bit.no5
#define IICAMK0 MK0H_bit.no6
#define TMMK02 MK0H_bit.no7
#define TMMK03 MK1L_bit.no0
#define ITMK MK1L_bit.no1
#define CMPMK0 MK1L_bit.no2
#define WDTIPR0 PR00L_bit.no0
#define PPR00 PR00L_bit.no1
#define PPR01 PR00L_bit.no2
#define CSIPR000 PR00L_bit.no3
#define IICPR000 PR00L_bit.no3
#define STPR00 PR00L_bit.no3
#define CSIPR001 PR00L_bit.no4
#define SRPR00 PR00L_bit.no4
#define SREPR00 PR00L_bit.no5
#define TMPR001H PR00L_bit.no6
#define TMPR000 PR00L_bit.no7
#define TMPR001 PR00H_bit.no0
#define ADPR0 PR00H_bit.no1
#define KRPR0 PR00H_bit.no2
#define PPR02 PR00H_bit.no3
#define PPR03 PR00H_bit.no4
#define TMPR003H PR00H_bit.no5
#define IICAPR00 PR00H_bit.no6
#define TMPR002 PR00H_bit.no7
#define TMPR003 PR01L_bit.no0
#define ITPR0 PR01L_bit.no1
#define CMPPR00 PR01L_bit.no2
#define WDTIPR1 PR10L_bit.no0
#define PPR10 PR10L_bit.no1
#define PPR11 PR10L_bit.no2
#define CSIPR100 PR10L_bit.no3
#define IICPR100 PR10L_bit.no3
#define STPR10 PR10L_bit.no3
#define CSIPR101 PR10L_bit.no4
#define SRPR10 PR10L_bit.no4
#define SREPR10 PR10L_bit.no5
#define TMPR101H PR10L_bit.no6
#define TMPR100 PR10L_bit.no7
#define TMPR101 PR10H_bit.no0
#define ADPR1 PR10H_bit.no1
#define KRPR1 PR10H_bit.no2
#define PPR12 PR10H_bit.no3
#define PPR13 PR10H_bit.no4
#define TMPR103H PR10H_bit.no5
#define IICAPR10 PR10H_bit.no6
#define TMPR102 PR10H_bit.no7
#define TMPR103 PR11L_bit.no0
#define ITPR1 PR11L_bit.no1
#define CMPPR10 PR11L_bit.no2
#define MAA PMC_bit.no0

/*
 Interrupt vector addresses
 */
#define RST_vect (0x0)
#define INTDBG_vect (0x2)
#define INTWDTI_vect (0x4)
#define INTP0_vect (0x6)
#define INTP1_vect (0x8)
#define INTCSI00_vect (0xA)
#define INTIIC00_vect (0xA)
#define INTST0_vect (0xA)
#define INTCSI01_vect (0xC)
#define INTSR0_vect (0xC)
#define INTSRE0_vect (0xE)
#define INTTM01H_vect (0x10)
#define INTTM00_vect (0x12)
#define INTTM01_vect (0x14)
#define INTAD_vect (0x16)
#define INTKR_vect (0x18)
#define INTP2_vect (0x1A)
#define INTP3_vect (0x1C)
#define INTTM03H_vect (0x1E)
#define INTIICA0_vect (0x20)
#define INTTM02_vect (0x22)
#define INTTM03_vect (0x24)
#define INTIT_vect (0x26)
#define INTCMP0_vect (0x28)
#define BRK_I_vect (0x7E)

#endif
