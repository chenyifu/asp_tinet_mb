#
#  @(#) $Id: Makefile.prc 5 2012-01-14 09:35:55Z tetsuya $
# 

#
#		Makefile �Υ��åװ�¸����Microbalze�ѡ�
#

#
#  GNU��ȯ�Ķ��Υ������åȥ������ƥ���������
#
GCC_TARGET = mb

#
#  �ץ��å���¸���ǥ��쥯�ȥ�̾�����
#
PRCDIR = $(SRCDIR)/arch/$(PRC)_$(TOOL)

#
#  ����ѥ��륪�ץ����
#
COPTS := $(COPTS) -mxl-gp-opt -N
LDFLAGS := -nostdlib $(LDFLAGS)
LIBS := $(LIBS) -lgcc

#
#  �����ͥ�˴ؤ������
#
KERNEL_DIR := $(KERNEL_DIR) $(PRCDIR)
KERNEL_ASMOBJS := $(KERNEL_ASMOBJS) prc_support.o
KERNEL_COBJS := $(KERNEL_COBJS) prc_config.o xps_timer.o

#
#  ����ե�����졼���ط����ѿ������
#
CFG_TABS := $(CFG_TABS) --cfg1-def-table $(PRCDIR)/prc_def.csv

#
#  ��¸�ط������
#
cfg1_out.c: $(PRCDIR)/prc_def.csv
kernel_cfg.timestamp: $(PRCDIR)/prc.tf
$(OBJFILE): $(PRCDIR)/prc_check.tf
