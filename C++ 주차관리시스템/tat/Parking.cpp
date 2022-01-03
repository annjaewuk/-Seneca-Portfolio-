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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "Parking.h"

using namespace std;

namespace sdds {
	Parking::Parking() {
		fileName = nullptr;
		parkingMenu = nullptr;
		vehicleSelection = nullptr;
		numOfSpots = 0;
		numOfParkedVehicle = 0;

		for (int i = 0; i < MAX_NUM_OF_PARK_SPOTS; i++) {
			parkingSpots[i] = nullptr;
		}
	}

	Parking::Parking(const char* d_file, int n_of_spots) {
		if (d_file != nullptr && d_file[0] != '\0' && n_of_spots >= 10 && n_of_spots <= MAX_NUM_OF_PARK_SPOTS) {
			fileName = new char[strlen(d_file) + 1];
			strcpy(fileName, d_file);
			numOfSpots = n_of_spots;
			numOfParkedVehicle = 0;

			for (int i = 0; i < MAX_NUM_OF_PARK_SPOTS; i++) {
				parkingSpots[i] = nullptr;
			}

			bool valid = loadData();
			if (valid) {
				parkingMenu = new Menu("Parking Menu, select an action:");
				parkingMenu->add("Park Vehicle");
				parkingMenu->add("Return Vehicle");
				parkingMenu->add("List Parked Vehicles");
				parkingMenu->add("Close Parking (End of day)");
				parkingMenu->add("Exit Program");
				vehicleSelection = new Menu("Select type of the vehicle:", 1);
				vehicleSelection->add("Car");
				vehicleSelection->add("Motorcycle");
				vehicleSelection->add("Cancel");
			}
			else {
				parkingMenu = nullptr;
				vehicleSelection = nullptr;
			}
		}
		else{
			cout << "Error in data file" << endl;
			fileName = nullptr;
			parkingMenu = nullptr;
			vehicleSelection = nullptr;
			numOfSpots = 0;
			numOfParkedVehicle = 0;
			for (int i = 0; i < MAX_NUM_OF_PARK_SPOTS; i++) {
				parkingSpots[i] = nullptr;
			}
		}

	}

	bool Parking::isEmpty() {
		bool valid = false;

		if (fileName == nullptr && parkingMenu == nullptr && vehicleSelection == nullptr) {
			valid = true;
		}
		return valid;
	}

	void Parking::parkingStatus() {
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout.setf(ios::left);
		cout.width(4);
		cout << numOfSpots - numOfParkedVehicle;
		cout.unsetf(ios::left);
		cout << " *****" << endl;
	}

	void Parking::parkVehicle() {
		bool valid = true;
		Vehicle* vehic = nullptr;
		if ((numOfSpots != numOfParkedVehicle)) {
			int option = vehicleSelection->run();
			switch (option) {
			case 1:
				vehic = new Car();
				vehic->setCsv(false);
				vehic->read();

				for (int i = 0; i < numOfSpots; i++) {
					if (valid) {
						if (parkingSpots[i] == nullptr) {
							parkingSpots[i] = vehic;
							vehic->setParkingSpot(i + 1);
							numOfParkedVehicle++;
							cout << "\n";
							cout << "Parking Ticket" << endl;
							cout << *vehic << endl;
							valid = false;
						}
					}
				}
				break;
			case 2:
				vehic = new Motorcycle();
				vehic->setCsv(false);
				vehic->read();
				for (int i = 0; i < numOfSpots; i++) {
					if (valid) {
						if (parkingSpots[i] == nullptr) {
							parkingSpots[i] = vehic;
							vehic->setParkingSpot(i + 1);
							numOfParkedVehicle++;
							cout << "\n";
							cout << "Parking Ticket" << endl;
							cout << *vehic << endl;
							valid = false;
						}
					}
				}
				break;
			case 3:
				cout << "Parking cancelled" << endl;
				break;
			}
		}
		else {
			cout << "Parking is full" << endl;
		}
	}

	void Parking::returnVehicle() {
		char tempLP[MAX_LicensePlate + 1];

		cout << "Return Vehicle" << endl;
		cout << "Enter Licence Plate Number: ";
		do {
			cin.getline(tempLP, MAX_LicensePlate + 1);
			if (strlen(tempLP) < MIN_LicensePlate && strlen(tempLP) > MAX_LicensePlate) {
				cout << "Invalid Licence Plate, try again: ";
			}
		} while (strlen(tempLP) < MIN_LicensePlate && strlen(tempLP) > MAX_LicensePlate);

		for (int i = 0; i < numOfSpots; i++) {
			if (parkingSpots[i] != nullptr && *parkingSpots[i] == tempLP) {
				parkingSpots[i]->setCsv(false);
				cout << "\n";
				cout << "Returning: " << endl;
				cout << *parkingSpots[i] << endl;
				numOfParkedVehicle--;
				delete parkingSpots[i];
				parkingSpots[i] = nullptr;
			}
			else {
				if (i == numOfSpots) {
					cout << tempLP << " Not found" << endl;
				}
			}
		}
	}

