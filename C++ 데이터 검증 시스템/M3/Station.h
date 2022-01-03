/*I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NCC
// Date:           November 13, 2020
//==============================================
// Milestone :	   1
//==============================================

#ifndef STATION_H
#define STATION_H
#include <iostream>
#include <string>
#include <iomanip>

class Station {
	int m_id;
	std::string m_item;
	std::string m_desc;
	unsigned int m_serialNum;
	unsigned int m_quantity;
	static size_t m_widthField;
	static size_t id_generator;
public:
	Station(const std::string& src);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};
#endif