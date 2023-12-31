
/*
 * Filename: swc_control.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: Software component for Statemachine logic and send data on min and hour widgets
 */

#ifndef _H_DEFINE_SWC_CONTROL
#define _H_DEFINE_SWC_CONTROL

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START SWC_CONTROL_INCLUDES */
#include "statemachine_cfg.h"
#include "statemachine.h"
#include <stdlib.h>

/* USER CODE END SWC_CONTROL_INCLUDES */



/* USER CODE START SWC_CONTROL_USERDEFINITIONS */

void CONTROL_init_run();
/* USER CODE END SWC_CONTROL_USERDEFINITIONS */


/*
 * component: swc_Control
 * cycletime: 0
 * description: Runnable for Statemachine logic and send data on min and hour widgets
 * events: ev_Button_OnData
 * name: CONTROL_Clock_control_run
 * shortname: Clock_control
 * signalIN: so_ButtonEvent
 * signalOUT: so_ControlOut
 * task: tsk_realtime
 */
void CONTROL_Clock_control_run(RTE_event ev);


#endif