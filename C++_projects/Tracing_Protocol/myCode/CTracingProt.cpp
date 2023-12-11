/*
 * CTracingProt.cpp
 *
 *  Created on: 05-Oct-2023
 *      Author: umesh
 */

#include "CTracingProt.h"
#include <iostream>
#include "string.h"
#include <fstream>
using namespace std;

/**
 * Constructor for the class CTracingProt.
 * @param none
 * @return none
 */
CTracingProt::CTracingProt()
{
	// TODO Auto-generated constructor stub
	// Constructor left empty because init function is created

}

/**
 * Destructor for the class CTracingProt.
 * @param none
 * @return none
 */
CTracingProt::~CTracingProt()
{
	// Free the memory created dynamically
	delete[] m_Payload;
}

/**
 * Init function created to initialise class member attributes
 * @param none
 * @return RC_SUCCESS - return ok when end of function is reached
 */
RC_t CTracingProt::ProtInit()
{
	m_PayloadLen=0;
	m_protReadidx=0;
	m_LRC=0;
	m_Payload=0;
	m_Header.MsgHeaderInit();

	return RC_SUCCESS;
}


/************************** APIs for decoding Encoded Protocol  ****************************/
/**
 * Read protocol from Decoding_TC_I.txt and save the metadata in class members.
 * Write the saved metadata in Decoding_TC_O.txt in a decoded message format
 * @param none
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CTracingProt::ReadProtAndParse()
{
	uint8_t data;
	char Readbuffer[1];

	//set the cursor before reading the file
	m_protReadidx= 0;

	//Read first three bytes to get message header and payload length
	cout<<"Reading Protocol from Decoding_TC_I.txt.."<<endl;
	//Get the message header
	ReadProtByte(data);
	m_Header.unpackMsg(data);

	//Get the payload length
	ReadProtByte(data);
	m_PayloadLen= uint16_t (data)| m_PayloadLen << 8;
	ReadProtByte(data);
	m_PayloadLen= uint16_t (data)| m_PayloadLen;

	//dynamically allocate payload array based of the length
	m_Payload = new uint8_t [m_PayloadLen];
	if(m_Payload==NULL)
	{
		return RC_NOMEMORY;
	}

	//read the rest of the bytes of the protocol from the file
	//read the payload data
	if(m_Header.getType()== RAW)
	{
		for(int j=0; j<m_PayloadLen; j++)
		{
			ReadProtByte(data);

			m_Payload[m_PayloadLen-1-j]= data;
		}
	}
	else if(m_Header.getType()== STRING)
	{
		for(int j=0; j<m_PayloadLen; j++)
		{
			FILE_ReadChar(Readbuffer,1 , m_protReadidx);
			m_Payload[m_PayloadLen-1-j]= Readbuffer[0];
		}
	}

	//Read the LRC
	ReadProtByte(data);
	m_LRC= data;

	//Calculate the LRC and compare
	if(CalcLRC(m_Header.getMsgHeader(), m_PayloadLen, m_Payload)==m_LRC)
	{

		// if the value is the same then write the decoded protocol message to the file
		cout<<"LRC verified! Protocol read successfully."<<endl;
		cout<<"Writing decoded message to Decoding_TC_O.txt.."<<endl;
		WriteMsg();
	}
	else
	{
		//else discard all data and show LRC error on the console
		ProtInit();
		delete[] m_Payload;
		cout<<"LRC error: Protocol is discarded"<<endl;
		return RC_ERROR;
	}

	return RC_SUCCESS;
}

/**
 * Write the metadata saved in class member attributes into the file Decoding_TC_O.txt.
 * Function is called inside ReadProtAndParse()
 * @param none
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CTracingProt::WriteMsg()
{
	// Writing to a text file
	ofstream outputFile("Decoding_TC_O.txt"); // Open a file for writing

	if (outputFile.is_open())
	{
		//write message header type
		if(m_Header.getType() == STRING)
		{
			outputFile<<"Message Header Type: STRING"<<endl;
		}
		else if(m_Header.getType() == RAW)
		{
			outputFile<<"Message Header Type: RAW"<<endl;
		}
		// write message header severity
		char severity_name[50]={""};
		uint8_t index;

		index= m_Header.getSeverity();
		strcat(severity_name,MsgHdr_Sevrtytable[index].name);
		outputFile<<"Message Header Severity: "<<severity_name<<endl;

		//Write Payload length
		outputFile<<"Payload Length: "<<to_string(m_PayloadLen)<<endl;

		//Write Payload data
		if(m_Header.getType()==RAW)
		{
			for(int k=0; k<m_PayloadLen;k++)
			{
				outputFile<<"Payload "<<k<<" : "<<to_string(m_Payload[k])<<endl;
			}
		}
		else if(m_Header.getType()==STRING)
		{
			for(int k=0; k<m_PayloadLen;k++)
			{
				outputFile<<"Payload "<<k<<" : "<<m_Payload[k]<<endl;
			}
		}

		outputFile<<"LRC verified"<<endl;
		outputFile.close(); // Close the file
	}

	return RC_SUCCESS;
}

/************************* APIs for Encoding Message into a Protocol ************************/

