/* Citation and Sources...
Final Project Milestone 5
Module: PosIO
Filename: PosIO.cpp
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
