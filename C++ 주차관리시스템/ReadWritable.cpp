/*I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NAA
// Date:           August 3, 2020
//==============================================
// Milestone :	   5
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include "ReadWritable.h"

using namespace std;

namespace sdds {

	ReadWritable::ReadWritable() {
		commaFlag = false;
	}

	ReadWritable::~ReadWritable() {

	}

	bool ReadWritable::isCsv() const {
		return commaFlag;
	}

	void ReadWritable::setCsv(bool value) {
		commaFlag = value;
	}


	ostream& operator<<(ostream& out, const ReadWritable& rw) {
		return rw.write(out);
	}

	istream& operator>>(istream& in, ReadWritable& rw) {
		return rw.read(in);
	}

}