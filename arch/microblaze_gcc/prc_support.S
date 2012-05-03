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
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ��������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ��������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id: prc_support.S 1776 2010-04-05 11:12:59Z ertl-honda $
 */

/*
 *  �ץ����å���¸�⥸�塼�� ������֥��������Microblaze�ѡ�
 */

#define TOPPERS_MACRO_ONLY
#define UINT_C(val)		(val)		/* uint_t�����������ޥ��� */
#define ULONG_C(val)	(val)		/* ulong_t�����������ޥ��� */
#define CAST(type, val)	(val)		/* �����㥹�Ȥ�Ԥ��ޥ��� */

/*
 *  ������֥��ѤΥޥ�����ͭ���ˤ���
 */
#define TOPPERS_ASM_MACRO
#include "kernel_impl.h"
#include "offset.h"
#include "microblaze_asm.inc"

/*
 * �٥����ơ��֥�
 */
	.section .vectors.reset,"a"
	.global vectors_reset
vectors_reset:
	brai start           /* 0x00-0x04 Reset       */

	.section .vectors.sw_exception,"a"
	.global vectors_sw_exception
vectors_sw_exception:
	brai usrexcept_entry /* 0x08-0x0C User Vector */

	.section .vectors.interrupt,"a"
	.global vectors_interrupt
vectors_interrupt:
	brai interrupt_entry /* 0x10-14 Interrupt     */

	.section .vectors.hw_exception,"a"
	.global vectors_hw_exception
vectors_hw_exception:
	brai hwexcept_entry  /* 0x20-0x24 Break       */

	.section .vectors.reserve,"a"
	.global vectors_reserve
vectors_reserve:
	nop                  /* 0x28 Reserved         */
	nop                  /* 0x2C Reserved         */
	nop                  /* 0x30 Reserved         */
	nop                  /* 0x34 Reserved         */
	nop                  /* 0x38 Reserved         */
	nop                  /* 0x3C Reserved         */
	nop                  /* 0x40 Reserved         */
	nop                  /* 0x44 Reserved         */
	nop                  /* 0x48 Reserved         */
	nop                  /* 0x4C Reserved         */


/*
 *  �桼�����㳰����ȥ�
 *  ����ͤ�r15�����äƤ���Ȥ��ƥ꥿����
 */
	.text
	.global usrexcept_entry
	.align 2
usrexcept_entry:
	rtsd r15, 8
	 nop


/*
 *  �㳰����ȥ�
 */
	.text
	.global hwexcept_entry
	.align 2
hwexcept_entry:
	/*
	 * ����ƥ����Ȥ���¸
	 * ����襢�ɥ쥹��R17�⤷����BTR�����äƤ��롥
	 * �и��Υ����ɤ����ߤȶ��̲����뤿�ᡤR14�γ�Ǽ����
	 * ��¸���롥
	 */
	addik r1,r1,-64
	swi   r3,  r1, 60
	swi   r4,  r1, 56
	swi   r5,  r1, 52
	swi   r6,  r1, 48
	swi   r7,  r1, 44
	swi   r8,  r1, 40
	swi   r9,  r1, 36
	swi   r10, r1, 32
	swi   r11, r1, 28
	swi   r12, r1, 24
	swi   r17, r1, 20
	swi   r15, r1, 16
	swi   r16, r1, 12
	swi   r14, r1, 8
	swi   r18, r1, 4
	mfs   r3,  rmsr
	swi   r3,  r1, 0       /* �������Ѥ���¸ */

	/*
	 *  �ٱ䥹���åȤǳ���ߤ�ȯ���������ˤϡ�����襢�ɥ쥹�ϡ�
	 *  BTR�˳�Ǽ����롥  
	 */
	mfs   r7,  resr        /* ESR ����� */
	andi  r4,  r7, ESR_DS  /* DS�ӥåȤ����åȤ���Ƥ���� */
	beqi  r4,  no_dslot    /* �ǥ��쥤�����åȤǤϤʤ�     */
	mfs   r5,  rbtr        /* BTR ����� */
	swi   r5,  r1, 20      /* ����襢�ɥ쥹�Ȥ�����¸     */
	Mov   r17, r5          /* �㳰�ե졼�������뤿��r17����¸ */

