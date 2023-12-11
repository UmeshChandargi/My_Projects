/*
 * Filename: swc_brake.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Set the red led based on the engine speed
 * name: swc_brake
 * shortname: brake
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "swc_brake.h"



/* USER CODE START SWC_BRAKE_INCLUDE */

/* USER CODE END SWC_BRAKE_INCLUDE */


#include "sp_common.h"

/* USER CODE START SWC_BRAKE_USERDEFINITIONS */

/* USER CODE END SWC_BRAKE_USERDEFINITIONS */



/*
 * component: swc_brake
 * cycletime: 0
 * description: Runnable to create brakelight signal for led red
 * events: ev_engine_speed_onData
 * name: BRAKE_setBrakeLight_run
 * shortname: setBrakeLight
 * signalIN: so_engine_speed
 * signalOUT: so_brakeLight
 * task: tsk_realtime
 */
void BRAKE_setBrakeLight_run(RTE_event ev){
    
	/* USER CODE START BRAKE_setBrakeLight_run */
    WD_Alive(3);
    
    
    SC_SPEED_data_t data = RTE_SC_SPEED_get(& SO_ENGINE_SPEED_signal);
    SC_BRAKELIGHT_data_t led;
    
    if(data.value == 0)
    {
       led.led_value= 1;
    }
    
    else
    {
      led.led_value= 0;  
    }
    
    
       RTE_SC_BRAKELIGHT_set(&SO_BRAKELIGHT_signal, led);
       RTE_SC_BRAKELIGHT_pushPort( &SO_BRAKELIGHT_signal); //write the GPIO led red value to the driver
    
    
    /* USER CODE END BRAKE_setBrakeLight_run */
}

/* USER CODE START SWC_BRAKE_FUNCTIONS */

/* USER CODE END SWC_BRAKE_FUNCTIONS */
