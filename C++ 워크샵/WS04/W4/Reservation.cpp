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
#include "Reservation.h"

using namespace std;
namespace sdds {

	Reservation::Reservation() :num(0), day(0), hour(0) {

	}

	void Reservation::trim(string& src) const {

		if (!src.empty()) {
			src.erase(0, src.find_first_not_of(" "));
			src.erase(src.find_last_not_of(" ") + 1);
		}
	}

	Reservation::Reservation(const string& res) {

		size_t start = 0;
		size_t end = res.find(':');

		this->trim(m_id = res.substr(start, end - start));
		start = end + 1;
		end = res.find(',', start);

		this->trim(m_name = res.substr(start, end - start));
		start = end + 1;
		end = res.find(',', start);

		this->trim(m_email = res.substr(start, end - start));
		start = end + 1;
		end = res.find(',', start);

		num = stoi(res.substr(start, end - start));
		start = end + 1;
		end = res.find(',', start);

		day = stoi(res.substr(start, end - start));
		start = end + 1;
		end = res.find(',', start);

		hour = stoi(res.substr(start, end - start));

	}

	ostream& operator<<(ostream& os, const Reservation& res) {

		string email = "<" + res.m_email + ">";
		os << "Reservation " << res.m_id << ": "
			<< setw(10) << right << res.m_name << "  "
			<< setw(20) << left << email << right << "    ";

		if (res.hour >= 6 && res.hour <= 9)
			os << "Breakfast on day " << res.day << " @ " << res.hour;

		else if (res.hour >= 11 && res.hour <= 15)
			os << "Lunch on day " << res.day << " @ " << res.hour;

		else if (res.hour >= 17 && res.hour <= 21)
			os << "Dinner on day " << res.day << " @ " << res.hour;

		else
			os << "Drinks on day " << res.day << " @ " << res.hour;

		os << ":00 for " << res.num << " people." << endl;

		return os;
	}
}