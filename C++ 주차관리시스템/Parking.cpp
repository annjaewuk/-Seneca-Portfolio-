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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Parking.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Utils.h"

using namespace std;
namespace sdds {

	Parking::Parking(const char* datafile, int noOfSpots) :
		m_datafile(nullptr),
		m_parkingMenu("Parking Menu, select an action:"),
		m_vehicleMenu("Select type of the vehicle:", 1) {

		if (datafile != nullptr && *datafile != '\0' && noOfSpots >= 10 && noOfSpots <= MAX_PARKING_SPOT) {

			m_datafile = new char[strlen(datafile) + 1];
			strcpy(m_datafile, datafile);
			m_noOfSpots = noOfSpots;
			m_noOfParked = 0;

			for (int i = 0; i < MAX_PARKING_SPOT; i++) {
				m_parkingSpots[i] = nullptr;
			}


			if (load()) {

				m_parkingMenu.add("Park Vehicle");
				m_parkingMenu.add("Return Vehicle");
				m_parkingMenu.add("List Parked Vehicles");
				m_parkingMenu.add("Close Parking (End of day)");
				m_parkingMenu.add("Exit Program");

				m_vehicleMenu.add("Car");
				m_vehicleMenu.add("Motorcycle");
				m_vehicleMenu.add("Cancel");
			}
			else {
				m_parkingMenu = nullptr;
				m_vehicleMenu = nullptr;
			}
		}
		else {
			cout << "Error in data file" << endl;
			m_datafile = nullptr;
			m_parkingMenu = nullptr;
			m_vehicleMenu = nullptr;
			m_noOfSpots = 0;
			m_noOfParked = 0;
			for (int i = 0; i < MAX_PARKING_SPOT; i++) {
				m_parkingSpots[i] = nullptr;
			}
		}
	}

	void Parking::parkVehicle() {

		Vehicle* vehicle = nullptr;
		bool check = true;

		if (m_noOfSpots == m_noOfParked) 
			cout << "Parking is full" << endl;
		else {

			int selection = m_vehicleMenu.run();
			switch (selection) {
			case 1:
				vehicle = new Car();
				vehicle->setCsv(false);
				vehicle->read();

				for (int i = 0; i < m_noOfSpots; i++) {
					if (check) {
						if (m_parkingSpots[i] == nullptr) {
							m_parkingSpots[i] = vehicle;
							vehicle->setParkingSpot(i + 1);
							m_noOfParked++;
							cout << "\n";
							cout << "Parking Ticket" << endl;
							cout << *vehicle << endl;
							check = false;
						}
					}
				}
				break;
			case 2:
				vehicle = new Motorcycle();
				vehicle->setCsv(false);
				vehicle->read();

				for (int i = 0; i < m_noOfSpots; i++) {
					if (check) {
						if (m_parkingSpots[i] == nullptr) {
							m_parkingSpots[i] = vehicle;
							vehicle->setParkingSpot(i + 1);
							m_noOfParked++;
							cout << "\n";
							cout << "Parking Ticket" << endl;
							cout << *vehicle << endl;
							check = false;
						}
					}
				}
				break;
			case 3:
				cout << "Parking cancelled" << endl;
				break;
			}
		}

	}

	void Parking::returnVehicle() {

		char licensePlate[9];
		bool check = false;

		cout << "Return Vehicle" << endl;
		cout << "Enter Licence Plate Number: ";
		
		do {
			cin.getline(licensePlate, 9);
			if (strlen(licensePlate) < 2 && strlen(licensePlate) > 8) {
				cout << "Invalid Licence Plate, try again: ";
			}
			else check = true;

		} while (!(check));

		for (int i = 0; i < m_noOfSpots; i++) {
			if (m_parkingSpots[i] != nullptr && *m_parkingSpots[i] == licensePlate) {

				m_parkingSpots[i]->setCsv(false);
				cout << "\n";
				cout << "Returning: " << endl;
				cout << *m_parkingSpots[i] << endl;
				m_noOfParked--;
				delete m_parkingSpots[i];
				m_parkingSpots[i] = nullptr;
			}

			else {
				if (i == m_noOfSpots) {
					cout << licensePlate << " Not found" << endl;
				}
			}
		}
	}


