/*-
 * Copyright (c) 2015-2016 Kevin Lo <kevlo@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _IF_UREREG_H_
#define	_IF_UREREG_H_

#define	URE_CONFIG_IDX		0	/* config number 1 */
#define	URE_IFACE_IDX		0

#define	URE_CTL_READ		0x01
#define	URE_CTL_WRITE		0x02

#define	URE_TIMEOUT		1000
#define	URE_PHY_TIMEOUT		2000

#define	URE_BYTE_EN_DWORD	0xff
#define	URE_BYTE_EN_WORD	0x33
#define	URE_BYTE_EN_BYTE	0x11
#define	URE_BYTE_EN_SIX_BYTES	0x3f

#define	URE_FRAMELEN(mtu)	((mtu) + ETHER_HDR_LEN + ETHER_CRC_LEN + ETHER_VLAN_ENCAP_LEN)
#define	URE_MAX_FRAMELEN	(ETHER_MAX_LEN + ETHER_VLAN_ENCAP_LEN)
#define	URE_JUMBO_FRAMELEN	(9*1024)
#define	URE_JUMBO_MTU		(URE_JUMBO_FRAMELEN - ETHER_HDR_LEN - ETHER_CRC_LEN - ETHER_VLAN_ENCAP_LEN)

#define	URE_PLA_IDR		0xc000
#define	URE_PLA_RCR		0xc010
#define	URE_PLA_RMS		0xc016
#define	URE_PLA_RXFIFO_CTRL0	0xc0a0
#define	URE_PLA_RXFIFO_CTRL1	0xc0a4
#define	URE_PLA_RXFIFO_CTRL2	0xc0a8
#define	URE_PLA_DMY_REG0	0xc0b0
#define	URE_PLA_FMC		0xc0b4
#define	URE_PLA_CFG_WOL		0xc0b6
#define	URE_PLA_TEREDO_CFG	0xc0bc
#define	URE_PLA_MAR0		0xcd00
#define	URE_PLA_MAR4		0xcd04
#define	URE_PLA_BACKUP		0xd000
#define	URE_PAL_BDC_CR		0xd1a0
#define	URE_PLA_TEREDO_TIMER	0xd2cc
#define	URE_PLA_REALWOW_TIMER	0xd2e8
#define	URE_PLA_SUSPEND_FLAG	0xd38a
#define	URE_PLA_INDICATE_FALG	0xd38c
#define	URE_PLA_EXTRA_STATUS	0xd398
#define	URE_PLA_LEDSEL		0xdd90
#define	URE_PLA_LED_FEATURE	0xdd92
#define	URE_PLA_PHYAR		0xde00
#define	URE_PLA_BOOT_CTRL	0xe004
#define	URE_PLA_GPHY_INTR_IMR	0xe022
#define	URE_PLA_EEE_CR		0xe040
#define	URE_PLA_EEEP_CR		0xe080
#define	URE_PLA_MAC_PWR_CTRL	0xe0c0
#define	URE_PLA_MAC_PWR_CTRL2	0xe0ca
#define	URE_PLA_MAC_PWR_CTRL3	0xe0cc
#define	URE_PLA_MAC_PWR_CTRL4	0xe0ce
#define	URE_PLA_WDT6_CTRL	0xe428
#define	URE_PLA_TCR0		0xe610
#define	URE_PLA_TCR1		0xe612
#define	URE_PLA_MTPS		0xe615
#define	URE_PLA_TXFIFO_CTRL	0xe618
#define	URE_PLA_RSTTALLY	0xe800
#define	URE_PLA_CR		0xe813
#define	URE_PLA_CRWECR		0xe81c
#define	URE_PLA_CONFIG34	0xe820
#define	URE_PLA_CONFIG5		0xe822
#define	URE_PLA_PHY_PWR		0xe84c
#define	URE_PLA_OOB_CTRL	0xe84f
#define	URE_PLA_CPCR		0xe854
#define	URE_PLA_MISC_0		0xe858
#define	URE_PLA_MISC_1		0xe85a
#define	URE_PLA_OCP_GPHY_BASE	0xe86c
#define	URE_PLA_TELLYCNT	0xe890
#define	URE_PLA_SFF_STS_7	0xe8de
#define	URE_PLA_PHYSTATUS	0xe908
#define	URE_GMEDIASTAT		0xe908
#define	URE_PLA_BP_BA		0xfc26
#define	URE_PLA_BP_0		0xfc28
#define	URE_PLA_BP_1		0xfc2a
#define	URE_PLA_BP_2		0xfc2c
#define	URE_PLA_BP_3		0xfc2e
#define	URE_PLA_BP_4		0xfc30
#define	URE_PLA_BP_5		0xfc32
#define	URE_PLA_BP_6		0xfc34
#define	URE_PLA_BP_7		0xfc36
#define	URE_PLA_BP_EN		0xfc38

