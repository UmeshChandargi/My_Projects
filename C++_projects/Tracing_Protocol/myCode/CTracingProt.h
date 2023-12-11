/*
 * CTracingProt.h
 *
 *  Created on: 05-Oct-2023
 *      Author: umesh
 */

#ifndef CTRACINGPROT_H_
#define CTRACINGPROT_H_
#include "CMsgHdr.h"
#include "global.h"
#include <iostream>
class CTracingProt
{
private:
	CMsgHdr m_Header;
	uint16_t m_PayloadLen;
	uint8_t* m_Payload;
	uint8_t m_LRC;
	uint32_t m_protReadidx;

public:
	/**
	 * Constructor for the class CTracingProt.
	 * @param none
	 * @return none
	 */
	 CTracingProt();

	 /**
	  * Destructor for the class CTracingProt.
	  * @param none
	  * @return none
	  */
	~CTracingProt();

	/**
	 * Init function created to initialise class member attributes
	 * @param none
	 * @return RC_SUCCESS - return ok when end of function is reached
	 */
	RC_t ProtInit();

	/************************** APIs for decoding Encoded Protocol  ****************************/
	/**
	 * Read protocol from Decoding_TC_I.txt and save the metadata in class members.
	 * Write the saved metadata in Decoding_TC_O.txt in a decoded message format
	 * @param none
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t ReadProtAndParse();

	/**
	 * Write the metadata saved in class member attributes into the file Decoding_TC_O.txt.
	 * Function is called inside ReadProtAndParse()
	 * @param none
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t WriteMsg();

	/************************* APIs for Encoding Message into a Protocol ************************/

	/**
	 * Read a message from Encoding_TC_I.txt and save the metadata in class members.
	 * Encode the saved metadata into a Protocol and write the result in Encoding_TC_O.txt
	 * @param none
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t ReadMsgWriteProt();

	/**
	 * Encode the saved metadata into a Protocol and write the result in Encoding_TC_O.txt.
	 * Function is called inside ReadMsgWriteProt()
	 * @param none
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t WriteProt();

	/************************************ Helper functions ************************************/
	/**
	 * Calculate Longitudinal Redundancy Check (LRC) as per mentioned in the assignment sheet
	 * Function is called inside ReadProtAndParse and WriteProt()
	 * @param uint8_t header - IN Message Header data
	 * @param uint16_t Payload_length - IN Payload length data
	 * @param uint8_t* payload - IN Payload data
	 * @return uint8_t - returns calculated LRC
	 */
	uint8_t CalcLRC(uint8_t header,uint16_t Payload_length, uint8_t* payload);

	/**
	 * Reads one binary byte from the protocol.
	 * Function is called inside ReadProtAndParse
	 * @param uint8_t& data_byte - OUT Output data which contains 1 byte of the Protocol
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t ReadProtByte(uint8_t& data_byte);

};


/*****************************************************************************/
/* API functions                                                             */
/*****************************************************************************/
/**
 * Reads Characters from an input file
 * Function is called inside ReadProtByte and ReadProtAndParse
 * @param char* buffer - OUT Output data which contains 1 character from the file
 * @param const int bufferSize - IN Number of characters to be read
 * @param uint32_t& readidx - IN/OUT Cursor in the file
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t FILE_ReadChar(char* buffer, const int bufferSize, uint32_t& readidx);

/**
 * Function converts uint8_t data to a binary string
 * @param uint8_t value - IN input data
 * @return string - returns binary string
 */
std::string uint8ToBinaryString(uint8_t value);

#endif /* CTRACINGPROT_H_ */
