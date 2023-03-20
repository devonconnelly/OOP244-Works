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
