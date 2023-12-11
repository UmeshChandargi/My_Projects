///**
//* \file <filename>
//* \author <author-name>
//* \date <date>
//*
//* \brief <Symbolic File name>
//*
//* \copyright Copyright ©2016
//* Department of electrical engineering and information technology, Hochschule Darmstadt - University of applied sciences (h_da). All Rights Reserved.
//* Permission to use, copy, modify, and distribute this software and its documentation for educational, and research purposes in the context of non-commercial
//* (unless permitted by h_da) and official h_da projects, is hereby granted for enrolled students of h_da, provided that the above copyright notice,
//* this paragraph and the following paragraph appear in all copies, modifications, and distributions.
//* Contact Prof.Dr.-Ing. Peter Fromm, peter.fromm@h-da.de, Birkenweg 8 64295 Darmstadt - GERMANY for commercial requests.
//*
//* \warning This software is a PROTOTYPE version and is not designed or intended for use in production, especially not for safety-critical applications!
//* The user represents and warrants that it will NOT use or redistribute the Software for such purposes.
//* This prototype is for research purposes only. This software is provided "AS IS," without a warranty of any kind.
//*/
//
///*****************************************************************************/
///* Include files                                                             */
///*****************************************************************************/
//#include "statemachine_cfg.h"
//#include "statemachine.h"
//#include <stdlib.h>
//#include "project.h"
//
///*****************************************************************************/
///* Local pre-processor symbols/macros ('#define')                            */
///*****************************************************************************/
//
///*****************************************************************************/
///* Global variable definitions (declared in header file with 'extern')       */
///*****************************************************************************/
//STATE_state_t REACTION_GAME_state_variable= REACTION_GAME_INIT_DATA;
//
///*****************************************************************************/
///* Local type definitions ('typedef')                                        */
///*****************************************************************************/
//
//
///*****************************************************************************/
///* Local function prototypes ('static')                                      */
///*****************************************************************************/
//static void Start_random_time();
//static boolean_t ifGameChancelessThan10();
//static boolean_t ifGameChanceEqualTo10();
//static void  ShowTotalReactionTime();
//static void  Display_Seven_seg();
//static void  ShowMessageWrong();
//static void  ShowMessageReactionTime();
//static void  ShowMessageTooSLow();
//static void  ShowMessageWelcome();
//static void  ShowMessageIsWaiting();
//static void  GameChanceInc();
//
//static boolean_t  ButtonNotCorrect();
//static boolean_t  ButtonCorrect();
//
//
//
//
///** ---------------------------------- Transitions ---------------------------------------- **/
//
///**  ===== IS_Displaying ====   */
//static const STATE_stateInnerTransitionTable_t IS_Displaying_Transitions = {
///*    Event                 ToState                 Guard                       Action                       */
//    { EV_KeyLeft,           IS_ContainerHour,           0,           dispatch_KeyleftWdgHours}, 
//    { EV_1MIN,               IS_Displaying,              0,                           0},
//};
//
///**  ===== IS_ContainerHour ====   */
//static const STATE_stateInnerTransitionTable_t IS_ContainerHour_Transitions = {
///*    Event                 ToState                 Guard                       Action                       */
//    { EV_KeyLeft,           IS_ContainerMin,            0,                      dispatch_KeyleftWdgToMinutes}, 
//    { EV_KeyRight,          IS_ContainerHour,           0,                      dispatch_KeyRightWdgToHours},
//    { EV_RightLongPress,          IS_ContainerHour,           0,                dispatch_RightLongPressWdgToHours},
//    { EV_250ms,          IS_ContainerHour,           0,                         dispatch_250msWdgToHours}, 
//};
//
///**  ===== IS_ContainerMin ====   */
//static const STATE_stateInnerTransitionTable_t IS_ContainerMin_Transitions = {
///*    Event                 ToState                 Guard                       Action                       */
//    { EV_KeyLeft,           IS_Displaying,            0,                        dispatch_KeyleftWdgToDisplaying}, 
//    { EV_KeyRight,          IS_ContainerMin,           0,                      dispatch_KeyRightWdgToMinutes},
//    { EV_RightLongPress,          IS_ContainerMin,           0,                dispatch_RightLongPressWdgToMinutes},
//    { EV_250ms,          IS_ContainerMin,           0,                         dispatch_250msWdgToMinutes}, 
//};
//
//
//static const STATE_stateOuterTransitionTable_t ContainerStateMachine_Transitions = {
///*    fromState                  Pointer to table                            Size of table [Elements]    */
//    { IS_Displaying,          &IS_Displaying_Transitions,              sizeof(IS_Displaying_Transitions)/sizeof(STATE_stateInnerTransition_t)    },
//    { IS_ContainerHour,     &IS_ContainerHour_Transitions,         sizeof(IS_ContainerHour_Transitions)/sizeof(STATE_stateInnerTransition_t)     },
//    { IS_ContainerMin,     &IS_ContainerMin_Transitions,         sizeof(IS_ContainerMin_Transitions)/sizeof(STATE_stateInnerTransition_t) },
//};
//static const uint16_t ContainerStateMachine_Transitions_size = sizeof(ContainerStateMachine_Transitions)/sizeof(STATE_stateOuterTransition_t);
//
///** ---------------------------------- Action ------------------------------------------- **/
//
//static const STATE_stateActionTable_t ContainerStateMachine_StateActions = {
///*  fromState               Entry                    Exit    */
//  { IS_Waiting_Start,       ShowMessageWelcome,      0   },
//  { IS_Waiting_RandomTime,  ShowMessageIsWaiting,    0   }, 
//  { IS_Waiting_UserButton,  0,                       GameChanceInc   },
//};
//static const uint16_t ContainerStateMachine_StateActions_size = sizeof(ContainerStateMachine_StateActions)/sizeof(STATE_stateAction_t);
//
//
///*****************************************************************************/
///* Local variable definitions ('static')                                     */
///*****************************************************************************/
//static uint16_t game_chance, seven_seg_val=0,reaction_time=0;
//static uint16_t correct_press=0,total_reaction_time=0, average_reaction_time=0;
//
//
//
///*****************************************************************************/
///* Function implementation - global ('extern') and local ('static')          */
///*****************************************************************************/
//
//static void Start_random_time()
//{
//    char buffer[256];// we need buffer to display in string format for UART  
//    
//    UART_1_PutString("=======================================\r\n");
//    itoa(game_chance,buffer, 10);
//    UART_1_PutString("Reaction game round: ");
//    UART_1_PutString(buffer);
//    UART_1_PutString("\r\n"); 
//    random_time_wait();
//}
//
//static boolean_t ifGameChancelessThan10()
//{
//    if(game_chance<10)
//    return TRUE;
//    
//    else
//    return FALSE;
//    
//}
//
//static boolean_t ifGameChanceEqualTo10()
//{
//    if(game_chance>=10)
//    return TRUE;
//    
//    else
//    return FALSE;
//    
//}
//static void ShowTotalReactionTime()
//{
//    char buffer[256];// we need buffer to display in string format for UART 
//     UART_1_PutString("=======================================\r\n");            
//     UART_1_PutString("10 chances completed. Game Ended\r\n");
//     itoa(correct_press,buffer, 10);
//     UART_1_PutString("Total number of correct presses: ");
//     UART_1_PutString(buffer);
//     UART_1_PutString("\r\n");
//            
//     itoa(total_reaction_time,buffer, 10);
//     UART_1_PutString("Total Reaction time: ");
//     UART_1_PutString(buffer);
//     UART_1_PutString("ms\r\n");
//            
//     average_reaction_time= total_reaction_time/10;
//     itoa(average_reaction_time,buffer, 10);
//     UART_1_PutString("Average Reaction time: ");
//     UART_1_PutString(buffer);
//     UART_1_PutString("ms\r\n");
//    
//}
//
//static void  Display_Seven_seg()
//{  
//    seven_seg_val=local_tick%2;
//    seven_seg_val++;
//    print_seven_both_seg(seven_seg_val); // Display 1 or 2 in seven segment 
//    reaction_time=local_tick; //Copy the start time from the tick counter 
//}
//
//static void  ShowMessageWrong()
//{
//   UART_1_PutString("Wrong Button Pressed \r"); 
//}
//static void  ShowMessageReactionTime()
//{
//    char buffer[256];// we need buffer to display in string format for UART
//    
//    reaction_time=local_tick-reaction_time; // Calculate the reaction time
//    itoa(reaction_time,buffer, 10);
//    UART_1_PutString("Reaction time: ");
//    UART_1_PutString(buffer);// print the reaction time in the UART screen
//    UART_1_PutString("ms\r\n");
//    UART_1_PutString("Start the game again by pressing one of the two buttons\r\n");
//    correct_press++;
//    total_reaction_time=total_reaction_time+ reaction_time;
//     
//    
//    
//}
//static void  ShowMessageTooSLow()
//{
//  UART_1_PutString("Too slow\r\n");
//  UART_1_PutString("Start the game again by pressing one of the two buttons\r\n");
//    
//}
//static void  ShowMessageWelcome()
//{
//   //Game initial message
////    UART_1_PutString("=======================================\r\n");
////    UART_1_PutString("Welcome to Reaction game\r\n");
////    UART_1_PutString("Start the game by pressing one of the two buttons\r\n"); 
//    
//}
//static void  ShowMessageIsWaiting()
//{
//   UART_1_PutString("Is waiting for Random timeout\r\n");  
//    
//}
//static void  GameChanceInc()
//{
//   seven_both_seg_clear();
//   game_chance++;
//    
//}
//
//
//static boolean_t  ButtonCorrect()
//{
//    if(seven_seg_val==2)
//            {
//               // check if left button is pressed for seven seg value "2"
//                {
//                   if(Button_1_Read()==1)
//                      {
//                        UART_1_PutString("Great! Correct Button 1 pressed\r\n");
//                        return TRUE;
//                      }
//                    else
//                    {//if wrong button is pressed
//                      UART_1_PutString("incorrect. Button 1 should be pressed\r\n");
//                      UART_1_PutString("Start the game again by pressing one of the two buttons\r\n");
//                      return FALSE;
//                    }
//                       
//                        
//                }
//            }
//            else if (seven_seg_val==1)
//            {
//                // check if right button is pressed for seven seg value "1"
//                   if(Button_2_Read()==1)
//                      {
//                        UART_1_PutString("Great! Correct Button 2 pressed\r\n");
//                        return TRUE;
//                      }
//                    else
//                    {//if wrong button is pressed
//                      UART_1_PutString("incorrect. Button 2 should be pressed\r\n");
//                      UART_1_PutString("Start the game again by pressing one of the two buttons\r\n"); 
//                      return FALSE;
//                    }
//                       
//            }
//            else
//            return FALSE;
//            
//    
//}
//
//static boolean_t  ButtonNotCorrect()
//{
//    if(ButtonCorrect()==FALSE)
//    return TRUE;
//    
//    else
//    return FALSE;
//    
//}
//void statemachine_init()
//{
//   STATE_initState(   REACTION_GAME_StateActions, 
//                        REACTION_GAME_StateActions_size,
//                        &REACTION_GAME_state_variable);
//    
//}
//
//void statemachine_main(STATE_event_t ev)
//{
//    STATE_processEvent(REACTION_GAME_Transitions,
//                        REACTION_GAME_Transitions_size,
//                        REACTION_GAME_StateActions, 
//                        REACTION_GAME_StateActions_size,
//                        ev,
//                        &REACTION_GAME_state_variable);
//    
//}