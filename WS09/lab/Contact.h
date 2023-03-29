// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Mar 29 2023
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include "Person.h"
namespace sdds
{
class Contact: public Person {
private:
    char* m_address = nullptr;
    char* m_city = nullptr;
    char m_province[3]{};
    char m_postalCode[7]{};
public:
    Contact();
    Contact(const Contact& copyFrom);
    Contact& operator=(const Contact& RightOperand);
    virtual ~Contact();
    std::istream& read(std::istream& istr);
    std::ostream& write(std::ostream& ostr)const;
    operator bool()const;
    void operator~();
    
};
}
#endif
