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

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>

using namespace std;
namespace sdds {

	class Movie {

		string m_title;
		size_t m_year;
		string m_desc;

		void trim(string&) const;

	public:

		Movie();
		Movie(const string& strMovie);
		~Movie() {

		};

		const string& title() const {
			return m_title;
		}

		template <typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(m_desc);
		}

		friend ostream& operator<<(ostream&, const Movie&);

	};
}

#endif
