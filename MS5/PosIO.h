/* Citation and Sources...
Final Project Milestone 5
Module: PosIO
Filename: PosIO.h
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
#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H
#include <iostream>
namespace sdds
{
class PosIO
{
public:
    virtual std::ostream& write(std::ostream& ostr) const = 0;
    virtual std::istream& read(std::istream& istr) = 0;
    virtual std::ofstream& save(std::ofstream& ostr) const = 0;
    virtual std::ifstream& load(std::ifstream& istr) = 0;
};
std::ostream& operator<<(std::ostream& ostr, const PosIO& posIO);
std::istream& operator>>(std::istream& istr, PosIO& posIO);

std::ofstream& operator<<(std::ofstream& ofstr, const PosIO& posIO);
std::ifstream& operator>>(std::ifstream& ifstr, PosIO& posIO);
}
#endif
