#ifndef SDDS_VIDEO_H
#define SDDS_VIDEO_H
#include <iostream>
#include "Media.h"
namespace sdds
{
class Video : public Media {
private:
    int m_length;
protected:
    int get();
public:
    Video();
    Video(int length);
    Video(const Video& source) = delete;
    Video& operator=(const Video& source) = delete;
    void load(std::istream& istr);
    
    
};
}
#endif
