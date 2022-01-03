/*I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NAA
// Date:           July 11, 2020
//==============================================
// Milestone :	   1
//==============================================
#ifndef _SDDS_MENU_H_
#define _SDDS_MENU_H_
#include <iostream>

namespace sdds {

	const int MAX_NO_OF_ITEMS = 10;

	class Menu;
	class MenuItem {

	private:
		char* m_item;
		MenuItem();
		MenuItem(const char* item);
		void display() const;
		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;
		~MenuItem();
		friend class Menu;

	};

	class Menu {

	private:

		char* m_title;
		MenuItem* m_items[MAX_NO_OF_ITEMS];
		int m_indentation;
		int m_count;
		void clear();
		void indent() const;

	public:

		Menu(const char* title, int indentation = 0);
		Menu(const Menu& menu);
		Menu& operator=(const Menu&);
		Menu& operator=(const char* title);
		~Menu();
		void add(const char* item);
		Menu& operator<<(const char* item);
		void display() const;
		operator int() const;
		operator bool() const;
		bool isEmpty() const;
		int run() const;
	};

}

#endif