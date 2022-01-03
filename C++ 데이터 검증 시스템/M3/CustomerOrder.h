/*I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NCC
// Date:           November 21, 2020
//==============================================
// Milestone :	   2
//==============================================

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
#include <iostream>
#include <string>
#include "Station.h"

struct Item  {

	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};

};

class CustomerOrder {

	std::string m_name{ "" };
	std::string m_product{ "" };
	unsigned int m_cntItem{ 0 };
	Item** m_lstItem{ nullptr };
	static size_t m_widthField;

public:

	CustomerOrder() {};
	CustomerOrder(std::string&);
	CustomerOrder(CustomerOrder&);
	CustomerOrder& operator=(CustomerOrder&) = delete;
	CustomerOrder(CustomerOrder&& order) noexcept;
	CustomerOrder& operator=(CustomerOrder&& order) noexcept;
	~CustomerOrder();

	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;

};

#endif
