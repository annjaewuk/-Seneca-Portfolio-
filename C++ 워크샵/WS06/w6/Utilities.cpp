
#include <sstream>
#include <string>
#include "Utilities.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in) {

		std::string line;
		char type = '\0';
		char deli = '\0';

		std::getline(in, line);
		std::stringstream ss(line);
		ss >> type >> deli;

		if (ss) {

			switch (type) {

			case 'c':
			case 'C':

				return new Car(ss);
				break;

			case 'r':
			case 'R':

				return new Racecar(ss);
				break;

			default:

				throw type;
				break;
			}
		}
		return nullptr;
	}
}