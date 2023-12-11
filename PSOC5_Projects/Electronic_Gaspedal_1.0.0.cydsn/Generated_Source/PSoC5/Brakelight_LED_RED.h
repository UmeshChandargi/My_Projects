/*******************************************************************************
* File Name: Brakelight_LED_RED.h  
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

#if !defined(CY_PINS_Brakelight_LED_RED_H) /* Pins Brakelight_LED_RED_H */
#define CY_PINS_Brakelight_LED_RED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Brakelight_LED_RED_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Brakelight_LED_RED__PORT == 15 && ((Brakelight_LED_RED__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Brakelight_LED_RED_Write(uint8 value);
void    Brakelight_LED_RED_SetDriveMode(uint8 mode);
uint8   Brakelight_LED_RED_ReadDataReg(void);
uint8   Brakelight_LED_RED_Read(void);
void    Brakelight_LED_RED_SetInterruptMode(uint16 position, uint16 mode);
uint8   Brakelight_LED_RED_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Brakelight_LED_RED_SetDriveMode() function.
     *  @{
     */
        #define Brakelight_LED_RED_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Brakelight_LED_RED_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Brakelight_LED_RED_DM_RES_UP          PIN_DM_RES_UP
        #define Brakelight_LED_RED_DM_RES_DWN         PIN_DM_RES_DWN
        #define Brakelight_LED_RED_DM_OD_LO           PIN_DM_OD_LO
        #define Brakelight_LED_RED_DM_OD_HI           PIN_DM_OD_HI
        #define Brakelight_LED_RED_DM_STRONG          PIN_DM_STRONG
        #define Brakelight_LED_RED_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Brakelight_LED_RED_MASK               Brakelight_LED_RED__MASK
#define Brakelight_LED_RED_SHIFT              Brakelight_LED_RED__SHIFT
#define Brakelight_LED_RED_WIDTH              1u

/* Interrupt constants */
#if defined(Brakelight_LED_RED__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Brakelight_LED_RED_SetInterruptMode() function.
     *  @{
     */
        #define Brakelight_LED_RED_INTR_NONE      (uint16)(0x0000u)
        #define Brakelight_LED_RED_INTR_RISING    (uint16)(0x0001u)
        #define Brakelight_LED_RED_INTR_FALLING   (uint16)(0x0002u)
        #define Brakelight_LED_RED_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Brakelight_LED_RED_INTR_MASK      (0x01u) 
#endif /* (Brakelight_LED_RED__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Brakelight_LED_RED_PS                     (* (reg8 *) Brakelight_LED_RED__PS)
/* Data Register */
#define Brakelight_LED_RED_DR                     (* (reg8 *) Brakelight_LED_RED__DR)
/* Port Number */
#define Brakelight_LED_RED_PRT_NUM                (* (reg8 *) Brakelight_LED_RED__PRT) 
/* Connect to Analog Globals */                                                  
#define Brakelight_LED_RED_AG                     (* (reg8 *) Brakelight_LED_RED__AG)                       
/* Analog MUX bux enable */
#define Brakelight_LED_RED_AMUX                   (* (reg8 *) Brakelight_LED_RED__AMUX) 
/* Bidirectional Enable */                                                        
#define Brakelight_LED_RED_BIE                    (* (reg8 *) Brakelight_LED_RED__BIE)
/* Bit-mask for Aliased Register Access */
#define Brakelight_LED_RED_BIT_MASK               (* (reg8 *) Brakelight_LED_RED__BIT_MASK)
/* Bypass Enable */
#define Brakelight_LED_RED_BYP                    (* (reg8 *) Brakelight_LED_RED__BYP)
/* Port wide control signals */                                                   
#define Brakelight_LED_RED_CTL                    (* (reg8 *) Brakelight_LED_RED__CTL)
/* Drive Modes */
#define Brakelight_LED_RED_DM0                    (* (reg8 *) Brakelight_LED_RED__DM0) 
#define Brakelight_LED_RED_DM1                    (* (reg8 *) Brakelight_LED_RED__DM1)
#define Brakelight_LED_RED_DM2                    (* (reg8 *) Brakelight_LED_RED__DM2) 
/* Input Buffer Disable Override */
#define Brakelight_LED_RED_INP_DIS                (* (reg8 *) Brakelight_LED_RED__INP_DIS)
/* LCD Common or Segment Drive */
#define Brakelight_LED_RED_LCD_COM_SEG            (* (reg8 *) Brakelight_LED_RED__LCD_COM_SEG)
/* Enable Segment LCD */
#define Brakelight_LED_RED_LCD_EN                 (* (reg8 *) Brakelight_LED_RED__LCD_EN)
/* Slew Rate Control */
#define Brakelight_LED_RED_SLW                    (* (reg8 *) Brakelight_LED_RED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Brakelight_LED_RED_PRTDSI__CAPS_SEL       (* (reg8 *) Brakelight_LED_RED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Brakelight_LED_RED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Brakelight_LED_RED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Brakelight_LED_RED_PRTDSI__OE_SEL0        (* (reg8 *) Brakelight_LED_RED__PRTDSI__OE_SEL0) 
#define Brakelight_LED_RED_PRTDSI__OE_SEL1        (* (reg8 *) Brakelight_LED_RED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Brakelight_LED_RED_PRTDSI__OUT_SEL0       (* (reg8 *) Brakelight_LED_RED__PRTDSI__OUT_SEL0) 
#define Brakelight_LED_RED_PRTDSI__OUT_SEL1       (* (reg8 *) Brakelight_LED_RED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Brakelight_LED_RED_PRTDSI__SYNC_OUT       (* (reg8 *) Brakelight_LED_RED__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Brakelight_LED_RED__SIO_CFG)
    #define Brakelight_LED_RED_SIO_HYST_EN        (* (reg8 *) Brakelight_LED_RED__SIO_HYST_EN)
    #define Brakelight_LED_RED_SIO_REG_HIFREQ     (* (reg8 *) Brakelight_LED_RED__SIO_REG_HIFREQ)
    #define Brakelight_LED_RED_SIO_CFG            (* (reg8 *) Brakelight_LED_RED__SIO_CFG)
    #define Brakelight_LED_RED_SIO_DIFF           (* (reg8 *) Brakelight_LED_RED__SIO_DIFF)
#endif /* (Brakelight_LED_RED__SIO_CFG) */

/* Interrupt Registers */
#if defined(Brakelight_LED_RED__INTSTAT)
    #define Brakelight_LED_RED_INTSTAT            (* (reg8 *) Brakelight_LED_RED__INTSTAT)
    #define Brakelight_LED_RED_SNAP               (* (reg8 *) Brakelight_LED_RED__SNAP)
    
	#define Brakelight_LED_RED_0_INTTYPE_REG 		(* (reg8 *) Brakelight_LED_RED__0__INTTYPE)
#endif /* (Brakelight_LED_RED__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Brakelight_LED_RED_H */


/* [] END OF FILE */
