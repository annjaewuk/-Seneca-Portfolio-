/*I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NCC
// Date:           November 29, 2020
//==============================================
// Workshop :	   9
// Part     :      2
//==============================================

#include <iostream>
#include <fstream>
#include <string>
#include "SecureData.h"
#include "SecureData.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;

	if (argc != 4)
	{
		cerr << endl << "***Incorrect number of arguments***" << endl;
		return 1;
	}

	char key = argv[3][0];

	try {
		w9::SecureData sd(argv[1], key, &cout);
		sd.backup(argv[2]);

		sd.restore(argv[2], key);
		cout << sd << std::endl;

	}
	catch (const std::string & msg) {
		cout << msg << std::endl;
	}

	return 0;
}