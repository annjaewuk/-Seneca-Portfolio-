/*
Name:			Luis Jaime Hernandez
E-mail :		ljaime-hernandez@myseneca.ca
Student ID :	137797197
Date :			October 4, 2020
Class :			OOP345NEE
Assignment :	w2

I have done all the coding by myself and only copied that my professor provided to complete my workshops and assignments.
*/

#include <iomanip>
#include "TimedEvents.h"

namespace sdds
{

	void TimedEvents::startClock()
	{
		start = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		end = std::chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* str)
	{
		auto ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		if (num_rec < MAX_RECORDS)
		{
			this->events[num_rec].ev_name = str;
			this->events[num_rec].ev_unit = "nanoseconds";
			this->events[num_rec].dur = ms;
			num_rec++;
		}
	}

	std::ostream& operator<<(std::ostream& out, const TimedEvents& events)
	{
		out << "--------------------------\n";
		out << "Execution Times:\n";
		out << "--------------------------\n";

		for (int i = 0; i < events.num_rec; i++)

			out << std::setw(20) << std::left
			<< events.events[i].ev_name << ' ' << std::setw(12) << std::right
			<< events.events[i].dur.count() << ' '
			<< events.events[i].ev_unit << '\n';
		out << "--------------------------\n";
		return out;
	}
}