/*
Name:			Luis Jaime Hernandez
E-mail :		ljaime-hernandez@myseneca.ca
Student ID :	137797197
Date :			October 4, 2020
Class :			OOP345NEE
Assignment :	w2

I have done all the coding by myself and only copied that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <chrono>

namespace sdds
{
	const int MAX_RECORDS = 7;
	class TimedEvents
	{
		int num_rec{ 0 };
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;
		struct
		{
			std::string ev_name{};
			std::string ev_unit{};
			std::chrono::steady_clock::duration dur{};
		} events[MAX_RECORDS];
	public:
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		friend std::ostream& operator<<(std::ostream& out, const TimedEvents& events);
	};
}
#endif