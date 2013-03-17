/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2002-2008 by Y.D.K Co.,Ltd
 *  Copyright (C) 2010 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN 
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
 *  @(#) $Id: prc_config.h 5 2012-01-14 09:35:55Z tetsuya $
 */

/*
 *		�ץ��å���¸�⥸�塼���SH34�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�target_config.h�ʤޤ��ϡ��������饤��
 *  �롼�ɤ����ե�����ˤΤߤ��饤�󥯥롼�ɤ���롥¾�Υե����뤫��
 *  ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
 */

#ifndef TOPPERS_PRC_CONFIG_H
#define TOPPERS_PRC_CONFIG_H

#include "microblaze.h"

/*
 *  �㳰�θĿ�
 */  
#define TNUM_EXCH  20U

/*
 *  ����ߥϥ�ɥ��ֹ�˴ؤ������
 */ 
#define TMIN_INHNO 0U
#define TMAX_INHNO 31U
#define TNUM_INH   32U

/*
 *  ������ֹ�˴ؤ������
 */ 
#define TMIN_INTNO 0U
#define TMAX_INTNO 31U
#define TNUM_INT   32U

/*
 *  �����ͥ���٤θĿ�
 */
#define  TNUM_INT_PRI  8U

/*
 *  ������ֹ���ϰϤ�Ƚ��
 *
 *  �ӥåȥѥ���������Τ��ưפˤ��뤿��ˡ�8�Ϸ��֤ˤʤäƤ��롥
 */
#define VALID_INTNO(intno) (TMIN_INTNO <= (intno) && (intno) <= TMAX_INTNO)
#define VALID_INTNO_DISINT(intno)	VALID_INTNO(intno)
#define VALID_INTNO_CFGINT(intno)	VALID_INTNO(intno)
#define VALID_INTNO_ATTISR(intno)   VALID_INTNO(intno)

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �󥿥�������ƥ������ѤΥ����å����ϥ��ɥ쥹����ޥ���
 */
#define TOPPERS_ISTKPT(istk, istksz) ((STK_T *)((char *)(istk) + (istksz)))

/*
 *  ����������ƥ����ȥ֥�å������
 */
typedef struct task_context_block {
	void	*sp;		/* �����å��ݥ��� */
	FP		pc;			/* �ץ���५���� */
} TSKCTXB;
 
/*
 *  �ץ��å����ü�̿��Υ���饤��ؿ����
 */
#include "prc_insn.h"

/*
 *  TOPPERSɸ�����߽�����ǥ�μ¸�
 *
 *  �����ͥ�������γ���ߤ��ߤ��ʤ���
 */

/*
 * �㳰�ʳ����/CPU�㳰�ˤΥͥ��Ȳ���Υ������
 * ����ƥ����Ȼ��ȤΤ���˻���
 */
extern uint32_t except_nest_count; /* �㳰�ʳ����/CPU�㳰�ˤΥͥ��Ȳ���Υ������ */

/*
 *  ����ƥ����Ȥλ���
 *
 *   �㳰�ʳ����/CPU�㳰�ˤΥͥ��Ȳ���򥫥���Ȥ����ѿ���except_nest_count�ˤ�
 *   �Ѱդ����㳰��������ǥ��󥯥���Ȥ��뤳�Ȥǡ�����ƥ����Ȥ�Ƚ�ꤹ�롥
 */
Inline bool_t
sense_context(void)
{
    return(except_nest_count > 0U);
}

/*
 *  CPU��å����֤ؤΰܹ�
 */
Inline void
x_lock_cpu(void)
{
	set_msr(current_msr() & ~MSR_IE);
	/* ����ƥ����륻������������ǥ��꤬�񤭴�����ǽ�������� */
	Asm("":::"memory");
}

#define t_lock_cpu()   x_lock_cpu()
#define i_lock_cpu()   x_lock_cpu()

/*
 *  CPU��å����֤β��
 */
Inline void
x_unlock_cpu(void)
{
	/* ����ƥ����륻������������ǥ��꤬�񤭴�����ǽ�������� */
	Asm("":::"memory");
	set_msr(current_msr() | MSR_IE);
}

#define t_unlock_cpu() x_unlock_cpu()
#define i_unlock_cpu() x_unlock_cpu()

/*
 *  CPU��å����֤λ���
 */
Inline bool_t
x_sense_lock(void)
{
	return((current_msr() & MSR_IE) == 0U);
}

#define t_sense_lock()    x_sense_lock()
#define i_sense_lock()    x_sense_lock()

/*
 *  ����ߥϥ�ɥ����Ͽ�ѥơ��֥�
 *   ���֤ϥ���ե�����졼������������ 
 */
extern const FP inh_tbl[TNUM_INH];

/*
 *  ����ߥϥ�ɥ������
 */
Inline void
x_define_inh(INHNO inhno, FP int_entry)
{
}

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 */
#define INT_ENTRY(inhno, inthdr)    inthdr
#define INTHDR_ENTRY(inhno, inhno_num, inthdr) extern void inthdr(void);

/*
 * �Ƴ���ߤγ�����׵�ػߥե饰�ξ���
 */
extern uint32_t idf;

/*
 *  �����ͥ���٥ޥ������饤�֥��
 *
 *  XPS Interrupt Controller �ϳ����ͥ���٤γ�ǰ���ʤ����ᡤ
 *  ���եȥ������ǵ���Ū�˼¸����롥 
 */

/*
 *  ���ߤγ����ͥ���٥ޥ������͡�����ɽ����
 */
extern uint8_t iipm;

/*
 *  �����ͥ���٥ޥ�����˥��åȤ��롤������׵�ػߥե饰����
 *  �Υơ��֥��kernel_cfg.c��
 */
extern const uint32_t iipm_mask_tbl[TNUM_INT_PRI];

/*
 *  IPM��imp_mask_tbl�Υ���ǥå������Ѵ�����ޥ���
 */
#define INDEX_IPM(ipm)  (-(ipm))

/*
 *  �����ͥ���٥ޥ����γ���ɽ��������ɽ�����Ѵ�
 *
 */
#define EXT_IPM(iipm)    (-((PRI)(iipm)))       /* ����ɽ������ɽ���� */
#define INT_IPM(ipm)     ((uint8_t)(-(ipm)))    /* ����ɽ��������ɽ���� */

/*
 *  (��ǥ���)�����ͥ���٥ޥ���������
 * 
 *  ���ꤵ�줿ͥ���٤����ꤵ�줿������׵�ػߥե饰�Υơ��֥���ͤȡʥ��
 *  ���Ρ˳Ƴ���ߤγ�����׵�ػߥե饰�ξ��֤��ݻ������ѿ����ͤȤ�
 *  OR��IRC�γ�����׵�ػߥե饰�˥��åȤ������ꤷ��ͥ���٤������ѿ�
 *  ipm����¸���롥
 */
Inline void
x_set_ipm(PRI intpri)
{
	uint32_t ipm_mask = iipm_mask_tbl[INT_IPM(intpri)];

	/*
	 *  XPS INTC �γ���ߥ���ȥ���ϥ��͡��֥�쥸������
	 *  ���ꥢ���쥸���������뤿�ᡤ��ö���Ƥγ���ߤ�ػߤ��Ƥ��顤
	 *  ����γ���ߤΤߵ��Ĥ���ɬ�פ�����
	 */
	/* ������߶ػ� */
	xintc_disable_int(~0U);

	/* �ޥ������ꤵ��Ƥ��ʤ�����ߤΤߵ��� */
	xintc_enable_int(~(ipm_mask|idf));

	iipm = INT_IPM(intpri);
}

#define t_set_ipm(intpri) x_set_ipm(intpri)
#define i_set_ipm(intpri) x_set_ipm(intpri)

/*
 *  (��ǥ���)�����ͥ���٥ޥ����λ���
 *
 *  ipm���ͤ��֤�
 */
Inline PRI
x_get_ipm(void)
{
    return(EXT_IPM(iipm));
}

#define t_get_ipm() x_get_ipm()
#define i_get_ipm() x_get_ipm()

/*
 *  �����°�������ꤵ��Ƥ��뤫��Ƚ�̤��뤿����ѿ�
 */
extern uint32_t	bitpat_cfgint;

/*
 * �ʥ�ǥ��Ρ˳�����׵�ػߥե饰�Υ��å�
 *
 *  ���ꤵ�줿��������ֹ�γ�����׵�ػߥե饰�Υ��åȤ��ơ�����ߤ�
 *  �ػߤ��롥�ޤ����ʥ�ǥ��Ρ˳�����׵�ػߥե饰���������idf����
 *  ������ӥåȤ�򥻥åȤ��롥
 *  ������׵��ޥ������뵡ǽ�򥵥ݡ��Ȥ��Ƥ��ʤ����ˤϡ�false���֤�
 */
Inline bool_t
x_disable_int(INTNO intno)
{
    if ((bitpat_cfgint & INTNO_BITPAT(intno)) == 0U) {
        return(false);
    }
    xintc_disable_int(INTNO_BITPAT(intno));
    idf |= INTNO_BITPAT(intno);
    return(true);
}

#define t_disable_int(intno)  x_disable_int(intno)
#define i_disable_int(intno)  t_disable_int(intno)

/* 
 * (��ǥ���)����׵�ػߥե饰�β��
 *
 * ���ꤵ�줿��������ֹ�γ�����׵�ػߥե饰�Υ��ꥢ���ơ�����ߤ�
 * ���Ĥ��롥�ޤ����ʥ�ǥ��Ρ˳�����׵�ػߥե饰���������idf����
 * ������ӥåȤ�򥯥ꥢ���롥
 * ������׵��ޥ������뵡ǽ�򥵥ݡ��Ȥ��Ƥ��ʤ����ˤϡ�false���֤�
 */
Inline bool_t
x_enable_int(INTNO intno)
{
    if ((bitpat_cfgint & INTNO_BITPAT(intno)) == 0U) {
        return(false);
    }    
    xintc_enable_int(INTNO_BITPAT(intno));
    idf &= ~INTNO_BITPAT(intno);
    return(true);
}

#define t_enable_int(intno) x_enable_int(intno)
#define i_enable_int(intno) x_enable_int(intno)

/*
 * ������׵�Υ��ꥢ
 */
Inline void
x_clear_int(INTNO intno)
{
	xintc_ack_int(INTNO_BITPAT(intno));
}

#define t_clear_int(intno) x_clear_int(intno) 
#define i_clear_int(intno) x_clear_int(intno) 


/*
 *  ������׵�Υ����å�
 */
Inline bool_t
x_probe_int(INTNO intno)
{
    return(xintc_probe_int(INTNO_BITPAT(intno)));
}

#define t_probe_int(intno) x_probe_int(intno)
#define i_probe_int(intno) x_probe_int(intno)

/*
 *  ������׵�饤���°��������
 */
extern void x_config_int(INTNO intno, ATR intatr, PRI intpri);

/*
 *  �����°���ơ��֥��kernel_cfg.c��
 */
extern ATR intatr_tbl[TNUM_INT];

/*
 *  ����ߥϥ�ɥ���������ɬ�פ�IRC���
 */
Inline void
i_begin_int(INTNO intno)
{
    /* ���å��ȥꥬ(TA_EDGE)�ʤ����ߤ򥯥ꥢ */
    if((intatr_tbl[intno] & TA_EDGE) == TA_EDGE)
    {
        xintc_ack_int(INTNO_BITPAT(intno));    
	}
}

/*
 *  ����ߥϥ�ɥ�νи���ɬ�פ�IRC���
 */
Inline void
i_end_int(INTNO intno)
{
	/* ��٥�ȥꥬ�ʤ����ߤ򥯥ꥢ */
	if((intatr_tbl[intno] & TA_EDGE) != TA_EDGE)
    {
		xintc_ack_int(INTNO_BITPAT(intno));    
	}
}

/*
 *  ̤����γ���ߤ����ä����ν���
 */
extern void default_int_handler(void *p_exinf);


/*
 *  CPU�㳰��ǽ
 */

/*
 *  CPU�㳰�ե졼��Υ��ե��å�
 */
#define CPUEXC_FLM_MSR  0x00U
#define CPUEXC_FLM_ESR  0x01U
#define CPUEXC_FLM_EAR  0x02U
#define CPUEXC_FLM_NEST 0x03U
#define CPUEXC_FLM_PC   0x04U
#define CPUEXC_FLM_IPM  0x05U

/*
 *  CPU�㳰�ϥ�ɥ����Ͽ�ѥơ��֥�
 */
extern const FP exch_tbl[TNUM_EXCH];

/*
 * �������å����¸���˴ޤޤ��ɸ����㳰������ǽ�ν�����������Ѥ��ʤ�
 */
#define OMIT_INITIALIZE_EXCEPTION

/*
 * CPU�㳰�ϥ�ɥ�ν����
 */
Inline void
initialize_exception(void)
{
}

/*
 *  CPU�㳰��ȯ���������Υ����ƥ���֤λ���
 */

/*
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥλ���
 *
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥ�������������ƥ����Ȥλ���false��
 *  �����Ǥʤ�����true���֤���
 */
Inline bool_t
exc_sense_context(void *p_excinf)
{
	return((*(((uint32_t *)p_excinf) + CPUEXC_FLM_NEST) != 0U));
}

/*
 *  CPU�㳰��ȯ����������(��ǥ���)�����ͥ���٥ޥ����λ���
 */
Inline uint8_t
exc_get_ipm(void *p_excinf)
{
	return((uint8_t)(*(((uint32_t *)p_excinf) + CPUEXC_FLM_IPM)));
}

/*
 * CPU�㳰��ȯ������������CPU��å����֤λ���
 *
 *  CPU��å����֤ξ���true��CPU��å�������֤ξ��ˤ�false���֤�
 */
Inline bool_t
exc_sense_lock(void *p_excinf){
	return((*(((uint32_t *)p_excinf) + CPUEXC_FLM_MSR) & MSR_IE) != MSR_IE);
}

/*
 * ����ߥ�å����֤�
 */
Inline bool_t
exc_sense_int_lock(void *p_excinf){
	return false;
}

/*
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥȳ���ߤΥޥ������֤λ���
 *
 *  CPU�㳰��ȯ���������Υ����ƥ���֤��������ͥ�¹���Ǥʤ�����������
 *  ��ƥ����ȤǤ��ꡤ����ߥ�å����֤Ǥʤ���CPU��å����֤Ǥʤ����ʥ�
 *  �ǥ��Ρ˳����ͥ���٥ޥ�����������֤Ǥ������true�������Ǥʤ���
 *  ��false���֤���CPU�㳰�������ͥ�������γ���߽������ȯ���������
 *  �ˤ�false���֤��ˡ�
 *
 */
Inline bool_t
exc_sense_intmask(void *p_excinf)
{
	return(!exc_sense_context(p_excinf)
		   && (exc_get_ipm(p_excinf) == 0U)
		   && !exc_sense_lock(p_excinf)
		   && !exc_sense_int_lock(p_excinf));
}

/*
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥȳ���ߡ�CPU��å����֤λ���
 *
 *  CPU�㳰��ȯ���������Υ����ƥ���֤��������ͥ�¹���Ǥʤ�����������
 *  ��ƥ����ȤǤ��ꡤ����ߥ�å����֤Ǥʤ���CPU��å����֤Ǥʤ�����
 *  true�������Ǥʤ�����false���֤���CPU�㳰�������ͥ�������γ���߽�
 *  �����ȯ���������ˤ�false���֤��ˡ�
 *
 */
Inline bool_t
exc_sense_unlock(void *p_excinf)
{
	return(!exc_sense_context(p_excinf)
		   && !exc_sense_lock(p_excinf)
		   && !exc_sense_int_lock(p_excinf));
}

/*
 *  �ץ��å���¸�ν����
 */
extern void prc_initialize(void);

/*
 *  �ץ��å���¸�ν�λ������
 */
extern void prc_terminate(void);

/*
 *  ̤������㳰�����ä����ν���
 */
extern void default_exc_handler(void *p_excinf);

/*
 *  �������ǥ����ѥå���
 */

/*
 *  �ǹ�ͥ���̥������ؤΥǥ����ѥå���core_support.S��
 *
 *  dispatch�ϡ�����������ƥ����Ȥ���ƤӽФ��줿�����ӥ������������
 *  ��ƤӽФ��٤���Τǡ�����������ƥ����ȡ�CPU��å����֡��ǥ����ѥ�
 *  �����ľ��֡��ʥ�ǥ��Ρ˳����ͥ���٥ޥ�����������֤ǸƤӽФ���
 *  ����Фʤ�ʤ���
 */
extern void dispatch(void);

/*
 *  �ǥ����ѥå����ư��ϡ�core_support.S��
 *
 *  start_dispatch�ϡ������ͥ뵯ư���˸ƤӽФ��٤���Τǡ����٤Ƥγ��
 *  �ߤ�ػߤ������֡ʳ���ߥ�å����֤�Ʊ���ξ��֡ˤǸƤӽФ��ʤ����
 *  �ʤ�ʤ���
 */
extern void start_dispatch(void) NoReturn;

/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå���core_support.S��
 *
 *  exit_and_dispatch�ϡ�ext_tsk����ƤӽФ��٤���Τǡ�����������ƥ�
 *  ���ȡ�CPU��å����֡��ǥ����ѥå����ľ��֡��ʥ�ǥ��Ρ˳����ͥ��
 *  �٥ޥ�����������֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void exit_and_dispatch(void) NoReturn;

/*
 *  �����ͥ�ν�λ�����θƽФ���core_support.S��
 *
 *  call_exit_kernel�ϡ������ͥ�ν�λ���˸ƤӽФ��٤���Τǡ��󥿥���
 *  ����ƥ����Ȥ��ڤ괹���ơ������ͥ�ν�λ������exit_kernel�ˤ�Ƥӽ�
 *  ����
 */
extern void call_exit_kernel(void) NoReturn;

/*
 *  ����������ƥ����Ȥν����
 *
 *  ���������ٻ߾��֤���¹ԤǤ�����֤˰ܹԤ�����˸ƤФ�롥���λ���
 *  �ǥ����å��ΰ��ȤäƤϤʤ�ʤ���
 *
 *  activate_context�򡤥���饤��ؿ��ǤϤʤ��ޥ�������Ȥ��Ƥ���Τϡ�
 *  ���λ����Ǥ�TCB���������Ƥ��ʤ�����Ǥ��롥
 */
extern void    start_r(void);

#define activate_context(p_tcb)                                         \
{                                                                       \
    (p_tcb)->tskctxb.sp = (void *)((char *)((p_tcb)->p_tinib->stk)      \
                                        + (p_tcb)->p_tinib->stksz);     \
    (p_tcb)->tskctxb.pc = (FP)start_r;                                  \
}

/*
 *  calltex�ϻ��Ѥ��ʤ�
 */
#define OMIT_CALLTEX

/*
 *  atexit�ν����ȥǥ��ȥ饯���μ¹�
 */
Inline void
call_atexit(void)
{
    extern void    software_term_hook(void);
    void (*volatile fp)(void) = software_term_hook;

    /*
     *  software_term_hook�ؤΥݥ��󥿤򡤰�övolatile����Τ���fp����
     *  �����Ƥ���Ȥ��Τϡ�0�Ȥ���Ӥ���Ŭ���Ǻ������ʤ��褦�ˤ��뤿
     *  ��Ǥ��롥
     */
    if (fp != 0) {
        (*fp)();
    }
}
#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_PRC_CONFIG_H */
