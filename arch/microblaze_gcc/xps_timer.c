/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2002-2008 by Y.D.K Co.,Ltd
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
 *  @(#) $Id: xps_timer.c 1433 2009-01-21 15:43:24Z ydkinc-matsumoto $
 */

/*
 *  �����ޥɥ饤�С�XPS Timer/Counter��
 */

#include "kernel_impl.h"
#include "time_event.h"
#include <sil.h>
#include "target_timer.h"
 
/*
 *  �����ޤε�ư����
 */
void
target_timer_initialize(intptr_t exinf)
{
	CLOCK    cyc = TO_CLOCK(TIC_NUME, TIC_DENO);

	/*
	 *  �����޼��������ꤷ�������ޤ�ư��򳫻Ϥ��롥
	 */

	/*
	 * ��������ߡ������ߥ��ꥢ
	 */
	sil_wrw_mem((void*)XTIMER_TCSR0, XTIMER_TCSR_INT_BIT);

	/* �����޾���ͤΥ����å� */
	assert(cyc <= MAX_CLOCK);

	/* ��������ͥ��å� */
	sil_wrw_mem((void*)XTIMER_TLR0, cyc);

	/*
	 * �������ͥ���
	 */
	sil_wrw_mem((void*)XTIMER_TCSR0, XTIMER_TCSR_LOAD_BIT);

	/*
	 * ������0���͡��֥롤����ߵ��ġ������ȥ���ɡ������󥫥���ȡ�
	 * �����ͥ��⡼�� 
	 */
	sil_wrw_mem((void*)XTIMER_TCSR0,
				(XTIMER_TCSR_ENT_BIT | XTIMER_TCSR_ENIT_BIT |
				  XTIMER_TCSR_ARHT_BIT |
				   XTIMER_TCSR_UDT_BIT));
}

/*
 *  �����ޤ���߽���
 */
void
target_timer_terminate(intptr_t exinf)
{
	/*
	 * ��������ߡ������ߥ��ꥢ
	 */
	sil_wrw_mem((void*)XTIMER_TCSR0, XTIMER_TCSR_INT_BIT);
}

/*
 *  �����޳���ߥϥ�ɥ�
 */
void
target_timer_handler(void)
{
	/* �������׵�򥯥ꥢ */
	sil_wrw_mem((void*)XTIMER_TCSR0, sil_rew_mem((void*)XTIMER_TCSR0));
    
	i_begin_int(INTNO_TIMER);
	/* ������ƥ��å��ζ��� */
	signal_time();              
	i_end_int(INTNO_TIMER);
}
