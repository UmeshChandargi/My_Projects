/*
 * ModuloNDigit.h
 *
 *  Created on: 09-Nov-2023
 *      Author: umesh
 */

#ifndef MODULONDIGIT_H_
#define MODULONDIGIT_H_

#include "ModuloNCounter.h"
class ModuloNDigit
{
private:
	ModuloNCounter* m_pNDigitArray;
	int m_NoOfDigits;
public:

	/*!
	 * initializes a multiple digit counter by creating an array of m counters and storing the number
	 * of digits into the Class member. Additionally, the constructor initializes the counters of the
	 * array by setting their current count values to 0 and their maximum count value to one of the
	 * following values: 2 (binary), 8 (octal), 10 (decimal) or 16 (hexadecimal).
	 * @param int noDigits - IN No of digits
	 * @param int CounterType - IN Counter type: 2 (binary), 8 (octal), 10 (decimal) or 16 (hexadecimal)
	 * @return int- returns 0 in case the maximum count value is not allowed or the number of digits is 0,
	 * otherwise 1 if all okay, returns -1 if malloc fails
	 */
	ModuloNDigit(int noDigits, int CounterType);

	/*!
	 * Copy constructor created because there is a deep copy of ModuloNCounters
	 * It is needed for operator ++, while returning result object.
	 * @param ModuloNDigit& other - the object value with should be copied
	 * @return none
	 */
	ModuloNDigit(const ModuloNDigit& other);

	/*!
	 * Operator overloading for assignment operator. it created as a rule of three(Copy constructor,
	 * assignment operator, destructor)
	 * @param  ModuloNDigit& rop - the right hand object which should be assigned to the left object
	 * @return ModuloNDigit&- returns a reference of the left hand object
	 */
	ModuloNDigit& operator =(const ModuloNDigit& rop);

	/*!
	 * de-initializes a multiple digit counter by releasing the memory of its array of counters and
	 * setting its members to NULL and 0 respectively
	 * @param none
	 * @return none
	 */
	~ModuloNDigit();

	/*!
	 * counts, that is increase the current count value of a passed counter by 1 or reset it to 0, in case
	 * of the value becomes greater than n-1 (overflow).
	 * arbitrary value.
	 * @param none
	 * @return int - returns 1 if an overflow had occurred otherwise 0
	 */
	int count();

	/*!
	 * prints the name of the counter (m digit binary/octal/decimal/hexadecimal counter,
	 * m and the type should be replaced by the current values) or the current count value of the m
	 * digit counter (with one space after the digits!)
	 * @param COUNTER_PrintOption_t option - IN Print option passed as a param
	 * @return none
	 */
	void print(COUNTER_PrintOption_t option);

	/*!
	 * Operator overloading for postfix increment operator.
	 * @param  int- dummy parameter to make post-increment recognizable
	 * @return ModuloNDigit- returns a temperory object with the value before the increment
	 */
	ModuloNDigit operator ++(int);

	/*!
	 * Operator overloading for prefix increment operator.
	 * @param  none
	 * @return ModuloNDigit& - returns a reference of "this" object after increment
	 */
	ModuloNDigit& operator ++();


private:
	/*!
	 * Counts each digit by recursing till the last digit if overflow occurs
	 * @param int& digit - IN/OUT reference of the digit value
	 * @return none
	 */
	void recursivefuntCount(int& digit);

};

#endif /* MODULONDIGIT_H_ */
