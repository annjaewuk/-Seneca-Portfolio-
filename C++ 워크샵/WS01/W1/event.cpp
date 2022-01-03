/*I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NCC
// Date:           September 27, 2020
//==============================================
// Workshop :	   1
// Part     :      1
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iomanip>
#include <cstring>

using namespace std;
unsigned int g_sysClock = 0;
namespace sdds {

	Event::Event() {

		desc = nullptr;
		time = 0;

	}

	Event::Event(const Event& characters) {

		if (characters.desc != nullptr) {

			desc = new char[strlen(characters.desc) + 1];
			strcpy(desc, characters.desc);
			time = characters.time;

		}
		else {

			desc = nullptr;
			time = 0;

		}
	}

	Event::~Event() {

		delete[] desc;
		desc = nullptr;

	}


	void Event::display() {

		static int counter = 0;

		cout << setfill(' ') << setw(3) << ++counter << ". ";
		//if (desc[0] == '\0') {
		if (!desc) {

			cout << "[ No Event ]" << endl;

		}
		else {

			cout << setfill('0')
				<< setw(2) << time / 3600 << ":"
				<< setw(2) << (time % 3600) / 60 << ":"
				<< setw(2) << time % 60 << " -> " << desc << endl;

		}

	}

	void Event::setDescription(const char* characters) {

		delete[] desc;
		desc = nullptr;

		if (!characters || !*characters) {

			*this = Event();

		}
		else {

			desc = new char[strlen(characters) + 1];
			strcpy(desc, characters);
			time = g_sysClock;

		}
	}

	Event& Event::operator=(const Event& characters) {

		if (this != &characters) {

			if (characters.desc != nullptr) {

				desc = new char[strlen(characters.desc) + 1];
				strcpy(desc, characters.desc);
				time = characters.time;

			}
			else {

				desc = nullptr;
				time = 0;

			}

		}
		return *this;
	}

}