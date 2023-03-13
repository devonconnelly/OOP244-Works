// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Feb 15 2023
#include <iostream>
#include "EggCarton.h"
using namespace std;
namespace sdds
{
EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize)
{
    if(!(size % 6 == 0 && size >= 6 && size <= 36 && noOfEggs >= 0 && noOfEggs <= size))
    {
        setBroken();
    }
    else
    {
        m_size = size;
        m_jumboSize = jumboSize;
        m_noOfEggs = noOfEggs;
    }
}
void EggCarton::setBroken()
{
    m_size = -1;
    m_noOfEggs = -1;
}
ostream& EggCarton::display(ostream& ostr) const
{
    if(!*this)
    {
        ostr << "Broken Egg Carton!" << endl;
    }
    else
    {
        displayCarton(m_size, m_noOfEggs, m_jumboSize, ostr);
    }
    return ostr;
}
ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const {
    int cartonWidth = size == 6 ? 3 : 6;
    for(int i = 0; i < size; i++) {
        ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
        ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
    }
    return ostr;
}
istream& EggCarton::read(istream& istr)
{
    istr.get(m_jumboFlag);
    if(m_jumboFlag == 'j')
    {
        m_jumboSize = true;
    }
    else
    {
        m_jumboSize = false;
    }
    istr.ignore();
    istr >> m_size;
    istr.ignore();
    istr >> m_noOfEggs;
    istr.ignore();
    if(!(m_size % 6 == 0 && m_size >= 6 && m_size <= 36 && m_noOfEggs >= 0 && m_noOfEggs <= m_size))
    {
        setBroken();
    }
    return istr;
}
EggCarton::operator bool() const
{
    return m_size > 0;
}
EggCarton::operator int() const
{
    return m_size > 0 ? m_noOfEggs : -1;
}
EggCarton::operator double() const
{
    double weight;
    if(m_size > 0)
    {
        if(m_jumboSize)
        {
            weight = (m_noOfEggs * JumboEggWieght);
        }
        else
        {
            weight = (m_noOfEggs * RegularEggWieght);
        }
        weight /= 1000;
    }
    else
    {
        weight = -1.0;
    }
    return weight;
}
EggCarton& EggCarton::operator--()
{
    if(m_size > 0 && m_noOfEggs > 0)
    {
        --m_noOfEggs;
    }
    return *this;
}
EggCarton& EggCarton::operator++()
{
    if(m_size > 0 && m_noOfEggs > 0)
    {
        ++m_noOfEggs;
    }
    if(m_noOfEggs > m_size)
    {
        setBroken();
    }
    return *this;
}
EggCarton EggCarton::operator--(int)
{
    EggCarton copy(*this);
    --(*this);
    return copy;
}
EggCarton EggCarton::operator++(int)
{
    EggCarton copy(*this);
    ++(*this);
    return copy;
}
EggCarton& EggCarton::operator=(int value)
{
    m_noOfEggs = value;
    if(m_noOfEggs > m_size)
    {
        setBroken();
    }
    return *this;
}
EggCarton& EggCarton::operator+=(int value)
{
    if(*this)
    {
        m_noOfEggs += value;
    }
    if(m_noOfEggs > m_size)
    {
        setBroken();
    }
    return *this;
}
EggCarton& EggCarton::operator+=(EggCarton& right)
{
    if(m_size > 0 && m_noOfEggs > 0)
    {
        int space = this->m_size - this->m_noOfEggs;
        if (space <= right.m_noOfEggs)
        {
            this->m_noOfEggs += space;
            right.m_noOfEggs -= space;
        }
        else
        {
            this->m_noOfEggs += right.m_noOfEggs;
            right.m_noOfEggs = 0;
        }
    }
    return *this;
}
bool EggCarton::operator==(const EggCarton& right) const
{
    int weight = right.operator double() - this->operator double();
    return(weight >= -0.001 && weight <= 0.001);
}
int operator+(int left, const EggCarton& right)
{
    
    int val = 0;
    
    if(right)
    {
        val = left + (int)right;
    }
    else
    {
        val = left;
    }
    
    return val;
}


ostream& operator<<(ostream& ostr, const EggCarton& right)
{
    right.display(ostr);
    return ostr;
}

istream& operator>>(istream& istr, EggCarton& right)
{
    right.read(istr);
    return istr;
}
}
