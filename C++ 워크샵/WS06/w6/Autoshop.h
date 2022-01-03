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

#ifndef SDDS_AUTOSHOP_H 
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {

	class Autoshop {

		std::vector<Vehicle*> m_vehicles;

	public:

		Autoshop() = default;
		~Autoshop();
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {

			for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {

				if (test(*i)) {
					vehicles.push_back(*i);

				}
			}
		}
	};
}
#endif 