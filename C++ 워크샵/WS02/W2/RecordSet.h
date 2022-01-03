/*I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NCC
// Date:           October 3, 2020
//==============================================
// Workshop :	   2
// Part     :      2
//==============================================
#ifndef _345_RECORDSET_H_
#define _345_RECORDSET_H_

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <string>
#include <fstream>

using namespace std;
namespace sdds {

	class RecordSet {

		string* record;
		size_t num;

	public:

		RecordSet();
		RecordSet(const string& file_name);
		RecordSet(const RecordSet& copy);
		RecordSet(RecordSet&&);	
		RecordSet& operator=(const RecordSet& copy);
		RecordSet& operator=(RecordSet&& copy);
		~RecordSet();
		size_t size() const;
		string getRecord(size_t index);

	};
}

#endif