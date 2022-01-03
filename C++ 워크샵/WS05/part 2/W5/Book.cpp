
#include <iomanip>
#include "Book.h"
using namespace std;

namespace sdds {

	void Book::trim(string& src) const {

		if (!src.empty()) {
			src.erase(0, src.find_first_not_of(" "));
			src.erase(src.find_last_not_of(" ") + 1);
		}
	}

	Book::Book(const string& strBook) {

		size_t start = 0, end = 0;

		end = strBook.find(',', start);
		trim(m_author = strBook.substr(start, end - start));

		start = end + 1;
		end = strBook.find(',', start);
		trim(m_title = strBook.substr(start, end - start));

		start = end + 1;
		end = strBook.find(',', start);
		trim(m_country = strBook.substr(start, end - start));

		start = end + 1;
		end = strBook.find(',', start);
		m_price = stod(strBook.substr(start, end - start));

		start = end + 1;
		end = strBook.find(',', start);
		m_year = stoi(strBook.substr(start, end - start));

		start = end + 1;
		trim(m_desc = strBook.substr(start));
	}

	const string& Book::title() const {
		return m_title;
	}
	const string& Book::country() const {
		return m_country;
	}
	const size_t& Book::year() const {
		return m_year;
	}
	double& Book::price() {
		return m_price;
	}

	ostream& operator<<(ostream& os, const Book& book) {

		os
			<< setw(20) << book.m_author << " | "
			<< setw(22) << book.title() << " | "
			<< setw(5) << book.country() << " | "
			<< setw(4) << book.year() << " | "
			<< setw(6) << fixed << setprecision(2) << book.m_price << " | "
			<< book.m_desc << endl;

		return os;
	}
}