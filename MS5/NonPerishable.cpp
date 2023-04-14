/* Citation and Sources...
Final Project Milestone 5
Module: NonPerishable
Filename: NonPerishable.cpp
Version 1.0
Author    Devon Connelly
Revision History
-----------------------------------------------------------
Date      Reason
2023/04/14 Submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
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
