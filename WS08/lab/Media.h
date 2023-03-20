// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Mar 20 2023
#ifndef SDDS_MEDIA_H
#define SDDS_MEDIA_H
#include <iostream>
namespace sdds
{
class Media {
    
public:
    virtual std::ostream& play(std::ostream& ostr) = 0;
    virtual void load(std::istream& istr) = 0;
    virtual ~Media() {}
};
std::ostream& operator<<(std::ostream& ostr, Media& media);
std::istream& operator>>(std::istream& istr, Media& media);
}
#endif