	void Parking::listParkedVehicles() {

		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < m_noOfSpots; i++) {
			if (m_parkingSpots[i] != nullptr) {
				m_parkingSpots[i]->setCsv(false);
				m_parkingSpots[i]->write();
				cout << "-------------------------------" << endl;

			}
		}
	}

	bool Parking::closeParking() {

		bool yes;

		if (m_noOfParked == 0) {
			cout << "Closing Parking" << endl;
			return true;
		}
		else {
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			yes = Utils::yes();

			if (yes) {

				cout << "Closing Parking" << endl;

				for (int i = 0; i < m_noOfSpots; i++) {
					if (m_parkingSpots[i] != nullptr) {
						cout << "\n";
						cout << "Towing request" << endl;
						cout << "*********************" << endl;
						m_parkingSpots[i]->write();
						delete m_parkingSpots[i];
						m_parkingSpots[i] = nullptr;

					}
				}
				return true;
			}
			else {
				cout << "Aborted!" << endl;
				return false;
			}

		}
	}

	bool Parking::exitParkingApp() {

		if (Utils::confirmed("terminate the program")) {

			cout << "Exiting program!" << endl;
			return true;

		}
		else
			return false;
	}

	void Parking::parkingStatus() const {

			cout << "****** Seneca Valet Parking ******" << endl;
			cout << "*****  Available spots: ";
			cout.setf(ios::left);
			cout.width(4);
			cout << m_noOfSpots - m_noOfParked;
			cout.unsetf(ios::left);
			cout << " *****" << endl;
		
	}

	Parking::~Parking() {
		save();
		setEmpty();
	}

	bool Parking::load() {

		int num = 0;
		bool goodState = true;
		Vehicle* vehicle;

		if (!isEmpty()) {

			ifstream fileIn(m_datafile);

			if (!fileIn.is_open() || isEmpty()) {
				goodState = true;
			}

			while (goodState && num < m_noOfSpots && fileIn) {

				vehicle = nullptr;
				char ch = '\0';

				fileIn >> ch;
				fileIn.ignore();

				if (ch == 'M') {
					vehicle = new Motorcycle();
				}

				else if (ch == 'C') {
					vehicle = new Car();
				}

				if (vehicle) {
					vehicle->setCsv(true);
					fileIn >> *vehicle;

					if (fileIn) {
						m_parkingSpots[vehicle->getParkingSpot() - 1] = vehicle;
						m_noOfParked++;
					}
					else {
						delete vehicle;
						vehicle = nullptr;
						goodState = false;
					}
				}
				num++;
			}
		}
		return goodState;
	}

	void Parking::save() {

		ofstream fileOut(m_datafile);

		if (!isEmpty() && fileOut.is_open()) {

			for (int i = 0; i < m_noOfSpots; i++) {

				if (m_parkingSpots[i] != nullptr) {

					m_parkingSpots[i]->setCsv(true);
					m_parkingSpots[i]->write(fileOut);

				}
			}	
		}
	}

	bool Parking::isEmpty() const {
		return m_datafile == nullptr;
	}

	void Parking::setEmpty() {
		delete[] m_datafile;
		m_datafile = nullptr;
	}

	int Parking::run() {
		bool done = false;
		int selection = 0;
		while (!isEmpty() && !done) {

			parkingStatus();
			selection = m_parkingMenu.run();
			switch (selection) {
			case 1:parkVehicle();
				break;

			case 2: returnVehicle();
				break;

			case 3: listParkedVehicles();
				break;

			case 4:
				if (closeParking()) {
					done = true;
					return 0;
				}
				else {
					break;
				}

			case 5:
				if (exitParkingApp()) {
					done = true;
				}
				else {
					break;
				}
			}
		}
		return 0;
	}

}