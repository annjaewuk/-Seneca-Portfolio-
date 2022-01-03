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

#include <vector>
#include <iomanip>
#include <sstream>
#include "Utilities.h"
#include "CustomerOrder.h"
using namespace std;

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder(string& src) {
    Utilities uti;
    bool more;
    size_t next_pos = 0;
    m_name = uti.extractToken(src, next_pos, more);
    m_product = uti.extractToken(src, next_pos, more);

    vector<string> tmp;
    while (more) {
        tmp.push_back(uti.extractToken(src, next_pos, more));
    }
    m_cntItem = tmp.size();
    m_lstItem = new Item * [m_cntItem];
    for (size_t i = 0; i < m_cntItem; ++i) {
        m_lstItem[i] = new Item(tmp[i]);
    }

    if (m_widthField < uti.getFieldWidth())
        m_widthField = uti.getFieldWidth();

}

CustomerOrder::CustomerOrder(CustomerOrder& order) {
    throw "Copy operations are not allowed!";
}

CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept {
    *this = move(order);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept {
    if (this != &order) {
        if (m_lstItem) {
            for (size_t i = 0; i < m_cntItem; ++i) {
                delete m_lstItem[i];
            }
            delete[] m_lstItem;
        }

        m_name = move(order.m_name);
        m_product = move(order.m_product);
        m_cntItem = order.m_cntItem;
        m_lstItem = order.m_lstItem;
        order.m_cntItem = 0;
        order.m_lstItem = nullptr;
    }

    return *this;
}

CustomerOrder::~CustomerOrder() {
    for (size_t i = 0; i < m_cntItem; ++i) {
        delete m_lstItem[i];
    }
    delete[] m_lstItem;
}

bool CustomerOrder::isOrderFilled() const {
    bool flag = true;
    for (size_t i = 0; i < m_cntItem; i++) {
        flag = flag && m_lstItem[i]->m_isFilled;
    }
    return flag;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
    for (size_t i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled)
            return false;
    }
    return true;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
    for (size_t i = 0; i < m_cntItem; i++) {
        if (station.getItemName() == m_lstItem[i]->m_itemName && !m_lstItem[i]->m_isFilled) {
            unsigned int quantity = station.getQuantity();
            if (quantity > 1) {
                m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                m_lstItem[i]->m_isFilled = true;
                station.updateQuantity();
                os << "    Filled ";
            }
            else {
                os << "    Unable to fill ";
            }
            os << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
        }
    }
}

void CustomerOrder::display(std::ostream& os) const {
    string status;
    os << m_name << " - " << m_product << endl;
    for (size_t i = 0; i < m_cntItem; i++) {
        if ((m_lstItem[i]->m_isFilled)) {
            status = "FILLED";
        }
        else {
            status = "MISSING";
        }
        os << "[" << right << setfill('0') << setw(6) << m_lstItem[i]->m_serialNumber << "] "
            << left << setfill(' ') << setw(m_widthField) << m_lstItem[i]->m_itemName << " - " << status << endl;
    }

}