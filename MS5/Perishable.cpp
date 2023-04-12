// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: April 12 2023
#include <iostream>
#include <fstream>
#include <cstring>
#include "Perishable.h"
#include "Date.h"
using namespace std;
namespace sdds
{
char Perishable::itemType() const {
    return 'P';
}

std::ostream& Perishable::write(std::ostream& ostr) const {
    Item::write(ostr);
    if(*this)
    {
        if(m_displayType == POS_LIST)
        {
            ostr << "  " << m_date << " |";
        }
        else
        {
            ostr << "Expiry date: " << m_date << endl << "=============^" << endl;
        }
    }
    return ostr;
}

std::istream& Perishable::read(std::istream& istr) {
    Item::read(istr);
    if(*this && !istr.fail())
    {
        do {
            if(istr.fail())
            {
                istr.clear();
            }
            Date date;
            date.dateOnly(true);
            cout << "Expiry date (YYYY/MM/DD)" << endl << "> ";
            istr >> date;
            if(date)
            {
                m_date = date;
            }
            else
            {
                m_error = date.error();
            }
        }while(istr.fail());
    }
    return istr;
}

std::ofstream& Perishable::save(std::ofstream& ofstr) const {
    Item::save(ofstr);
    if(*this)
    {
        ofstr << ',' << m_date;
    }
    return ofstr;
}

std::ifstream& Perishable::load(std::ifstream& ifstr) {
    Item::load(ifstr);
    if(*this && !ifstr.fail())
    {
        Date date;
        date.dateOnly(true);
        ifstr.ignore();
        ifstr >> date;
        if(date)
        {
            m_date = date;
        }
        else
        {
            m_error = date.error();
        }
    }
    return ifstr;
}
}

