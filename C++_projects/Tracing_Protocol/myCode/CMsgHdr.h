/*
 * CMsgHdr.h
 *
 *  Created on: 05-Oct-2023
 *      Author: umesh
 */

#ifndef CMSGHDR_H_
#define CMSGHDR_H_

#include "global.h"

/*****************************************************************************/
/* Global pre-processor symbols/macros and type declarations                 */
/*****************************************************************************/
//Enum definitions for the Message header frame format
typedef enum{
	STRING,
	RAW,
	RESERVED
}Type_t;

typedef enum{
	MAX,
	FATAL,
	ERROR,
	WARNING,
	INFO,
	USER,
	DEBUG,
	TRACE,
	RSV
}Severity_t;

typedef struct{
	Severity_t m_Severity;
	char name[50];
}SeverityTable_t;

extern SeverityTable_t MsgHdr_Sevrtytable[9];

/*****************************************************************************/
/* Class declarations                                                        */
/*****************************************************************************/
class CMsgHdr
{
private:
	Type_t m_Type;
	Severity_t m_Severity;
	uint8_t m_header;

public:
	/**
	 * Constructor for the class CMsgHdr.
	 * @param none
	 * @return none
	 */
	CMsgHdr();

	/**
	 * Init function created to initialise class member attributes
	 * @param none
	 * @return RC_SUCCESS - return ok when end of function is reached
	 */
	RC_t MsgHeaderInit();

	/**
	 * Unpacking the message once read from the Protocol
	 * The data is checked for Message Header type and Severity
	 * @param uint8_t data- IN 8 bit Message header read from the Protocol
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t unpackMsg(uint8_t data);

	/**
	 * Packing the message header once Message Header type and Severity is known
	 * The type and Severity bits are set in the message header
	 * @param none
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t packMsg();

	/**
	 * Check Message Header type and assign it to the class attribute
	 * @param none
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t checkType();

	/**
	 * Check Message Header Severity and assign it to the class attribute
	 * @param none
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t checkSeverity();

	/**
	 * returns a class attribute
	 * @param none
	 * @return uint8_t - return m_header
	 */
	uint8_t getMsgHeader();

	/**
	 * returns a class attribute
	 * @param none
	 * @return Type_t - return m_Type
	 */
	Type_t getType();

	/**
	 * returns a class attribute
	 * @param none
	 * @return Severity_t - return m_Severity
	 */
	Severity_t getSeverity();

	/**
	 * sets a class attribute
	 * @param Type_t type- IN value to be assigned
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t setType(Type_t type);

	/**
	 * sets a class attribute
	 * @param Severity_t severity- IN value to be assigned
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t setSeverity(Severity_t severity);



};

#endif /* CMSGHDR_H_ */
