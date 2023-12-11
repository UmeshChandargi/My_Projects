/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "global.h"

#include "tsk_realtime.h"
#include "tsk_system.h"

#include "sp_common.h"
#include "swc_input.h"
#include "swc_control.h"
//ISR which will increment the systick counter every ms
ISR(systick_handler)
{
    CounterTick(cnt_systick);
}

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
   
    //Set systick period to 1 ms. Enable the INT and start it.
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, BCLK__BUS_CLK__HZ));
	EE_systick_enable_int();
    // Start Operating System
    for(;;)	    
    	StartOS(OSDEFAULTAPPMODE);
}

void unhandledException()
{
    //Ooops, something terrible happened....check the call stack to see how we got here...
    __asm("bkpt");
}

/********************************************************************************
 * Task Definitions
 ********************************************************************************/

TASK(tsk_init)
{
    
    //Init MCAL Drivers
    UART_LOG_Start();
    //Reconfigure ISRs with OS parameters.
    //This line MUST be called after the hardware driver initialisation!
    EE_system_init();
    //Start SysTick
	//Must be done here, because otherwise the isr vector is not overwritten yet
    EE_systick_start();
    CONTROL_init_run();
    ActivateTask(tsk_background);
    ActivateTask(tsk_realtime);
    SetRelAlarm(alarm_callback,1,1);
    
    TerminateTask();
    
}

TASK(tsk_background)
{
    
    while(1)
    {
        //do something with low prioroty
        
    
        __asm("nop");
    }
}

ALARMCALLBACK(Cyclic_callback) 
{ 
   
/* do application processing */ 
    
    SetEvent(tsk_realtime,ev_1ms);
    ActivateTask(tsk_system);
    ActivateTask(tsk_hmi);
} 


/********************************************************************************
 * ISR Definitions
 ********************************************************************************/
ISR2(isr_button)//ISR category2 is declared. 
{
    ISR_Flag= TRUE;
    
}
/* [] END OF FILE */
