
#include "Utilities.h"
using namespace std;

char Utilities::m_delimiter;

void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

string Utilities::extractToken(const string& str, size_t& next_pos, bool& more) {
	string token;
	if (str.length() >= next_pos) {
		more = true;
		size_t pos = str.find_first_of(m_delimiter, next_pos);
		if (pos != string::npos) {
			token = str.substr(next_pos, pos - next_pos);
			next_pos = pos + 1;
		}
		else {
			token = str.substr(next_pos);
			next_pos = str.length() + 1;
		}
		if (token.empty() && next_pos != str.length() + 1) {
			more = false;
			throw "Error: There are two delimiters with no token between them.";
		}
		if (m_widthField < token.length()) {
			m_widthField = token.length();
		}
		more = str.length() >= next_pos;
	}
	return token;
}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}