#define	URE_USB_USB2PHY		0xb41e
#define	URE_USB_SSPHYLINK2	0xb428
#define	URE_USB_U2P3_CTRL	0xb460
#define	URE_USB_CSR_DUMMY1	0xb464
#define	URE_USB_CSR_DUMMY2	0xb466
#define	URE_USB_DEV_STAT	0xb808
#define	URE_USB_CONNECT_TIMER	0xcbf8
#define	URE_USB_MSC_TIMER	0xcbfc
#define	URE_USB_BURST_SIZE	0xcfc0
#define	URE_USB_LPM_CONFIG	0xcfd8
#define	URE_USB_FW_CTRL		0xd334	/* RTL8153B */
#define	URE_USB_USB_CTRL	0xd406
#define	URE_USB_PHY_CTRL	0xd408
#define	URE_USB_TX_AGG		0xd40a
#define	URE_USB_RX_BUF_TH	0xd40c
#define	URE_USB_FW_TASK		0xd4e8	/* RTL8153B */
#define	URE_USB_USB_TIMER	0xd428
#define	URE_USB_RX_EARLY_AGG	0xd42c
#define	URE_USB_RX_EARLY_SIZE	0xd42e
#define	URE_USB_PM_CTRL_STATUS	0xd432	/* RTL8153A */
#define	URE_USB_RX_EXTRA_AGG_TMR	0xd432 /* RTL8153B */
#define	URE_USB_TX_DMA		0xd434
#define	URE_USB_UPT_RXDMA_OWN	0xd437
#define	URE_USB_FC_TIMER		0xd340
#define	URE_USB_TOLERANCE	0xd490
#define	URE_USB_LPM_CTRL	0xd41a
#define	URE_USB_BMU_RESET	0xd4b0
#define	URE_USB_U1U2_TIMER	0xd4da
#define	URE_USB_UPS_CTRL	0xd800
#define	URE_USB_POWER_CUT	0xd80a
#define	URE_USB_MISC_0		0xd81a
#define	URE_USB_AFE_CTRL2	0xd824
#define	URE_USB_WDT11_CTRL	0xe43c
#define	URE_USB_BP_BA		URE_PLA_BP_BA
#define	URE_USB_BP_0		URE_PLA_BP_0
#define	URE_USB_BP_1		URE_PLA_BP_1
#define	URE_USB_BP_2		URE_PLA_BP_2
#define	URE_USB_BP_3		URE_PLA_BP_3
#define	URE_USB_BP_4		URE_PLA_BP_4
#define	URE_USB_BP_5		URE_PLA_BP_5
#define	URE_USB_BP_6		URE_PLA_BP_6
#define	URE_USB_BP_7		URE_PLA_BP_7
#define	URE_USB_BP_EN		URE_PLA_BP_EN	/* RTL8153A */
#define	URE_USB_BP_8		0xfc38		/* RTL8153B */
#define	URE_USB_BP_9		0xfc3a
#define	URE_USB_BP_10		0xfc3c
#define	URE_USB_BP_11		0xfc3e
#define	URE_USB_BP_12		0xfc40
#define	URE_USB_BP_13		0xfc42
#define	URE_USB_BP_14		0xfc44
#define	URE_USB_BP_15		0xfc46
#define	URE_USB_BP2_EN		0xfc48


