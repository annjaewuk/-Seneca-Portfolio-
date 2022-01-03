/*I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NCC
// Date:           October 18, 2020
//==============================================
// Workshop :	   4
// Part     :      2
//==============================================

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
#include <string>

using namespace std;
namespace sdds {
	class Reservation {

		string m_id = "";
		string m_name = "";
		string m_email = "";
		size_t num;
		size_t day;
		size_t hour;

		void trim(std::string& src) const;

	public:

		Reservation();
		Reservation(const string& res);
		friend ostream& operator<<(ostream& os, const Reservation& res);

	};

}
#endif