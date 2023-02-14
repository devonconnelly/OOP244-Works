// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Feb 7 2023
#ifndef Tournament_h
#define Tournament_h
#include <iostream>
#include "Soccer.h"
using namespace std;
namespace sdds
{
class Tournament
{
private:
    char* m_name;//points to a dynamically allocated Cstring
    int m_num;//size of the dynamically allocated array of soccer team. It should be more then zero
    SoccerTeam* m_soccer=nullptr;//pointer to the dynamically allocated array of soccerTeam
public:
    void setTournament(const char* name, int noOfteam,const SoccerTeam* soccer);
    void setEmpty();
    bool isEmpty() const;
    Tournament& match(const SoccerTeam* ls);
    ostream& display() const;
    Tournament();
    Tournament(const char* name, int noOfteam,const SoccerTeam* soccer);
    ~Tournament();
    
};
}
#endif /* Tournament_h */
