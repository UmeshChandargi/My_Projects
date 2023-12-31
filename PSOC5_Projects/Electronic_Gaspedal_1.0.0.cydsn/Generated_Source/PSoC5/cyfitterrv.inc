;
; File Name: cyfitterrv.inc
; 
; PSoC Creator  4.4
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; Clock_1
Clock_1__CFG0 EQU CYREG_CLKDIST_DCFG2_CFG0
Clock_1__CFG1 EQU CYREG_CLKDIST_DCFG2_CFG1
Clock_1__CFG2 EQU CYREG_CLKDIST_DCFG2_CFG2
Clock_1__CFG2_SRC_SEL_MASK EQU 0x07
Clock_1__INDEX EQU 0x02
Clock_1__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock_1__PM_ACT_MSK EQU 0x04
Clock_1__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock_1__PM_STBY_MSK EQU 0x04

; UART_LOG
UART_LOG_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB10_11_ACTL
UART_LOG_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB10_11_CTL
UART_LOG_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB10_11_CTL
UART_LOG_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB10_11_CTL
UART_LOG_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB10_11_CTL
UART_LOG_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB10_11_MSK
UART_LOG_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB10_11_MSK
UART_LOG_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB10_11_MSK
UART_LOG_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB10_11_MSK
UART_LOG_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB10_ACTL
UART_LOG_BUART_sRX_RxBitCounter__CONTROL_REG EQU CYREG_B1_UDB10_CTL
UART_LOG_BUART_sRX_RxBitCounter__CONTROL_ST_REG EQU CYREG_B1_UDB10_ST_CTL
UART_LOG_BUART_sRX_RxBitCounter__COUNT_REG EQU CYREG_B1_UDB10_CTL
UART_LOG_BUART_sRX_RxBitCounter__COUNT_ST_REG EQU CYREG_B1_UDB10_ST_CTL
UART_LOG_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
UART_LOG_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
UART_LOG_BUART_sRX_RxBitCounter__PERIOD_REG EQU CYREG_B1_UDB10_MSK
UART_LOG_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB10_11_ACTL
UART_LOG_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG EQU CYREG_B1_UDB10_11_ST
UART_LOG_BUART_sRX_RxBitCounter_ST__MASK_REG EQU CYREG_B1_UDB10_MSK
UART_LOG_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
UART_LOG_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
UART_LOG_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB10_ACTL
UART_LOG_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG EQU CYREG_B1_UDB10_ST_CTL
UART_LOG_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B1_UDB10_ST_CTL
UART_LOG_BUART_sRX_RxBitCounter_ST__STATUS_REG EQU CYREG_B1_UDB10_ST
UART_LOG_BUART_sRX_RxShifter_u0__16BIT_A0_REG EQU CYREG_B1_UDB10_11_A0
UART_LOG_BUART_sRX_RxShifter_u0__16BIT_A1_REG EQU CYREG_B1_UDB10_11_A1
UART_LOG_BUART_sRX_RxShifter_u0__16BIT_D0_REG EQU CYREG_B1_UDB10_11_D0
UART_LOG_BUART_sRX_RxShifter_u0__16BIT_D1_REG EQU CYREG_B1_UDB10_11_D1
UART_LOG_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB10_11_ACTL
UART_LOG_BUART_sRX_RxShifter_u0__16BIT_F0_REG EQU CYREG_B1_UDB10_11_F0
UART_LOG_BUART_sRX_RxShifter_u0__16BIT_F1_REG EQU CYREG_B1_UDB10_11_F1
UART_LOG_BUART_sRX_RxShifter_u0__A0_A1_REG EQU CYREG_B1_UDB10_A0_A1
UART_LOG_BUART_sRX_RxShifter_u0__A0_REG EQU CYREG_B1_UDB10_A0
UART_LOG_BUART_sRX_RxShifter_u0__A1_REG EQU CYREG_B1_UDB10_A1
UART_LOG_BUART_sRX_RxShifter_u0__D0_D1_REG EQU CYREG_B1_UDB10_D0_D1
UART_LOG_BUART_sRX_RxShifter_u0__D0_REG EQU CYREG_B1_UDB10_D0
UART_LOG_BUART_sRX_RxShifter_u0__D1_REG EQU CYREG_B1_UDB10_D1
UART_LOG_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B1_UDB10_ACTL
UART_LOG_BUART_sRX_RxShifter_u0__F0_F1_REG EQU CYREG_B1_UDB10_F0_F1
UART_LOG_BUART_sRX_RxShifter_u0__F0_REG EQU CYREG_B1_UDB10_F0
UART_LOG_BUART_sRX_RxShifter_u0__F1_REG EQU CYREG_B1_UDB10_F1
UART_LOG_BUART_sRX_RxShifter_u0__MSK_DP_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
UART_LOG_BUART_sRX_RxShifter_u0__PER_DP_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
UART_LOG_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB10_11_ACTL
UART_LOG_BUART_sRX_RxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB10_11_ST
UART_LOG_BUART_sRX_RxSts__3__MASK EQU 0x08
UART_LOG_BUART_sRX_RxSts__3__POS EQU 3
UART_LOG_BUART_sRX_RxSts__4__MASK EQU 0x10
UART_LOG_BUART_sRX_RxSts__4__POS EQU 4
UART_LOG_BUART_sRX_RxSts__5__MASK EQU 0x20
UART_LOG_BUART_sRX_RxSts__5__POS EQU 5
UART_LOG_BUART_sRX_RxSts__MASK EQU 0x38
UART_LOG_BUART_sRX_RxSts__MASK_REG EQU CYREG_B0_UDB10_MSK
UART_LOG_BUART_sRX_RxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB10_ACTL
UART_LOG_BUART_sRX_RxSts__STATUS_REG EQU CYREG_B0_UDB10_ST
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG EQU CYREG_B0_UDB10_11_A0
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG EQU CYREG_B0_UDB10_11_A1
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG EQU CYREG_B0_UDB10_11_D0
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG EQU CYREG_B0_UDB10_11_D1
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB10_11_ACTL
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG EQU CYREG_B0_UDB10_11_F0
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG EQU CYREG_B0_UDB10_11_F1
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG EQU CYREG_B0_UDB10_A0_A1
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG EQU CYREG_B0_UDB10_A0
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG EQU CYREG_B0_UDB10_A1
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG EQU CYREG_B0_UDB10_D0_D1
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG EQU CYREG_B0_UDB10_D0
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG EQU CYREG_B0_UDB10_D1
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG EQU CYREG_B0_UDB10_ACTL
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG EQU CYREG_B0_UDB10_F0_F1
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG EQU CYREG_B0_UDB10_F0
UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG EQU CYREG_B0_UDB10_F1
UART_LOG_BUART_sTX_TxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB13_14_A0
UART_LOG_BUART_sTX_TxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB13_14_A1
UART_LOG_BUART_sTX_TxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB13_14_D0
UART_LOG_BUART_sTX_TxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB13_14_D1
UART_LOG_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
UART_LOG_BUART_sTX_TxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB13_14_F0
UART_LOG_BUART_sTX_TxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB13_14_F1
UART_LOG_BUART_sTX_TxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB13_A0_A1
UART_LOG_BUART_sTX_TxShifter_u0__A0_REG EQU CYREG_B0_UDB13_A0
UART_LOG_BUART_sTX_TxShifter_u0__A1_REG EQU CYREG_B0_UDB13_A1
UART_LOG_BUART_sTX_TxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB13_D0_D1
UART_LOG_BUART_sTX_TxShifter_u0__D0_REG EQU CYREG_B0_UDB13_D0
UART_LOG_BUART_sTX_TxShifter_u0__D1_REG EQU CYREG_B0_UDB13_D1
UART_LOG_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
UART_LOG_BUART_sTX_TxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB13_F0_F1
UART_LOG_BUART_sTX_TxShifter_u0__F0_REG EQU CYREG_B0_UDB13_F0
UART_LOG_BUART_sTX_TxShifter_u0__F1_REG EQU CYREG_B0_UDB13_F1
UART_LOG_BUART_sTX_TxSts__0__MASK EQU 0x01
UART_LOG_BUART_sTX_TxSts__0__POS EQU 0
UART_LOG_BUART_sTX_TxSts__1__MASK EQU 0x02
UART_LOG_BUART_sTX_TxSts__1__POS EQU 1
UART_LOG_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB14_15_ACTL
UART_LOG_BUART_sTX_TxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB14_15_ST
UART_LOG_BUART_sTX_TxSts__2__MASK EQU 0x04
UART_LOG_BUART_sTX_TxSts__2__POS EQU 2
UART_LOG_BUART_sTX_TxSts__3__MASK EQU 0x08
UART_LOG_BUART_sTX_TxSts__3__POS EQU 3
UART_LOG_BUART_sTX_TxSts__MASK EQU 0x0F
UART_LOG_BUART_sTX_TxSts__MASK_REG EQU CYREG_B0_UDB14_MSK
UART_LOG_BUART_sTX_TxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB14_ACTL
UART_LOG_BUART_sTX_TxSts__STATUS_REG EQU CYREG_B0_UDB14_ST
UART_LOG_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG1_CFG0
UART_LOG_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG1_CFG1
UART_LOG_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG1_CFG2
UART_LOG_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
UART_LOG_IntClock__INDEX EQU 0x01
UART_LOG_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
UART_LOG_IntClock__PM_ACT_MSK EQU 0x02
UART_LOG_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
UART_LOG_IntClock__PM_STBY_MSK EQU 0x02
UART_LOG_Rx__0__INTTYPE EQU CYREG_PICU12_INTTYPE6
UART_LOG_Rx__0__MASK EQU 0x40
UART_LOG_Rx__0__PC EQU CYREG_PRT12_PC6
UART_LOG_Rx__0__PORT EQU 12
UART_LOG_Rx__0__SHIFT EQU 6
UART_LOG_Rx__AG EQU CYREG_PRT12_AG
UART_LOG_Rx__BIE EQU CYREG_PRT12_BIE
UART_LOG_Rx__BIT_MASK EQU CYREG_PRT12_BIT_MASK
UART_LOG_Rx__BYP EQU CYREG_PRT12_BYP
UART_LOG_Rx__DM0 EQU CYREG_PRT12_DM0
UART_LOG_Rx__DM1 EQU CYREG_PRT12_DM1
UART_LOG_Rx__DM2 EQU CYREG_PRT12_DM2
UART_LOG_Rx__DR EQU CYREG_PRT12_DR
UART_LOG_Rx__INP_DIS EQU CYREG_PRT12_INP_DIS
UART_LOG_Rx__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
UART_LOG_Rx__MASK EQU 0x40
UART_LOG_Rx__PORT EQU 12
UART_LOG_Rx__PRT EQU CYREG_PRT12_PRT
UART_LOG_Rx__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
UART_LOG_Rx__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
UART_LOG_Rx__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
UART_LOG_Rx__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
UART_LOG_Rx__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
UART_LOG_Rx__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
UART_LOG_Rx__PS EQU CYREG_PRT12_PS
UART_LOG_Rx__SHIFT EQU 6
UART_LOG_Rx__SIO_CFG EQU CYREG_PRT12_SIO_CFG
UART_LOG_Rx__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
UART_LOG_Rx__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
UART_LOG_Rx__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
UART_LOG_Rx__SLW EQU CYREG_PRT12_SLW
UART_LOG_Tx__0__INTTYPE EQU CYREG_PICU12_INTTYPE7
UART_LOG_Tx__0__MASK EQU 0x80
UART_LOG_Tx__0__PC EQU CYREG_PRT12_PC7
UART_LOG_Tx__0__PORT EQU 12
UART_LOG_Tx__0__SHIFT EQU 7
UART_LOG_Tx__AG EQU CYREG_PRT12_AG
UART_LOG_Tx__BIE EQU CYREG_PRT12_BIE
UART_LOG_Tx__BIT_MASK EQU CYREG_PRT12_BIT_MASK
UART_LOG_Tx__BYP EQU CYREG_PRT12_BYP
UART_LOG_Tx__DM0 EQU CYREG_PRT12_DM0
UART_LOG_Tx__DM1 EQU CYREG_PRT12_DM1
UART_LOG_Tx__DM2 EQU CYREG_PRT12_DM2
UART_LOG_Tx__DR EQU CYREG_PRT12_DR
UART_LOG_Tx__INP_DIS EQU CYREG_PRT12_INP_DIS
UART_LOG_Tx__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
UART_LOG_Tx__MASK EQU 0x80
UART_LOG_Tx__PORT EQU 12
UART_LOG_Tx__PRT EQU CYREG_PRT12_PRT
UART_LOG_Tx__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
UART_LOG_Tx__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
UART_LOG_Tx__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
UART_LOG_Tx__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
UART_LOG_Tx__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
UART_LOG_Tx__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
UART_LOG_Tx__PS EQU CYREG_PRT12_PS
UART_LOG_Tx__SHIFT EQU 7
UART_LOG_Tx__SIO_CFG EQU CYREG_PRT12_SIO_CFG
UART_LOG_Tx__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
UART_LOG_Tx__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
UART_LOG_Tx__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
UART_LOG_Tx__SLW EQU CYREG_PRT12_SLW

