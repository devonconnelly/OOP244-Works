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
