#include <iostream>
#include "Fish.h"
using namespace std;
namespace sdds
{

Fish::Fish(char *name, int origAge) : Pet(name, origAge, COST_BASE) {}


void Fish::feed()
{
    Pet::feed();
    if(isAlive())
    {
        addCharge(m_feed);
    }
}

void Fish::reSpawn()
{
    Pet::reSpawn();
    addCharge(m_respawn);
}

void Fish::operator++(int num)
{
    if(isAlive())
    {
        double healthDelta = 0;
        healthDelta += 0.20 * (getFeeds() - 1);
        applyHealthDelta(healthDelta);
        Pet::operator++(num);
    }
}

Fish& Fish::operator=(const Fish& rhs)
{
    Pet::operator=(rhs);
    addCharge(m_clone);
    return *this;
}
ostream& operator<<(ostream& os, Pet& pet)
{
    os << "** Generic Fish **" << endl;
    pet.outputData(os);
    return os;
}
}
