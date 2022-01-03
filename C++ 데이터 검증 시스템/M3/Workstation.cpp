/*I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NCC
// Date:           November 28, 2020
//==============================================
// Milestone :	   3
//==============================================

#include <iomanip>
#include <sstream>
#include "Utilities.h"
#include "Workstation.h"
using namespace std;


void Workstation::runProcess(ostream& os) {
	if (!m_orders.empty()) {
		m_orders.front().fillItem(*this, os);
	}
}

bool Workstation::moveOrder() {
	bool flag = false;
	if (m_orders.empty()) {
		return flag;
	}

	flag = m_orders.front().isItemFilled(getItemName()) && m_pNextStation;
	if (flag) {
		*m_pNextStation += move(m_orders.front());
		m_orders.pop_front();
	}

	return flag;
}

void Workstation::setNextStation(Station& station) {
	m_pNextStation = static_cast<Workstation*>(&station);
}

const Workstation* Workstation::getNextStation() const {
	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order) {
	bool flag = false;
	if (m_orders.empty()) {
		return flag;
	}
	flag = m_orders.front().isOrderFilled();
	if (flag) {
		order = move(m_orders.front());
		m_orders.pop_front();
	}
	return flag;
}

void Workstation::display(ostream& os) {
	if (!m_pNextStation)
		os << (*this).getItemName() << " --> END OF LINE" << endl;
	else
		os << (*this).getItemName() << " --> " << m_pNextStation->getItemName() << endl;

}

Workstation& Workstation::operator+=(CustomerOrder&& order) {
	m_orders.push_back(move(order));
	return *this;
}