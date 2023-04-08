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