; PWM_RGB_G
PWM_RGB_G_PWMUDB_genblk1_ctrlreg__7__MASK EQU 0x80
PWM_RGB_G_PWMUDB_genblk1_ctrlreg__7__POS EQU 7
PWM_RGB_G_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB15_ACTL
PWM_RGB_G_PWMUDB_genblk1_ctrlreg__CONTROL_REG EQU CYREG_B0_UDB15_CTL
PWM_RGB_G_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG EQU CYREG_B0_UDB15_ST_CTL
PWM_RGB_G_PWMUDB_genblk1_ctrlreg__COUNT_REG EQU CYREG_B0_UDB15_CTL
PWM_RGB_G_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG EQU CYREG_B0_UDB15_ST_CTL
PWM_RGB_G_PWMUDB_genblk1_ctrlreg__MASK EQU 0x80
PWM_RGB_G_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL
PWM_RGB_G_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL
PWM_RGB_G_PWMUDB_genblk1_ctrlreg__PERIOD_REG EQU CYREG_B0_UDB15_MSK
PWM_RGB_G_PWMUDB_genblk8_stsreg__0__MASK EQU 0x01
PWM_RGB_G_PWMUDB_genblk8_stsreg__0__POS EQU 0
PWM_RGB_G_PWMUDB_genblk8_stsreg__2__MASK EQU 0x04
PWM_RGB_G_PWMUDB_genblk8_stsreg__2__POS EQU 2
PWM_RGB_G_PWMUDB_genblk8_stsreg__3__MASK EQU 0x08
PWM_RGB_G_PWMUDB_genblk8_stsreg__3__POS EQU 3
PWM_RGB_G_PWMUDB_genblk8_stsreg__MASK EQU 0x0D
PWM_RGB_G_PWMUDB_genblk8_stsreg__MASK_REG EQU CYREG_B0_UDB15_MSK
PWM_RGB_G_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL
PWM_RGB_G_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL
PWM_RGB_G_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB15_ACTL
PWM_RGB_G_PWMUDB_genblk8_stsreg__STATUS_CNT_REG EQU CYREG_B0_UDB15_ST_CTL
PWM_RGB_G_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG EQU CYREG_B0_UDB15_ST_CTL
PWM_RGB_G_PWMUDB_genblk8_stsreg__STATUS_REG EQU CYREG_B0_UDB15_ST
PWM_RGB_G_PWMUDB_sP8_pwmdp_u0__A0_A1_REG EQU CYREG_B0_UDB15_A0_A1
PWM_RGB_G_PWMUDB_sP8_pwmdp_u0__A0_REG EQU CYREG_B0_UDB15_A0
PWM_RGB_G_PWMUDB_sP8_pwmdp_u0__A1_REG EQU CYREG_B0_UDB15_A1
PWM_RGB_G_PWMUDB_sP8_pwmdp_u0__D0_D1_REG EQU CYREG_B0_UDB15_D0_D1
PWM_RGB_G_PWMUDB_sP8_pwmdp_u0__D0_REG EQU CYREG_B0_UDB15_D0
PWM_RGB_G_PWMUDB_sP8_pwmdp_u0__D1_REG EQU CYREG_B0_UDB15_D1
PWM_RGB_G_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB15_ACTL
PWM_RGB_G_PWMUDB_sP8_pwmdp_u0__F0_F1_REG EQU CYREG_B0_UDB15_F0_F1
PWM_RGB_G_PWMUDB_sP8_pwmdp_u0__F0_REG EQU CYREG_B0_UDB15_F0
PWM_RGB_G_PWMUDB_sP8_pwmdp_u0__F1_REG EQU CYREG_B0_UDB15_F1
PWM_RGB_G_PWMUDB_sP8_pwmdp_u0__MSK_DP_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL
PWM_RGB_G_PWMUDB_sP8_pwmdp_u0__PER_DP_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL

