#ifndef SDDS_DOG_H
#define SDDS_DOG_H
#include "Pet.h"
namespace sdds
{
class Dog : public Pet
{
private:
    const double m_create = 4.00;
    const double m_feed = 0.25;
    const double m_respawn = 1.00;
    const double m_clone = m_create * 2;
    int m_numWalks;
public:
    Dog(const char* name, int origAge = 0, int numWalks = 0);
    void feed();
    void walk();
    void reSpawn();
    void operator++(int num);
    Dog& operator=(const Dog& rhs);
    std::ostream& outputData(std::ostream& os);
};
std::ostream& operator<<(std::ostream& os, Dog& dog);
}

#endif

