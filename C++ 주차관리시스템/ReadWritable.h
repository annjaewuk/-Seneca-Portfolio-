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
#ifndef _SDDS_RW_H_
#define _SDDS_RW_H_
#include <iostream>

using namespace std;
namespace sdds {

	class ReadWritable {
		bool commaFlag;

	public:
		ReadWritable();
		virtual ~ReadWritable();
		bool isCsv() const;
		void setCsv(bool value);
		virtual ostream& write(ostream& out = cout) const = 0;
		virtual istream& read(istream& in = cin) = 0;
	};
	ostream& operator<<(ostream& out, const ReadWritable& rw);
	istream& operator>>(istream& in, ReadWritable& rw);

}

#endif