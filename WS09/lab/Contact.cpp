// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Mar 29 2023
#include <iostream>
#include "Person.h"
#include "Contact.h"
#include "Tools.h"
namespace sdds
{
Contact::Contact() {}

Contact::Contact(const Contact &copyFrom) : Person(copyFrom) {
    operator=(copyFrom);
}

Contact& Contact::operator=(const Contact& RightOperand) {
    if(this != &RightOperand)
    {
        Person::operator=(RightOperand);
        delAlloCopy(m_address, RightOperand.m_address);
        delAlloCopy(m_city, RightOperand.m_city);
        strCpy(m_province, RightOperand.m_province);
        strCpy(m_postalCode, RightOperand.m_postalCode);
    }
    return *this;
}

Contact::~Contact() {
    ~*this;
}

std::istream& Contact::read(std::istream& istr) {
    ~*this;
    Person::read(istr);
    m_address = dynRead(istr, ',');
    m_city = dynRead(istr, ',');
    istr.getline(m_province, 3,  ',');
    istr.getline(m_postalCode, 7,  '\n');
    if(istr.fail()) ~*this;
    return istr;
}

std::ostream& Contact::write(std::ostream& ostr) const {
    
    if(*this) {
        Person::write(ostr);
        ostr << std::endl;
        ostr << m_address << std::endl << m_city << " " << m_province << std::endl;
        for(int i = 0; i < strLen(m_postalCode); i++)
        {
            if(i == 3)
            {
                ostr << " ";
            }
            ostr << m_postalCode[i];
        }
        ostr << std::endl;
    }
    return ostr;
}

Contact::operator bool() const {
    return Person::operator bool() && m_address[0] && m_city[0] && m_province[0] && m_postalCode[0];
}

void Contact::operator~() {
    Person::operator~();
    delete[] m_address;
    delete[] m_city;
    m_address = m_city = nullptr;
    m_province[0] = m_postalCode[0] = '\0';
}

}

