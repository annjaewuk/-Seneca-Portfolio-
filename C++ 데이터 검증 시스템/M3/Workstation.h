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

#ifndef WORKSTATION_H
#define WORKSTATION_H
#include <iostream>
#include <deque>
#include <string>
#include "Station.h"
#include "CustomerOrder.h"

class Workstation :public Station {
	std::deque<CustomerOrder> m_orders{};
	Workstation* m_pNextStation{};

public:
	Workstation(std::string& src) :Station(src) {}
	Workstation(Workstation&) = delete;
	Workstation(Workstation&&) = delete;
	Workstation& operator=(Workstation&) = delete;
	Workstation& operator=(Workstation&&) = delete;

	void runProcess(std::ostream&);
	bool moveOrder();
	void setNextStation(Station& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&);
	Workstation& operator+=(CustomerOrder&& order);

};
#endif