no_dslot:
	/* 
	 * ����ߡ��㳰�Υͥ��Ȳ����1�ʾ�ʤ饹���å����ڤ��ؤ��ʤ� 
	 */
	lwi   r5,  r13, except_nest_count
	bgti  r5,  nest_int_exc      

	/*
	 * �����å��ݥ����ڤ��ؤ�
	 */
	lwi   r4,  r2, _kernel_istkpt /* �󥿥�������ƥ������ѤΥ����å����ɤ߹��� */
	addik r4,  r4, -4             /* �����å��ݥ��󥿤�ǥ������   */
	sw    r1,  r0, r4             /* �����������å�����¸             */
	Mov   r1,  r4                 /* �����å��ݥ����ڤ��ؤ�         */

nest_int_exc:
	/* 
	 * ����ߡ��㳰�Υͥ��Ȳ���Υ��󥯥����
	 */
	addi  r6,  r5,  1 
	swi   r6,  r13, except_nest_count

	/*
	 * �㳰�ե졼��κ���    
	 *     ����                       ���ե��å�
	 *    MSR(r3)                         0
	 *    ESR(r7)                         4
	 *    EAR(r6)                         8
	 *    ����ߡ��㳰�ͥ��ȥ������(r5) 12
	 *    ��ꥢ�ɥ쥹(r17)              16
	 *    �����ͥ���٥ޥ���             20
	 */
	mfs   r4,  rear
	lbui  r6,  r13, iipm
	addik r1,  r1,  -24
	swi   r6,  r1,   20 
	swi   r17, r1,   16 
	swi   r5,  r1,   12 
	swi   r4,  r1,    8
	swi   r7,  r1,    4
	swi   r3,  r1,    0

	/*
	 *  �㳰�ե졼�����Ƭ���Ϥ�CPU�㳰�ϥ�ɥ�ΰ���������
	 */
	Mov   r5,  r1         

	/*
	 *  CPU�㳰�ֹ�μ���
	 */
	andi  r6,  r7, ESR_EC

	/*
	 *  �㳰�ϥ�ɥ饢�ɥ쥹�μ���
	 */
	add   r8,  r6, r6              /* 4�ܤ��ƥ��ե��åȤ�����    */
	add   r8,  r8, r8
	lwi   r7,  r8, exch_tbl

	/*
	 * �㳰����(EE=1), �㳰�����楯�ꥢ(EIP=0)�Ȥ���
	 */   
	ori   r8,  r3, MSR_EE
	andi  r8,  r8, ~(MSR_EIP)
	mts   rmsr,r8

#ifdef LOG_EXC_ENTER
	Push  r6         /* CPU�㳰�ֹ���¸               */
	Push  r7         /* CPU�㳰�ϥ�ɥ饢�ɥ쥹��¸   */
	Push  r5         /* CPU�㳰�ե졼�����Ƭ������¸ */
	brlid r15, log_exc_enter
	 Mov   r5, r6    /* CPU�㳰�ֹ������ˤ���       */
	Pop   r5         /* CPU�㳰�ե졼�����Ƭ�������� */
	Pop   r7        /* CPU�㳰�ϥ�ɥ饢�ɥ쥹����   */
#endif /* LOG_EXC_ENTER */

	/* 
	 *  CPU�㳰�ϥ�ɥ�ƤӽФ� 
	 */
	brald r15, r7             
	 nop

#ifdef LOG_EXC_LEAVE
	brlid r15, log_exc_leave
	 Pop   r5         /* CPU�㳰�ֹ�����               */
#endif /* LOG_EXC_LEAVE */

	/*
	 *  ����߶ػ�
	 */
	mfs   r3,  rmsr            
	andi  r3,  r3, ~MSR_IE
	mts   rmsr,r3

	/*
	 *  �㳰�ե졼���ΤƤ�
	 */
	addik r1,  r1,  20
	bri   ret_exc


/*
 *  ����ߥ���ȥ�
 */
	.text
	.global interrupt_entry
	.align 2
