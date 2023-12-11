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

/* [] END OF FILE */
#include "project.h"
#include "reaction_game.h"
#include "global.h"

/*
This array is declared to find the eqavalent value of '0' to '9' and 'A' to 'F' to write in the control register.
we will write a array to act as lookup table for each character.
for eg. '0' requires 
A   B   C   D   E   F   G   DP
1   1   1   1   1   1   0   0   = 0XFC

LED structure: 
        _A_
      F|_G_|B
      E|__ |C    . DP
        D

*/
const static uint8 lookup[]={
        0xFC    //0
        ,0x60   //1
        ,0xDA  //2
        ,0xF2  //3
        ,0x66  //4
        ,0xB6  //5
        ,0xBE   //6
        ,0xE0   //7
        ,0xFE   //8
        ,0xE6   //9
        ,0xEE   //A
        ,0xFE   //B
        ,0x9C   //C
        ,0xFC   //D
        ,0x9E   //E
        ,0x8E   //F
    };
/**
 * Clears both seven segment display
 * @return RC_OK if function was executed as exepected
 */
RC_t seven_both_seg_clear()
{
    Sel_A_7_Seg_Write(SegmentA);// Choose SegmentA
  Control_Reg_1_Write(0); //Switch off all leds

Sel_A_7_Seg_Write(SegmentB);// Choose SegmentB
  Control_Reg_1_Write(0); //Switch off all leds
  return RC_OK;
}

/**
 * Prints any character from 0- F in both seven segment displays
 * @param uint8 value - the value to be printed
 * @return RC_OK if function was executed as expected, other error code in case of error
 */
RC_t print_seven_both_seg(uint8 value)
{
    uint8 print_letter=0;
    if(print_letter> 0xF)
    return RC_BADPARAM; //We cannot print any character after 'F'
    
    else
    {
        Sel_A_7_Seg_Write(SegmentA);// Choose SegmentA
       print_letter= lookup[value]; // Obtain the hex equvalent of the character to be printed
       Control_Reg_1_Write(print_letter); 
    
    Sel_A_7_Seg_Write(SegmentB);// Choose SegmentB
       print_letter= lookup[value]; // write the same value
       Control_Reg_1_Write(print_letter); 
        
    }
    return RC_OK;
    
}
/**
 * Function creates a random delay of 1-3s
 */
void random_time_wait()
{
   int random;
    random=local_tick%3;// creates 1,2,or 3 randomly
    random++;
    SetRelAlarm(alarm_random,random*1000,0);// set alarm based on the random generated values
    
}
/**
 * Function to provide fading effect for led red, yellow, green in the same order
 */
void arcadian_fader()
{
    
    if(time_period > 1000) // Repeat the fading effect after 1000ms. 
    //time_period increments every 1ms. This is done with the help of SetRelAlarm(alarm_fader,1,1) in tsk_init
    {
        time_period=0;
    }
    else
    {
    
    if((time_period>0) && (time_period<=250)) 
    {
        PWM_led_red_WriteCompare(red_bightness++); // Increase led_red brightness from offset 0-250ms
    }
        if((time_period>250) && (time_period<=500))
    {
        PWM_led_yellow_WriteCompare(yellow_bightness++);// Increase led_yellow brightness from offset 250-500ms
      
    }
       if((time_period>250) && (time_period<=500))// Decrease led_red brightness from offset 250-500ms
    {
        PWM_led_red_WriteCompare(red_bightness--);
    }
    
    
        if((time_period>500) && (time_period<=750))// Decrease led_yellow brightness from offset 500-750ms
    {
        PWM_led_yellow_WriteCompare(yellow_bightness--);
      
    }
           
        if((time_period>500) && (time_period<=750))// Increase led_green brightness from offset 500-750ms
    {
      
        PWM_led_green_WriteCompare(green_brightness++);
    }
        if((time_period>750) && (time_period<=1000))
    {
        PWM_led_green_WriteCompare(green_brightness--);// Decrease led_green brightness from offset 750-1000ms
    }
    
    time_period++;
    
    }
    
}