/* OCP Registers. */
#define	URE_OCP_ALDPS_CONFIG	0x2010
#define	URE_OCP_EEE_CONFIG1	0x2080
#define	URE_OCP_EEE_CONFIG2	0x2092
#define	URE_OCP_EEE_CONFIG3	0x2094
#define	URE_OCP_BASE_MII	0xa400
#define	URE_OCP_EEE_AR		0xa41a
#define	URE_OCP_EEE_DATA	0xa41c
#define	URE_OCP_PHY_STATUS	0xa420
#define	URE_OCP_POWER_CFG	0xa430
#define	URE_OCP_EEE_CFG		0xa432
#define	URE_OCP_SRAM_ADDR	0xa436
#define	URE_OCP_SRAM_DATA	0xa438
#define	URE_OCP_DOWN_SPEED	0xa442
#define	URE_OCP_EEE_ABLE	0xa5c4
#define	URE_OCP_EEE_ADV		0xa5d0
#define	URE_OCP_EEE_LPABLE	0xa5d2
#define	URE_OCP_PHY_STATE	0xa708
#define	URE_OCP_PHY_PATCH_STAT	0xb800
#define	URE_OCP_PHY_PATCH_CMD	0xb820
#define	URE_OCP_PHY_LOCK	0xb82e
#define	URE_OCP_ADC_CFG		0xbc06

/* SRAM Register. */
#define	URE_SRAM_GREEN_CFG	0x8011
#define	URE_SRAM_LPF_CFG	0x8012
#define	URE_SRAM_GPHY_FW_VER	0x801e
#define	URE_SRAM_10M_AMP1	0x8080
#define	URE_SRAM_10M_AMP2	0x8082
#define	URE_SRAM_IMPEDANCE	0x8084
#define	URE_SRAM_PHY_LOCK	0xb82e

/* PLA_RCR */
#define	URE_RCR_AAP		0x00000001
#define	URE_RCR_APM		0x00000002
#define	URE_RCR_AM		0x00000004
#define	URE_RCR_AB		0x00000008
#define	URE_RCR_AR		0x00000010	/* runt */
#define	URE_RCR_AER		0x00000020	/* error pkts */
#define	URE_RCR_ACPTFLOW	0x00000080
#define	URE_RCR_RXEMPTY		0x00020000
#define	URE_RCR_ACPT_ALL	\
	(URE_RCR_AAP | URE_RCR_APM | URE_RCR_AM | URE_RCR_AB)

/* PLA_RXFIFO_CTRL0 */
#define	URE_RXFIFO_THR1_NORMAL	0x00080002
#define	URE_RXFIFO_THR1_OOB	0x01800003

/* PLA_RXFIFO_CTRL1 */
#define	URE_RXFIFO_THR2_FULL	0x00000060
#define	URE_RXFIFO_THR2_HIGH	0x00000038
#define	URE_RXFIFO_THR2_OOB	0x0000004a
#define	URE_RXFIFO_THR2_NORMAL	0x00a0

/* PLA_RXFIFO_CTRL2 */
#define	URE_RXFIFO_THR3_FULL	0x00000078
#define	URE_RXFIFO_THR3_HIGH	0x00000048
#define	URE_RXFIFO_THR3_OOB	0x0000005a
#define	URE_RXFIFO_THR3_NORMAL	0x0110

/* PLA_TXFIFO_CTRL */
#define	URE_TXFIFO_THR_NORMAL	0x00400008
#define	URE_TXFIFO_THR_NORMAL2	0x01000008

/* PLA_DMY_REG0 */
#define	URE_ECM_ALDPS		0x0002

/* PLA_FMC */
#define	URE_FMC_FCR_MCU_EN	0x0001

/* PLA_EEEP_CR */
#define	URE_EEEP_CR_EEEP_TX	0x0002

/* PLA_WDT6_CTRL */
#define	URE_WDT6_SET_MODE	0x0010

