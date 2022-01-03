#include <iomanip>	
#include "TimedEvents.h"

using namespace std;
namespace sdds {

	void TimedEvents::startClock() {

		Start_time = chrono::steady_clock::now();

	}

	void TimedEvents::stopClock() {

		End_time = chrono::steady_clock::now();

	}

	void TimedEvents::recordEvent(const char* Event_name) {

		auto ms = chrono::duration_cast<chrono::nanoseconds>(End_time - Start_time);

		if (Stored_records < MAX_RECORDS) {

			this->events[Stored_records].Event_name = Event_name;
			this->events[Stored_records].unit_time = "nanoseconds";
			this->events[Stored_records].duration_time = ms;
			Stored_records++;

		}
	}

		ostream& operator<<(ostream& out, const TimedEvents& events) {

			out << "--------------------------" << endl;
			out << "Execution Times:" << endl;
			out << "--------------------------" << endl;

			for (int i = 0; i < events.Stored_records; i++) {
				out << setw(20) << left << events.events[i].Event_name 
					<< ' ' << setw(12) << right
					<< events.events[i].duration_time.count() << ' '
					<< events.events[i].unit_time << endl;
			}

			out << "--------------------------" << endl;

			return out;
		}

	}
