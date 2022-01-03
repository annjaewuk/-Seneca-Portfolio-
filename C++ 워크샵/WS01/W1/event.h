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
#include <iostream>
#ifndef _345_EVENT_H_
#define _345_EVENT_H_

extern unsigned int g_sysClock;

namespace sdds {

	class Event {

		char* desc;
		unsigned int time;

	public:

		Event();
		~Event();
		Event(const Event&);
		void display();
		void setDescription(const char* characters);
		Event& operator=(const Event& characters);

	};

}


#endif