/* PLA_TCR0 */
#define	URE_TCR0_TX_EMPTY	0x0800
#define	URE_TCR0_AUTO_FIFO	0x0080

/* PLA_TCR1 */
#define	URE_VERSION_MASK	0x7cf0

/* PLA_MTPS */
#define	URE_MTPS_DEFAULT	96
#define	URE_MTPS_JUMBO		192

/* PLA_RSTTALLY */
#define	URE_TALLY_RESET		0x0001

/* PLA_CR */
#define	URE_CR_RST		0x10
#define	URE_CR_RE		0x08
#define	URE_CR_TE		0x04

/* PLA_CRWECR */
#define	URE_CRWECR_NORAML	0x00
#define	URE_CRWECR_CONFIG	0xc0

/* PLA_OOB_CTRL */
#define	URE_NOW_IS_OOB		0x80
#define	URE_TXFIFO_EMPTY	0x20
#define	URE_RXFIFO_EMPTY	0x10
#define	URE_LINK_LIST_READY	0x02
#define	URE_DIS_MCU_CLROOB	0x01
#define	URE_FIFO_EMPTY		(URE_TXFIFO_EMPTY | URE_RXFIFO_EMPTY)

/* PLA_MISC_1 */
#define	URE_RXDY_GATED_EN	0x0008

/* PLA_SFF_STS_7 */
#define	URE_RE_INIT_LL		0x8000
#define	URE_MCU_BORW_EN		0x4000

/* PLA_CPCR */
#define	URE_CPCR_RX_VLAN	0x0040

/* PLA_TEREDO_CFG */
#define	URE_TEREDO_SEL			0x8000
#define	URE_TEREDO_WAKE_MASK		0x7f00
#define	URE_TEREDO_RS_EVENT_MASK	0x00fe
#define	URE_OOB_TEREDO_EN		0x0001

/* PAL_BDC_CR */
#define	URE_ALDPS_PROXY_MODE	0x0001

/* URE_PLA_CONFIG34 */
#define	URE_LINK_OFF_WAKE_EN	0x0008
#define	URE_LINK_ON_WAKE_EN	0x0010

/* PLA_CONFIG5 */
#define	URE_LAN_WAKE_EN		0x0002

/* PLA_LED_FEATURE */
#define	URE_LED_MODE_MASK	0x0700

/* PLA_PHY_PWR */
#define	URE_TX_10M_IDLE_EN	0x0080
#define	URE_PFM_PWM_SWITCH	0x0040

/* PLA_MAC_PWR_CTRL */
#define	URE_D3_CLK_GATED_EN	0x00004000
#define	URE_MCU_CLK_RATIO	0x07010f07
#define	URE_MCU_CLK_RATIO_MASK	0x0f0f0f0f
#define	URE_ALDPS_SPDWN_RATIO	0x0f87

/* PLA_MAC_PWR_CTRL2 */
#define	URE_MAC_CLK_SPDWN_EN	0x8000
#define	URE_EEE_SPDWN_RATIO	0x8007

/* PLA_MAC_PWR_CTRL3 */
#define	URE_PLA_MCU_SPDWN_EN	0x4000
#define	URE_PKT_AVAIL_SPDWN_EN	0x0100
#define	URE_SUSPEND_SPDWN_EN	0x0004
#define	URE_U1U2_SPDWN_EN	0x0002
#define	URE_L1_SPDWN_EN		0x0001

/* PLA_MAC_PWR_CTRL4 */
#define	URE_PWRSAVE_SPDWN_EN	0x1000
#define	URE_RXDV_SPDWN_EN	0x0800
#define	URE_TX10MIDLE_EN	0x0100
#define	URE_TP100_SPDWN_EN	0x0020
#define	URE_TP500_SPDWN_EN	0x0010
#define	URE_TP1000_SPDWN_EN	0x0008
#define	URE_EEE_SPDWN_EN	0x0001

/* PLA_GPHY_INTR_IMR */
#define	URE_GPHY_STS_MSK	0x0001
#define	URE_SPEED_DOWN_MSK	0x0002
#define	URE_SPDWN_RXDV_MSK	0x0004
#define	URE_SPDWN_LINKCHG_MSK	0x0008

