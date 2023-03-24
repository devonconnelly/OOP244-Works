// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Mar 20 2023
#ifndef SDDS_VRVIDEO_H
#define SDDS_VRVIDEO_H
#include <iostream>
#include "Video.h"
namespace sdds
{
class VRVideo : public Video {
private:
    char* m_equipment;
public:
    VRVideo();
    VRVideo(int length, const char* equipment);
    ~VRVideo();
    void load(std::istream& istr);
    std::ostream& play(std::ostream& ostr);
};
}
#endif
