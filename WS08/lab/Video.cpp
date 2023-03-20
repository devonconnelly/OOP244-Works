#include <iostream>
#include "Video.h"
using namespace std;
namespace sdds
{

int Video::get()
{
    return m_length;
}
Video::Video()
{
    m_length = 0;
}

Video::Video(int length)
{
    if(length >= 0)
    {
        m_length = length;
    }
    else
    {
        m_length = -1;
    }
}

void Video::load(std::istream& istr)
{ 
    istr >> m_length;
    istr.ignore();
}
}
