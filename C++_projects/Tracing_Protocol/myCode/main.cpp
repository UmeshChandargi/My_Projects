// Standard (system) header files
#include <iostream>
#include <cstdlib>
using namespace std;

// Add your project's header files here
#include "CTracingProt.h"

// Main program
int main()
{

	//Creating object of Class- CTracingProt
	CTracingProt Prot;

	//Protocol member attributes are initialized
	Prot.ProtInit();

	/* Read protocol from Decoding_TC_I.txt and
	Write the decoded message in Decoding_TC_O.txt*/
	Prot.ReadProtAndParse();

	/* Read a message from Encoding_TC_I.txt
	   and write the encoded result in Encoding_TC_O.txt */
	Prot.ReadMsgWriteProt();



    return 0;
}