/* PLA_PHYAR */
#define	URE_PHYAR_PHYDATA	0x0000ffff
#define	URE_PHYAR_BUSY		0x80000000

/* PLA_EEE_CR */
#define	URE_EEE_RX_EN		0x0001
#define	URE_EEE_TX_EN		0x0002

/* PLA_BOOT_CTRL */
#define	URE_AUTOLOAD_DONE	0x0002

/* PLA_SUSPEND_FLAG */
#define	URE_LINK_CHG_EVENT	0x01

/* PLA_INDICATE_FALG */
#define	URE_UPCOMING_RUNTIME_D3	0x01

/* PLA_EXTRA_STATUS */
#define	URE_POLL_LINK_CHG		0x0001
#define	URE_LINK_CHANGE_FLAG	0x0100
#define	URE_CUR_LINK_OK			0x8000

/* URE_PLA_PHYSTATUS */
#define	URE_PHYSTATUS_FDX	0x0001
#define	URE_PHYSTATUS_LINK	0x0002
#define	URE_PHYSTATUS_10MBPS	0x0004
#define	URE_PHYSTATUS_100MBPS	0x0008
#define	URE_PHYSTATUS_1000MBPS	0x0010
#define	URE_PHYSTATUS_500MBPS	0x0100
#define	URE_PHYSTATUS_1250MBPS	0x0200
#define	URE_PHYSTATUS_2500MBPS	0x0400

/* USB_USB2PHY */
#define	URE_USB2PHY_SUSPEND	0x0001
#define	URE_USB2PHY_L1		0x0002

/* USB_SSPHYLINK2 */
#define	URE_PWD_DN_SCALE_MASK	0x3ffe
#define	URE_PWD_DN_SCALE(x)	((x) << 1)

/* USB_CSR_DUMMY1 */
#define	URE_DYNAMIC_BURST	0x0001

/* USB_CSR_DUMMY2 */
#define	URE_EP4_FULL_FC		0x0001

/* USB_DEV_STAT */
#define	URE_STAT_SPEED_MASK	0x0006
#define	URE_STAT_SPEED_HIGH	0x0000
#define	URE_STAT_SPEED_FULL	0x0001

/* URE_USB_LPM_CONFIG */
#define	URE_LPM_U1U2_EN		0x0001

/* USB_TX_AGG */
#define	URE_TX_AGG_MAX_THRESHOLD	0x03

/* USB_RX_BUF_TH */
#define	URE_RX_THR_SUPER	0x0c350180
#define	URE_RX_THR_HIGH		0x7a120180
#define	URE_RX_THR_SLOW		0xffff0180
#define	URE_RX_THR_B		0x00010001

/* USB_TX_DMA */
#define	URE_TEST_MODE_DISABLE	0x00000001
#define	URE_TX_SIZE_ADJUST1	0x00000100

/* USB_BMU_RESET */
#define	URE_BMU_RESET_EP_IN		0x01
#define	URE_BMU_RESET_EP_OUT	0x02

/* USB_UPT_RXDMA_OWN */
#define	URE_OWN_UPDATE		0x01
#define	URE_OWN_CLEAR		0x02

/* USB_FW_TASK */
#define	URE_FC_PATCH_TASK	0x0001

/* USB_UPS_CTRL */
#define	URE_POWER_CUT		0x0100

/* USB_PM_CTRL_STATUS */
#define	URE_RESUME_INDICATE	0x0001

/* USB_FW_CTRL */
#define	URE_FLOW_CTRL_PATCH_OPT	0x01

/* USB_FC_TIMER */
#define	URE_CTRL_TIMER_EN	0x8000

/* USB_USB_CTRL */
#define	URE_RX_AGG_DISABLE	0x0010
#define	URE_RX_ZERO_EN		0x0080

/* USB_U2P3_CTRL */
#define	URE_U2P3_ENABLE		0x0001