; led_rgb_g
led_rgb_g__0__INTTYPE EQU CYREG_PICU2_INTTYPE4
led_rgb_g__0__MASK EQU 0x10
led_rgb_g__0__PC EQU CYREG_PRT2_PC4
led_rgb_g__0__PORT EQU 2
led_rgb_g__0__SHIFT EQU 4
led_rgb_g__AG EQU CYREG_PRT2_AG
led_rgb_g__AMUX EQU CYREG_PRT2_AMUX
led_rgb_g__BIE EQU CYREG_PRT2_BIE
led_rgb_g__BIT_MASK EQU CYREG_PRT2_BIT_MASK
led_rgb_g__BYP EQU CYREG_PRT2_BYP
led_rgb_g__CTL EQU CYREG_PRT2_CTL
led_rgb_g__DM0 EQU CYREG_PRT2_DM0
led_rgb_g__DM1 EQU CYREG_PRT2_DM1
led_rgb_g__DM2 EQU CYREG_PRT2_DM2
led_rgb_g__DR EQU CYREG_PRT2_DR
led_rgb_g__INP_DIS EQU CYREG_PRT2_INP_DIS
led_rgb_g__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
led_rgb_g__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
led_rgb_g__LCD_EN EQU CYREG_PRT2_LCD_EN
led_rgb_g__MASK EQU 0x10
led_rgb_g__PORT EQU 2
led_rgb_g__PRT EQU CYREG_PRT2_PRT
led_rgb_g__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
led_rgb_g__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
led_rgb_g__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
led_rgb_g__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
led_rgb_g__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
led_rgb_g__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
led_rgb_g__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
led_rgb_g__PS EQU CYREG_PRT2_PS
led_rgb_g__SHIFT EQU 4
led_rgb_g__SLW EQU CYREG_PRT2_SLW

