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
#include "reaction_game.h"
 
  

const RG__Glow_t RG_glowtable_1[] = {
//Red Green Blue TimeInMS
{255, 0, 0, 500},
{0, 255, 0, 500},
{0, 0, 255, 500},
{0, 0, 0, 100},
{255, 255, 255, 100},
{0, 0, 0, 100},
{255, 255, 255, 100},
{0, 0, 0, 100},
{255, 255, 255, 100}
};


//ISR which will increment the systick counter every ms
ISR(systick_handler)
{
    local_tick++;// local tick created from the main systick
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
	
    //PWM initialisation
    PWM_led_red_Start();
    PWM_led_green_Start();
    PWM_led_yellow_Start();
    
    //Initial state of the game
    game_state_t= IS_Waiting_Start;
    //Enable timeout alarm of 1ms cycle for the archadian fader
    SetRelAlarm(alarm_fader,1,1);
    // Activate all the tasks
    ActivateTask(tsk_reactiongame);
    ActivateTask(tsk_glower);
    ActivateTask(tsk_background);
    
    //Enable ISR
    CyGlobalIntEnable;
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
TASK(tsk_reactiongame)
{
    // variables declared for the reaction game results calculation
    unsigned int seven_seg_val=0,reaction_time=0, game_chance=1;
    unsigned int correct_press=0,total_reaction_time=0, average_reaction_time=0;
    char buffer[256];// we need buffer to display in string format for UART 
    
     EventMaskType ev=0;
    //Game initial message
    UART_1_PutString("=======================================\r\n");
    UART_1_PutString("Welcome to Reaction game\r\n");
    UART_1_PutString("Start the game by pressing one of the two buttons\r\n");
   while(1)
    {
    // We use total two events for the reaction game.    
    WaitEvent(ev_button| ev_rndtimeout);
    GetEvent(tsk_reactiongame, &ev);
    ClearEvent(ev);
    
    // state machine start
    switch(game_state_t)
    {
        case IS_Waiting_Start: //First state
        {
            if(game_chance>10) // End the game
            {
               UART_1_PutString("=======================================\r\n");            
               UART_1_PutString("10 chances completed. Game Ended\r\n");
               itoa(correct_press,buffer, 10);
               UART_1_PutString("Total number of correct presses: ");
               UART_1_PutString(buffer);
               UART_1_PutString("\r\n");
            
               itoa(total_reaction_time,buffer, 10);
               UART_1_PutString("Total Reaction time: ");
               UART_1_PutString(buffer);
               UART_1_PutString("ms\r\n");
            
               average_reaction_time= total_reaction_time/10;
               itoa(average_reaction_time,buffer, 10);
               UART_1_PutString("Average Reaction time: ");
               UART_1_PutString(buffer);
               UART_1_PutString("ms\r\n");
            break;
            }
            else
            {
               UART_1_PutString("=======================================\r\n");
               itoa(game_chance,buffer, 10);
               UART_1_PutString("Reaction game round: ");
               UART_1_PutString(buffer);
               UART_1_PutString("\r\n");
               if(ev & ev_button) // wait for one of the two button press.
               {
                random_time_wait();
                game_state_t= IS_Waiting_RandomTime;  // state transition to IS_Waiting_RandomTime          
                }   
            }
        }
        break;
        case IS_Waiting_RandomTime: //Second state
        {
           if(ev & ev_rndtimeout) // wait for timeout from random_time_wait() 
        {
            seven_seg_val=local_tick%2;
            seven_seg_val++;
            print_seven_both_seg(seven_seg_val); // Display 1 or 2 in seven segment 
            reaction_time=local_tick; //Copy the start time from the tick counter
            game_state_t= IS_Waiting_UserButton; // state transition to IS_Waiting_UserButton
        }
        }
        break;
        case IS_Waiting_UserButton:// Third state
        {
           if (local_tick-reaction_time>=1000)// check if the reaction time is more than 1s
        {
            UART_1_PutString("Too slow\r\n");
            UART_1_PutString("Start the game again by pressing one of the two buttons\r\n");
            seven_both_seg_clear(); 
            game_chance++;// one game chance lost
            game_state_t= IS_Waiting_Start;// State transition to IS_Waiting_Start
        }
        else
        {
            if(ev & ev_button)// wait for user to press one of the two buttons
            {
               switch(seven_seg_val)
            {
               case 2:// check if left button is pressed for seven seg value "2"
                {
                   if(Button_1_Read()==1)
                      {
                        reaction_time=local_tick-reaction_time; // Calculate the reaction time
                        UART_1_PutString("Great! Correct Button 1 pressed\r\n");
                        itoa(reaction_time,buffer, 10);
                        UART_1_PutString("Reaction time: ");
                        UART_1_PutString(buffer);// print the reaction time in the UART screen
                        UART_1_PutString("ms\r\n");
                        UART_1_PutString("Start the game again by pressing one of the two buttons\r\n");
                        correct_press++;
                        total_reaction_time=total_reaction_time+ reaction_time;
                      }
                    else
                    {//if wrong button is pressed
                      UART_1_PutString("incorrect. Button 1 should be pressed\r\n");
                      UART_1_PutString("Start the game again by pressing one of the two buttons\r\n");
                    }
                       
                        
                }
                break;
                case 1:
                {// check if right button is pressed for seven seg value "1"
                   if(Button_2_Read()==1)
                      {
                        reaction_time=local_tick-reaction_time;//Calculate the reaction time
                        UART_1_PutString("Great! Correct Button 2 pressed\r\n");                        
                        itoa(reaction_time,buffer, 10);
                        UART_1_PutString("Reaction time: ");
                        UART_1_PutString(buffer);// print the reaction time in the UART screen
                        UART_1_PutString("ms\r\n");
                        UART_1_PutString("Start the game again by pressing one of the two buttons\r\n");
                        correct_press++;
                        total_reaction_time=total_reaction_time+ reaction_time;
                      }
                    else
                    {//if wrong button is pressed
                      UART_1_PutString("incorrect. Button 2 should be pressed\r\n");
                      UART_1_PutString("Start the game again by pressing one of the two buttons\r\n");  
                    }
                       
                }
                break;
            }
               game_chance++;
               seven_both_seg_clear(); 
               game_state_t= IS_Waiting_Start; //state transition to IS_Waiting_Start for currect and wrong button press
            
        }
        }
        break;
        }
    }
    }
    TerminateTask();
    
}
TASK(tsk_glower)
{
    {
        if(glower_cycle<=8) //Array size of RG_glowtable_1 is 9. Therefore read the arrays and repeat
    {
        //set the leds according to data present in the array
        led_rgb_r_Write(RG_glowtable_1[glower_cycle].red); 
        led_rgb_g_Write(RG_glowtable_1[glower_cycle].green);
        led_rgb_b_Write(RG_glowtable_1[glower_cycle].blue);
    // provide the necessary offset by using alarm_glower
        SetRelAlarm(alarm_glower,RG_glowtable_1[glower_cycle].time,RG_glowtable_1[glower_cycle].time); 
        glower_cycle++;
    }
    else
    glower_cycle=0;// repeat the cycle
        
    }
    
    TerminateTask();
}
TASK(tsk_fader)
{
    arcadian_fader();// this function is called every 1ms by the alarm_fader
   
    TerminateTask();
}
ISR2(isr_button)//ISR category2 is declared. 
{
    SetEvent(tsk_reactiongame,ev_button); //Event ev_button will be set when button_1 or button_2 is pressed 
}


/* [] END OF FILE */