/* USB_POWER_CUT */
#define	URE_PWR_EN			0x0001
#define	URE_PHASE2_EN		0x0008
#define	URE_UPS_EN			0x0010
#define	URE_USP_PREWAKE		0x0020

/* USB_MISC_0 */
#define	URE_PCUT_STATUS		0x0001

/* USB_RX_EARLY_TIMEOUT */
#define	URE_COALESCE_SUPER	85000U
#define	URE_COALESCE_HIGH	250000U
#define	URE_COALESCE_SLOW	524280U

/* USB_WDT11_CTRL */
#define	URE_TIMER11_EN		0x0001

/* USB_LPM_CTRL */
#define	URE_FIFO_EMPTY_1FB	0x30
#define	URE_LPM_TIMER_MASK	0x0c
#define	URE_LPM_TIMER_500MS	0x04
#define	URE_LPM_TIMER_500US	0x0c
#define	URE_ROK_EXIT_LPM	0x02

/* USB_AFE_CTRL2 */
#define	URE_SEN_VAL_MASK	0xf800
#define	URE_SEN_VAL_NORMAL	0xa000
#define	URE_SEL_RXIDLE		0x0100

/* OCP_ALDPS_CONFIG */
#define	URE_ENPWRSAVE		0x8000
#define	URE_ENPDNPS		0x0200
#define	URE_LINKENA		0x0100
#define	URE_DIS_SDSAVE		0x0010

/* OCP_PHY_STATUS */
#define	URE_PHY_STAT_MASK	0x0007
#define	URE_PHY_STAT_EXT_INIT	2
#define	URE_PHY_STAT_LAN_ON	3
#define	URE_PHY_STAT_PWRDN	5

/* OCP_POWER_CFG */
#define	URE_EEE_CLKDIV_EN	0x8000
#define	URE_EN_ALDPS		0x0004
#define	URE_EN_10M_PLLOFF	0x0001

/* OCP_EEE_CFG */
#define	URE_CTAP_SHORT_EN	0x0040
#define	URE_EEE10_EN		0x0010

/* OCP_DOWN_SPEED */
#define	URE_EN_10M_BGOFF	0x0080
#define	URE_EN_10M_CLKDIV	0x0800
#define	URE_EN_EEE_100		0x1000
#define	URE_EN_EEE_1000		0x2000
#define	URE_EN_EEE_CMODE	0x4000

/* OCP_PHY_STATE */
#define	URE_TXDIS_STATE		0x01
#define	URE_ABD_STATE		0x02

/* OCP_PHY_PATCH_STAT */
#define	URE_PATCH_READY		0x40

/* OCP_PHY_PATCH_CMD */
#define	URE_PATCH_REQUEST	0x10

/* OCP_PHY_LOCK */
#define	URE_PATCH_LOCK		0x01

/* OCP_ADC_CFG */
#define	URE_CKADSEL_L		0x0100
#define	URE_ADC_EN		0x0080
#define	URE_EN_EMI_L		0x0040

/* SRAM_GREEN_CFG */
#define	URE_GREEN_ETH_EN	0x8000

/* SRAM_PHY_LOCK */
#define	URE_PHY_PATCH_LOCK		0x0001

#define	URE_ADV_2500TFDX	0x0080

#define	URE_MCU_TYPE_PLA	0x0100
#define	URE_MCU_TYPE_USB	0x0000

#define	GET_MII(sc)		uether_getmii(&(sc)->sc_ue)

struct ure_intrpkt {
	uint8_t	ure_tsr;
	uint8_t	ure_rsr;
	uint8_t	ure_gep_msr;
	uint8_t	ure_waksr;
	uint8_t	ure_txok_cnt;
	uint8_t	ure_rxlost_cnt;
	uint8_t	ure_crcerr_cnt;
	uint8_t	ure_col_cnt;
} __packed;