; WDT_Button
WDT_Button__0__INTTYPE EQU CYREG_PICU0_INTTYPE3
WDT_Button__0__MASK EQU 0x08
WDT_Button__0__PC EQU CYREG_PRT0_PC3
WDT_Button__0__PORT EQU 0
WDT_Button__0__SHIFT EQU 3
WDT_Button__AG EQU CYREG_PRT0_AG
WDT_Button__AMUX EQU CYREG_PRT0_AMUX
WDT_Button__BIE EQU CYREG_PRT0_BIE
WDT_Button__BIT_MASK EQU CYREG_PRT0_BIT_MASK
WDT_Button__BYP EQU CYREG_PRT0_BYP
WDT_Button__CTL EQU CYREG_PRT0_CTL
WDT_Button__DM0 EQU CYREG_PRT0_DM0
WDT_Button__DM1 EQU CYREG_PRT0_DM1
WDT_Button__DM2 EQU CYREG_PRT0_DM2
WDT_Button__DR EQU CYREG_PRT0_DR
WDT_Button__INP_DIS EQU CYREG_PRT0_INP_DIS
WDT_Button__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
WDT_Button__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
WDT_Button__LCD_EN EQU CYREG_PRT0_LCD_EN
WDT_Button__MASK EQU 0x08
WDT_Button__PORT EQU 0
WDT_Button__PRT EQU CYREG_PRT0_PRT
WDT_Button__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
WDT_Button__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
WDT_Button__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
WDT_Button__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
WDT_Button__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
WDT_Button__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
WDT_Button__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
WDT_Button__PS EQU CYREG_PRT0_PS
WDT_Button__SHIFT EQU 3
WDT_Button__SLW EQU CYREG_PRT0_SLW

