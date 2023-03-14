#include <iostream>
#include "Dog.h"
using namespace std;
namespace sdds
{
Dog::Dog(char *name, int origAge) : Pet(name, origAge, COST_BASE) {}

void Dog::feed()
{
    Pet::feed();
    if(isAlive())
    {
        addCharge(m_feed);
    }
}

void Dog::walk()
{
    if(isAlive())
    {
        m_numWalks++;
    }
}

void Dog::reSpawn()
{
    Pet::reSpawn();
    m_numWalks = 0;
    addCharge(m_respawn);
}

void Dog::operator++(int num)
{
    if(isAlive())
    {
        double healthDelta = 0;
        healthDelta += 0.15 * (getHugs()   - 1);
        healthDelta += 0.10 * (getFeeds()  - 2);
        healthDelta += 0.10 * (getGrooms() - 1);
        healthDelta += 0.20 * (m_numWalks  - 2);
        Pet::operator++(num);
    }
}

Dog& Dog::operator=(const Dog& rhs)
{
    Pet::operator=(rhs);
    m_numWalks = rhs.m_numWalks;
    addCharge(m_clone);
    return *this;
}
ostream& operator<<(ostream& os, Dog& dog)
{
    os << "** Generic Dog **" << endl;
    dog.outputData(os);
    return os;
}
}
