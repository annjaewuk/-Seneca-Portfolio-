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
#include "Car.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	Car::Car() : Vehicle(), m_carWash(false) {

	}

	Car::Car(const char* licensePlate, const char* makeModel) : Vehicle(licensePlate, makeModel), m_carWash(false) {

	}

	istream& Car::read(istream& in) {

		if (!(isCsv())) {
			cout << "\nCar information entry" << endl;
			Vehicle::read(in);
			cout << "Carwash while parked? (Y)es/(N)o: ";
			m_carWash = Utils::yes(in);
		}
		else {
			Vehicle::read(in);
			in >> m_carWash;
			in.ignore(100, '\n');
		}

		return in;

	}
	ostream& Car::write(ostream& out) const {
		if (Vehicle::isEmpty()) {
			out << "Invalid Car Object" << endl;
		}
		else {
			if (isCsv()) {
				out << "C,";
			}
			else {
				out << "Vehicle type: Car" << endl;
			}

			Vehicle::write(out);

			if (isCsv()) {
				out << m_carWash << endl;
			}
			else {
				if (m_carWash == 1) {
					out << "With Carwash" << endl;
				}
				else {
					out << "Without Carwash" << endl;
				}
			}
		}
		return out;
	}
}