interrupt_entry:
	/*
	 * ����ƥ����Ȥ���¸
	 */
	addik r1,r1,-64
	swi   r3,  r1, 60
	swi   r4,  r1, 56
	swi   r5,  r1, 52
	swi   r6,  r1, 48
	swi   r7,  r1, 44
	swi   r8,  r1, 40
	swi   r9,  r1, 36
	swi   r10, r1, 32
	swi   r11, r1, 28
	swi   r12, r1, 24
	swi   r14, r1, 20
	swi   r15, r1, 16
	swi   r16, r1, 12
	swi   r17, r1, 8
	swi   r18, r1, 4

	/* 
	 * msr����¸ 
	 */
	mfs   r3,  rmsr
	swi   r3,  r1, 0

	/* 
	 * ����ߡ��㳰�Υͥ��Ȳ����1�ʾ�ʤ饹���å����ڤ��ؤ��ʤ� 
	 */
	lwi   r5,  r13, except_nest_count
	bgti  r5,  nest_int      

	/*
	 * �����å��ݥ����ڤ��ؤ�
	 */
	lwi   r4,  r2, _kernel_istkpt /* �󥿥�������ƥ������ѤΥ����å����ɤ߹��� */
	addik r4,  r4, -4             /* �����å��ݥ��󥿤�ǥ������   */
	sw    r1,  r0, r4             /* �����������å�����¸             */
	Mov   r1,  r4                 /* �����å��ݥ����ڤ��ؤ�         */


nest_int:
	/* 
	 * ����ߡ��㳰�Υͥ��Ȳ���Υ��󥯥����
	 */
	addi  r5,  r5,  1 
	swi   r5,  r13, except_nest_count
                    
	/*
	 *  �������װ��μ���
	 *  R5�����졤default_int_handler() �ΰ����Ȥ��롥
	 */
	lwi   r5,  r0, XINTC_IVR       /* ������ֹ���ɤ߹���             */

	/*
	 *  ������װ��γ����ͥ���٤���(��ǥ���)�����ͥ���٥ޥ����򥻥å�
	 *  ���롥�ޤ����κݡ��ϥ�ɥ�¹�����(��ǥ���)�����ͥ���٥ޥ�����
	 *  ��¸���롥
	 */
	lbui  r3,  r5,  inh_iipm_tbl  /* �����դ�������ߤγ����ͥ���٥ޥ�������� */
	lbui  r6,  r13, iipm          /* �����ȯ�����γ����ͥ���٥ޥ����򥹥��å�������� */
	Push  r6
	sbi   r3,  r13, iipm          /* (��ǥ���)�����ͥ���٥ޥ����򥻥å� */

	/*
	 *  XINTC������դ�������ߤγ����ͥ���٤��б�����
	 *  �ޥ����ӥåȤǥ��åȤ��롥
	 */
	add   r6,  r3, r3                /* �����ͥ���٥ޥ�����4�ܤ��ƥ��ե��åȤ�����    */
	add   r6,  r6, r6
	lwi   r7,  r6, iipm_mask_tbl     /* �����ͥ���٥ޥ������б���������߶ػߥѥ����� */
	lwi   r8,  r13, idf              /* �Ƴ���ߤγ�����׵�ػߥե饰�ξ��֤����     */
	or    r7,  r7,  r8               /* ξ�Ԥ�OR������                                 */
	xori  r7,  r7, -1                /* ȿž                                           */
	swi   r7,  r0, XINTC_IER         /* ���ꤷ������ߤΤߵ���                         */

	/*
	 *  ����ߥϥ�ɥ�Υ��ɥ쥹���ɤ߹���
	 */
	add   r4,  r5,  r5               /* ������ֹ��4�ܤ��ƥ��ե��åȤ�����  */
	add   r4,  r4,  r4
	lwi   r6,  r4, inh_tbl           

	/*
	 *  ����ߵ���
	 */
	mfs   r3,  rmsr
	ori   r3,  r3, MSR_IE
	mts   rmsr,r3

#ifdef LOG_INH_ENTER
	Push  r6           /* �ϥ�ɥ饢�ɥ쥹����¸ */
	Push  r5           /* ������ֹ����¸ */
	brlid r15, log_inh_enter
	 nop   
	Pop   r5           /* ������ֹ������ */
	Pop   r6           /* �ϥ�ɥ饢�ɥ쥹������ */
	Push  r5           /* ������ֹ����¸ */
#endif /* LOG_INH_ENTER */

	/* 
	 *  ����ߥϥ�ɥ�ƤӽФ� 
	 */
	brald r15, r6
	 nop

#ifdef LOG_INH_LEAVE
	Pop  r5           /* ������ֹ������ */     
	brlid r15, log_inh_leave
	 nop
