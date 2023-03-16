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
    Date(const int& year, const int& month, const int& day, const int& hour, const int& minute);
    ~Date();
    bool operator==(const Date& right);
    bool operator!=(const Date& right);
    bool operator<(const Date& right);
    bool operator>(const Date& right);
    bool operator<=(const Date& right);
    bool operator>=(const Date& right);
    Date& dateOnly(bool dateOnly);
    operator bool() const;
    const Error& error();
    
    
};



std::istream& operator>>(std::istream& istr, Date& right);
std::ostream& operator<<(std::ostream& ostr, const Date& right);
}
#endif
