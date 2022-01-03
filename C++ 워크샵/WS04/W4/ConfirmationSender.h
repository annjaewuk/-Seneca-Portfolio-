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

#ifndef _SDDS_CONFIRMATIONSENDER_H
#define _SDDS_CONFIRMATIONSENDER_H
#include <iostream>
#include "Reservation.h"

using namespace std;
namespace sdds {

	class ConfirmationSender {

		const Reservation** m_reservations = nullptr;
		size_t m_cnt = 0u;

	public:

		ConfirmationSender() {};
		~ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src) noexcept;
		ConfirmationSender& operator=(ConfirmationSender&& src) noexcept;

		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend ostream& operator<<(ostream& os, const ConfirmationSender& conSender);
	};
}
#endif
