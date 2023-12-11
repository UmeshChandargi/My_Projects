/*
 * ModuloNCounter.h
 *
 *  Created on: 09-Nov-2023
 *      Author: umesh
 */

#ifndef MODULONCOUNTER_H_
#define MODULONCOUNTER_H_

typedef enum
{
	COUNTER_NAME,
	COUNTER_VALUE,

}COUNTER_PrintOption_t;

class ModuloNCounter
{
private:
	int m_maxCount;
	int m_currentCount;
public:

	/*!
	 * initializes a counter by setting the current count value to 0 and the maximum count value to an
	 * arbitrary value.
	 * @param int maxCount - IN Max value at which the counter will overflow
	 * @return none
	 */
	ModuloNCounter(int maxCount=2);

	/*!
	 * counts, that is increase the current count value of a passed counter by 1 or reset it to 0, in case
	 * of the value becomes greater than n-1 (overflow).
	 * arbitrary value.
	 * @param none
	 * @return int - returns 1 if an overflow had occurred otherwise 0
	 */
	int count();

	/*!
	 * prints the name of the counter (modulo n counter, n should be replaced by the
	 * current value of the maximum count value) or the current count value based on enum option
	 * @param COUNTER_PrintOption_t option - IN Print option passed as a param
	 * @return none
	 */
	void print(COUNTER_PrintOption_t option);

	/*!
	 * getter function for m_maxCount
	 * @param none
	 * @return int- returns value of m_maxCount
	 */
	int getMaxCount();

	/*!
	 * getter function for m_currentCount
	 * @param none
	 * @return int- returns value of m_currentCount
	 */
	int getCurrentCount();

	/*!
	 * set function for all the members
	 * @param int maxCount, int currentCount - IN member values to be set
	 * @return none
	 */
	void set(int maxCount, int currentCount);

};

#endif /* MODULONCOUNTER_H_ */