#define	URE_RXPKT_ALIGN		8
struct ure_rxpkt {
	uint32_t ure_pktlen;
#define	URE_RXPKT_LEN_MASK	0x7fff
	uint32_t ure_csum;
/* Linux driver has this in ure_misc, but my device has it in ure_csum */
#define	URE_RXPKT_VLAN_MASK	0xffff
#define	URE_RXPKT_RX_VLAN_TAG	(1 << 16)
#define	URE_RXPKT_IPV4_CS	(1 << 19)
#define	URE_RXPKT_IPV6_CS	(1 << 20)
#define	URE_RXPKT_TCP_CS	(1 << 22)
#define	URE_RXPKT_UDP_CS	(1 << 23)
	uint32_t ure_misc;
#define	URE_RXPKT_TCP_F		(1 << 21)
#define	URE_RXPKT_UDP_F		(1 << 22)
#define	URE_RXPKT_IP_F		(1 << 23)
	uint32_t ure_rsvd2;
	uint32_t ure_rsvd3;
	uint32_t ure_rsvd4;
} __packed;

#define	URE_TXPKT_ALIGN		4
struct ure_txpkt {
	uint32_t ure_pktlen;
#define	URE_TKPKT_TX_FS		(1 << 31)
#define	URE_TKPKT_TX_LS		(1 << 30)
#define	URE_TXPKT_LEN_MASK	0xffff
	uint32_t ure_csum;
#define	URE_L4_OFFSET_MAX       0x7ff
#define	URE_L4_OFFSET_SHIFT     17
#define	URE_TXPKT_VLAN_MASK	0xffff
#define	URE_TXPKT_VLAN		(1 << 16)
#define	URE_TXPKT_IPV6_CS	(1 << 28)
#define	URE_TXPKT_IPV4_CS	(1 << 29)
#define	URE_TXPKT_TCP_CS	(1 << 30)
#define	URE_TXPKT_UDP_CS	(1 << 31)
/* Lower 12 bits are the VLAN tag */
} __packed;

#define	URE_MAX_TX	4
#define	URE_MAX_RX	4

#define	URE_TX_BUFSZ		16384
#define	URE_8152_RX_BUFSZ	(16 * 1024)
#define	URE_8153_RX_BUFSZ	(32 * 1024)
#define	URE_8156_RX_BUFSZ	(48 * 1024)


struct ure_softc {
	struct usb_ether	sc_ue;
	struct ifmedia		sc_ifmedia;
	struct mtx		sc_mtx;
	struct usb_xfer		*sc_rx_xfer[URE_MAX_RX];
	struct usb_xfer		*sc_tx_xfer[URE_MAX_TX];

	int			sc_rxbufsz;
	int			sc_rxstarted;

	int			sc_phyno;

	u_int			sc_flags;
#define	URE_FLAG_LINK		0x0001
#define	URE_FLAG_8152		0x0100	/* RTL8152 */
#define	URE_FLAG_8153		0x0200	/* RTL8153 */
#define	URE_FLAG_8153B		0x0400	/* RTL8153B */
#define	URE_FLAG_8156		0x0800	/* RTL8156 */
#define	URE_FLAG_8156B		0x1000	/* RTL8156B */

	u_int			sc_chip;
	u_int			sc_ver;
#define	URE_CHIP_VER_4C00	0x0001
#define	URE_CHIP_VER_4C10	0x0002
#define	URE_CHIP_VER_5C00	0x0004
#define	URE_CHIP_VER_5C10	0x0008
#define	URE_CHIP_VER_5C20	0x0010
#define	URE_CHIP_VER_5C30	0x0020
#define	URE_CHIP_VER_6000	0x0040
#define	URE_CHIP_VER_6010	0x0080
#define	URE_CHIP_VER_7020	0x0100
#define	URE_CHIP_VER_7030	0x0200
#define	URE_CHIP_VER_7400	0x0400
#define	URE_CHIP_VER_7410	0x0800
};

#define	URE_LOCK(_sc)		mtx_lock(&(_sc)->sc_mtx)
#define	URE_UNLOCK(_sc)		mtx_unlock(&(_sc)->sc_mtx)
#define	URE_LOCK_ASSERT(_sc, t)	mtx_assert(&(_sc)->sc_mtx, t)

#endif		/* _IF_UREREG_H_ */
