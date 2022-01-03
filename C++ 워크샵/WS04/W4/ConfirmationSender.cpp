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

#include <iomanip>
#include "ConfirmationSender.h"

using namespace std;
namespace sdds {

	ConfirmationSender::~ConfirmationSender() {
		delete[] m_reservations;

	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {
		*this = src;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) {

		if (this != &src) {

			m_cnt = src.m_cnt;

			delete[] this->m_reservations;
			this->m_reservations = new const Reservation * [m_cnt];

			for (auto i = 0u; i < m_cnt; i++) {
				this->m_reservations[i] = src.m_reservations[i];
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept {
		*this = move(src);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept {

		if (this != &src) {

			m_cnt = src.m_cnt;

			delete[] this->m_reservations;

			this->m_reservations = src.m_reservations;
			src.m_cnt = 0;
			src.m_reservations = nullptr;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {

		bool flag = false;

		for (auto i = 0u; i < m_cnt && flag == false; i++) {

			if (&res == m_reservations[i]) {
				flag = true;
			}
		}

		if (flag == false) {

			const Reservation** temp = nullptr;

			temp = new const Reservation * [m_cnt + 1];
			for (auto i = 0u; i < m_cnt; i++) {
				temp[i] = m_reservations[i];
			}

			temp[m_cnt] = &res;
			m_cnt++;

			delete[] m_reservations;
			m_reservations = temp;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {

		bool flag = false;
		int index = -1;

		for (auto i = 0u; i < m_cnt && flag == false; i++) {

			if (&res == m_reservations[i]) {
				flag = true;
				index = i;
			}
		}

		if (flag == true) {

			const Reservation** temp = nullptr;

			if (m_cnt > 0) {

				temp = new const Reservation * [m_cnt - 1];

				for (int i = 0; i < (int)m_cnt - 1; i++) {
					if (i < index) {
						temp[i] = m_reservations[i];
					}
					else
						temp[i] = m_reservations[i + 1];
				}
			}
			m_cnt--;
			delete[] m_reservations;
			m_reservations = temp;
		}

		return *this;
	}

	ostream& operator<<(ostream& os, const ConfirmationSender& conSender) {

		os << "--------------------------\n"
			<< "Confirmations to Send\n"
			<< "--------------------------\n";

		if (conSender.m_cnt == 0) {
			os << "The object is empty!\n";
		}

		for (auto i = 0u; i < conSender.m_cnt; i++) {

			if (conSender.m_reservations[i] != nullptr) {
				os << *conSender.m_reservations[i];
			}
		}
		os << "--------------------------\n";
		return os;
	}
}