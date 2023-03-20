// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Mar 20 2023
#include <iostream>
#include "Media.h"

using namespace std;
namespace sdds
{
std::ostream& operator<<(std::ostream& ostr, Media& media)
{
    media.play(ostr);
    return ostr;
}
std::istream& operator>>(std::istream& istr, Media& media)
{
    media.load(istr);
    return istr;
}
}
