// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Feb 7 2023
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Soccer.h"
using namespace std;
namespace sdds
{
void SoccerTeam::setTeam(const SoccerTeam& team)
{
    m_noFouls = team.m_noFouls;
    m_fines = team.m_fines;
    setName(team.m_teamName);
    
}
void SoccerTeam::setName(const char* tname)
{
    if(tname[0] != '\0' && tname != nullptr)
    {
        strcpy(m_teamName, tname);
    }
    else
    {
        setEmpty();
    }
}
void SoccerTeam::setFine(double fines, int foul)
{
    if(fines >= 0 && foul >= 0)
    {
        m_fines = fines;
        m_noFouls = foul;
    }
    else
    {
        setEmpty();
    }
}
void SoccerTeam::setEmpty()
{
    strcpy(m_teamName, "");
    m_fines = -1;
    m_noFouls = -1;
    m_goals = 0;
}
bool SoccerTeam::isEmpty() const
{
    if(m_teamName[0] != '\0' && m_fines >= 0 && m_noFouls >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void SoccerTeam::calFines()
{
    m_fines = m_fines + (m_fines * 0.2);
    m_noFouls = m_noFouls * 2;
}
int SoccerTeam::fouls() const
{
    return m_noFouls;
}
SoccerTeam::SoccerTeam()
{
    setEmpty();
}
SoccerTeam::SoccerTeam(const char* tname, double fines, int foul)
{
    setName(tname);
    setFine(fines, foul);
    m_goals = 0;
}
std::ostream& SoccerTeam::display() const
{
    if(isEmpty())
    {
        cout.width(30);
        cout << left << m_teamName;
        cout.width(6);
        cout << right << fixed << setprecision(2) << m_fines;
        cout.width(6);
        cout << m_noFouls;
        cout.width(10);
        cout << m_goals;
        if(m_goals > 0)
        {
            cout << "w";
        }
        else
        {
            cout << " ";
        }
    }
    else
    {
        cout << "Invalid Team";
    }
    return cout;
}
void SoccerTeam::goal()
{
    m_goals++;
}
}

