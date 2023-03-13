// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Feb 15 2023
#ifndef EggCarton_h
#define EggCarton_h

const int RegularEggWieght = 50;
const int JumboEggWieght = 75;
using namespace std;
namespace sdds
{
class EggCarton
{
private:
    int m_size;
    int m_noOfEggs;
    bool m_jumboSize;
    char m_jumboFlag;
    void setBroken();
    ostream& displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const;
    
public:
    EggCarton(int size=6, int noOfEggs=0, bool jumboSize=false);
    ostream& display(ostream& ostr = cout) const;
    istream& read(istream& istr = cin);
    operator bool() const;
    operator int() const;
    operator double() const;
    EggCarton& operator--();
    EggCarton& operator++();
    EggCarton operator--(int);
    EggCarton operator++(int);
    EggCarton& operator=(int value);
    EggCarton& operator+=(int value);
    EggCarton& operator+=(EggCarton& right);
    bool operator==(const EggCarton& right) const;
};
int operator+(int left, const EggCarton& right);
std::ostream& operator<<(std::ostream& ostr, const EggCarton& right);
std::istream& operator>>(std::istream& istr, EggCarton& right);
}
#endif
