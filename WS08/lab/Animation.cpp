// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Mar 20 2023
#include <iostream>
#include "Animation.h"
using namespace std;
namespace sdds
{

Animation::Animation() : Video(), m_dimension(0) {}

Animation::Animation(int length, int dimension) : Video(length)
{
    if(dimension == 2 || dimension == 3)
    {
        m_dimension = dimension;
    }
    else
    {
        m_dimension = -1;
    }
}

void Animation::load(std::istream &istr)
{
    Video::load(istr);
    istr >> m_dimension;
    istr.ignore(10000, '\n');
    if(m_dimension != 2 && m_dimension != 3)
    {
        m_dimension = -1;
    }
}

std::ostream& Animation::play(std::ostream &ostr)
{
    if(m_dimension != -1 && get() != -1)
    {
        ostr << "Animation is in " << m_dimension << "-D" << endl;
        ostr << "Video Length = " << Video::get();
    }
    return ostr;
}

}
