/*I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NCC
// Date:           October 28, 2020
//==============================================
// Workshop :	   5
// Part     :      2
//==============================================

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>

namespace sdds {

	class Book {

		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year = 0;
		double m_price = 0;
		std::string m_desc;

		void trim(std::string& src) const;

	public:

		Book() {};
		Book(const std::string&);

		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();

		friend std::ostream& operator<<(std::ostream&, const Book&);

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_desc);
		}
	};

}
#endif