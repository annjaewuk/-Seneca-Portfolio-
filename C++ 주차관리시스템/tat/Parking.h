/*
Name:		Tatsuro Hayashi
E-mail:		thayashi@myseneca.ca
Student ID:	137555199
Data:		August 7, 2020
Class:		OOP244NAA
Assignment:	MS6
Professor:	Andrei Sajeniouk

I have done all the coding by myself and only copied that my professor provided
to complete my workshops and assignments.
*/

#ifndef _244_MS_PARKING_H_
#define _244_MS_PARKING_H_
#include <iostream>
#include "Menu.h"
#include "Car.h"
#include "Motorcycle.h"

using namespace std;

namespace sdds {
	const int MAX_NUM_OF_PARK_SPOTS = 100;

	class Parking {
		char* fileName;
		Menu* parkingMenu;
		Menu* vehicleSelection;
		Vehicle* parkingSpots[MAX_NUM_OF_PARK_SPOTS] = { nullptr };
		int numOfSpots;
		int numOfParkedVehicle;

		bool isEmpty();
		void parkingStatus();
		void parkVehicle();
		void returnVehicle();
		void listParkedVehicle();
		bool closeParking();
		bool exitParking() const;
		bool loadData();
		void saveData();
	public:
		Parking();
		Parking(const char*, int);
		Parking(const Parking&) = delete;
		int run();
		Parking& operator=(const Parking&) = delete;
		~Parking();
	};
}
#endif 
