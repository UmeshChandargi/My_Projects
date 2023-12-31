/*
 * Filename: swc_system.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Software component
 * name: swc_System
 * shortname: System
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "swc_system.h"



/* USER CODE START SWC_SYSTEM_INCLUDE */

/* USER CODE END SWC_SYSTEM_INCLUDE */


#include "sp_common.h"

/* USER CODE START SWC_SYSTEM_USERDEFINITIONS */

/* USER CODE END SWC_SYSTEM_USERDEFINITIONS */



/*
 * component: swc_System
 * cycletime: 1
 * description: Runnable for incrementing age of all signals. This is done for debugging and diagnosis of the signals
 * events: 
 * name: SYSTEM_incAge_run
 * shortname: incAge
 * signalIN: so_ButtonEvent|so_ControlOut|so_Display
 * signalOUT: so_ButtonEvent|so_ControlOut|so_Display
 * task: tsk_system
 */
void SYSTEM_incAge_run(RTE_event ev){
	
	/* USER CODE START SYSTEM_incAge_run */

    /* USER CODE END SYSTEM_incAge_run */
}

/* USER CODE START SWC_SYSTEM_FUNCTIONS */

/* USER CODE END SWC_SYSTEM_FUNCTIONS */

