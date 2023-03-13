// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Feb 7 2023
#ifndef SoccerTeam_h
#define SoccerTeam_h


const int MAX_FOUL = 4;

using namespace std;
namespace sdds
{

struct SoccerTeam
{
private:
    char m_teamName[41];// a statically allocated Cstring with size 41. Remember, name could be
                       //maximum 40 characters long and 1 byte is for the null byte.
    int m_noFouls;//number of fouls, it can be zero or more but cannot be a negative number
    double m_fines;//it can be equal to and more than zero.
    int m_goals;//can be zero or more
public:
    void setTeam(const SoccerTeam& team);
    void setName(const char* tname);
    void setFine(double fines, int foul);
    void setEmpty();
    bool isEmpty() const;
    void calFines();
    int fouls() const ;
    SoccerTeam();
    SoccerTeam(const char* tname, double fines, int foul);
    void goal();
    ostream& display() const;
};
}


#endif /* SoccerTeam_h */
