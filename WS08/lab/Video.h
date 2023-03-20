// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Mar 20 2023
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