; isr_button1
isr_button1__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
isr_button1__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
isr_button1__INTC_MASK EQU 0x02
isr_button1__INTC_NUMBER EQU 1
isr_button1__INTC_PRIOR_NUM EQU 7
isr_button1__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_1
isr_button1__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
isr_button1__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; JOYSTICK_ADC_X
JOYSTICK_ADC_X__0__INTTYPE EQU CYREG_PICU0_INTTYPE0
JOYSTICK_ADC_X__0__MASK EQU 0x01
JOYSTICK_ADC_X__0__PC EQU CYREG_PRT0_PC0
JOYSTICK_ADC_X__0__PORT EQU 0
JOYSTICK_ADC_X__0__SHIFT EQU 0
JOYSTICK_ADC_X__AG EQU CYREG_PRT0_AG
JOYSTICK_ADC_X__AMUX EQU CYREG_PRT0_AMUX
JOYSTICK_ADC_X__BIE EQU CYREG_PRT0_BIE
JOYSTICK_ADC_X__BIT_MASK EQU CYREG_PRT0_BIT_MASK
JOYSTICK_ADC_X__BYP EQU CYREG_PRT0_BYP
JOYSTICK_ADC_X__CTL EQU CYREG_PRT0_CTL
JOYSTICK_ADC_X__DM0 EQU CYREG_PRT0_DM0
JOYSTICK_ADC_X__DM1 EQU CYREG_PRT0_DM1
JOYSTICK_ADC_X__DM2 EQU CYREG_PRT0_DM2
JOYSTICK_ADC_X__DR EQU CYREG_PRT0_DR
JOYSTICK_ADC_X__INP_DIS EQU CYREG_PRT0_INP_DIS
JOYSTICK_ADC_X__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
JOYSTICK_ADC_X__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
JOYSTICK_ADC_X__LCD_EN EQU CYREG_PRT0_LCD_EN
JOYSTICK_ADC_X__MASK EQU 0x01
JOYSTICK_ADC_X__PORT EQU 0
JOYSTICK_ADC_X__PRT EQU CYREG_PRT0_PRT
JOYSTICK_ADC_X__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
JOYSTICK_ADC_X__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
JOYSTICK_ADC_X__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
JOYSTICK_ADC_X__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
JOYSTICK_ADC_X__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
JOYSTICK_ADC_X__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
JOYSTICK_ADC_X__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
JOYSTICK_ADC_X__PS EQU CYREG_PRT0_PS
JOYSTICK_ADC_X__SHIFT EQU 0
JOYSTICK_ADC_X__SLW EQU CYREG_PRT0_SLW

