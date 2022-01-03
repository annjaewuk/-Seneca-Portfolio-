/*
Name:			Luis Jaime Hernandez
E-mail :		ljaime-hernandez@myseneca.ca
Student ID :	137797197
Date :			October 4, 2020
Class :			OOP345NEE
Assignment :	w2

I have done all the coding by myself and only copied that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iomanip>

#include "RecordSet.h"


namespace sdds
{
	RecordSet::~RecordSet()
	{
		delete[] rec;
		rec = nullptr;
	}

	RecordSet::RecordSet()
	{
		rec = nullptr;
		rec_num = 0;
	}

	RecordSet::RecordSet(const string& str)
	{
		string buff;
		ifstream file(str.c_str());
		int i = 0;

		while (!file.eof())
		{
			getline(file, buff, ' ');
			i++;
		}

		rec = new string[i + 1];
		buff = {};
		file.close();
		file.open(str);

		i = 0;

		while (getline(file, buff, ' '))
		{
			rec[i] = buff;
			i++;
		}
		rec_num = i;
	}

	RecordSet::RecordSet(const RecordSet& other)
	{
		*this = other;
	}

	RecordSet::RecordSet(RecordSet&& other)
	{
		*this = std::move(other);
	}

	RecordSet& RecordSet::operator=(const RecordSet& other)
	{
			rec_num = other.rec_num;
			rec = new string[rec_num];

			for (unsigned int i = 0; i < rec_num; i++)
			{
				rec[i] = other.rec[i];
			}
			return *this;
	}

	RecordSet& RecordSet::operator=(RecordSet&& other)
	{
		if (this != &other)
		{
			rec_num = other.rec_num;
			rec = other.rec;
			
			other.rec_num = 0;
			other.rec = nullptr;
		}
		return *this;
	}

	size_t RecordSet::size()
	{
		return rec_num;
	}

	string RecordSet::getRecord(int given_t)
	{
		if (rec != nullptr)
		{
			return string(rec[given_t]);
		}
		else
		{
			return "";
		}
	}
}