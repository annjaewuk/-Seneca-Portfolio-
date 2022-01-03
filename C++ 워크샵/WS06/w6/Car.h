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

#ifndef SDDS_CAR_H 
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {

	class Car : public Vehicle {

		std::string m_maker = "";
		std::string m_condition = "";
		double m_topSpeed = 0.0;

	public:

		std::string trim(std::string&);
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream&) const;

	};
}

#endif 
