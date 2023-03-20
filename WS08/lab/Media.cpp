#include <iostream>
#include "Media.h"

using namespace std;
namespace sdds
{
std::ostream& operator<<(std::ostream& ostr, Media& media)
{
    media.play(ostr);
    return ostr;
}
std::istream& operator>>(std::istream& istr, Media& media)
{
    media.load(istr);
    return istr;
}
}