#endif /* LOG_INH_LEAVE */

	/*
	 *  ����߶ػ�
	 */
	mfs   r3,  rmsr            
	andi  r3,  r3, ~MSR_IE
	mts   rmsr,r3

/*
 *  ����ߥϥ�ɥ�/CPU�㳰�ϥ�ɥ�и�����
 *
 *  ret_int�ϡ�����ߥϥ�ɥ餫����ä�ľ��˼¹Ԥ���롼����ǡ�
 *  ����ߥϥ�ɥ齪λ�塤�������åȰ�¸�ν�����¹Ԥ����塤
 *  �����ͥ�����γ���ߤ�ػߡ������å����������Υ����å��ˤ���
 *  ���֤ǸƤӽФ���롥
 */
	.global ret_int
	.global ret_exc
rer_int:
ret_exc:
	/*
	 *  (��ǥ���)�����ͥ���٥ޥ����򸵤��᤹
	 */
	Pop   r6
	sbi   r6,  r13, iipm             /* (��ǥ���)�����ͥ���٥ޥ����򥻥å� */
	add   r5,  r6,  r6               /* �����ͥ���٥ޥ�����4�ܤ��ƥ��ե��åȤ�����  */
	add   r5,  r5,  r5
	lwi   r7,  r5,  iipm_mask_tbl    /* �����ͥ���٥ޥ������б���������߶ػߥѥ����� */
	lwi   r8,  r13, idf              /* �Ƴ���ߤγ�����׵�ػߥե饰�ξ��֤���� */
	or    r8,  r7,  r8               /* ξ�Ԥ�OR������                             */
	xori  r8,  r8,  -1               /* IER�˥��åȤ��뤿���ȿž����              */
	swi   r8,  r0, XINTC_IER         /* ���ꤷ������ߤΤߵ���                     */

	/*
	 *  ����ߥͥ��Ȳ���Υǥ������
	 */
	lwi   r5,  r13, except_nest_count
	addi  r5,  r5,  -1 
	swi   r5,  r13, except_nest_count

	bgti  r5,  ret_int_1            /* �ͥ��Ȳ����1�ʾ�ʤ���� */

	lw    r1,  r0, r1               /* �����å��ݥ��󥿤��᤹    */  
	lwi   r4,  r13, reqflg          /* reqflg �Υ����å�         */
	beqi  r4,  ret_int_1            /* false �ʤ� �����������   */
	bri   ret_int_2                 /* true �ʤ� ret_int_2 ��    */

ret_int_1:
	lwi  r3,  r1, 0
	lwi  r18, r1, 4
	lwi  r17, r1, 8
	lwi  r16, r1, 12
	lwi  r15, r1, 16
	lwi  r14, r1, 20
	lwi  r12, r1, 24
	lwi  r11, r1, 28
	lwi  r10, r1, 32
	lwi  r9,  r1, 36
	lwi  r8,  r1, 40
	lwi  r7,  r1, 44
	lwi  r6,  r1, 48
	lwi  r5,  r1, 52
	lwi  r4,  r1, 56

	/*
	 *  CPU�㳰����Υ꥿���󤫤�Ƚ��
	 */
	andi r3,  r3, MSR_EIP
	bnei r3,  ret_int_1_EIP

	/*
	 *  ����ߤ���Υ꥿����
	 */
	lwi  r3,  r1, 0
	mts  rmsr,r3
	lwi  r3,  r1, 60
	rtid r14,0 
	 addik r1,r1,64

	/*
	 *  CPU�㳰����Υ꥿����
	 */
ret_int_1_EIP:
	lwi  r3,  r1, 0
	mts  rmsr,r3
	lwi  r3,  r1, 60
	rted r14,0 
	 addik r1,r1,64

	/*
	 *  ����ߥϥ�ɥ�/CPU�㳰�ϥ�ɥ�и�����1
	 * 
	 *  �����Ǥϡ�����褬�������Ǥ��ꡤ�����å��ϡ������������å��ξ�
	 *  �˥�����å��쥸�����Τߤ���¸���줿���֤ˤʤäƤ��롥�ޤ���
	 *  �ץ����å��ϡ������ѡ��Х������⡼�ɡ������ͥ�����γ���ߤ�ػ�
	 *  �������֤ȤʤäƤ��롥
	 */  
