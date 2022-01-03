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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	MenuItem::MenuItem() {
		m_item = nullptr;
	}

	MenuItem::MenuItem(const char* item) : m_item(nullptr) {

		if (item != nullptr) {

			m_item = new char[strlen(item) + 1];
			strcpy(m_item, item);

		}

		else {
			m_item = nullptr;
		}
	}

	MenuItem::~MenuItem() {

		delete[] m_item;
		m_item = nullptr;

	}

	void MenuItem::display() const {
		if (m_item != nullptr)
			cout << m_item << endl;
	}

	void Menu::indent() const {

		cout.width(m_indentation * 4);

	}

	void Menu::clear() {

		for (int i = 0; i < m_count; ++i) {
			delete m_items[i];
			m_items[i] = nullptr;
		}
		delete[] m_title;
		m_title = nullptr;
		m_indentation = 0;
		m_count = 0;

	}

	Menu::Menu(const char* title, int indentation) {

		if (title != nullptr) {

			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);

			*m_items = nullptr;

			m_indentation = indentation;
			m_count = 0;

		}
		else {
			m_title = nullptr;
			m_indentation = 0;
			m_count = 0;
		}
	}

	Menu::Menu(const Menu& menu) {

		m_indentation = menu.m_indentation;
		m_count = menu.m_count;

		if (menu.m_title != nullptr) {

			m_title = new char[strlen(menu.m_title) + 1];
			strcpy(m_title, menu.m_title);

			for (int i = 0; i < menu.m_count; i++) {

				if (menu.m_items[i] != nullptr) {
					m_items[i] = new MenuItem(menu.m_items[i]->m_item);

				}
				else {
					m_items[i] = nullptr;
				}

			}
		}
		else {
			m_title = nullptr;
		}
	}

	Menu& Menu::operator=(const char* title) {

		if (m_title != nullptr) {

			delete[] m_title;
			m_title = nullptr;

			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);

		}
		else {
			clear();
		}
		return *this;
	}

	Menu& Menu::operator=(const Menu& menu) {

		if (this != &menu) {

			clear();

			m_indentation = menu.m_indentation;
			m_count = menu.m_count;

			if (menu.m_title != nullptr) {

				m_title = new char[strlen(menu.m_title) + 1];
				strcpy(m_title, menu.m_title);

				for (int i = 0; i < menu.m_count; i++) {
					m_items[i] = new MenuItem(menu.m_items[i]->m_item);
				}

			}
			else {

				clear();

			}
		}

		return *this;
	}

	Menu::~Menu() {

		clear();

	}

	void Menu::add(const char* item) {

		if (item != nullptr) {

			m_items[m_count] = new MenuItem(item);
			m_count++;

		}
		else {
			clear();
		}

	}

	Menu& Menu::operator<<(const char* item) {
		add(item);
		return *this;
	}

	void Menu::display() const {

		if (isEmpty()) {
			cout << "Invalid Menu!" << endl;
		}

		else {

			indent();
			cout << "";
			cout << m_title << endl;

			if (m_items[0] == nullptr) {
				cout << "No Items to display!" << endl;
			}

			else {

				for (int i = 0; i < m_count; i++) {
					indent();
					cout << "";
					cout << i + 1 << "- ";
					m_items[i]->display();
				}

				indent();
				cout << "";
				cout << "> ";
			}
		}
	}

	Menu::operator int() const {
		return run();
	}

	Menu::operator bool() const {
		return !isEmpty();
	}

	bool Menu::isEmpty() const {
		return (m_title == nullptr);
	}

	int Menu::run() const {
		int selection = 0;
		display();
		if (!isEmpty() && m_count > 0)
			Utils::read(selection, 1, m_count, "Invalid selection, try again: ");
		return selection;
	}


}