/*
 * Filename: sc_buttonevent_type.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Signalclass for event leftbutton short press and right button short/long press
 * name: sc_ButtonEvent
 * shortname: ButtonEvent
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "sc_buttonevent_type.h"



/* USER CODE START SC_BUTTONEVENT_INCLUDE */

/* USER CODE END SC_BUTTONEVENT_INCLUDE */




/* USER CODE START SC_BUTTONEVENT_USERDEFINITIONS */


/* USER CODE END SC_BUTTONEVENT_USERDEFINITIONS */


/*****************************************************************************************
 *************** Port Wrapper Implementation for SC_BUTTONEVENT signal  ****************
 *****************************************************************************************/
 
 

/**
 * Default IN driver API
 */
inline RC_t SC_BUTTONEVENT_driverIn(SC_BUTTONEVENT_data_t *const data)
{
	/* USER CODE START driverInSC_BUTTONEVENT */
    
    /* Create two State variables for two Buttons and initialise them    */
    static ButtonPressStates_t ButtonLeftStateVar = CheckShortPress;
    static ButtonPressStates_t ButtonRightStateVar= CheckShortPress;
    data->m_ev = EV_NULL;

    /* Check Short press for Button Left*/
    EV_ShortLongPressStateMachine(&ButtonLeftStateVar, Button_Left_Read(), data , EV_KeyLeft, EV_NULL );
    
    /* Check Short/Long press for Button Right*/
    EV_ShortLongPressStateMachine(&ButtonRightStateVar,Button_Right_Read(), data , EV_KeyRight, EV_RightLongPress );
    
    
    static uint16_t tick_ev;
        
        tick_ev++;
        if((tick_ev % 5)==0) // 250ms
        {
           data->m_ev = EV_250ms; 
        }
        if((tick_ev % 1200)==0) // 1 minute
        {
            data->m_ev = EV_1MIN;
            tick_ev=0;
        }
            
        
        
        

	return RC_SUCCESS;
	/* USER CODE END driverInSC_BUTTONEVENT */
}


/**
 * Statemachine code for Button long press event  
 * @param ButtonPressStates_t* StateVar - IN Statemachine variable
* @param  uint8_t BUTTONSTATUS - IN Status of the Button
 * @param SC_BUTTONEVENT_data_t* EV_value - OUT Event data
 * @param EVENT_t EV_shortpress,EV_Longpress - IN Event names
 * @return RC_SUCCESS if all ok
 */
RC_t EV_ShortLongPressStateMachine(ButtonPressStates_t* StateVar, uint8_t BUTTONSTATUS, 
    SC_BUTTONEVENT_data_t *const EV_value, EVENT_t EV_shortpress, EVENT_t EV_Longpress )
{
    static uint8_t count;
    switch(*StateVar)
    {
        case CheckShortPress:
        {
            if(BUTTONSTATUS==1)
            {
                EV_value->m_ev= EV_shortpress;  
                *StateVar= CheckLongPress;
            } 
        }
        break;

        case CheckLongPress:
        {
            if(BUTTONSTATUS==1)
            {
                if(count<LPTickFactor)
                {
                    EV_value->m_ev= EV_NULL; 
                }
                else if(count>=LPTickFactor)
                {
                    EV_value->m_ev= EV_Longpress;  
                }
                count++;          
                *StateVar= CheckLongPress;
            }
            
            else if(BUTTONSTATUS==0)
            {
                EV_value->m_ev= EV_NULL;
                count=0;
                *StateVar= CheckShortPress;
            }
        }
        break;
    }
    return RC_SUCCESS;  
}

