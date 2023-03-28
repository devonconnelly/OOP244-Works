#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include "Person.h"
namespace sdds
{
class Contact: public Person {
private:
    char* m_address = nullptr;
    char* m_city = nullptr;
    char m_province[2]{};
    char m_postalCode[6]{};
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
