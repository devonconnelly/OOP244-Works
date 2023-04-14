/* Citation and Sources...
Final Project Milestone 5
Module: NonPerishable
Filename: NonPerishable.h
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
#ifndef SDDS_NONPERISHABLE_H
#define SDDS_NONPERISHABLE_H
#include "Item.h"
namespace sdds
{
class NonPerishable : public Item {
public:
    char itemType() const;
    std::ostream& write(std::ostream& ostr) const;
};
}


#endif /* NonPerishable_h */