ret_int_2:
	swi  r0,  r13,  reqflg   /* reqflg �� false �� */

	/*
	 *  CPU���å����֤˰ܹԤ��롥
	 *
	 *  ���λ�����CPU���å����֤Ȥ���Τϡ�dispatcher��ʬ��������ȡ�
	 *  call_texrtn��ƤӽФ����ˡ�CPU���å����֤ˤʤäƤ���ɬ�פ�����
	 *  ����Ǥ��롥
	 *
	 *  Microbalze�Ǥϡ������ͥ�������γ���ߤ��ߤ��ʤ����ᡤ�����Ǥϡ�
	 *  �ä˲���Ԥ�ʤ���
	 */

	/*
	 *  dspflg��false�Ǥ�����ȡ�p_runtsk��p_schedtsk��Ʊ�����ˤϡ�
	 *  �ǥ����ѥå���Ԥ�ʤ������Υ����å���ɬ�פʤΤϡ��������㳰��
	 *  ���롼����θƽФ���ɬ�פʾ��ˡ��ǥ����ѥå���ɬ�פʤ��Ƥ⡤
	 *  reqflg��true�ˤ��뤿��Ǥ��롥
	 */
	lwi  r4,  r13,  p_runtsk   /* r4 <- p_runtsk        */
	lwi  r6,  r13,  dspflg     /* r6 <- dspflg          */
	beqi r6,  ret_int_3        /* dspflg �� false �ʤ� ret_int_3 �� */
	lwi  r5,  r13,  p_schedtsk /* r5 <- p_schedtsk                  */
	sub  r6,  r5,   r4         /* p_runtsk �� p_schedtsk ��Ʊ���ʤ� */
	beqi r6,  ret_int_3        /* ret_int_3 ��                      */
	addi  r1,  r1,  -52        /* �Ĥ�Υ쥸��������¸����          */
	swi   r19, r1,  48
	swi   r20, r1,  44
	swi   r21, r1,  40
	swi   r22, r1,  36
	swi   r23, r1,  32
	swi   r24, r1,  28
	swi   r25, r1,  24
	swi   r26, r1,  20
	swi   r27, r1,  16
	swi   r28, r1,  12
	swi   r29, r1,  8
	swi   r30, r1,  4
	swi   r31, r1,  0
	swi   r1 , r4,  TCB_sp     /* �����������å���TCB����¸ */
	la    r6 , r0,  ret_int_r  /* �¹ԺƳ����Ϥ���¸ */
	swi   r6 , r4,  TCB_pc     /* �¹ԺƳ����Ϥ�TCB����¸   */
	bri   dispatcher

	/*
	 *  ����ߡ��㳰�ǥ���ƥ�������¸�������������롼����
	 */
ret_int_r:
	lwi  r31,  r1,  0      
	lwi  r30,  r1,  4
	lwi  r29,  r1,  8
	lwi  r28,  r1,  12
	lwi  r27,  r1,  16
	lwi  r26,  r1,  20
	lwi  r25,  r1,  24
	lwi  r24,  r1,  28
	lwi  r23,  r1,  32
	lwi  r22,  r1,  36
	lwi  r21,  r1,  40
	lwi  r20,  r1,  44
	lwi  r19,  r1,  48
	addi r1,   r1,  52
	lwi  r3,   r1,   0
	mts  rmsr, r3                

ret_int_3:
	/*
	 * �������㳰�롼����ε�ư
	 * ret_int_r �� dispatcher ����ƤӽФ���뤿�ᡤ
	 * tcb �Υ��ɥ쥹�� r4 �����äƤ���
	 */
	lbui r5,  r4,  TCB_enatex  /* r5 <- enatex                 */
	andi r6,  r5,  TCB_enatex_mask  
	beqi r6,  ret_int_4        /* enatex �� false �ʤ�꥿���� */
	lwi  r7,  r4,  TCB_texptn  /* r5 <- texptn                 */
	beqi r7,  ret_int_4        /* texptn �� 0 �Ǥʤ����       */
	brlid r15  call_texrtn     /* �������㳰�롼����θƤӽФ� */
	 nop

