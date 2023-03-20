#include <iostream>
#include <cstring>
#include "VRVideo.h"
using namespace std;
namespace sdds
{

VRVideo::VRVideo() : Video(), m_equipment(nullptr) {}


VRVideo::VRVideo(int length, const char *equipment) : Video(length)
{
    if (Video::get() != -1 && equipment != nullptr)
    {
        m_equipment = new char[strlen(equipment) + 1];
        strcpy(m_equipment, equipment);
    }
    else
    {
        m_equipment = nullptr;
    }
}

VRVideo::~VRVideo()
{
    delete[] m_equipment;
}

void VRVideo::load(std::istream &istr)
{
    Video::load(istr);
    char* temp = new char[200];
    istr.getline(temp, 200);
    if (Video::get() != -1 && temp != nullptr)
    {
        delete[] m_equipment;
        m_equipment = new char[strlen(temp) + 1];
        strcpy(m_equipment, temp);
    }
    else
    {
        m_equipment = nullptr;
    }
}

std::ostream& VRVideo::play(std::ostream &ostr)
{
    if(m_equipment != nullptr)
    {
        ostr << "VRVideo requires " << m_equipment << endl;
        ostr << "Video Length = " << Video::get();
    }
    return ostr;
}

}

