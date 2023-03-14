#include <iostream>
#include "Dog.h"
using namespace std;
namespace sdds
{
Dog::Dog(const char *name, int origAge, int numWalks) : Pet(name, origAge, COST_BASE), m_numWalks(numWalks) {}

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
        //from WS07 Instructions
        double healthDelta = 0;
        healthDelta += 0.15 * (getHugs()   - 1);
        healthDelta += 0.10 * (getFeeds()  - 2);
        healthDelta += 0.10 * (getGrooms() - 1);
        healthDelta += 0.20 * (m_numWalks  - 2);
        //
        applyHealthDelta(healthDelta);
        Pet::operator++(num);
    }
}

Dog& Dog::operator=(const Dog& rhs)
{
    if (this != &rhs)
    {
        Pet::operator=(rhs);
        m_numWalks = rhs.m_numWalks;
        addCharge(m_clone);
        m_numWalks = 0;
    }
    return *this;
}

ostream& Dog::outputData(ostream& os)
{
    os << "   Walks: " << m_numWalks << endl;
    Pet::outputData(os);
    return os;
}

ostream& operator<<(ostream& os, Dog& dog)
{
    os << "** Generic Dog **" << endl;
    dog.outputData(os);
    return os;
}
}