ret_int_4:
	lwi  r3,  r1, 0    /* MSR ���᤹�ʳ����IE=0�ǳ���߶ػߤˤʤ��*/
	lwi  r18, r1, 4
	lwi  r17, r1, 8
	lwi  r16, r1, 12
	lwi  r15, r1, 16
	lwi  r14, r1, 20
	lwi  r12, r1, 24
	lwi  r11, r1, 28
	lwi  r10, r1, 32
	lwi  r9,  r1, 36
	lwi  r8,  r1, 40
	lwi  r7,  r1, 44
	lwi  r6,  r1, 48
	lwi  r5,  r1, 52
	lwi  r4,  r1, 56

	/*
	 *  CPU�㳰����Υ꥿���󤫤�Ƚ��
	 */
	andi r3,  r3, MSR_EIP
	bnei r3,  ret_int_4_EIP

	/*
	 *  ����ߤ���Υ꥿����
	 */
	lwi  r3,  r1, 0
	mts  rmsr,r3
	lwi  r3,  r1, 60
	rtid r14,0 
	 addik r1,r1,64

	/*
	 *  CPU�㳰����Υ꥿����
	 */
ret_int_4_EIP:
	lwi  r3,  r1, 0
	mts  rmsr,r3
	lwi  r3,  r1, 60
	rted r14,0 
	 addik r1,r1,64


/*
 * �������ǥ����ѥå���
 */
	.global dispatch
	.align  2
dispatch:
	/*
	 *  ���Υ롼����ϡ�����������ƥ����ȡ�CPU���å����֡��ǥ����ѥå�
	 *  ���ľ��֡��ʥ�ǥ��Ρ˳����ͥ���٥ޥ�����������֤ǸƤӽФ�
	 *  ��롥
	 */
	addi  r1,  r1,  -64  /* ������å��쥸�����ʳ�����¸���� */
	swi   r15, r1,  60
	mfs   r3,  rmsr      /* msr����¸                        */
	swi   r3,  r1,  56                
	swi   r18, r1,  52   
	swi   r19, r1,  48
	swi   r20, r1,  44
	swi   r21, r1,  40
	swi   r22, r1,  36
	swi   r23, r1,  32
	swi   r24, r1,  28
	swi   r25, r1,  24
	swi   r26, r1,  20
	swi   r27, r1,  16
	swi   r28, r1,  12
	swi   r29, r1,  8
	swi   r30, r1,  4
	swi   r31, r1,  0
	lwi   r4 , r13, p_runtsk   /* r4 <- p_runtsk */
	swi   r1 , r4,  TCB_sp 	   /* �����������å���TCB����¸ */
	la    r5 , r0,  dispatch_r /* �¹ԺƳ����Ϥ���¸ */
	swi   r5 , r4,  TCB_pc     /* �¹ԺƳ����Ϥ�TCB����¸   */
	bri   dispatcher

dispatch_r:
	lwi  r31,  r1, 0      /* �쥸���������� */
	lwi  r30,  r1, 4
	lwi  r29,  r1, 8
	lwi  r28,  r1, 12
	lwi  r27,  r1, 16
	lwi  r26,  r1, 20
	lwi  r25,  r1, 24
	lwi  r24,  r1, 28
	lwi  r23,  r1, 32
	lwi  r22,  r1, 36
	lwi  r21,  r1, 40
	lwi  r20,  r1, 44
	lwi  r19,  r1, 48
	lwi  r18,  r1, 52
	lwi  r3,   r1, 56   
	mts  rmsr,r3            
	addi r1,   r1, 60   /* �����å��ݥ��󥿤��᤹ */

	/*
	 *  �������㳰�����롼����ε�ư
	 *  dispatch_r �� dispatcher ����ƤӽФ���뤿�ᡤ
	 *  tcb �Υ��ɥ쥹�� r4 �����äƤ���
	 */
	lbui r5,  r4,  TCB_enatex  /* r5 <- enatex                 */
	andi r6,  r5,  TCB_enatex_mask  
	beqi r6,  dispatch_r_1     /* enatex �� false �ʤ�꥿���� */
	lwi  r7,  r4,  TCB_texptn  /* r5 <- texptn                 */
	beqi r7,  dispatch_r_1     /* texptn �� 0 �Ǥʤ����       */
	brlid r15  call_texrtn     /* �������㳰�롼����θƤӽФ� */
	 nop
dispatch_r_1:
	Pop     r15
	rtsd	r15, 8
	 nop

/*
 *  �ǥ����ѥå����ư���
 */
    .globl start_dispatch
