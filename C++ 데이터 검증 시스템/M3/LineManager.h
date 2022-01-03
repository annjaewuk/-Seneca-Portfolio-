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

#ifndef LINEMANAGER_H
#define LINEMANAGER_H
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include "Workstation.h"
#include "CustomerOrder.h"

class LineManager {
	std::vector<Workstation*> AssemblyLine{};
	std::deque<CustomerOrder> ToBeFilled{};
	std::deque<CustomerOrder> Completed{};
	unsigned int m_cntCustomerOrder{ 0 };
	static size_t cnt;
	std::vector<Workstation*> m_Station{};
public:
	LineManager(const std::string& file, std::vector<Workstation*>& stations, std::vector<CustomerOrder>& orders);
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations();
	void displayStationsSorted() const;

};

#endif