/**
 * Read a message from Encoding_TC_I.txt and save the metadata in class members.
 * Encode the saved metadata into a Protocol and write the result in Encoding_TC_O.txt
 * @param none
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CTracingProt::ReadMsgWriteProt()
{
	string line;
	char buffer[1];

	// Reading from a text file
	ifstream inputFile("Encoding_TC_I.txt");

	if (inputFile.is_open())
	{
		cout<<"Reading the message from Encoding_TC_I.txt.."<<endl;
		// Read Message Header Type from the file
		getline(inputFile, line);
		if(line.compare("RAW")==0)
		{
			m_Header.setType(RAW);
		}
		else if(line.compare("STRING")==0)
		{
			m_Header.setType(STRING);
		}
		else
		{
			cout<<"Message Type format not correct "<<endl;
			inputFile.close(); // Close the file
			return RC_ERROR;
		}

		// Read Message Header Severity from the file
		getline(inputFile, line);
		for(int i=0;i<9;i++)
		{
			if(line.compare(MsgHdr_Sevrtytable[i].name)==0)
			{
				m_Header.setSeverity((Severity_t)i);
				break;
			}
			else if(i==8)
			{
				cout<<"Message Severity format not correct "<<endl;
				inputFile.close(); // Close the file
				return RC_ERROR;
			}
		}
		m_Header.packMsg();

		// Read Payload length from the file
		getline(inputFile, line);
		m_PayloadLen= stoi(line);

		//dynamically allocate payload array based of the length
		m_Payload = new uint8_t [m_PayloadLen];
		if(m_Payload==NULL)
		{
			return RC_NOMEMORY;
		}

		// Read Payload data from the file
		if(m_Header.getType()==RAW)
		{
			for(int i=0; i<m_PayloadLen; i++)
			{
				getline(inputFile, line);
				m_Payload[i]= stoi(line);
			}

		}

		else if(m_Header.getType()==STRING)
		{
			for(int i=0; i<m_PayloadLen; i++)
			{
				inputFile.read(buffer, 1);
				getline(inputFile, line);
				m_Payload[i]= buffer[0];
			}
		}

		inputFile.close(); // Close the file
	}
	else
	{
		cerr << "Unable to open the file for reading." << endl;
		return RC_ERROR; // Return an error code
	}

	WriteProt();
	return RC_SUCCESS;
}

/**
 * Encode the saved metadata into a Protocol and write the result in Encoding_TC_O.txt.
 * Function is called inside ReadMsgWriteProt()
 * @param none
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CTracingProt::WriteProt()
{
	string data;
	uint8_t LRC=0;

	// Writing to a text file
	ofstream outputFile("Encoding_TC_O.txt");

	if (outputFile.is_open())
	{
		cout<<"Writing the encoded Protocol to Encoding_TC_O.txt.."<<endl;
		//write message header
		data= uint8ToBinaryString(m_Header.getMsgHeader());
		outputFile<<data;

		//write payload length
		data= uint8ToBinaryString(m_PayloadLen>>8);
		outputFile<<data;
		data= uint8ToBinaryString(uint8_t(m_PayloadLen));
		outputFile<<data;

		//write payload data
		if(m_Header.getType()==RAW)
		{
			for(int k= m_PayloadLen-1; k>=0;k--)
			{
				data= uint8ToBinaryString(m_Payload[k]);
				outputFile<<data;

			}
		}
		else if(m_Header.getType()==STRING)
		{
			for(int k= m_PayloadLen-1; k>=0;k--)
			{
				outputFile<<m_Payload[k];
			}
		}

		//Write LRC
		LRC= CalcLRC(m_Header.getMsgHeader(),m_PayloadLen,m_Payload);
		data= uint8ToBinaryString(LRC);
		outputFile<<data;

		outputFile.close(); // Close the file
	}
	return RC_SUCCESS;
}

/************************************ Helper functions ************************************/
/**
 * Calculate Longitudinal Redundancy Check (LRC) as per mentioned in the assignment sheet
 * Function is called inside ReadProtAndParse and WriteProt()
 * @param uint8_t header - IN Message Header data
 * @param uint16_t Payload_length - IN Payload length data
 * @param uint8_t* payload - IN Payload data
 * @return uint8_t - returns calculated LRC
 */
