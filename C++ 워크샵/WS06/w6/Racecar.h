/*I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NCC
// Date:           October 18, 2020
//==============================================
// Workshop :	   6
// Part     :      2
//==============================================

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include "Car.h"

namespace sdds {

	class Racecar : public Car {

		double m_booster;

	public:

		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;

	};
}
#endif