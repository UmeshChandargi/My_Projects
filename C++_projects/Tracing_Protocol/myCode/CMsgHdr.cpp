/*
 * CMsgHdr.cpp
 *
 *  Created on: 05-Oct-2023
 *      Author: umesh
 */

#include "CMsgHdr.h"

//Array table created to hold the string equivalent of enum value
SeverityTable_t MsgHdr_Sevrtytable[9]=
{ /* Severity            Name    */
	{ MAX,			    "MAX"},
	{ FATAL,			"FATAL"},
	{ ERROR,			"ERROR"},
	{ WARNING,			"WARNING"},
	{ INFO ,			"INFO"},
	{ USER ,			"USER"},
	{ DEBUG,			"DEBUG"},
	{ TRACE,			"TRACE"},
	{ RSV,  			"RESERVED"}

};

/**
 * Constructor for the class CMsgHdr.
 * @param none
 * @return none
 */
CMsgHdr::CMsgHdr()
{
	// TODO Auto-generated constructor stub
	// Constructor left empty because init function is created

}

/**
 * Init function created to initialise class member attributes
 * @param none
 * @return RC_SUCCESS - return ok when end of function is reached
 */
RC_t CMsgHdr::MsgHeaderInit()
{
	m_Type= RESERVED;
	m_Severity = MAX;
	m_header =0;
	return RC_SUCCESS;
}

/**
 * Unpacking the message once read from the Protocol
 * The data is checked for Message Header type and Severity
 * @param uint8_t data- IN 8 bit Message header read from the Protocol
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CMsgHdr::unpackMsg(uint8_t data)
{
	m_header= data;
	checkType();
	checkSeverity();

	return RC_SUCCESS;
}

/**
 * Packing the message header once Message Header type and Severity is known
 * The type and Severity bits are set in the message header
 * @param none
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CMsgHdr::packMsg()
{
	m_header = uint8_t (m_Severity) <<4;
	m_header |= m_Type;
	return RC_SUCCESS;
}

/**
 * Check Message Header type and assign it to the class attribute
 * @param none
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CMsgHdr::checkType()
{
	if((m_header & 0x0F) == 0u)
	{
		m_Type= STRING;
	}
	else if((m_header & 0x0F) == 1u)
	{
		m_Type= RAW;
	}
	else
	{
		m_Type= RESERVED;
	}
	return RC_SUCCESS;
}

/**
 * Check Message Header Severity and assign it to the class attribute
 * @param none
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CMsgHdr::checkSeverity()
{
	uint8_t bit4_7;
	bit4_7= (m_header & 0xF0)>>4;

	if(bit4_7<8)
	{
		m_Severity= Severity_t (bit4_7);
	}
	else
	{
		m_Severity= RSV;
	}
	return RC_SUCCESS;

}

/**
 * returns a class attribute
 * @param none
 * @return uint8_t - return m_header
 */
uint8_t CMsgHdr::getMsgHeader()
{
	return m_header;
}

/**
 * returns a class attribute
 * @param none
 * @return Type_t - return m_Type
 */
Type_t CMsgHdr::getType()
{
	return m_Type;
}

/**
 * returns a class attribute
 * @param none
 * @return Severity_t - return m_Severity
 */
Severity_t CMsgHdr::getSeverity()
{
	return m_Severity;
}

/**
 * sets a class attribute
 * @param Type_t type- IN value to be assigned
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CMsgHdr::setType(Type_t type)
{
	m_Type=type;
	return RC_SUCCESS;
}

/**
 * sets a class attribute
 * @param Severity_t severity- IN value to be assigned
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CMsgHdr::setSeverity(Severity_t severity)
{
	m_Severity= severity;
	return RC_SUCCESS;
}