; JOYSTICK_ADC_Y
JOYSTICK_ADC_Y__0__INTTYPE EQU CYREG_PICU0_INTTYPE1
JOYSTICK_ADC_Y__0__MASK EQU 0x02
JOYSTICK_ADC_Y__0__PC EQU CYREG_PRT0_PC1
JOYSTICK_ADC_Y__0__PORT EQU 0
JOYSTICK_ADC_Y__0__SHIFT EQU 1
JOYSTICK_ADC_Y__AG EQU CYREG_PRT0_AG
JOYSTICK_ADC_Y__AMUX EQU CYREG_PRT0_AMUX
JOYSTICK_ADC_Y__BIE EQU CYREG_PRT0_BIE
JOYSTICK_ADC_Y__BIT_MASK EQU CYREG_PRT0_BIT_MASK
JOYSTICK_ADC_Y__BYP EQU CYREG_PRT0_BYP
JOYSTICK_ADC_Y__CTL EQU CYREG_PRT0_CTL
JOYSTICK_ADC_Y__DM0 EQU CYREG_PRT0_DM0
JOYSTICK_ADC_Y__DM1 EQU CYREG_PRT0_DM1
JOYSTICK_ADC_Y__DM2 EQU CYREG_PRT0_DM2
JOYSTICK_ADC_Y__DR EQU CYREG_PRT0_DR
JOYSTICK_ADC_Y__INP_DIS EQU CYREG_PRT0_INP_DIS
JOYSTICK_ADC_Y__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
JOYSTICK_ADC_Y__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
JOYSTICK_ADC_Y__LCD_EN EQU CYREG_PRT0_LCD_EN
JOYSTICK_ADC_Y__MASK EQU 0x02
JOYSTICK_ADC_Y__PORT EQU 0
JOYSTICK_ADC_Y__PRT EQU CYREG_PRT0_PRT
JOYSTICK_ADC_Y__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
JOYSTICK_ADC_Y__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
JOYSTICK_ADC_Y__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
JOYSTICK_ADC_Y__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
JOYSTICK_ADC_Y__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
JOYSTICK_ADC_Y__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
JOYSTICK_ADC_Y__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
JOYSTICK_ADC_Y__PS EQU CYREG_PRT0_PS
JOYSTICK_ADC_Y__SHIFT EQU 1
JOYSTICK_ADC_Y__SLW EQU CYREG_PRT0_SLW

