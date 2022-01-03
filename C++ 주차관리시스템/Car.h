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
#ifndef _SDDS_CAR_H_
#define _SDDS_CAR_H_
#include <iostream>
#include "Vehicle.h"

using namespace std;
namespace sdds {
	class Car : public Vehicle {

	private:
		bool m_carWash;

	public:
		Car();
		Car(const char* licensePlate, const char* makeModel);
		Car(const Car&) = delete;
		void operator=(const Car&) = delete;
		istream& read(istream& in = cin);
		ostream& write(ostream& out = cout) const;
	};
}
#endif