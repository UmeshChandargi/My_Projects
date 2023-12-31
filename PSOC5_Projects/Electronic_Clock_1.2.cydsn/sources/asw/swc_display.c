/*
 * Filename: swc_display.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Software component for TFT data display
 * name: swc_Display
 * shortname: Display
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "swc_display.h"



/* USER CODE START SWC_DISPLAY_INCLUDE */

/* USER CODE END SWC_DISPLAY_INCLUDE */


#include "sp_common.h"

/* USER CODE START SWC_DISPLAY_USERDEFINITIONS */

/* USER CODE END SWC_DISPLAY_USERDEFINITIONS */



/*
 * component: swc_Display
 * cycletime: 250
 * description: Runnable for TFT data display
 * events: 
 * name: DISPLAY_Clock_display_run
 * shortname: Clock_display
 * signalIN: so_ControlOut
 * signalOUT: so_Display
 * task: tsk_hmi
 */
void DISPLAY_Clock_display_run(RTE_event ev){
	
	/* USER CODE START DISPLAY_Clock_display_run */
    SC_CONTROLOUT_data_t value;
    value= RTE_SC_CONTROLOUT_get(&SO_CONTROLOUT_signal);
    
    if(value.Mode== CLOCK_MODE_DISPLAYING)
    UART_LOG_PutString("CLOCK_MODE_DISPLAYING \r");
    if(value.Mode== CLOCK_MODE_EDITING_HOUR)
    UART_LOG_PutString("CLOCK_MODE_EDITING_HOUR \r");
    if(value.Mode== CLOCK_MODE_EDITING_MINUTE)
    UART_LOG_PutString("CLOCK_MODE_EDITING_MINUTE \r");
    
    //UART_LOG_PutString("CLOCK_Time.m_Hour = ");
   UART_PutintVal(value.Time_data.m_Hour);
   UART_LOG_PutString(" : ");
   //UART_LOG_PutString("CLOCK_Time.m_Min = ");
   UART_PutintVal(value.Time_data.m_Min);
   UART_LOG_PutString("\r");


    /* USER CODE END DISPLAY_Clock_display_run */
}

/* USER CODE START SWC_DISPLAY_FUNCTIONS */

/* USER CODE END SWC_DISPLAY_FUNCTIONS */

