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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Vehicle.h"
#include "Utils.h"
using namespace std;
namespace sdds {

	Vehicle::Vehicle() : ReadWritable(), m_licensePlate{}, m_makeModel(nullptr), m_parkingSpot(0) {
		setEmpty();
	}

	Vehicle::Vehicle(const char* licensePlate, const char* makeModel) : ReadWritable(), m_licensePlate{}, m_makeModel(nullptr), m_parkingSpot(0) {

		if (licensePlate != nullptr && *licensePlate != '\0' && strlen(licensePlate) <= 8 && makeModel != nullptr && strlen(makeModel) >= 2) {
			m_parkingSpot = 0;
			strcpy(m_licensePlate, licensePlate);
			setMakeModel(makeModel);
			Utils::toUpper(m_makeModel);
		}
		else
			setEmpty();
	}

	Vehicle::~Vehicle() {
		delete[] m_makeModel;
	}

	bool Vehicle::isEmpty() const {
		return m_makeModel == nullptr;
	}

	void Vehicle::setEmpty() {
		delete[] m_makeModel;
		m_makeModel = nullptr;
		m_licensePlate[0] = 0;
		m_parkingSpot = -1;
	}
	int Vehicle::getParkingSpot() const {
		return m_parkingSpot;
	}
	void Vehicle::setParkingSpot(int value) {
		if (value < 0) {
			setEmpty();
		}
		else m_parkingSpot = value;
	}
	const char* Vehicle::getLicensePlate() const {
		return m_licensePlate;
	}
	const char* Vehicle::getMakeModel() const {
		return m_makeModel;
	}
	void Vehicle::setMakeModel(const char* value) {
		if (value != nullptr && value[0] != '\0') {
			delete[] m_makeModel;
			m_makeModel = new char[strlen(value) + 1];
			strcpy(m_makeModel, value);
		}
		else
			setEmpty();
	}
	bool Vehicle::operator==(const char* licensePlate) const {

		if (*licensePlate != '\0' && licensePlate != nullptr) {

			int length = strlen(licensePlate);

			for (int i = 0; i < length; i++) {
				if (toupper(m_licensePlate[i]) != toupper(licensePlate[i])) {
					return false;
				}
			}
		}
		return true;
	}
	bool Vehicle::operator==(const Vehicle& V) const {
		return operator==(V.m_licensePlate);
	}
	istream& Vehicle::read(istream& in) {

		int i = 0;
		in.clear();

		if (isCsv()) {

			in >> m_parkingSpot;
			in.ignore();
			in.getline(m_licensePlate, 9, ',');

			int plateLen1 = strlen(m_licensePlate);

			for (int i = 0; i < plateLen1; i++) {
				m_licensePlate[i] = toupper(m_licensePlate[i]);
			}

			char temp[61] = { '\0' };
			in.getline(temp, 61, ',');
			setMakeModel(temp);

		}

		else {
			cout << "Enter Licence Plate Number: ";
			int invalid;
			do {

				invalid = 0;
				in.getline(m_licensePlate, 10);

				if (strlen(m_licensePlate) > 8 || strlen(m_licensePlate) == 0 || isspace(m_licensePlate[0])) {
					invalid = 1;
					cout << "Invalid Licence Plate, try again: ";
				}

			} while (invalid);

			while (m_licensePlate[i]) {
				m_licensePlate[i] = toupper(m_licensePlate[i]);
				i++;
			}

			cout << "Enter Make and Model: ";
			char temp[61] = { '\0' };

			do {

				invalid = 0;
				in.getline(temp, 61);

				if (strlen(temp) < 2 || strlen(temp) > 60) {
					invalid = 1;
					cout << "Invalid Make and model, try again: ";
				}

			} while (invalid);

			setMakeModel(temp);
			in.clear();
			m_parkingSpot = 0;
		}

		if (in.fail()) {
			in.clear();
			setEmpty();
		}

		return in;
	}

	ostream& Vehicle::write(ostream& out) const {

		if (isEmpty()) {
			out << "Invalid Vehicle Object" << endl;
		}

		else {

			if (isCsv()) {
				out << m_parkingSpot << "," << m_licensePlate << "," << m_makeModel << ",";
			}
			else {
				out << "Parking Spot Number: ";
				if (m_parkingSpot > 0) {
					out << m_parkingSpot << endl;
				}
				else {
					out << "N/A" << endl;
				}
				out << "Licence Plate: " << m_licensePlate << endl;
				out << "Make and Model: " << m_makeModel << endl;
			}
		}
		return out;
	}
}