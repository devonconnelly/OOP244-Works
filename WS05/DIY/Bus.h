// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Feb 22 2023
#ifndef bus_h
#define bus_h
const double ticketCost = 125.34;
namespace sdds
{
class Bus
{
private:
    int m_seats;
    int m_passengers;
public:
    Bus(int seats=20, int passengers=0);
    void outOfService();
    friend std::ostream& operator<<(std::ostream& ostr, const Bus& bus);
    void drawBus(int seats, int noOfPassengers, std::ostream& ostr) const;
    friend std::istream& operator>>(std::istream& istr, Bus& right);
    operator bool() const;
    operator int() const;
    operator double() const;
    bool operator--();
    bool operator++();
    bool operator--(int);
    bool operator++(int);
    Bus& operator=(int value);
    Bus& operator+=(int value);
    Bus& operator+=(Bus& right);
    bool operator==(const Bus& right) const;
};
int operator+(int left, const Bus& bus);
std::ostream& operator<<(std::ostream& ostr, const Bus& bus);
std::istream& operator>>(std::istream& istr, Bus& bus);
}
#endif
