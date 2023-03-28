#include <iostream>
#include "Person.h"
#include "Contact.h"
#include "Tools.h"
namespace sdds
{
Contact::Contact() { 
}

Contact::Contact(const sdds::Contact &copyFrom) { 
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
    Person::read(istr);
    ~*this;
    m_address = dynRead(istr, ',');
    m_city = dynRead(istr, ',');
    istr.getline(m_province, 2, ',');
    istr.getline(m_postalCode, 6, '\n');
    if(istr.fail()) ~*this;
    return istr;
}

std::ostream& Contact::write(std::ostream& ostr) const {
    Person::write(ostr);
    if(*this) {
        ostr << std::endl;
        ostr << m_address << "," << m_city << "," << m_province << "," << m_postalCode;
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
}

}

