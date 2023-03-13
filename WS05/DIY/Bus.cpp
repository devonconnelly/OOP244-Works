// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Feb 22 2023
#include <iostream>
#include "Bus.h"
using namespace std;
namespace sdds {
Bus::Bus(int seats, int passengers)
{
    if(!(seats % 2 == 0 && seats >= 10 && seats <= 40 && passengers >= 0 && passengers <= seats))
    {
        outOfService();
    }
    else
    {
        m_seats = seats;
        m_passengers = passengers;
    }
}
void Bus::outOfService()
{
    m_seats = -1;
    m_passengers = -1;
}
ostream& operator<<(std::ostream& ostr, const Bus& bus)
{
    if(!bus)
    {
        ostr << "Out of service!" << endl;
    }
    else
    {
        bus.drawBus(bus.m_seats, bus.m_passengers, ostr);
        ostr << "Total Fare Price: " << (double)bus;
        if((double)bus == 0) ostr << ".00";
        ostr << endl;
    }
    return ostr;
}
void Bus::drawBus(int seats, int noOfPassengers, ostream& ostr) const
{
    int i, p;
    ostr.fill('_');
    ostr.width((seats / 2) * 3 + 4);
    ostr << "_";
    ostr << endl << "| ";
    for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
    ostr << "|_\\_" << endl;
    ostr << "| ";
    ostr.fill(' ');
    ostr.width(((seats / 2) * 3 - 14) / 2);
    ostr << " " << "Seneca College";
    ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
    ostr << " " << "    )" << endl;
    ostr << "`---OO";
    ostr.fill('-');
    ostr.width((seats / 2) * 3 - 5);
    ostr << "-" << "O---'" << endl;
}
istream& operator>>(istream& istr, Bus& bus)
{
    istr >> bus.m_seats;
    istr.ignore();
    istr >> bus.m_passengers;
    istr.ignore();
    if(!(bus.m_seats % 2 == 0 && bus.m_seats >= 10 && bus.m_seats <= 40 && bus.m_passengers >= 0 && bus.m_passengers <= bus.m_seats))
    {
        bus.outOfService();
    }
    return istr;
}
Bus::operator bool() const
{
    return m_seats > 0;
}
Bus::operator int() const
{
    return m_seats > 0 ? m_passengers : -1;
}
Bus::operator double() const
{
    double totalFare;
    if(*this)
    {
        totalFare = ticketCost * m_passengers;
    }
    else
    {
        totalFare = -1.0;
    }
    return totalFare;
}
bool Bus::operator--()
{
    bool val;
    if(*this && m_passengers > 0)
    {
        --m_passengers;
        val = true;
    }
    else
    {
        val = false;
    }
    return val;
}
bool Bus::operator++()
{
    bool val;
    if(*this && m_seats > m_passengers)
    {
        ++m_passengers;
        val = true;
    }
    else
    {
        val = false;
    }
    return val;
}
bool Bus::operator--(int)
{
    bool val;
    if(*this && m_passengers > 0)
    {
        m_passengers--;
        val = true;
    }
    else
    {
        val = false;
    }
    return val;
}
bool Bus::operator++(int)
{
    bool val;
    if(*this && m_seats > m_passengers)
    {
        m_passengers++;
        val = true;
    }
    else
    {
        val = false;
    }
    return val;
}
Bus& Bus::operator=(int value)
{
    m_passengers = value;
    if(m_passengers > m_seats)
    {
        outOfService();
    }
    return *this;
}
Bus& Bus::operator+=(int value)
{
    if(*this)
    {
        m_passengers += value;
    }
    if(m_passengers > m_seats)
    {
        outOfService();
    }
    return *this;
}
Bus& Bus::operator+=(Bus& right)
{
    if(*this && right)
    {
        int space = this->m_seats - this->m_passengers;
        if (space <= right.m_passengers)
        {
            this->m_passengers += space;
            right.m_passengers -= space;
        }
        else
        {
            this->m_passengers += right.m_passengers;
            right.m_passengers = 0;
        }
    }
    return *this;
}
bool Bus::operator==(const Bus& right) const
{
    return (*this && right && m_passengers == right.m_passengers) ? true : false;
}
int operator+(int left, const Bus& bus)
{
    int val;
    if (bus)
    {
        val = left + (int)bus;
    }
    else
    {
        val = left;
    }
    return val;
}
}
