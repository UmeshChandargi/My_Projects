// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>
#include "ModuloNDigit.h"
using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
int main ()
{
	//!/***************** ModuloNDigit testcase ******************************/

	while(1)
	{
		int digits=0, counterType=0;

		cout<<endl<<"Please enter the parameters of your counter: "<<endl;
		cout<<"number of digits: ";
		cin>>digits;

		cout<<"type (2/8/10/16): ";
		cin>>counterType;

		if( (counterType== 2 || counterType== 8 || counterType== 10 || counterType== 16) && digits>0)
		{
			ModuloNDigit mod102D(digits,counterType);

			mod102D.print(COUNTER_NAME);


			for(int i=0;i<500;i++)
			{
				mod102D.print(COUNTER_VALUE);
				int ret= mod102D.count();
				cout<<" ";
				if(ret == 1)
				{
					cout<<endl;
				}

			}
		}
		else
		{
			cout<<"Test Ended";
			break;
		}
	}

	//!/***************** Prefix increment operator testcase ******************************/

	//	ModuloNDigit mod102D(2,10);
	//	ModuloNDigit mod102D_Obj2(2,10);
	//
	//	mod102D_Obj2 = ++mod102D;
	//
	//	mod102D.print(COUNTER_VALUE);
	//	cout<<endl;
	//
	//	mod102D_Obj2.print(COUNTER_VALUE);
	//	cout<<endl;

	//!/***************** Postfix increment operator testcase ******************************/

	//		ModuloNDigit mod102D(2,10);
	//		ModuloNDigit mod102D_Obj2(2,10);
	//
	//		mod102D_Obj2 = mod102D++;
	//
	//		mod102D.print(COUNTER_VALUE);
	//		cout<<endl;
	//
	//		mod102D_Obj2.print(COUNTER_VALUE);
	//		cout<<endl;

	return 0;
}