; JOYSTICK_ADC_XY
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB09_10_ACTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB09_10_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB09_10_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB09_10_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB09_10_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB09_10_MSK
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB09_10_MSK
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB09_10_MSK
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB09_10_MSK
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB09_ACTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__CONTROL_REG EQU CYREG_B0_UDB09_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__CONTROL_ST_REG EQU CYREG_B0_UDB09_ST_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__COUNT_REG EQU CYREG_B0_UDB09_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__COUNT_ST_REG EQU CYREG_B0_UDB09_ST_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB09_MSK_ACTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB09_MSK_ACTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter__PERIOD_REG EQU CYREG_B0_UDB09_MSK
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB09_10_ACTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter_ST__16BIT_STATUS_REG EQU CYREG_B0_UDB09_10_ST
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter_ST__MASK_REG EQU CYREG_B0_UDB09_MSK
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB09_MSK_ACTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB09_MSK_ACTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB09_ACTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter_ST__STATUS_CNT_REG EQU CYREG_B0_UDB09_ST_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter_ST__STATUS_CONTROL_REG EQU CYREG_B0_UDB09_ST_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_ChannelCounter_ST__STATUS_REG EQU CYREG_B0_UDB09_ST
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__0__MASK EQU 0x01
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__0__POS EQU 0
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__1__MASK EQU 0x02
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__1__POS EQU 1
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB09_10_ACTL
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB09_10_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB09_10_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB09_10_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB09_10_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB09_10_MSK
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB09_10_MSK
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB09_10_MSK
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB09_10_MSK
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB09_ACTL
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__CONTROL_REG EQU CYREG_B1_UDB09_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__CONTROL_ST_REG EQU CYREG_B1_UDB09_ST_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__COUNT_REG EQU CYREG_B1_UDB09_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__COUNT_ST_REG EQU CYREG_B1_UDB09_ST_CTL
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__MASK EQU 0x03
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
JOYSTICK_ADC_XY_bSAR_SEQ_CtrlReg__PERIOD_REG EQU CYREG_B1_UDB09_MSK
JOYSTICK_ADC_XY_bSAR_SEQ_EOCSts__0__MASK EQU 0x01
JOYSTICK_ADC_XY_bSAR_SEQ_EOCSts__0__POS EQU 0
JOYSTICK_ADC_XY_bSAR_SEQ_EOCSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
JOYSTICK_ADC_XY_bSAR_SEQ_EOCSts__16BIT_STATUS_REG EQU CYREG_B0_UDB13_14_ST
JOYSTICK_ADC_XY_bSAR_SEQ_EOCSts__MASK EQU 0x01
JOYSTICK_ADC_XY_bSAR_SEQ_EOCSts__MASK_REG EQU CYREG_B0_UDB13_MSK
JOYSTICK_ADC_XY_bSAR_SEQ_EOCSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
JOYSTICK_ADC_XY_bSAR_SEQ_EOCSts__STATUS_REG EQU CYREG_B0_UDB13_ST
JOYSTICK_ADC_XY_FinalBuf__DRQ_CTL EQU CYREG_IDMUX_DRQ_CTL0
JOYSTICK_ADC_XY_FinalBuf__DRQ_NUMBER EQU 0
JOYSTICK_ADC_XY_FinalBuf__NUMBEROF_TDS EQU 0
JOYSTICK_ADC_XY_FinalBuf__PRIORITY EQU 2
JOYSTICK_ADC_XY_FinalBuf__TERMIN_EN EQU 0
JOYSTICK_ADC_XY_FinalBuf__TERMIN_SEL EQU 0
JOYSTICK_ADC_XY_FinalBuf__TERMOUT0_EN EQU 1
JOYSTICK_ADC_XY_FinalBuf__TERMOUT0_SEL EQU 0
JOYSTICK_ADC_XY_FinalBuf__TERMOUT1_EN EQU 0
JOYSTICK_ADC_XY_FinalBuf__TERMOUT1_SEL EQU 0
JOYSTICK_ADC_XY_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
JOYSTICK_ADC_XY_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
JOYSTICK_ADC_XY_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
JOYSTICK_ADC_XY_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
JOYSTICK_ADC_XY_IntClock__INDEX EQU 0x00
JOYSTICK_ADC_XY_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
JOYSTICK_ADC_XY_IntClock__PM_ACT_MSK EQU 0x01
JOYSTICK_ADC_XY_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
JOYSTICK_ADC_XY_IntClock__PM_STBY_MSK EQU 0x01
JOYSTICK_ADC_XY_IRQ__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
JOYSTICK_ADC_XY_IRQ__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
JOYSTICK_ADC_XY_IRQ__INTC_MASK EQU 0x01
JOYSTICK_ADC_XY_IRQ__INTC_NUMBER EQU 0
JOYSTICK_ADC_XY_IRQ__INTC_PRIOR_NUM EQU 7
JOYSTICK_ADC_XY_IRQ__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
JOYSTICK_ADC_XY_IRQ__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
JOYSTICK_ADC_XY_IRQ__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0
JOYSTICK_ADC_XY_SAR_ADC_SAR__CLK EQU CYREG_SAR0_CLK
JOYSTICK_ADC_XY_SAR_ADC_SAR__CSR0 EQU CYREG_SAR0_CSR0
JOYSTICK_ADC_XY_SAR_ADC_SAR__CSR1 EQU CYREG_SAR0_CSR1
JOYSTICK_ADC_XY_SAR_ADC_SAR__CSR2 EQU CYREG_SAR0_CSR2
JOYSTICK_ADC_XY_SAR_ADC_SAR__CSR3 EQU CYREG_SAR0_CSR3
JOYSTICK_ADC_XY_SAR_ADC_SAR__CSR4 EQU CYREG_SAR0_CSR4
JOYSTICK_ADC_XY_SAR_ADC_SAR__CSR5 EQU CYREG_SAR0_CSR5
JOYSTICK_ADC_XY_SAR_ADC_SAR__CSR6 EQU CYREG_SAR0_CSR6
JOYSTICK_ADC_XY_SAR_ADC_SAR__PM_ACT_CFG EQU CYREG_PM_ACT_CFG11
JOYSTICK_ADC_XY_SAR_ADC_SAR__PM_ACT_MSK EQU 0x01
JOYSTICK_ADC_XY_SAR_ADC_SAR__PM_STBY_CFG EQU CYREG_PM_STBY_CFG11
JOYSTICK_ADC_XY_SAR_ADC_SAR__PM_STBY_MSK EQU 0x01
JOYSTICK_ADC_XY_SAR_ADC_SAR__SW0 EQU CYREG_SAR0_SW0
JOYSTICK_ADC_XY_SAR_ADC_SAR__SW2 EQU CYREG_SAR0_SW2
JOYSTICK_ADC_XY_SAR_ADC_SAR__SW3 EQU CYREG_SAR0_SW3
JOYSTICK_ADC_XY_SAR_ADC_SAR__SW4 EQU CYREG_SAR0_SW4
JOYSTICK_ADC_XY_SAR_ADC_SAR__SW6 EQU CYREG_SAR0_SW6
JOYSTICK_ADC_XY_SAR_ADC_SAR__TR0 EQU CYREG_SAR0_TR0
JOYSTICK_ADC_XY_SAR_ADC_SAR__WRK0 EQU CYREG_SAR0_WRK0
JOYSTICK_ADC_XY_SAR_ADC_SAR__WRK1 EQU CYREG_SAR0_WRK1
JOYSTICK_ADC_XY_TempBuf__DRQ_CTL EQU CYREG_IDMUX_DRQ_CTL0
JOYSTICK_ADC_XY_TempBuf__DRQ_NUMBER EQU 1
JOYSTICK_ADC_XY_TempBuf__NUMBEROF_TDS EQU 0
JOYSTICK_ADC_XY_TempBuf__PRIORITY EQU 2
JOYSTICK_ADC_XY_TempBuf__TERMIN_EN EQU 0
JOYSTICK_ADC_XY_TempBuf__TERMIN_SEL EQU 0
JOYSTICK_ADC_XY_TempBuf__TERMOUT0_EN EQU 1
JOYSTICK_ADC_XY_TempBuf__TERMOUT0_SEL EQU 1
JOYSTICK_ADC_XY_TempBuf__TERMOUT1_EN EQU 0
JOYSTICK_ADC_XY_TempBuf__TERMOUT1_SEL EQU 0

