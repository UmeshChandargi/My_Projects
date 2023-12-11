/*
 * global.h
 *
 *  Created on: 14.09.2022
 *      Author: Fromm
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

//typedef unsigned int uint32_t;
typedef signed 		char    	sint8_t;
typedef enum {
	RC_OK,			//! Return ok
	RC_ERROR,		//! Unspecific error
	RC_BADPARAM,	//Wrog parameter value
	RC_EMPTYBUFFER,
	RC_FULLBUFFER,
	RC_NOMEMORY,

}RC_t;

typedef enum {
  IS_Waiting_Start,          /**< Idle state */
  IS_Waiting_RandomTime,       /**< S1 state */
  IS_Waiting_UserButton,        /**< S2 state */
}game_state ;

typedef struct {
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int time;
    
}RG__Glow_t;




#endif /* GLOBAL_H_ */
