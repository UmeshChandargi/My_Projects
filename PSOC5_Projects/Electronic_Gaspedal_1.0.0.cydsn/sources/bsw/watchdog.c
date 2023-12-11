/**
* \file watchdog.c
* \author P. Fromm
* \date 29.8.17
*
* \brief watchdog driver
*
* \copyright Copyright ©2016
* Department of electrical engineering and information technology, Hochschule Darmstadt - University of applied sciences (h_da). All Rights Reserved.
* Permission to use, copy, modify, and distribute this software and its documentation for educational, and research purposes in the context of non-commercial
* (unless permitted by h_da) and official h_da projects, is hereby granted for enrolled students of h_da, provided that the above copyright notice,
* this paragraph and the following paragraph appear in all copies, modifications, and distributions.
* Contact Prof.Dr.-Ing. Peter Fromm, peter.fromm@h-da.de, Birkenweg 8 64295 Darmstadt - GERMANY for commercial requests.
*
* \warning This software is a PROTOTYPE version and is not designed or intended for use in production, especially not for safety-critical applications!
* The user represents and warrants that it will NOT use or redistribute the Software for such purposes.
* This prototype is for research purposes only. This software is provided "AS IS," without a warranty of any kind.
*/

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/

#include "project.h"
#include "watchdog.h"
#include <stdlib.h>
#include "CyLib.h"

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/
static uint8_t WDT_bitfield=0;
#ifdef DEBUG_STATIC
uint8_t debug=0;
#endif
/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/



/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/


/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

/**
* Activate the Watchdog Trigger
* \param WDT_TimeOut_t timeout - [IN] Timeout Period
* @return RC_SUCCESS
*/
RC_t WD_Start(WDT_TimeOut_t timeout)
{
    
    CyWdtStart(timeout, CYWDT_LPMODE_NOCHANGE); 

}

/**
* Service the Watchdog Trigger
* @return RC_SUCCESS
*/
RC_t WD_Trigger()
{
   if(WDT_bitfield==31)
    {
        WDT_bitfield=0;
        CyWdtClear();
    }
       
}

/**
* Checks the watchdog bit
* @return TRUE if watchdog reset bit was set
*/
boolean_t WD_CheckResetBit()
{
    #ifdef DEBUG_STATIC
    debug=2;
    char buffer[200];
    itoa(debug, buffer, 10);
    UART_LOG_PutString("debug in funct= ");
    UART_LOG_PutString(buffer);
    UART_LOG_PutString("\r");
    CyDelay(3000);
    #endif
    
    if(CyResetStatus==8) //The CyResetStatus variable is used to obtain value of RESET_SR0 register after a device reset.
    {
      return TRUE; 
    }
    else if(CyResetStatus==0)
    {
      return FALSE;
    }
    
}

/**
* sets the bit at the corresponding position
* @return TRUE if watchdog reset bit was set
*/
RC_t WD_Alive(uint8_t myBitPosition)
{
    uint8_t bitmask;
    bitmask = bitmask | (1<<myBitPosition);
    WDT_bitfield= WDT_bitfield | bitmask;
    
}