start_dispatch:
	/*
	 *  ���Υ롼����ϡ������ͥ뵯ư���ˡ����٤Ƥγ���ߤ�ػߤ�������
	 * �ʳ���ߥ��å����֤�Ʊ���ˤǸƤӽФ���롥�ޤ�������ߥ⡼�ɡ���
	 *  ����������ƥ����Ȥ�Ʊ���ˤǸƤӽФ���뤳�Ȥ����ꤷ�Ƥ��롥
	 *
	 *  dispatcher�ϡ�CPU���å����֡��ʥ�ǥ��Ρ˳����ͥ���٥ޥ�����
	 *  ������֡��㳰�ʳ����/CPU�㳰�ˤΥͥ��Ȳ��0�ǸƤӽФ���     
	 *  target_initialize�Ǥϡ��ʥ�ǥ��Ρ˳����ͥ���٥ޥ��������
	 *  �Ȥ��������ͥ�������γ���ߤǤ���FIQ����Ĥ��뤳�Ȥǡ�
	 *  CPU���å����֡��ʥ�ǥ��Ρ˳����ͥ���٥ޥ�����������֤ˤʤ롥
	 *  �ޤ���task_initialize��disdsp��false�˽�������Ƥ��뤿�ᡤ�ǥ�
	 *  ���ѥå����ľ��֤ˤʤäƤ��롥
	 */ 
	/* �㳰�ʳ����/CPU�㳰�ˤΥͥ��Ȳ���򥯥ꥢ */
	swi   r0,  r13, except_nest_count

/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå�
 */
    .globl exit_and_dispatch
exit_and_dispatch:
	/* �ǥ����ѥå������Ρ�dispatcher�ˤ� */  

/*
 *  �ǥ����ѥå�������
 */
dispatcher:
	/*
	 *  ���Υ롼����ϡ�����������ƥ����ȡ�CPU���å����֡��ǥ����ѥå�
	 *  ���ľ��֡��ʥ�ǥ��Ρ˳����ͥ���٥ޥ�����������֤ǸƤӽФ�
	 *  ��롥�¹ԺƳ����Ϥؤ⤳�ξ��֤Τޤ�ʬ�����롥
	 */
#ifdef LOG_DSP_ENTER
	brlid r15, log_dsp_enter
	 lwi  r5,  r13, p_runtsk  /* r5 <- p_schedtsk            */
#endif /* LOG_DSP_ENTER */

dispatcher_0:
	lwi  r4,  r13, p_schedtsk /* r4 <- p_schedtsk            */
	swi  r4,  r13, p_runtsk   /* p_schedtsk �� runtsk ��     */        
	beqi r4,  dispatcher_1    /* p_schedtsk �����뤫         */
	lwi  r1,  r4,  TCB_sp     /* TCB���饿���������å������� */

#ifdef LOG_DSP_ENTER
	Push r4
	brlid r15, log_dsp_leave
	 Mov   r5, r4
	Pop  r4
#endif /* LOG_DSP_ENTER */

	lwi  r5,  r4,  TCB_pc     /* TCB����¹ԺƳ����Ϥ�����   */
	bra  r5
dispatcher_1:
	/*
	 * CPU���å����֤β���ȡ��󥿥�������ƥ����ȼ¹Ծ��֤ؤ�
	 * �����򤹤�
	 */
	lwi   r1,   r2,  _kernel_istkpt   /* �󥿥�������ƥ������ѤΥ����å����ɤ߹��� */
	la    r6,   r0,  1                /* except_nest_count ��1��                    */
	swi   r6,   r13, except_nest_count
	andi  r4,   r3, ~MSR_IE           /* IE = '0'               */
