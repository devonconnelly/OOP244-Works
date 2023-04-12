// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: April 12 2023
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include "Item.h"
#include "Date.h"
namespace sdds
{
class Perishable : public Item {
private:
    Date m_date;
public:
    char itemType() const;
    std::ostream& write(std::ostream& ostr) const;
    std::istream& read(std::istream& istr);
    std::ofstream& save(std::ofstream& ofstr) const;
    std::ifstream& load(std::ifstream& ifstr);
};
}

#endif /* Perishable_h */
