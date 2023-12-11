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
#include "msg.h"
#include <stdio.h>
#include <stdlib.h>

/**
* Initialises the ringbuffer and sets up the memory for the metadata
* \param MSG_messagebox_t *const me : [IN/OUT] Message Box Object
* \param EventMaskType const ev : [IN] Event which will be fired in case of a new message
* \param TaskType const task : [IN] Receiver task of the event
* \return RC_t: RC_SUCCESS in case of no error else error code
*/
RC_t MSG_init(MSG_messagebox_t *const me,EventMaskType const ev, TaskType const task)
{
	me->m_size = POSTBOX_SIZE;
	me->m_fillLevel = 0;
	me->m_readIdx = 0;
	me->m_writeIdx = 0; 
    me->ev = ev;
    me->m_task= task;

	return RC_SUCCESS;
}

/**
* Send a message by creating a temporary transfer buffer, 
* copying the data into this buffer and firing an event to the receiver task
* \param MSG_messagebox_t *const me : [IN/OUT] Message Box Object
* \param void const* const pData : [IN] Data to be transmitted
* \param uint16_t const size : [IN] Size of the transmitted data
* \return RC_t: RC_SUCCESS in case of no error else error code
*/ 
RC_t MSG_sendMessage(MSG_messagebox_t *const me, void const* const pData, uint16_t const size)
{
    uint8_t i;
    char buffer[200];
	if (me->m_fillLevel < me->m_size)
	{
        GetResource(res_messagebox);
		me->m_messageboxBuffer[me->m_writeIdx].m_pBuffer = (uint8_t*)malloc(size * sizeof(uint8_t));
		me->m_messageboxBuffer[me->m_writeIdx].m_size= size;
        
        if (me->m_messageboxBuffer[me->m_writeIdx].m_pBuffer == NULL)
        return RC_ERROR_MEMORY;
        
		for(i=0;i<size;i++)
		{
			((uint8_t*)me->m_messageboxBuffer[me->m_writeIdx].m_pBuffer)[i] = ((uint8_t*)pData)[i];
		}

		me->m_writeIdx++;
		me->m_writeIdx %= me->m_size;
        me->m_fillLevel++;
        
        ReleaseResource(res_messagebox);
        SetEvent(tsk_hmi,ev_msg);

		return RC_SUCCESS;

	}
	else
    return RC_ERROR_BUFFER_FULL;
}

/**
* Reads the message from the transfer buffer and releases the allocated memory
* \param MSG_messagebox_t *const me : [IN/OUT] Message Box Object
* \param void *const pData : [OUT] Pointer to the memory for storing the received message
* \return RC_t: RC_SUCCESS in case of no error else error code
*/
RC_t MSG_receiveMessage(MSG_messagebox_t *const me, void* pData,uint16_t const size)
{
	uint8_t i;

	if (me->m_fillLevel > 0)
	{
        GetResource(res_messagebox);
		for(i=0;i<size;i++)
		{
			((uint8_t*)pData)[i]=((uint8_t*)me->m_messageboxBuffer[me->m_readIdx].m_pBuffer)[i];

		}
        free(me->m_messageboxBuffer[me->m_readIdx].m_pBuffer);
		me->m_readIdx++;
		me->m_fillLevel--;
        ReleaseResource(res_messagebox);
		return RC_SUCCESS;
	}
	else
	{
		return RC_ERROR_BUFFER_EMTPY;
	}

	return RC_SUCCESS;
}

/**
* Wait for the next message (using OS services)
* \param MSG_messagebox_t *const me : [IN/OUT] Message Box Object
* \return RC_t: RC_SUCCESS in case of no error else error code
*/ 
RC_t MSG_waitNextMessage(MSG_messagebox_t *const me)
{
    EventMaskType ev=0;
    WaitEvent(me->ev);
    GetEvent(me->m_task, &ev);
    ClearEvent(ev);
    
    if(me->ev & ev)
        return RC_SUCCESS;
    else
        return RC_ERROR;
}

/**
* Checks if messages are available in the transfer buffer. This is required when there are multiple send
* operation happening and the events are lost before reading them
* \param MSG_messagebox_t *const me : [IN] Message Box Object 
* \return boolean_t: TRUE in case of messages available or return FALSE
*/
boolean_t if_MSGs_available(MSG_messagebox_t *const me)
{
    if(me->m_fillLevel>0)
    return TRUE;
    
    else
    return FALSE;
    
}