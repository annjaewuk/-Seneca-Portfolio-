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

#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>
#include <string>

class Utilities {
	size_t m_widthField = 1;
	static char m_delimiter;
public:
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
};

#endif