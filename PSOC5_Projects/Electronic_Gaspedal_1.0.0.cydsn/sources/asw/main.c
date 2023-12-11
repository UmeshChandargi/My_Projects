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
#include "watchdog.h"


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
    WD_Start(Ticks_1024); //Watchdog timer set for 2-3s
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
    JOYSTICK_Init();
    PWM_RGB_G_Start();
    if(WD_CheckResetBit()==TRUE) //check initially which type if reset happened
    {
      UART_LOG_PutString("Watchdog Reset\r"); 
    }
    else if(WD_CheckResetBit()==FALSE)
    {
       UART_LOG_PutString("Power On Reset\r"); 
    }
    
    
    
   
    //Reconfigure ISRs with OS parameters.
    //This line MUST be called after the hardware driver initialisation!
    EE_system_init();
	
    //Start SysTick
	//Must be done here, because otherwise the isr vector is not overwritten yet
    EE_systick_start();  
    ActivateTask(tsk_background);
    ActivateTask(tsk_realtime);
    SetRelAlarm(alrm_1ms,1,1);
    
    TerminateTask();
    
}

TASK(tsk_background)
{
    
    while(1)
    {
        //do something with low prioroty
        WD_Trigger();
        #ifdef DEBUG_STATIC
        char buffer[200];
        itoa(debug, buffer, 10);
        UART_LOG_PutString("debug in main= ");
        UART_LOG_PutString(buffer);
        UART_LOG_PutString("\r");
        #endif
    
        __asm("nop");
    }
}

ALARMCALLBACK(alrm_callback) 
{ 
   
/* do application processing */ 
    
    SetEvent(tsk_realtime,ev_1ms);
    ActivateTask(tsk_system);
} 


/********************************************************************************
 * ISR Definitions
 ********************************************************************************/
ISR2(isr_button1)//ISR category2 is declared. 
{
    UART_LOG_PutString("Button1 pressed\r");
    
   ShutdownOS(E_OK);
}
/* [] END OF FILE */
