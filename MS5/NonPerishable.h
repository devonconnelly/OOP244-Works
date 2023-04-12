// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: April 12 2023
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

