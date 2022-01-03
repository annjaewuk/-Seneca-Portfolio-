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

#ifndef SDDS_UTILITIES_H 
#define SDDS_UTILITIES_H
#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"


namespace sdds {
	Vehicle* createInstance(std::istream& in);
}
#endif 