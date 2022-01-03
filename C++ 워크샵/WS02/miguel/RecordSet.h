/*
Name:			Luis Jaime Hernandez
E-mail :		ljaime-hernandez@myseneca.ca
Student ID :	137797197
Date :			October 4, 2020
Class :			OOP345NEE
Assignment :	w2

I have done all the coding by myself and only copied that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <string>
#include <fstream>

using namespace std;

namespace sdds
{
	class RecordSet
	{
		string* rec;
		size_t rec_num;
	public:
		~RecordSet();
		RecordSet();
		RecordSet(const string& str);
		RecordSet(const RecordSet& other);
		RecordSet(RecordSet&& other);
		RecordSet& operator=(const RecordSet& other);
		RecordSet& operator=(RecordSet&& other);
		size_t size();
		string getRecord(int given_t);
	};
}
#endif