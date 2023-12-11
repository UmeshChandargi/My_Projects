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
#include <stdlib.h>
#include "project.h"
#include "global.h"
#include "Ringbuffer.h"
#include "parser.h"
#include "drawer.h"
#include "msg.h"



RB_t globalRingbuffer;//create a global ring buffer

MSG_messagebox_t bufferbox;//Global MSG_messagebox_t;


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

/*********************************************************************
***********
* Task Definitions
**********************************************************************
**********/
TASK(tsk_init)
{
    
    //Init MCAL Drivers
    CyGlobalIntDisable;
    UART_1_Start();
    //Reconfigure ISRs with OS parameters.
    //This line MUST be called after the hardware driver initialisation!
    EE_system_init();
	
    //Start SysTick
	//Must be done here, because otherwise the isr vector is not overwritten yet
    EE_systick_start();  
    // initiate the global ring buffer
    RB_init(&globalRingbuffer, 200);// size= 200 unsigned int type
    // initiate the Message_box buffer
    MSG_init(&bufferbox,ev_msg, tsk_hmi);
    // Activate all the tasks
    ActivateTask(tsk_json);
     ActivateTask(tsk_hmi);
    ActivateTask(tsk_background);
    
    //Enable ISR
    CyGlobalIntEnable;
    TerminateTask();
    
}
TASK(tsk_background)// Priority 1 task
{
    while(1)
    {
        //do something with low prioroty
        __asm("nop");
    }
}

TASK(tsk_hmi)// Priority 2 task
{
    Drawer_t draw_recieve; //created to read the recieved data
    char buffer[255];
    while(1)
    {
        RC_t ret = MSG_waitNextMessage(&bufferbox); //checks if the ev_msg is set
            if(ret== RC_SUCCESS)
            {
                while(if_MSGs_available(&bufferbox))// recieve all the remaining objects in the buffer
                {
                    MSG_receiveMessage(&bufferbox, &draw_recieve,sizeof(draw_recieve));
                    UART_1_PutString("Recieved drawer object contents are: \r");
                    print_Drawer_object(&draw_recieve); //print the drawer object once recieved
                }
            }
    }
}

TASK(tsk_json)// Priority 3 task
{
    
    EventMaskType ev=0;
    uint8_t data_get,r;//data_get is created to read each character in the RingBuffer. 
    //r is created to count the number of tokens after the parsing is done
    Parser_t P_t;//Parser object created
    PARSER_init(&P_t);//Parser object is initialised
    Drawer_t draw;// drawer object created to send the message
    
   while(1)
    {    
        WaitEvent(ev_endofstr);
        GetEvent(tsk_json, &ev);
        ClearEvent(ev);
    
        if(ev & ev_endofstr)//event set from the uart recieve ISR 
        {
            while(RB_prots_available(&globalRingbuffer))//read all the remaining protocols available in the RingBuffer
            {
                while(1)
                {
                    RC_t ret=RB_get(&globalRingbuffer, &data_get);
                    if (data_get=='\0') break; //Read only till one protocol
                    PARSER_addChar(&P_t, data_get);//write inside the content array of the parser object
                }
            }
        }
        PARSER_dbg_printContent(&P_t);//print the input to the parser function
        PARSER_parse(&P_t);
        PARSER_dbg_printToken(&P_t); // print the tokens of the parsed string
        while(P_t.token[r].end!=0){r++;}// count the number of tokens
        while(P_t.nextToken<r-1)// call the DRAWER_getNextDrawCommand for all the tokens
        {
            RC_t ret1= DRAWER_getNextDrawCommand(&draw, &P_t);// Get the draw commands from the tokens
            if(ret1== RC_SUCCESS)
            {
                MSG_sendMessage(&bufferbox, &draw, sizeof(draw));// for every successful drawer object, tsk_json will send the contents to tsk_hmi
            }
        }
        r=0;// clear everything before the next Protocol from the user arrives
        PARSER_clear(&P_t);
    }
}

ISR2(isr_uart1)//ISR category2 is declared. 
{
    uint8 data_put;
    data_put= UART_1_ReadRxData();
    RB_put(&globalRingbuffer ,data_put);//write into the buffer
    if(data_put=='\0')
    SetEvent(tsk_json,ev_endofstr); //Event ev_endofstr is triggered when user enters NULL character
}


/* [] END OF FILE */
