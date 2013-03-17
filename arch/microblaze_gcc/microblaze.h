/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2002-2008 by Y.D.K Co.,Ltd
 *  Copyright (C) 2012-2013 by Tetsuya Morizumi
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id: microblaze.h 1947 2010-10-11 07:41:09Z ertl-honda $
 */

/*
 *  Microbalze�Υϡ��ɥ������񸻤����
 */

#ifndef TOPPERS_MICROBLAZE_H
#define TOPPERS_MICROBLAZE_H

#include <sil.h>

/*
 *  ����(v7.00)��Ϣ�����
 */

/*
 *  MSR�Υӥå����
 */
#define MSR_EIP 0x0200  /* Exception In Progress */
#define MSR_EE  0x0100  /* Exception Enable */
#define MSR_DCE 0x0080  /* Data Cache Enable */
#define MSR_DZ  0x0040  /* Division by Zero */
#define MSR_ICE 0x0020  /* Instraction Cache Enable */
#define MSR_FSL 0x0010  /* FSL Error */
#define MSR_BIP 0x0008  /* Break in Progress */
#define MSR_C   0x0004  /* Arthemetic Carry */
#define MSR_IE  0x0002  /* Interrupt Enable */
#define MSR_BE  0x0001  /* Buslock Enable */

/*
 *  ESR�Υӥå����
 */
#define ESR_DS  0x1000  /* Delay Slot Exception */
#define ESR_EC  0x001f  /* Exception Cause */

/*
 *  �㳰�ֹ�
 */
#define EXCNO_FSL     0x00 /* FSL exception */
#define EXCNO_UNALIGN 0x01 /* Unaligned data access exception */
#define EXCNO_ILLGOP  0x02 /* Illegal op-code exception */
#define EXCNO_IBUSER  0x03 /* Instraction bus error exception */
#define EXCNO_DBUSER  0x04 /* Data bus error exception */
#define EXCNO_DIV0    0x05 /* Divided by zero exception */
#define EXCNO_FLOAT   0x06 /* Floating point unit exception */
#define EXCNO_PRIINS  0x07 /* Privileged instruction exception */
#define EXCNO_DATSTR  0x10 /* Data storage exception */
#define EXCNO_INSTSTR 0x11 /* Instruction storage exception */
#define EXCNO_DATTLB  0x12 /* Data TLB miss exception */
#define EXCNO_INSTTLB 0x13 /* Instruction TLB miss exception */

/*
 *  XPS Interrupt Controller(v1.00.a)
 */

/*
 *  �쥸�������
 */
#define XINTC_ISR (XINTC_BASE + 0x00)
#define XINTC_IPR (XINTC_BASE + 0x04)
#define XINTC_IER (XINTC_BASE + 0x08)
#define XINTC_IAR (XINTC_BASE + 0x0c)
#define XINTC_SIE (XINTC_BASE + 0x10)
#define XINTC_CIE (XINTC_BASE + 0x14)
#define XINTC_IVR (XINTC_BASE + 0x18)
#define XINTC_MER (XINTC_BASE + 0x1c)

/* 
 * MER�Υӥå����
 */
#define XINTC_MER_HIE_BIT 0x2
#define XINTC_MER_ME_BIT  0x1

/*
 * ����ߥϥ�ɥ��ֹ椫�顤IRC���Τ���Υӥåȥѥ���������ޥ���
 */
#define INTNO_BITPAT(intno) (1U << intno)

#ifndef TOPPERS_MACRO_ONLY

Inline void
xintc_start(void){
  sil_wrw_mem((void*)XINTC_MER,
			  (XINTC_MER_HIE_BIT | XINTC_MER_ME_BIT));
}

Inline void
xintc_disable_allint(){
	sil_wrw_mem((void*)XINTC_MER, 0U);
}

Inline void
xintc_enable_int(uint32_t mask)
{
	sil_wrw_mem((void*)XINTC_SIE, mask);
}

Inline void
xintc_disable_int(uint32_t mask)
{
	sil_wrw_mem((void*)XINTC_CIE, mask);
}

