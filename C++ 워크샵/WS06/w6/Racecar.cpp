
#include <string>
#include "Racecar.h"

namespace sdds {

	Racecar::Racecar(std::istream& in) : Car(in) {

		std::string src;
		std::getline(in, src, ',');
		m_booster = std::stod(Car::trim(src));

	}

	void Racecar::display(std::ostream& out) const {

		Car::display(out);
		out << "*";

	}

	double Racecar::topSpeed() const {

		return Car::topSpeed() * (1 + m_booster);

	}

}