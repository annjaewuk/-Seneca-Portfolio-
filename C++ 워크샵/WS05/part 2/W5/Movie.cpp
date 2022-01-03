
#include <iomanip>
#include "Movie.h"
using namespace std;

namespace sdds {

	Movie::Movie() : m_title{ "" }, m_year{ 0 }, m_desc{ "" } {
	
	}

	void Movie::trim(string& src) const {

		if (!src.empty()) {

			src.erase(0, src.find_first_not_of(" "));
			src.erase(src.find_last_not_of(" ") + 1);

		}
	}

	Movie::Movie(const string& strMovie) {

		size_t start = 0, end = 0;

		end = strMovie.find(',', start);
		trim(m_title = strMovie.substr(start, end - start));

		start = end + 1;
		end = strMovie.find(',', start);
		m_year = stoi(strMovie.substr(start, end - start));

		start = end + 1;
		trim(m_desc = strMovie.substr(start));
	}

	ostream& operator<<(ostream& os, const Movie& movie) {

		os << setw(40) << movie.m_title << " | "
			<< setw(4) << movie.m_year << " | "
			<< movie.m_desc << endl;

		return os;
	}
}