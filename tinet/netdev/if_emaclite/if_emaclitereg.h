/*
 *  TINET (TCP/IP Protocol Stack)
 * 
 *  Copyright (C) 2012 by Tetsuya Morizumi
 *
 *  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ�狼��Free Software Foundation 
 *  �ˤ�äƸ�ɽ����Ƥ��� GNU General Public License �� Version 2 �˵�
 *  �Ҥ���Ƥ���������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ�����
 *  ����Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����ξ������������ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
 *  �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
 *  ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 *  @(#) $Id: if_emaclitereg.h 9 2012-03-15 12:57:27Z tetsuya $
 */

/*
 * AXI Ethernet Lite MAC (v1.00a)
 */

#ifndef _IF_EMACLITEREG_H_
#define _IF_EMACLITEREG_H_

#define EMACLITE_TX_PING        0x1U
#define EMACLITE_TX_PONG        0x2U
#define EMACLITE_RX_PING        0x4U
#define EMACLITE_RX_PONG        0x8U

#define EMACLITE_BUFFER_OFFSET  0x0800U

#define EMACLITE_TX_BUFFER      0x0000U
#define EMACLITE_MDIOADDR       0x07E4U
#define EMACLITE_MDIOWR         0x07E8U
#define EMACLITE_MDIORD         0x07ECU
#define EMACLITE_MDIOCTRL       0x07F0U
#define EMACLITE_TX_LENGTH      0x07F4U
#define EMACLITE_GIE            0x07F8U  /* Global interrupt register */
#define EMACLITE_TX_CONTROL     0x07FCU
#define EMACLITE_RX_BUFFER      0x1000U
#define EMACLITE_RX_CONTROL     0x17FCU


/* Global Interrupt Enable Register (GIE) */
#define EMACLITE_GIE_GIE        (1U<<31)

/* Transmit Control Register */
#define EMACLITE_TX_LOOP_BACK   (1U<<4)
#define EMACLITE_TX_INT_EN      (1U<<3)
#define EMACLITE_TX_PROGRAM     (1U<<1)
#define EMACLITE_TX_STATUS      (1U<<0)

/* Recieve Control Register */
#define EMACLITE_RX_INT_EN      (1U<<3)
#define EMACLITE_RX_STATUS      (1U<<0)

#endif	/* of #ifndef _IF_EMACLITEREG_H_ */
