/*
 * Filename: swc_input.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Software component for Button input and send events for leftbutton short press and right button short/long press
 * name: swc_Input
 * shortname: Input
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "swc_input.h"



/* USER CODE START SWC_INPUT_INCLUDE */

/* USER CODE END SWC_INPUT_INCLUDE */


#include "sp_common.h"

/* USER CODE START SWC_INPUT_USERDEFINITIONS */
boolean_t ISR_Flag=FALSE;

/* USER CODE END SWC_INPUT_USERDEFINITIONS */



/*
 * component: swc_Input
 * cycletime: 50
 * description: Runnable for Button input and send events for leftbutton short press and right button short/long press
 * events: 
 * name: INPUT_Clock_input_run
 * shortname: Clock_input
 * signalIN: 
 * signalOUT: so_ButtonEvent
 * task: tsk_realtime
 */

void INPUT_Clock_input_run(RTE_event ev){
	
	/* USER CODE START INPUT_Clock_input_run */
 
        RTE_SC_BUTTONEVENT_pullPort(&SO_BUTTONEVENT_signal); 
        
        
        //else if(tick_ev == )
        {
            
            
        }
     
    /* USER CODE END INPUT_Clock_input_run */
}

/* USER CODE START SWC_INPUT_FUNCTIONS */

/* USER CODE END SWC_INPUT_FUNCTIONS */

