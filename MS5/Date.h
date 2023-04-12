// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: April 12 2023
#ifndef SDDS_DATE_H_
#define SDDS_DATE_H_
#include "Error.h"
namespace sdds
{

class Date {
private:
    int m_year, m_month, m_day, m_hour, m_minute;
    bool m_dateOnly;
    Error m_errors;
public:
    void validation();
    void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
    int uniqueDateValue(int year, int mon, int day, int hour, int min);
    int daysOfMonth(int year, int month);
    Date();
    Date(const int& year, const int& month, const int& day);
    Date(const int& year, const int& month, const int& day, const int& hour, const int& minute = 0);
    ~Date();
    bool operator==(Date& right);
    bool operator!=(Date& right);
    bool operator<(Date& right);
    bool operator>(Date& right);
    bool operator<=(Date& right);
    bool operator>=(Date& right);
    Date& dateOnly(bool dateOnly);
    operator bool() const;
    const Error& error();
    std::istream& read(std::istream& istr);
    std::ostream& display(std::ostream& ostr) const;
    void setEmpty();
    
    
};



std::istream& operator>>(std::istream& istr, Date& right);
std::ostream& operator<<(std::ostream& ostr, const Date& right);
}
#endif