dispatcher_2:
	/*
	 *  ����ߤ���Ĥ����󥿥�������ƥ����ȼ¹Ծ��֤Ȥ�����ߤ��Ԥġ�
	 *
	 *  �������󥿥�������ƥ����ȼ¹Ծ��֤��ڤ괹����Τϡ�������ȯ��
	 *  �������߽����ˤɤΥ����å���Ȥ����Ȥ�������β��ȡ������
	 *  �ϥ�ɥ���ǤΥ������ǥ����ѥå����ɻߤȤ���2�Ĥΰ�̣�����롥
	 *
	 *  �ץ����å��������Ԥ��˰ܹԤ���������ȡ�����ߵ��ĤȤϡ��Բ�
	 *  ʬ�˹Ԥʤ�ɬ�פ����롥
	 *  ������Բ�ʬ�˹Ԥʤ�ʤ���硤����ߤ���Ĥ���ľ��˳��
	 *  �ߤ����ꡤ������ǥ��������¹Բ�ǽ���֤ˤʤ�ȡ��¹Ԥ��٤�����
	 *  ��������ˤ⤫����餺�ץ����å���������Ԥ��ˤʤäƤ��ޤ���
	 *
	 *  ������Ԥ��δ֤ϡ�p_runtsk��NULL�ʡ�0�ˤ����ꤷ�ʤ���Фʤ��
	 *  �������Τ褦�����ꤷ�ʤ��ȡ�����ߥϥ�ɥ餫��iget_tid��Ƥӽ�
	 *  �����ݤ�ư����ͤ˹��פ��ʤ��ʤ롥
	 *
	 */
	mfs   r3,   rmsr                 /* ����ߵ���(MSR(IE)�򥻥å�)      */
	ori   r5,   r3, MSR_IE            
	mts   rmsr, r5
	nop
	nop
	mfs   r3,   rmsr                 /* ����߶ػ�(MSR(IE)�򥯥ꥢ)      */
	andi  r5,   r3, ~MSR_IE            
	mts   rmsr, r5
	lwi   r6,  r13,  reqflg           /* r6 <- reqflg                     */
	beqi  r6,  dispatcher_2           /* reqflg �� false �ʤ�             */
	swi   r0,  r13, except_nest_count /* except_nest_count �򥯥ꥢ       */
	swi   r0,  r13,  reqflg           /* reqflg �� false ��               */
	bri   dispatcher_0

/*
 *  �����ͥ�ν�λ�����θƽФ�
 *
 *  �⡼�ɤȥ����å����󥿥�������ƥ������Ѥ��ڤ��ؤ���
 */
    .globl call_exit_kernel
call_exit_kernel:
	lwi   r1,  r2,  _kernel_istkpt /* �󥿥�������ƥ������ѤΥ����å����ɤ߹��� */
	brlid r15  exit_kernel         
	 nop

/*
 *  ���������ϻ�����
 *
 *  �����å��μ����
 *  Microblaze Processor Reference Guide 52��53���
 *  �ؿ��ƽФ����ΰ����ϡ�r5��r10 �˳�Ǽ���롥
 *  �����Ʊ���˸ƽФ����ϥ����å��ե졼��˰����γ�Ǽ������ݤ���ɬ��
 *  �����롥����ˤ��ξ�ˤϥ�󥯥쥸����(R15)��ʬ���ΰ褬ɬ�פȤʤ롥
 *  �ƽФ���Ϲ���¾�δؿ���ƤӽФ�������� r5��r10 �򤳤��ΰ����¸��
 * �롥
 *  Low Address
 *             --------------------
 *  new_sp -> | Link Register(R15) |
 *             --------------------
 *            |   Arg1�Ѥ��ΰ�     |
 *             --------------------
 *            |   Arg2�Ѥ��ΰ�     |
 *             --------------------        
 *            |      ....          |
 *             --------------------
 *  High Address
 *  dispatcher����ƤӽФ���뤿�ᡤTCB�Υ��ɥ쥹�� r4 �����äƤ���
 */
	.text
	.global start_r
	.align 2
start_r:
	mfs   r3,   rmsr              /* ����ߵ���(MSR(IE)�򥻥å�)   */
	ori   r5,   r3, MSR_IE            
	mts   rmsr, r5
	lwi   r3,  r4, TCB_p_tinib    /* r3  <- p_runtsk->p_tinib      */
	lwi   r5,  r3, TINIB_exinf    /* r5  <- ������exinf��          */
	lwi   r11, r3, TINIB_task     /* r11 <- �������μ¹�����       */
	la    r15, r0, (ext_tsk - 8)  /* ����������������(ext_tsk)   */
	Push  r5                      /* �����å�����ΰ�����        */
	Push  r15
	bra   r11                     /* �������μ¹Գ���              */

/*
 * ���������Ԥ�
 */
	.global sil_dly_nse
sil_dly_nse:
	addi   r5, r5, -SIL_DLY_TIM1
	bgti   r5, sil_dly_nse_1
	rtsd   r15, 8
	nop  
sil_dly_nse_1:
	addi   r5, r5, -SIL_DLY_TIM2
	bgti   r5, sil_dly_nse_1
	rtsd   r15, 8
	 nop          