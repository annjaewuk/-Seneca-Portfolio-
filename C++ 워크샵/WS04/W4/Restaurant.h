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

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include "Reservation.h"

using namespace std;
namespace sdds {

	class Restaurant {

		Reservation* m_reservations = nullptr;
		size_t m_cnt = 0u;

	public:

		Restaurant() {};
		~Restaurant();
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& src);
		Restaurant& operator=(const Restaurant& src);
		Restaurant(Restaurant&& src) noexcept;
		Restaurant& operator=(Restaurant&& src) noexcept;
		size_t size() const;

		friend ostream& operator<<(ostream& os, const Restaurant& res);
	};
}
#endif 
