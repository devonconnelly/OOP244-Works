// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Mar 20 2023
#ifndef SDDS_ANIMATION_H
#define SDDS_ANIMATION_H
#include <iostream>
#include "Video.h"
namespace sdds
{
class Animation : public Video {
private:
    int m_dimension;
public:
    Animation();
    Animation(int length, int dimension);
    void load(std::istream& istr);
    std::ostream& play(std::ostream& ostr);
};
}
#endif
