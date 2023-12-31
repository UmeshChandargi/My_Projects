
/*
 * Filename: tsk_realtime.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: This task will contain all Realtime operations, eg. run_joystick, run_control, run_engine, run_brake
 */

#ifndef _H_DEFINE_TSK_REALTIME
#define _H_DEFINE_TSK_REALTIME

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START TSK_REALTIME_INCLUDES */

/* USER CODE END TSK_REALTIME_INCLUDES */



/*
 * description: This task will contain all Realtime operations, eg. run_joystick, run_control, run_engine, run_brake
 * events: ev_engine_speed_onData|ev_joystick_onData
 * mode: Cyclic and Event
 * name: tsk_realtime
 * shortname: realtime
 * signalpoolsRO: sp_common
 * signalpoolsRW: sp_common
 * tickEvent: 0
 * timertickperiod: 1
 */
DeclareTask(tsk_realtime);

/* USER CODE START TSK_REALTIME_TASKUSERFUNCTION */

/* USER CODE END TSK_REALTIME_TASKUSERFUNCTION */


#endif