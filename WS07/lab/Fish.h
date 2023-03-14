#ifndef SDDS_FISH_H
#define SDDS_FISH_H
#include "Pet.h"
namespace sdds
{
class Fish : public Pet
{
private:
    const double m_create = 2.00;
    const double m_feed = 0.10;
    const double m_respawn = 0.50;
    const double m_clone = m_create * 2;
public:
    Fish(const char* name, int origAge = 0);
    void feed();
    void reSpawn();
    void operator++(int num);
    Fish& operator=(const Fish& rhs);
    std::ostream& outputData(std::ostream& os);
};
std::ostream& operator<<(std::ostream& os, Fish& fish);
}
#endif
