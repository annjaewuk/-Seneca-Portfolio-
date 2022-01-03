/*I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NCC
// Date:           October 28, 2020
//==============================================
// Workshop :	   5
// Part     :      2
//==============================================

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <string>

using namespace std;
namespace sdds {

	const int MAX = 5;

	class SpellChecker {

		string m_badWords[MAX];
		string m_goodWords[MAX];

	public:

		SpellChecker(const char*);
		void operator()(string&) const;

	};
}

#endif
