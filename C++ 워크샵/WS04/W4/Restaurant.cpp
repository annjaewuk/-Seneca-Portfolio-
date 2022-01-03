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

#include "Restaurant.h"

using namespace std;
namespace sdds {

	Restaurant::~Restaurant() {
		delete[] m_reservations;
	}

	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {

		m_reservations = new Reservation[cnt];
		m_cnt = cnt;

		for (auto i = 0u; i < cnt; i++) {
			this->m_reservations[i] = *reservations[i];
		}
	}

	Restaurant::Restaurant(const Restaurant& src) {
		*this = src;
	}

	Restaurant& Restaurant::operator=(const Restaurant& src) {

		if (this != &src) {

			m_cnt = src.m_cnt;

			delete[] this->m_reservations;
			this->m_reservations = new Reservation[m_cnt];

			for (auto i = 0u; i < m_cnt; i++) {
				this->m_reservations[i] = src.m_reservations[i];
			}
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& src) noexcept {
		*this = move(src);
	}

	Restaurant& Restaurant::operator=(Restaurant&& src) noexcept {

		if (this != &src) {
			m_cnt = src.m_cnt;

			delete[] this->m_reservations;

			this->m_reservations = src.m_reservations;
			src.m_cnt = 0;
			src.m_reservations = nullptr;

		}
		return *this;
	}


	size_t Restaurant::size() const {
		return m_cnt;
	}

	ostream& operator<<(ostream& os, const Restaurant& res) {

		os << "--------------------------\n"
			<< "Fancy Restaurant\n"
			<< "--------------------------\n";

		if (res.m_cnt == 0) {
			os << "The object is empty!\n";
		}

		else {
			for (auto i = 0u; i < res.m_cnt; i++) {
				os << res.m_reservations[i];
			}
		}

		os << "--------------------------\n";
		return os;
	}
}