; Brakelight_LED_RED
Brakelight_LED_RED__0__INTTYPE EQU CYREG_PICU0_INTTYPE6
Brakelight_LED_RED__0__MASK EQU 0x40
Brakelight_LED_RED__0__PC EQU CYREG_PRT0_PC6
Brakelight_LED_RED__0__PORT EQU 0
Brakelight_LED_RED__0__SHIFT EQU 6
Brakelight_LED_RED__AG EQU CYREG_PRT0_AG
Brakelight_LED_RED__AMUX EQU CYREG_PRT0_AMUX
Brakelight_LED_RED__BIE EQU CYREG_PRT0_BIE
Brakelight_LED_RED__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Brakelight_LED_RED__BYP EQU CYREG_PRT0_BYP
Brakelight_LED_RED__CTL EQU CYREG_PRT0_CTL
Brakelight_LED_RED__DM0 EQU CYREG_PRT0_DM0
Brakelight_LED_RED__DM1 EQU CYREG_PRT0_DM1
Brakelight_LED_RED__DM2 EQU CYREG_PRT0_DM2
Brakelight_LED_RED__DR EQU CYREG_PRT0_DR
Brakelight_LED_RED__INP_DIS EQU CYREG_PRT0_INP_DIS
Brakelight_LED_RED__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
Brakelight_LED_RED__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Brakelight_LED_RED__LCD_EN EQU CYREG_PRT0_LCD_EN
Brakelight_LED_RED__MASK EQU 0x40
Brakelight_LED_RED__PORT EQU 0
Brakelight_LED_RED__PRT EQU CYREG_PRT0_PRT
Brakelight_LED_RED__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Brakelight_LED_RED__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Brakelight_LED_RED__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Brakelight_LED_RED__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Brakelight_LED_RED__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Brakelight_LED_RED__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Brakelight_LED_RED__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Brakelight_LED_RED__PS EQU CYREG_PRT0_PS
Brakelight_LED_RED__SHIFT EQU 6
Brakelight_LED_RED__SLW EQU CYREG_PRT0_SLW

; Miscellaneous
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 26
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E161069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 26
CYDEV_CHIP_MEMBER_4AA EQU 25
CYDEV_CHIP_MEMBER_4AB EQU 30
CYDEV_CHIP_MEMBER_4AC EQU 14
CYDEV_CHIP_MEMBER_4AD EQU 15
CYDEV_CHIP_MEMBER_4AE EQU 16
CYDEV_CHIP_MEMBER_4D EQU 20
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 27
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 24
CYDEV_CHIP_MEMBER_4I EQU 32
CYDEV_CHIP_MEMBER_4J EQU 21
CYDEV_CHIP_MEMBER_4K EQU 22
CYDEV_CHIP_MEMBER_4L EQU 31
CYDEV_CHIP_MEMBER_4M EQU 29
CYDEV_CHIP_MEMBER_4N EQU 11
CYDEV_CHIP_MEMBER_4O EQU 8
CYDEV_CHIP_MEMBER_4P EQU 28
CYDEV_CHIP_MEMBER_4Q EQU 17
CYDEV_CHIP_MEMBER_4R EQU 9
CYDEV_CHIP_MEMBER_4S EQU 12
CYDEV_CHIP_MEMBER_4T EQU 10
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 23
CYDEV_CHIP_MEMBER_4W EQU 13
CYDEV_CHIP_MEMBER_4X EQU 7
CYDEV_CHIP_MEMBER_4Y EQU 18
CYDEV_CHIP_MEMBER_4Z EQU 19
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 33
CYDEV_CHIP_MEMBER_FM3 EQU 37
CYDEV_CHIP_MEMBER_FM4 EQU 38
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 34
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 35
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 36
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4AA_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AB_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AC_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AD_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AE_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4W_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4X_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Y_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Z_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000003
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000003
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END
