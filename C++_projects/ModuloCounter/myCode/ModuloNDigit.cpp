/*
 * ModuloNDigit.cpp
 *
 *  Created on: 09-Nov-2023
 *      Author: umesh
 */
#include <iostream>
#include "ModuloNDigit.h"
using namespace std;

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
ModuloNDigit::ModuloNDigit(int noDigits, int CounterType)
{
	if( (CounterType== 2 || CounterType== 8 || CounterType== 10 || CounterType== 16) && noDigits>0)
	{
		m_NoOfDigits = noDigits;
		m_pNDigitArray= new ModuloNCounter[noDigits];

		if(m_pNDigitArray == NULL)
		{
			cerr<<"Mem allocation failed!"<<endl;
		}
		else
		{
			for(int i=0; i<m_NoOfDigits;i++)
			{

				m_pNDigitArray[i].set(CounterType, 0);
			}
		}
	}
	else
	{
		cerr<<"Illegal parameter: "
				"CounterType can have only following values: 2 (binary), 8 (octal), 10 (decimal) or 16 (hexadecimal)"
				" and number of digits should be min 1";

	}

}


/*!
 * Copy constructor created because there is a deep copy of ModuloNCounters
 * It is needed for operator ++, while returning result object.
 * @param ModuloNDigit& other - the object value with should be copied
 * @return none
 */
ModuloNDigit::ModuloNDigit(const ModuloNDigit &other)
{
	m_NoOfDigits = other.m_NoOfDigits;
	m_pNDigitArray= new ModuloNCounter[m_NoOfDigits];

	if(m_pNDigitArray == NULL)
	{
		cerr<<"Mem allocation failed!"<<endl;
	}
	else
	{
		for(int i=0; i<m_NoOfDigits;i++)
		{

			m_pNDigitArray[i]= other.m_pNDigitArray[i];
		}

	}

}


/*!
 * Operator overloading for assignment operator. it created as a rule of three(Copy constructor,
 * assignment operator, destructor)
 * @param  ModuloNDigit& rop - the right hand object which should be assigned to the left object
 * @return ModuloNDigit&- returns a reference of the left hand object
 */
ModuloNDigit& ModuloNDigit::operator =(const ModuloNDigit& rop)
{
	if(m_NoOfDigits!= rop.m_NoOfDigits)
	{
		delete[] m_pNDigitArray;
		m_pNDigitArray= new ModuloNCounter[m_NoOfDigits];
	}
	if(m_pNDigitArray == NULL)
	{
		cerr<<"Mem allocation failed!"<<endl;
	}
	else
	{
		m_NoOfDigits= rop.m_NoOfDigits;
		for(int i=0; i<m_NoOfDigits;i++)
		{
			m_pNDigitArray[i]= rop.m_pNDigitArray[i];
		}

	}

	return *this;

}

/*!
 * de-initializes a multiple digit counter by releasing the memory of its array of counters and
 * setting its members to NULL and 0 respectively
 * @param none
 * @return none
 */
ModuloNDigit::~ModuloNDigit()
{
	// TODO Auto-generated destructor stub
	delete[] m_pNDigitArray;
	m_pNDigitArray=0;
	m_NoOfDigits=0;
}

/*!
 * counts, that is increase the current count value of a passed counter by 1 or reset it to 0, in case
 * of the value becomes greater than n-1 (overflow).
 * arbitrary value.
 * @param none
 * @return int - returns 1 if an overflow had occurred otherwise 0
 */
int ModuloNDigit::count()
{
	int digit=0;
	recursivefuntCount(digit);

	if(m_pNDigitArray[0].getMaxCount()==2 && digit== m_NoOfDigits)
	{
		return 1;
	}
	else if(m_pNDigitArray[0].getMaxCount()!=2 && digit>0)
	{
		return 1;
	}
	return 0;

}

/*!
 * prints the name of the counter (m digit binary/octal/decimal/hexadecimal counter,
 * m and the type should be replaced by the current values) or the current count value of the m
 * digit counter (with one space after the digits!)
 * @param COUNTER_PrintOption_t option - IN Print option passed as a param
 * @return none
 */
void ModuloNDigit::print(COUNTER_PrintOption_t option)
{
	if(option== COUNTER_NAME)
	{
		cout<<m_NoOfDigits<<" digit ";
		switch(m_pNDigitArray[0].getMaxCount())
		{
		case 2:
			cout<<"binary counter"<<endl;
			break;
		case 8:
			cout<<"octal counter"<<endl;
			break;
		case 10:
			cout<<"decimal counter"<<endl;
			break;
		case 16:
			cout<<"hexadecimal counter"<<endl;
			break;

		}
	}
	else if(option == COUNTER_VALUE)
	{
		for(int i= m_NoOfDigits-1;i>=0;i--)
		{
			if(m_pNDigitArray[0].getMaxCount()==16 && m_pNDigitArray[i].getCurrentCount()>9)
			{
				switch(m_pNDigitArray[i].getCurrentCount())
				{
				case 10:
					cout<<"A";
					break;
				case 11:
					cout<<"B";
					break;
				case 12:
					cout<<"C";
					break;
				case 13:
					cout<<"D";
					break;
				case 14:
					cout<<"E";
					break;
				case 15:
					cout<<"F";
					break;
				}
			}
			else
			{
				cout<<m_pNDigitArray[i].getCurrentCount();
			}
		}
	}


}

/*!
 * Operator overloading for postfix increment operator.
 * @param  int- dummy parameter to make post-increment recognizable
 * @return ModuloNDigit- returns a temperory object with the value before the increment
 */
ModuloNDigit ModuloNDigit::operator ++(int int1)
{
	ModuloNDigit result = *this; //cc

	this->count();
	cout<<endl;

	//there is a need for copy constructor here.
	return result; //cc
}

/*!
 * Operator overloading for prefix increment operator.
 * @param  none
 * @return ModuloNDigit& - returns a reference of "this" object after increment
 */
ModuloNDigit& ModuloNDigit::operator ++()
{
	this->count();
	return *this;
}


/*!
 * Counts each digit by recursing till the last digit if overflow occurs
 * @param int& digit - IN/OUT reference of the digit value
 * @return none
 */
void ModuloNDigit::recursivefuntCount(int& digit)
{
	if(digit< m_NoOfDigits)
	{
		if(m_pNDigitArray[digit].count() == 1)
		{
			digit++;
			recursivefuntCount(digit);
		}
	}
}
