/*******************************************************************************
* File Name: Sel_A_7_Seg.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Sel_A_7_Seg_H) /* Pins Sel_A_7_Seg_H */
#define CY_PINS_Sel_A_7_Seg_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sel_A_7_Seg_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sel_A_7_Seg__PORT == 15 && ((Sel_A_7_Seg__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Sel_A_7_Seg_Write(uint8 value);
void    Sel_A_7_Seg_SetDriveMode(uint8 mode);
uint8   Sel_A_7_Seg_ReadDataReg(void);
uint8   Sel_A_7_Seg_Read(void);
void    Sel_A_7_Seg_SetInterruptMode(uint16 position, uint16 mode);
uint8   Sel_A_7_Seg_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Sel_A_7_Seg_SetDriveMode() function.
     *  @{
     */
        #define Sel_A_7_Seg_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Sel_A_7_Seg_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Sel_A_7_Seg_DM_RES_UP          PIN_DM_RES_UP
        #define Sel_A_7_Seg_DM_RES_DWN         PIN_DM_RES_DWN
        #define Sel_A_7_Seg_DM_OD_LO           PIN_DM_OD_LO
        #define Sel_A_7_Seg_DM_OD_HI           PIN_DM_OD_HI
        #define Sel_A_7_Seg_DM_STRONG          PIN_DM_STRONG
        #define Sel_A_7_Seg_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Sel_A_7_Seg_MASK               Sel_A_7_Seg__MASK
#define Sel_A_7_Seg_SHIFT              Sel_A_7_Seg__SHIFT
#define Sel_A_7_Seg_WIDTH              1u

/* Interrupt constants */
#if defined(Sel_A_7_Seg__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Sel_A_7_Seg_SetInterruptMode() function.
     *  @{
     */
        #define Sel_A_7_Seg_INTR_NONE      (uint16)(0x0000u)
        #define Sel_A_7_Seg_INTR_RISING    (uint16)(0x0001u)
        #define Sel_A_7_Seg_INTR_FALLING   (uint16)(0x0002u)
        #define Sel_A_7_Seg_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Sel_A_7_Seg_INTR_MASK      (0x01u) 
#endif /* (Sel_A_7_Seg__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sel_A_7_Seg_PS                     (* (reg8 *) Sel_A_7_Seg__PS)
/* Data Register */
#define Sel_A_7_Seg_DR                     (* (reg8 *) Sel_A_7_Seg__DR)
/* Port Number */
#define Sel_A_7_Seg_PRT_NUM                (* (reg8 *) Sel_A_7_Seg__PRT) 
/* Connect to Analog Globals */                                                  
#define Sel_A_7_Seg_AG                     (* (reg8 *) Sel_A_7_Seg__AG)                       
/* Analog MUX bux enable */
#define Sel_A_7_Seg_AMUX                   (* (reg8 *) Sel_A_7_Seg__AMUX) 
/* Bidirectional Enable */                                                        
#define Sel_A_7_Seg_BIE                    (* (reg8 *) Sel_A_7_Seg__BIE)
/* Bit-mask for Aliased Register Access */
#define Sel_A_7_Seg_BIT_MASK               (* (reg8 *) Sel_A_7_Seg__BIT_MASK)
/* Bypass Enable */
#define Sel_A_7_Seg_BYP                    (* (reg8 *) Sel_A_7_Seg__BYP)
/* Port wide control signals */                                                   
#define Sel_A_7_Seg_CTL                    (* (reg8 *) Sel_A_7_Seg__CTL)
/* Drive Modes */
#define Sel_A_7_Seg_DM0                    (* (reg8 *) Sel_A_7_Seg__DM0) 
#define Sel_A_7_Seg_DM1                    (* (reg8 *) Sel_A_7_Seg__DM1)
#define Sel_A_7_Seg_DM2                    (* (reg8 *) Sel_A_7_Seg__DM2) 
/* Input Buffer Disable Override */
#define Sel_A_7_Seg_INP_DIS                (* (reg8 *) Sel_A_7_Seg__INP_DIS)
/* LCD Common or Segment Drive */
#define Sel_A_7_Seg_LCD_COM_SEG            (* (reg8 *) Sel_A_7_Seg__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sel_A_7_Seg_LCD_EN                 (* (reg8 *) Sel_A_7_Seg__LCD_EN)
/* Slew Rate Control */
#define Sel_A_7_Seg_SLW                    (* (reg8 *) Sel_A_7_Seg__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sel_A_7_Seg_PRTDSI__CAPS_SEL       (* (reg8 *) Sel_A_7_Seg__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sel_A_7_Seg_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sel_A_7_Seg__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sel_A_7_Seg_PRTDSI__OE_SEL0        (* (reg8 *) Sel_A_7_Seg__PRTDSI__OE_SEL0) 
#define Sel_A_7_Seg_PRTDSI__OE_SEL1        (* (reg8 *) Sel_A_7_Seg__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sel_A_7_Seg_PRTDSI__OUT_SEL0       (* (reg8 *) Sel_A_7_Seg__PRTDSI__OUT_SEL0) 
#define Sel_A_7_Seg_PRTDSI__OUT_SEL1       (* (reg8 *) Sel_A_7_Seg__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sel_A_7_Seg_PRTDSI__SYNC_OUT       (* (reg8 *) Sel_A_7_Seg__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Sel_A_7_Seg__SIO_CFG)
    #define Sel_A_7_Seg_SIO_HYST_EN        (* (reg8 *) Sel_A_7_Seg__SIO_HYST_EN)
    #define Sel_A_7_Seg_SIO_REG_HIFREQ     (* (reg8 *) Sel_A_7_Seg__SIO_REG_HIFREQ)
    #define Sel_A_7_Seg_SIO_CFG            (* (reg8 *) Sel_A_7_Seg__SIO_CFG)
    #define Sel_A_7_Seg_SIO_DIFF           (* (reg8 *) Sel_A_7_Seg__SIO_DIFF)
#endif /* (Sel_A_7_Seg__SIO_CFG) */

/* Interrupt Registers */
#if defined(Sel_A_7_Seg__INTSTAT)
    #define Sel_A_7_Seg_INTSTAT            (* (reg8 *) Sel_A_7_Seg__INTSTAT)
    #define Sel_A_7_Seg_SNAP               (* (reg8 *) Sel_A_7_Seg__SNAP)
    
	#define Sel_A_7_Seg_0_INTTYPE_REG 		(* (reg8 *) Sel_A_7_Seg__0__INTTYPE)
#endif /* (Sel_A_7_Seg__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sel_A_7_Seg_H */


/* [] END OF FILE */
