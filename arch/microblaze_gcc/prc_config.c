/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2002-2008 by Y.D.K Co.,Ltd
 *  Copyright (C) 2012 by Tetsuya Morizumi
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
 *  @(#) $Id: prc_config.c 5 2012-01-14 09:35:55Z tetsuya $
 */

/*
 *  �ץ��å���¸�⥸�塼���Microbalze�ѡ�
 */
#include "kernel_impl.h"
#include "check.h"
#include "task.h"
#include "microblaze.h"

/*
 * �㳰�ʳ����/CPU�㳰�ˤΥͥ��Ȳ���Υ������
 * ����ƥ����Ȼ��ȤΤ���˻���
 */
uint32_t except_nest_count;

/*
 * �Ƴ���ߤγ�����׵�ػߥե饰�ξ���
 */
uint32_t idf;

/*
 * ���ߤγ����ͥ���٥ޥ�������
 */
uint8_t iipm;
 
/*
 *  �����°�������ꤵ��Ƥ��뤫��Ƚ�̤��뤿����ѿ�
 */
uint32_t bitpat_cfgint;
uint32_t bitpat_intedge;

/*
 *  �ץ��å���¸�ν����
 */
void
prc_initialize()
{
	/*
	 *  �����ͥ뵯ư�����󥿥�������ƥ����ȤȤ���ư����뤿��1��
	 */ 
	except_nest_count = 1;

	/*
	 * �Ƴ���ߤγ�����׵�ػߥե饰���ػ�
	 */
	idf = ~0U;

	/*
	 * �����ͥ���٥ޥ����ν����
	 */ 
	iipm = 0U;

	/*
	 * ���Ƥγ���ߤ�ޥ���
	 */ 
	xintc_disable_int(~0U);

	/*
	 *  �����°�������ꤵ��Ƥ��뤫��Ƚ�̤��뤿����ѿ����������롥
	 */
	bitpat_cfgint = 0U;
    bitpat_intedge = 0U;

	/*
	 *  XINTC�򳫻�
	 */
	xintc_start();
}

/*
 *  �ץ��å���¸�ν�λ����
 */
void
prc_terminate(void)
{
	/*
	 *  ���٤Ƥγ���ߤ�ޥ������롥
	 */
	xintc_disable_int(~0U);
}

/*
 *  ������׵�饤���°��������
 *
 *  ASP�����ͥ�Ǥ����Ѥ����ꤷ�ơ��ѥ�᡼�����顼�ϥ����������ǥ�����
 *  �����Ƥ��롥FI4�����ͥ�����Ѥ�����ˤϡ����顼���֤��褦�ˤ��٤�
 *  �Ǥ�����
 */
void
x_config_int(INTNO intno, ATR intatr, PRI intpri)
{
	assert(VALID_INTNO(intno));
	assert(TMIN_INTPRI <= intpri && intpri <= TMAX_INTPRI);

	/*
	 *  �����°�������ꤵ��Ƥ��뤫��Ƚ�̤��뤿����ѿ�������
	 */
	bitpat_cfgint |= INTNO_BITPAT(intno);
	if ((intatr & TA_EDGE) != 0U)
    {
        bitpat_intedge |= INTNO_BITPAT(intno);
    }

	/* 
	 * ���ä������ߤ�ػߤ���
	 */    
	x_disable_int(intno);

	if ((intatr & TA_ENAINT) != 0U){
		(void)x_enable_int(intno);
	}
}

/*
 *  CPU�㳰��ȯ�������Υ�����
 *
 *  CPU�㳰�ϥ�ɥ���椫�顤CPU�㳰����ݥ��󥿡�p_excinf�ˤ�����Ȥ�
 *  �ƸƤӽФ����Ȥǡ�CPU�㳰��ȯ�������򥷥��ƥ���˽��Ϥ��롥
 */
#ifdef SUPPORT_XLOG_SYS

void
xlog_sys(void *p_excinf)
{    
}

#endif /* SUPPORT_XLOG_SYS */

#ifndef OMIT_DEFAULT_EXC_HANDLER

/*
 * ̤������㳰�����ä����ν���
 */
void
default_exc_handler(void *p_excinf){
	syslog(LOG_EMERG, "Unregistered Exception occurs.");
	syslog(LOG_EMERG, " MSR = 0x%x, PC = 0x%x, IPM = %d.",
		   *(((uint32_t*)p_excinf) + CPUEXC_FLM_MSR),
		   *(((uint32_t*)p_excinf) + CPUEXC_FLM_PC),
		   *(((uint32_t*)p_excinf) + CPUEXC_FLM_IPM));
	syslog(LOG_EMERG, " ESR = 0x%x. EAR = 0x%x",
			 *(((uint32_t*)p_excinf) + CPUEXC_FLM_ESR),
			 *(((uint32_t*)p_excinf) + CPUEXC_FLM_EAR));
	syslog(LOG_EMERG, " Interrupt/Exception Nest Count = %d",
			 *(((uint32_t*)p_excinf) + CPUEXC_FLM_NEST));

	target_exit();
}

#endif /* OMIT_DEFAULT_EXC_HANDLER */

#ifndef OMIT_DEFAULT_INT_HANDLER

/*
 * ̤����γ���ߤ����ä����ν���
 */
void
default_int_handler(void *p_excinf){
	syslog(LOG_EMERG, "Unregistered Interrupt 0x%x occurs.",
		   *((int*)p_excinf));
	target_exit();
}

#endif /* OMIT_DEFAULT_INT_HANDLER */