uint8_t CTracingProt::CalcLRC(uint8_t header,uint16_t Payload_length, uint8_t* payload)
{
	uint8_t result=0;

	//Adding all bytes
	result = header+Payload_length;
	for(int k=0; k<Payload_length;k++)
	{
		result=result+payload[k];
	}
	//Get 1's complement
	result= 0xFF - result;

	//Get 2's complement
	result= result + 0x01;

	return result;
}

/**
 * Reads one binary byte from the protocol.
 * Function is called inside ReadProtAndParse
 * @param uint8_t& data_byte - OUT Output data which contains 1 byte of the Protocol
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CTracingProt::ReadProtByte(uint8_t& data_byte)
{
	char Readbuffer[8];
	data_byte=0;
	RC_t ret = FILE_ReadChar(Readbuffer, 8, m_protReadidx);
	if(ret == RC_SUCCESS)
	{
		for(int i=0; i<8;i++)
		{
			if(Readbuffer[i]== 48) //0
			{
				data_byte= data_byte|0<<(7-i);
			}
			else if(Readbuffer[i]== 49)//1
			{
				data_byte= data_byte|1<<(7-i);
			}
		}
		return RC_SUCCESS;
	}
	else
	{
		return RC_ERROR;
	}
}

/**
 * Reads Characters from an input file
 * Function is called inside ReadProtByte and ReadProtAndParse
 * @param char* buffer - OUT Output data which contains 1 character from the file
 * @param const int bufferSize - IN Number of characters to be read
 * @param uint32_t& readidx - IN/OUT Cursor in the file
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t FILE_ReadChar(char* buffer, const int bufferSize, uint32_t& readidx)
{
	// Reading from a text file
	    ifstream inputFile("Decoding_TC_I.txt");

	    if (inputFile.is_open())
	    {
	        // Read "bufferSize" bytes of data from the file
	    	inputFile.seekg(readidx);
	        inputFile.read(buffer, bufferSize);
	        readidx+=bufferSize;
	        inputFile.close(); // Close the file
	        return RC_SUCCESS;
	    }

	    else
	    {
	        cerr << "Unable to open the file for reading." << endl;
	        return RC_ERROR; // Return an error code
	    }
}

/**
 * Function converts uint8_t data to a binary string
 * @param uint8_t value - IN input data
 * @return string - returns binary string
 */
string uint8ToBinaryString(uint8_t value)
{
	string binaryString="";

	for (int i = 7; i >= 0; i--)
	{
		char bit = ((value >> i) & 1) ? '1' : '0';
		binaryString+=bit;
	}
	return binaryString;
}
