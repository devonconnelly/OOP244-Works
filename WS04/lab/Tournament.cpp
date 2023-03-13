// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Feb 7 2023
#include <stdio.h>
#include <cstring>
#include "Tournament.h"
using namespace std;
namespace sdds
{
void Tournament::setTournament(const char* name, int noOfteam,const SoccerTeam* soccer)
{
    if(name != nullptr && name[0] != '\0' && noOfteam > 0)
    {
        m_num = noOfteam;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        m_soccer = new SoccerTeam[m_num];
        for(int i = 0; i < m_num; i++)
        {
            m_soccer[i] = soccer[i];
        }
    }
    else
    {
        setEmpty();
    }
}
void Tournament::setEmpty()
{
    m_name = nullptr;
    m_soccer = nullptr;
    m_num = 0;
}
bool Tournament::isEmpty() const
{
    if(m_name != nullptr && m_soccer != nullptr && m_num > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Tournament& Tournament::match(const SoccerTeam* ls)
{
    for (int i = 0; i < m_num - 1; i++)
    {
        if (ls[i].fouls() < ls[i + 1].fouls())
        {
            m_soccer[i + 1].calFines();
            m_soccer[i].goal();
        }
        else if(ls[i].fouls() > ls[i + 1].fouls())
        {
            m_soccer[i].calFines();
            m_soccer[i + 1].goal();
        }
        if(m_soccer[i].fouls() > MAX_FOUL)
        {
            m_soccer[i].setEmpty();
        }
        else if(m_soccer[i + 1].fouls() > MAX_FOUL)
        {
            m_soccer[i + 1].setEmpty();
        }
    }
    return *this;
}
std::ostream& Tournament::display() const
{
    if(isEmpty())
    {
        cout << "Tournament name: " << m_name << endl << "list of the teams" << endl;
        cout.width(45);
        cout << "Fines";
        cout.width(10);
        cout << "Fouls";
        cout.width(10);
        cout << "Goals" << endl;
        for(int i = 0; i < m_num; i++)
        {
            cout << "Team[" << i + 1 << "] :";
            m_soccer[i].display();
            cout << endl;
        }
    }
    else
    {
        cout << "Invalid Tournament";
    }
    return cout;
    
}
Tournament::Tournament()
{
    setEmpty();
}
Tournament::Tournament(const char* name, int noOfteam,const SoccerTeam* soccer)
{
    setTournament(name, noOfteam, soccer);
    
}
Tournament::~Tournament()
{
    delete[] m_name;
    delete[] m_soccer;
}
}
