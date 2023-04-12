// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: April 12 2023
#include <iostream>
#include "PosIO.h"
namespace sdds
{
std::ostream& operator<<(std::ostream& ostr, const PosIO& posIO)
{
    posIO.write(ostr);
    return ostr;
}
std::istream& operator>>(std::istream& istr, PosIO& posIO)
{
    posIO.read(istr);
    return istr;
}
std::ofstream& operator<<(std::ofstream& ofstr, const PosIO& posIO)
{
    posIO.save(ofstr);
    return ofstr;
}
std::ifstream& operator>>(std::ifstream& ifstr, PosIO& posIO)
{
    posIO.load(ifstr);
    return ifstr;
}
}
