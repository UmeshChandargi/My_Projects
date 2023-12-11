/*
 * global.h
 *
 *  Created on: 02-Nov-2023
 *      Author: umesh
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

//-------------------------------------------------------------------- [Datatypes and related definitions]

typedef signed 		char    	sint8_t;            /**< \brief         -128 .. +127            */
typedef unsigned 	char  		uint8_t;            /**< \brief            0 .. 255             */
typedef signed 		short   	sint16_t;           /**< \brief       -32768 .. +32767          */
typedef unsigned 	short 		uint16_t;           /**< \brief            0 .. 65535           */
typedef signed 		long    	sint32_t;           /**< \brief  -2147483648 .. +2147483647     */
#ifndef uint32_t
    typedef unsigned 	long  		uint32_t;           /**< \brief            0 .. 4294967295      */
#endif


typedef enum{
	RC_SUCCESS,
	RC_ERROR,
	RC_BADPARAM,
	RC_EMPTYBUFFER,
	RC_VALID,
	RC_FLIP,
}RC_t;


#endif /* GLOBAL_H_ */
