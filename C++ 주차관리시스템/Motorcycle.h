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
#ifndef _SDDS_MOTOR_H_
#define _SDDS_MOTOR_H_
#include <iostream>
#include "Vehicle.h"

using namespace std;
namespace sdds {
	class Motorcycle : public Vehicle {

	private:
		bool m_hasSideCar;

	public:
		Motorcycle();
		Motorcycle(const char* licensePlate, const char* makeModel);
		Motorcycle(const Motorcycle&) = delete;
		void operator=(const Motorcycle&) = delete;
		istream& read(istream& in = cin);
		ostream& write(ostream& out = cout) const;
	};
}
#endif