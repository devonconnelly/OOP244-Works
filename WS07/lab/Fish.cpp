// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Mar 14 2023
#include <iostream>
#include "Fish.h"
using namespace std;
namespace sdds
{

Fish::Fish(const char *name, int origAge) : Pet(name, origAge, COST_BASE) {}


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

ostream& Fish::outputData(ostream& os)
{
    Pet::outputData(os);
    return os;
}

ostream& operator<<(ostream& os, Fish& fish)
{
    os << "** Generic Fish **" << endl;
    fish.outputData(os);
    return os;
}
}
