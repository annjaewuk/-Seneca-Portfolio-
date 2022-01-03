
#include <iomanip>
#include "Car.h"

using namespace std;
namespace sdds {

	string Car::trim(string& src) {

		while (src.length() > 0 && src[0] == ' ')
			src.erase(0, 1);

		while (src.length() > 0 && src[src.length() - 1] == ' ')
			src.erase(src.length() - 1, 1);

		return src;
	}

	Car::Car(istream& is) {

		string src;
		getline(is, src, ',');
		m_maker = trim(src);

		getline(is, src, ',');
		trim(src);

		if (src == "n" || src == "") {
			m_condition = "new";
		}

		else if (src == "u") {
			m_condition = "used";
		}

		else if (src == "b") {
			m_condition = "broken";
		}

		else {
			throw "Invalid record!";
		}

		getline(is, src, ',');

		try {
			m_topSpeed = stoi(trim(src));
		}

		catch (...) {
			throw "Invalid record!";
		}

	}

	string Car::condition() const {
		return m_condition;
	};

	double Car::topSpeed() const {
		return m_topSpeed;
	};

	void Car::display(ostream& os) const {

		os << "| " << setw(10) << right << m_maker
			<< " | " << setw(6) << left << m_condition
			<< " | " << setw(6) << fixed << setprecision(2) << topSpeed()
			<< " |";

	};
}