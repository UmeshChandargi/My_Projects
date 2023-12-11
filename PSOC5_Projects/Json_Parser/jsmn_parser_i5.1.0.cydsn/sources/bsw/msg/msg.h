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
#include "project.h"


//message objects attributes
typedef struct {
    uint16_t m_size;
    void *m_pBuffer;
}message_t;

//Message RingBuffer attributes

#define POSTBOX_SIZE 10 //Buffer size can be changed here
typedef struct {
	message_t m_messageboxBuffer[POSTBOX_SIZE]; //RingBuffer of message object type created
	uint16_t m_size; //size should be same as POSTBOX_SIZE
	uint16_t m_readIdx; 
	uint16_t m_writeIdx;
	uint16_t m_fillLevel;
    EventMaskType ev;
    TaskType m_task;
}MSG_messagebox_t;

/**
* Initialises the ringbuffer and sets up the memory for the metadata
* \param MSG_messagebox_t *const me : [IN/OUT] Message Box Object
* \param EventMaskType const ev : [IN] Event which will be fired in case of a new message
* \param TaskType const task : [IN] Receiver task of the event
* \return RC_t: RC_SUCCESS in case of no error else error code
*/
RC_t MSG_init(MSG_messagebox_t *const me,EventMaskType const ev, TaskType const task);
/**
* Send a message by creating a temporary transfer buffer, 
* copying the data into this buffer and firing an event to the receiver task
* \param MSG_messagebox_t *const me : [IN/OUT] Message Box Object
* \param void const* const pData : [IN] Data to be transmitted
* \param uint16_t const size : [IN] Size of the transmitted data
* \return RC_t: RC_SUCCESS in case of no error else error code
*/ 
RC_t MSG_sendMessage(MSG_messagebox_t *const me, void const* const pData, uint16_t const size);
/**
* Returns the size of the next message in the buffer.
* Required for providing storage on the receiver side
* \param MSG_messagebox_t *const me : [IN/OUT] Message Box Object
* \param uint16_t *const size : [OUT] Size of the next message, 0 in case of no message
* \return RC_t: RC_SUCCESS in case of no error else error code
*/ 
RC_t MSG_getSizeOfNextMessage(MSG_messagebox_t *const me, uint16_t *const size);
/**
* Wait for the next message (using OS services)
* \param MSG_messagebox_t *const me : [IN/OUT] Message Box Object
* \return RC_t: RC_SUCCESS in case of no error else error code
*/ 
RC_t MSG_waitNextMessage(MSG_messagebox_t *const me);
/**
* Reads the message from the transfer buffer and releases the allocated memory
* \param MSG_messagebox_t *const me : [IN/OUT] Message Box Object
* \param void *const pData : [OUT] Pointer to the memory for storing the received message
* \return RC_t: RC_SUCCESS in case of no error else error code
*/ 
RC_t MSG_receiveMessage(MSG_messagebox_t *const me, void* pData,uint16_t const size);

/**
* Checks if messages are available in the transfer buffer. This is required when there are multiple send
* operation happening and the events are lost before reading them
* \param MSG_messagebox_t *const me : [IN] Message Box Object 
* \return boolean_t: TRUE in case of messages available or return FALSE
*/
boolean_t if_MSGs_available(MSG_messagebox_t *const me);