	void Parking::listParkedVehicle() {
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < numOfSpots; i++) {
			if (parkingSpots[i] != nullptr) {
				parkingSpots[i]->setCsv(false);
				parkingSpots[i]->write();
				cout << "-------------------------------" << endl;
			}
		}
	}

	bool Parking::closeParking() {
		bool option_valid, input_valid;
		char option, input;
		if (numOfParkedVehicle == 0) {
			cout << "Closing Parking" << endl;
			return true;
		}
		else {
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			do {
				option = cin.get();
				input = cin.get();
				cin.clear();

				option_valid = (option == 'Y') || (option == 'y') || (option == 'N') || (option == 'n');
				input_valid = (input == '\n');

				if (!(option_valid && input_valid)) {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					cin.ignore(2000, '\n');
				}
			} while (!(option_valid && input_valid));

			if (option == 'N' || option == 'n') {
				cout << "Aborted!" << endl;
				return false;
			}
			else {
				cout << "Closing Parking" << endl;
				for (int i = 0; i < numOfSpots; i++) {
					if (parkingSpots[i] != nullptr) {
						cout << "\n";
						cout << "Towing request" << endl;
						cout << "*********************" << endl;
						parkingSpots[i]->write();
						delete parkingSpots[i];
						parkingSpots[i] = nullptr;
					}
				}
				return true;
			}
		}
	}

	bool Parking::exitParking() const {
		bool valid = true;
		bool option_valid, input_valid;
		char option, input;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		do {
			option = cin.get();
			input = cin.get();
			cin.clear();

			option_valid = (option == 'Y') || (option == 'y') || (option == 'N') || (option == 'n');
			input_valid = (input == '\n');

			if (!(option_valid && input_valid)) {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin.ignore(500, '\n');
			}
		} while (!(option_valid && input_valid));

		if (option == 'Y' || option == 'y') {
			cout << "Exiting program!" << endl;
		}
		else{
			valid = false;
		}
		return valid;
	}

	bool Parking::loadData() {
		bool valid = true;
		Vehicle* vehic;
		int num = 0;
		if (!isEmpty()) {
			ifstream fileIn(fileName);
			if (!fileIn.is_open() || isEmpty()) {
				valid = true;
			}
			while (valid && num < numOfSpots && fileIn) {
				vehic = nullptr;
				char cha = '\0';
				fileIn >> cha;
				fileIn.ignore();

				if (cha == 'M') {
					vehic = new Motorcycle();
				}
				else if (cha == 'C') {
					vehic = new Car();
				}
				if (vehic) {
					vehic->setCsv(true);
					fileIn >> *vehic;
					if (fileIn) {
						parkingSpots[vehic->getParkingSpot() - 1] = vehic;
						numOfParkedVehicle++;
					}
					else {
						delete vehic;
						vehic = nullptr;
						valid = false;
					}
				}
				num++;
			}
		}
		return valid;
	}

	void Parking::saveData() {
		ofstream fileOut(fileName);

		if (!isEmpty()) {
			if (fileOut.is_open()) {
				for (int i = 0; i < numOfSpots; i++) {
					if (parkingSpots[i] != nullptr) {
						parkingSpots[i]->setCsv(true);
						parkingSpots[i]->write(fileOut);
					}
				}
			}
		}
	}

	int Parking::run() {
		int option;
		int valid = 1;
		if (!isEmpty()) {
			while (valid) {
				parkingStatus();
				option = parkingMenu->run();
				switch (option) {

				case 1:
					parkVehicle();
					break;
				case 2:
					returnVehicle();
					break;
				case 3:
					listParkedVehicle();
					break;
				case 4:
					if (closeParking()) {
						return valid;
					}
					break;
				case 5:
					if (exitParking()) {
						return valid;
					}
					break;
				}
			}
		}
		return valid;
	}

	Parking::~Parking() {
		saveData();
		delete parkingMenu;
		delete vehicleSelection;
		delete[] fileName;
		fileName = nullptr;

		for (int i = 0; i < numOfSpots; i++) {
			delete parkingSpots[i];
			parkingSpots[i] = nullptr;
		}
	}
}