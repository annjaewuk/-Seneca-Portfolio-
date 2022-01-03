
#include "Autoshop.h"

namespace sdds {

	Autoshop::~Autoshop() {

		while (!m_vehicles.empty()) {

			delete m_vehicles.back();
			m_vehicles.pop_back();

		}
	}

	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {

		m_vehicles.push_back(theVehicle);
		return *this;

	}

	void Autoshop::display(std::ostream& out) const {

		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";

		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {

			(*i)->display(out);
			out << std::endl;

		}
		out << "--------------------------------\n";
	}

}