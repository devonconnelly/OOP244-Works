#ifndef SDDS_MEDIA_H
#define SDDS_MEDIA_H
#include <iostream>
namespace sdds
{
class Media {
    
public:
    virtual std::ostream& play(std::ostream& ostr) = 0;
    virtual void load(std::istream& istr) = 0;
    virtual ~Media() {}
};
std::ostream& operator<<(std::ostream& ostr, Media& media);
std::istream& operator>>(std::istream& istr, Media& media);
}
#endif
