/*
 * Filename: sc_joystick_type.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: joystick representation
 * name: sc_joystick
 * shortname: joystick
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "sc_joystick_type.h"



/* USER CODE START SC_JOYSTICK_INCLUDE */

/* USER CODE END SC_JOYSTICK_INCLUDE */




/* USER CODE START SC_JOYSTICK_USERDEFINITIONS */


/* USER CODE END SC_JOYSTICK_USERDEFINITIONS */


/*****************************************************************************************
 *************** Port Wrapper Implementation for SC_JOYSTICK signal  ****************
 *****************************************************************************************/
 
 

/**
 * Default IN driver API
 */
inline RC_t SC_JOYSTICK_driverIn(SC_JOYSTICK_data_t *const data)
{
	/* USER CODE START driverInSC_JOYSTICK */
    sint8_t x ,y;

    //Read data from the MCAL driver
    
    JOYSTICK_ReadPosition(&x,&y);
   
    //Scale it to the application type
    
    data->x= x;
    data->y=y;
    
	return RC_SUCCESS;
	/* USER CODE END driverInSC_JOYSTICK */
}


