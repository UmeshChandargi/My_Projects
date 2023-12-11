/*
 * ModuloNCounter.cpp
 *
 *  Created on: 09-Nov-2023
 *      Author: umesh
 */
#include <iostream>
#include "ModuloNCounter.h"

using namespace std;
/*!
 * initializes a counter by setting the current count value to 0 and the maximum count value to an
 * arbitrary value.
 * @param int maxCount - IN Max value at which the counter will overflow
 * @return none
 */
ModuloNCounter::ModuloNCounter(int maxCount)
{
	m_currentCount=0;
	m_maxCount= maxCount;
}

/*!
 * counts, that is increase the current count value by 1 or reset it to 0, in case
 * of the value becomes greater than n-1 (overflow).
 * arbitrary value.
 * @param none
 * @return int - returns 1 if an overflow had occurred otherwise 0
 */
int ModuloNCounter::count()
{
	if(m_currentCount +1 == m_maxCount)
	{
		m_currentCount=0;
		return 1;
	}
	else
	{
		m_currentCount++;
		return 0;
	}
}

/*!
 * prints the name of the counter (modulo n counter, n should be replaced by the
 * current value of the maximum count value) or the current count value based on enum option
 * @param COUNTER_PrintOption_t option - IN Print option passed as a param
 * @return none
 */
void ModuloNCounter::print(COUNTER_PrintOption_t option)
{
	if(option == COUNTER_NAME)
	{
		cout<<"modulo "<<m_maxCount<<" counter"<<endl;
	}
	else if(option == COUNTER_VALUE)
	{
		cout<<m_currentCount;
	}
}

/*!
 * getter function for m_maxCount
 * @param none
 * @return int- returns value of m_maxCount
 */
int ModuloNCounter::getMaxCount()
{
	return m_maxCount;
}

/*!
 * getter function for m_currentCount
 * @param none
 * @return int- returns value of m_currentCount
 */
int ModuloNCounter::getCurrentCount()
{
	return m_currentCount;
}

/*!
 * set function for all the members
 * @param int maxCount, int currentCount - IN member values to be set
 * @return none
 */
void ModuloNCounter::set(int maxCount, int currentCount)
{
	m_maxCount= maxCount;
	m_currentCount= currentCount;
}

