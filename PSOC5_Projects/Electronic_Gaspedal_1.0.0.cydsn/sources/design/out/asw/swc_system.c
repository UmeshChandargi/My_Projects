/*
 * Filename: swc_system.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Software component for incrementing age of all signals. This is done for debugging and diagnosis of the signals
 * name: swc_system
 * shortname: system
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
 * component: swc_system
 * cycletime: 1
 * description: Runnable for incrementing age of all signals. This is done for debugging and diagnosis of the signals
 * events: 
 * name: SYSTEM_incAge_run
 * shortname: incAge
 * signalIN: so_joystick|so_engine_speed|so_rgb_led|so_brakeLight
 * signalOUT: so_joystick|so_engine_speed|so_rgb_led|so_brakeLight
 * task: tsk_system
 */
void SYSTEM_incAge_run(RTE_event ev){
	
	/* USER CODE START SYSTEM_incAge_run */

    /* USER CODE END SYSTEM_incAge_run */
}

/* USER CODE START SWC_SYSTEM_FUNCTIONS */

/* USER CODE END SWC_SYSTEM_FUNCTIONS */

