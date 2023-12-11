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
#include "global.h"
#include <stdio.h>  


static int local_tick=0;
static game_state game_state_t;
static uint8_t glower_cycle;
RG__Glow_t glow;

static uint8_t red_bightness;
static uint8_t yellow_bightness;
static uint8_t green_brightness;
static uint32_t time_period;
void arcadian_fader();
void random_time_wait();
RC_t print_both_seven_seg(uint8_t value);
RC_t seven_both_seg_clear();
RC_t print_seven_both_seg(uint8_t value);

/**
* Enum to select the two seven segment displays in the Labboard
*/
 typedef enum {
  SegmentB,  /*Segment SA1 in the Labboard will be selected*/
  SegmentA, /*Segment SB1 in the Labboard will be selected*/
}SegSelect_t ;


