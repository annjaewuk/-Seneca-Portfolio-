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
#ifndef _244_VEHICLE_H__
#define _244_VEHICLE_H__

#include <iostream>
#include "ReadWritable.h"

namespace sdds{
	const int MAX_LicensePlate = 8;
	const int MIN_LicensePlate = 1;
	const int MAX_MakeModel = 60;
	const int MIN_MakeModel = 2;

	class Vehicle : public ReadWritable {
	private:
		char licensePlate[MAX_LicensePlate + 1];
		char* makeAndModel;
		int parkingSpotNumber;
	protected:
		void setEmpty();
		bool isEmpty() const;
		const char* getLicensePlate() const;
		const char* getMakeModel() const;
		bool setMakeModel(const char*);
	public:
		Vehicle();
		Vehicle(const char*, const char*);
		int getParkingSpot() const;
		bool setParkingSpot(int);
		bool operator==(const char*) const;
		bool operator==(const Vehicle&) const;
		std::istream& read(std::istream& = std::cin);
		std::ostream& write(std::ostream& = std:: cout) const;
		~Vehicle();
	};
}
#endif