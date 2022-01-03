
#include "Utilities.h"
#include "Station.h"
using namespace std;

size_t Station::m_widthField = 0;
size_t Station::id_generator = 0;

Station::Station(const string& src) {
	Utilities uti;
	size_t next_pos = 0;
	bool more = false;
	m_id = ++Station::id_generator;
	if (src.empty()) {
		m_item = "";
		m_serialNum = 0;
		m_quantity = 0;
		m_desc = "";
	}
	else {
		m_item = uti.extractToken(src, next_pos, more);
		if (more) {
			m_serialNum = stoi(uti.extractToken(src, next_pos, more));
		}
		if (more) {
			m_quantity = stoi(uti.extractToken(src, next_pos, more));
		}
		if (m_widthField < uti.getFieldWidth()) {
			m_widthField = uti.getFieldWidth();
		}
		if (more) {
			m_desc = uti.extractToken(src, next_pos, more);
		}

	}
}

const string& Station::getItemName() const {
	return m_item;
}

unsigned int Station::getNextSerialNumber() {
	return m_serialNum++;
}

unsigned int Station::getQuantity() const {
	return m_quantity;
}

void Station::updateQuantity() {
	if (m_quantity > 0) {
		m_quantity--;
	}
	else
		throw "No quantity!";
}

void Station::display(ostream& os, bool full) const {
	os << '[' << setw(3) << setfill('0') << right << m_id
		<< "] Item: " << setw(m_widthField) << setfill(' ') << left << m_item
		<< " [" << setw(6) << setfill('0') << right << m_serialNum << "]" << setfill(' ') << left;
	if (full) {
		os << " Quantity: " << setw(m_widthField) << m_quantity
			<< " Description: " << m_desc;
	}
	os << endl;
}