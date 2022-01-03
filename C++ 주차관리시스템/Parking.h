/*I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NAA
// Date:           July 18, 2020
//==============================================
// Milestone :	   2
//==============================================
#ifndef _SDDS_PARKING_H_
#define _SDDS_PARKING_H_
#include <iostream>
#include "Menu.h"
#include "Vehicle.h"

namespace sdds {

	const int MAX_PARKING_SPOT = 100;

	class Parking {

	private:
		char* m_datafile;
		Menu m_parkingMenu;
		Menu m_vehicleMenu;
		int m_noOfSpots;
		Vehicle* m_parkingSpots[MAX_PARKING_SPOT];
		int m_noOfParked;
	private:
		bool isEmpty() const;
		void setEmpty();
		void parkingStatus() const;
		void parkVehicle();
		void returnVehicle();
		void listParkedVehicles();
		bool closeParking();
		bool exitParkingApp();
		bool load();
		void save();
	public:
		Parking(const char* datafile, int noOfSpots);
		Parking(const Parking&) = delete;
		Parking& operator=(const Parking&) = delete;
		int run();
		~Parking();

	};

}

#endif