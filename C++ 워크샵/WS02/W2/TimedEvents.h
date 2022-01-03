/*I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NCC
// Date:           October 3, 2020
//==============================================
// Workshop :	   2
// Part     :      2
//==============================================
#ifndef _345_TIMED_H_
#define _345_TIMED_H_

#include <chrono>
#include <string>

using namespace std;
namespace sdds {

	const int MAX_RECORDS = 7;

	class TimedEvents {
		

		int Stored_records { 0 };
		chrono::steady_clock::time_point Start_time;
		chrono::steady_clock::time_point End_time;
		struct {
			string Event_name {};
			string unit_time {};
			chrono::steady_clock::duration duration_time {};
		} events[MAX_RECORDS];

	public:

		void startClock();	
		void stopClock();
		void recordEvent(const char*);
		friend ostream& operator<<(ostream& out, const TimedEvents& events);

	};

}

#endif