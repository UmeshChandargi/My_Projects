
/*
 * Filename: sp_common.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: The common global signal pool. All signals will be stored here
 */

#ifndef _H_DEFINE_SP_COMMON
#define _H_DEFINE_SP_COMMON

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START SP_COMMON_INCLUDES */
#include "uart_bsw.h"
#ifdef CODE_RECHECK
//#error "Remove the inclusion later"
#endif
/* USER CODE END SP_COMMON_INCLUDES */



#include "sc_buttonevent.h"
#include "sc_controlout.h"
#include "sc_display.h"



/*
 * description: A Signal for event leftbutton short press and right button short/long press
 * indriver: default
 * name: so_ButtonEvent
 * onDataError: 0
 * onDataUpdate: ev_Button_OnData
 * outdriver: 0
 * resource: None
 * shortname: ButtonEvent
 * signalclass: sc_ButtonEvent
 * signalpool: sp_common
 */
extern SC_BUTTONEVENT_t SO_BUTTONEVENT_signal;


/*
 * description: Sognal For output data from the control runnable. Which consists of the data of min and hour widget 
 * indriver: 0
 * name: so_ControlOut
 * onDataError: 0
 * onDataUpdate: 0
 * outdriver: 0
 * resource: None
 * shortname: ControlOut
 * signalclass: sc_ControlOut
 * signalpool: sp_common
 */
extern SC_CONTROLOUT_t SO_CONTROLOUT_signal;


/*
 * description: A Signal for TFT commands type
 * indriver: 0
 * name: so_Display
 * onDataError: 0
 * onDataUpdate: 0
 * outdriver: default
 * resource: None
 * shortname: Display
 * signalclass: sc_Display
 * signalpool: sp_common
 */
extern SC_DISPLAY_t SO_DISPLAY_signal;



/*
 * Increments the age of the signals in this pool 
 */
void RTE_timertick_sp_common_tick(uint32_t tick);

/*
 * Reset all signals in this pool
 */
void RTE_reset_sp_common();

#endif