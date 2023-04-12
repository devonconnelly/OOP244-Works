// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: April 12 2023
#include <iostream>
#include "NonPerishable.h"
namespace sdds
{
char NonPerishable::itemType() const {
    return 'N';
}

std::ostream& NonPerishable::write(std::ostream& ostr) const {
    if(*this)
    {
        Item::write(ostr);
        if(m_displayType == 1)
        {
            ostr << "     N / A   |";
        }
        else if(m_displayType == 2)
        {
            ostr << "=============^" << std::endl;
        }
    }
    return ostr;
}
}
