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
#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__
#include <iostream>	
#include "ReadWritable.h"
using namespace std;
namespace sdds {

	class Vehicle : public ReadWritable {

	private:
		char  m_licensePlate[9];
		char* m_makeModel;
		int   m_parkingSpot;

	public:

		Vehicle();
		Vehicle(const char* licensePlate, const char* makeModel);
		Vehicle(const Vehicle&) = delete;
		void operator=(const Vehicle&) = delete;
		virtual ~Vehicle();

		void		setEmpty();
		bool		isEmpty() const;
		const char* getLicensePlate() const;
		const char* getMakeModel() const;
		void		setMakeModel(const char* value);
		int			getParkingSpot() const;
		void		setParkingSpot(int value);

		bool operator==(const char* licensePlate) const;
		bool operator==(const Vehicle& v) const;

		istream& read(istream& in = cin);
		ostream& write(ostream& out = cout) const;
	};
}
#endif