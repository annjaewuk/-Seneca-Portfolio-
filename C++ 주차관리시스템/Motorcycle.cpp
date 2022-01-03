/*I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NAA
// Date:           August 3, 2020
//==============================================
// Milestone :	   5
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include "Motorcycle.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	Motorcycle::Motorcycle() : Vehicle(), m_hasSideCar(false) {

	}

	Motorcycle::Motorcycle(const char* licensePlate, const char* makeModel) : Vehicle(licensePlate, makeModel), m_hasSideCar(false) {

	}

	istream& Motorcycle::read(istream& in) {

		if (!(isCsv())) {
			cout << "\nMotorcycle information entry" << endl;
			Vehicle::read(in);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			m_hasSideCar = Utils::yes(in);
		}
		else {
			Vehicle::read(in);
			in >> m_hasSideCar;
			in.ignore(100, '\n');
		}

		return in;

	}
	ostream& Motorcycle::write(ostream& out) const {
		if (Vehicle::isEmpty()) {
			out << "Invalid Motorcycle Object" << endl;
		}
		else {
			if (isCsv()) {
				out << "M,";
			}
			else {
				out << "Vehicle type: Motorcycle" << endl;
			}

			Vehicle::write(out);

			if (isCsv()) {
				out << m_hasSideCar << endl;
			}
			else {
				if (m_hasSideCar == 1) {
					out << "With Sidecar" << endl;
				}
			}
		}
		return out;
	}
}