$ 
$     �ѥ�2�Υ������ƥ������¸�ƥ�ץ졼�ȡ�Microblaze�ѡ�
$ 

$ 
$ ͭ����CPU�㳰�ϥ�ɥ��ֹ�
$ 
$EXCNO_VALID = { 0,1,2,3,4,6,7,16,17,18,19 }$

$ 
$  DEF_EXC�ǻ��ѤǤ���CPU�㳰�ϥ�ɥ��ֹ�
$ 
$EXCNO_DEFEXC_VALID = EXCNO_VALID$

$ 
$  �������å����¸���˴ޤޤ��ɸ��γ���ߴ�����ǽ�ν�����������Ѥ��ʤ�
$ 
$OMIT_INITIALIZE_EXCEPTION = 1$

$ 
$  ͭ���ʳ�����ֹ桤����ߥϥ�ɥ��ֹ桤CPU�㳰�ϥ�ɥ��ֹ�
$ 
$INTNO_VALID = { 0,1,...,31 }$
$INHNO_VALID = INTNO_VALID$

$ 
$  ATT_ISR�ǻ��ѤǤ��������ֹ�Ȥ�����б��������ߥϥ�ɥ��ֹ�
$ 
$INTNO_ATTISR_VALID = INTNO_VALID$
$INHNO_ATTISR_VALID = INHNO_VALID$

$ 
$  DEF_INT�ǻ��ѤǤ������ߥϥ�ɥ��ֹ�
$ 
$INHNO_DEFINH_VALID = INHNO_VALID$

$ 
$  �����å���ˡ�λ���
$ 
$CHECK_STKSZ_ALIGN = 4$

$ 
$  CFG_INT�ǻ��ѤǤ��������ֹ�ȳ����ͥ����
$ 
$INTNO_CFGINT_VALID  = INTNO_VALID$
$INTPRI_CFGINT_VALID = { -1,-2,...,-7 }$

$ 
$  ɸ��ƥ�ץ졼�ȥե�����Υ��󥯥롼��
$ 
$INCLUDE "kernel/kernel.tf"$

$ 
$  �㳰�ϥ�ɥ�ơ��֥�
$ 
$FILE "kernel_cfg.c"$
$NL$
const FP _kernel_exch_tbl[TNUM_EXCH] = {$NL$
$FOREACH excno {0,1,...,6}$ 
	$IF LENGTH(EXC.EXCNO[excno])$
		$TAB$(FP)($EXC.EXCHDR[excno]$),
	$ELSE$
		$TAB$(FP)(_kernel_default_exc_handler),
	$END$
	$SPC$$FORMAT("/* %d */", +excno)$$NL$
$END$
};$NL$
$NL$

$ 
$  �����ͥ���٥ơ��֥������ɽ����
$ 
$FILE "kernel_cfg.c"$
$NL$
const uint8_t _kernel_inh_iipm_tbl[TNUM_INH] = {$NL$
$FOREACH inhno INHNO_VALID$ 
	$IF LENGTH(INH.INHNO[inhno])$
	  $TAB$UINT8_C($-INT.INTPRI[inhno]$),
	$ELSE$
	  $TAB$UINT8_C(0),
	$END$
	$SPC$$FORMAT("/* %d */", +inhno)$$NL$
$END$
};$NL$
$NL$

$ 
$  ����ߥޥ����ơ��֥�
$ 
const uint32_t _kernel_iipm_mask_tbl[TNUM_INT_PRI]={$NL$
$FOREACH intpri { 0,-1,...,-7 }$
 $intmask = 0$
 $FOREACH intno (INT.ID_LIST)$
  $IF INT.INTPRI[intno] >= intpri $
	$intmask = intmask | (1 << (INT.INTNO[intno]))$
  $END$
 $END$
 $TAB$UINT32_C($FORMAT("0x%08x", intmask)$),/* Priority $+intpri$ */$NL$
$END$
$NL$
};$NL$


$ 
$  ����ߥϥ�ɥ�ơ��֥�
$ 
$NL$
const FP _kernel_inh_tbl[TNUM_INH] = {$NL$
$FOREACH inhno INHNO_VALID$
	$IF LENGTH(INH.INHNO[inhno])$
		$TAB$(FP)($INH.INTHDR[inhno]$),
	$ELSE$
		$TAB$(FP)(_kernel_default_int_handler),
	$END$
	$SPC$$FORMAT("/* %d */", +inhno)$$NL$
$END$
};$NL$
$NL$

$ 
$  �����°���ơ��֥�
$ 
$NL$
ATR _kernel_intatr_tbl[TNUM_INT] = {$NL$
$FOREACH intno INTNO_VALID$
	$IF LENGTH(INT.INTNO[intno])$
		$TAB$($INT.INTATR[intno]$),
	$ELSE$
		$TAB$0U,
	$END$
	$SPC$$FORMAT("/* %d */", +intno)$$NL$
$END$
};$NL$
$NL$
