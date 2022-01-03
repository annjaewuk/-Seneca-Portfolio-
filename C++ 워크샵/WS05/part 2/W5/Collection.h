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

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>

using namespace std;
namespace sdds {

	template<typename T>
	class Collection {

		string m_name = "";
		T* m_items = nullptr;
		size_t m_size = 0;

		void (*addItem)(const Collection<T>&, const T&) = nullptr;

	public:

		Collection(string name) {
			m_name = name;
		}

		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;

		~Collection() {
			delete[] m_items;
		}

		const string& name() const {
			return m_name;
		}

		size_t size() const {
			return m_size;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			addItem = observer;
		}

		Collection<T>& operator+=(const T& item) {

			for (size_t i = 0; i < m_size; i++) {

				if (m_items[i].title() == item.title()) {
					return *this;
				}
			}

			T* temp = new T[m_size + 1];
			for (size_t i = 0; i < m_size; i++) {
				temp[i] = m_items[i];
			}

			temp[m_size] = item;
			delete[] m_items;
			m_items = temp;
			++m_size;

			if (addItem != nullptr) {
				addItem(*this, m_items[m_size - 1]);
			}
			return *this;
		}

		T& operator[](size_t idx) const {

			if (idx >= m_size) {

				string msg = "";
				msg = "Bad index [" + to_string(idx) + "]. Collection has [" + to_string(m_size) + "] items.";
				throw out_of_range(msg);

			}
			return m_items[idx];
		}

		T* operator[](string title) const {

			for (size_t i = 0; i < m_size; i++) {

				if (m_items[i].title() == title) {
					return &(m_items[i]);
				}
			}
			return nullptr;
		}
	};

	template<typename T>
	ostream& operator<<(ostream& os, const Collection<T>& collection) {

		for (size_t i = 0; i < collection.size(); i++) {
			os << collection[i];
		}

		return os;
	}
}
#endif