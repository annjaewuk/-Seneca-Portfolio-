
#include <iomanip>
#include <fstream>
#include "SpellChecker.h"
using namespace std;

namespace sdds {

	SpellChecker::SpellChecker(const char* filename) {

		ifstream file(filename);

		if (!file) {
			throw "Bad file name!";
		}

		for (size_t i = 0; i < MAX; i++) {
			file >> m_badWords[i];
			file >> m_goodWords[i];
		}
	}

	void SpellChecker::operator()(std::string& text) const {

		for (size_t i = 0; i < MAX; i++) {

			while (text.find(m_badWords[i]) != string::npos) {
				text = text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
			}
		}
	}

}