Inline void
xintc_ack_int(uint32_t mask)
{
	sil_wrw_mem((void*)XINTC_IAR, mask);
}

Inline bool_t
xintc_probe_int(uint32_t mask)
{
	return ((sil_rew_mem((void*)XINTC_IPR) & mask) == mask);
}

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  XPS Timer/Counter(v1.00.a)
 */

/*
 *  �쥸�������
 */
#define XTIMER_TCSR0 (XTIMER_BASE + 0x00)
#define XTIMER_TLR0  (XTIMER_BASE + 0x04)
#define XTIMER_TCR0  (XTIMER_BASE + 0x08)
#define XTIMER_TCSR1 (XTIMER_BASE + 0x10)
#define XTIMER_TLR1  (XTIMER_BASE + 0x14)
#define XTIMER_TCR1  (XTIMER_BASE + 0x18)

/*
 *  TCSR �Υӥå����
 */
#define XTIMER_TCSR_ENALL_BIT  0x400
#define XTIMER_TCSR_PWMA_BIT   0x200
#define XTIMER_TCSR_INT_BIT    0x100
#define XTIMER_TCSR_ENT_BIT    0x080
#define XTIMER_TCSR_ENIT_BIT   0x040
#define XTIMER_TCSR_LOAD_BIT   0x020
#define XTIMER_TCSR_ARHT_BIT   0x010
#define XTIMER_TCSR_CAPT_BIT   0x008
#define XTIMER_TCSR_GENT_BIT   0x004
#define XTIMER_TCSR_UDT_BIT    0x002
#define XTIMER_TCSR_MDT_BIT    0x001

/*
 *  XPS UART Lite(v1.00.a)
 */

/*
 *  �쥸�������
 */
#define XUARTL_RX_OFFSET     0x00
#define XUARTL_TX_OFFSET     0x04
#define XUARTL_STAT_OFFSET   0x08
#define XUARTL_CTRL_OFFSET   0x0c

/*
 *  CTRL_REG �Υӥå����
 */
#define XUARTL_CTRL_ENABLE_INTR_BIT  0x10
#define XUARTL_CTRL_RST_RX_FIFO_BIT  0x02
#define XUARTL_CTRL_RST_TX_FIFO_BIT  0x01

/*
 * Error condition masks 
 */
#define XUARTL_STAT_PAR_E_BIT     0x80
#define XUARTL_STAT_FRAME_E_BIT   0x40
#define XUARTL_STAT_OVERRUN_E_BIT 0x20

/*
 * Other status bit masks
 */
#define XUARTL_STAT_INTR_ENA_BIT      0x10
#define XUARTL_STAT_TX_FULL_BIT       0x08
#define XUARTL_STAT_TX_EMPTY_BIT      0x04
#define XUARTL_STAT_RX_FULL_BIT       0x02
#define XUARTL_STAT_RX_VALID_DATA_BIT 0x01

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �����ͥ�����٥�����ѽ�����ؿ�(XPS UART Lite��)
 */
Inline void
microbalze_xuartl_init(void)
{
	/* �������Хåե��Υ��ꥢ */
	sil_wrw_mem((void*)(KENEL_LOW_OUT_XUARTL_BASE + XUARTL_CTRL_OFFSET),
				(XUARTL_CTRL_RST_RX_FIFO_BIT | XUARTL_CTRL_RST_TX_FIFO_BIT));
}

/*
 *  �����ͥ�����٥�����Ѵؿ�(XPS UART Lite��)
 */
Inline void
microbalze_xuartl_putc(char c)
{
	while((sil_rew_mem((void*)(KENEL_LOW_OUT_XUARTL_BASE + XUARTL_STAT_OFFSET)) & XUARTL_STAT_TX_FULL_BIT) == XUARTL_STAT_TX_FULL_BIT);
	sil_wrw_mem((void*)(KENEL_LOW_OUT_XUARTL_BASE + XUARTL_TX_OFFSET), c);
}

#endif /* TOPPERS_MACRO_ONLY */

#endif /* TOPPERS_MICROBLAZE_H */
