#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <cstring>
#include "Error.h"
#include "Date.h"
#include "Pos.h"
using namespace std;
namespace sdds
{
void Date::validation()
{
    if(m_year < MIN_YEAR || m_year > MAX_YEAR)
    {
        m_errors = "Invalid Year";
    }
    else if(m_month < 1 || m_month > 12)
    {
        m_errors = "Invalid Month";
    }
    else if(m_day < 1 || m_day > daysOfMonth(m_year, m_month))
    {
        m_errors = "Invalid Day";
    }
    else if(m_hour < 0 || m_hour > 23)
    {
        m_errors = "Invalid Hour";
    }
    else if(m_minute < 0 || m_minute > 59)
    {
        m_errors = "Invalid Minute";
    }
}

void Date::getSystemDate(int &year, int &mon, int &day, int &hour, int &min, bool dateOnly)
{
    time_t t = time(NULL);
    tm lt = *localtime(&t);
    day = lt.tm_mday;
    mon = lt.tm_mon + 1;
    year = lt.tm_year + 1900;
    if(dateOnly) {
        hour = min = 0;
    } else {
        hour = lt.tm_hour;
        min = lt.tm_min;
    }
    
}

int Date::uniqueDateValue(int year, int mon, int day, int hour, int min)
{
    return year * 535680 + mon * 44640 + day * 1440 + hour * 60 + min;
}

int Date::daysOfMonth(int year, int month)
{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = month >= 1 && month <= 12 ? month : 13;
    mon--;
    return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

Date::Date()
{
    getSystemDate(m_year, m_month, m_day, m_hour, m_minute, m_dateOnly);
}

Date::Date(const int& year, const int& month, const int& day)
{
    m_dateOnly = true;
    m_year = year;
    m_month = month;
    m_day = day;
    validation();
}

Date::Date(const int& year, const int& month, const int& day, const int& hour, const int& minute)
{
    m_dateOnly = false;
    m_year = year;
    m_month = month;
    m_day = day;
    m_hour = hour;
    m_minute = minute;
    validation();
}

Date::~Date()
{
    <#code#>;
}

bool Date::operator==(Date& right)
{
    return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) == right.uniqueDateValue(m_year, m_month, m_day, m_hour, m_hour);
}

bool Date::operator!=(Date& right)
{
    return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) != right.uniqueDateValue(m_year, m_month, m_day, m_hour, m_hour);
}

bool Date::operator<(Date& right)
{
    return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) < right.uniqueDateValue(m_year, m_month, m_day, m_hour, m_hour);
}

bool Date::operator>(Date& right)
{
    return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) > right.uniqueDateValue(m_year, m_month, m_day, m_hour, m_hour);
}

bool Date::operator<=(Date& right)
{
    return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) <= right.uniqueDateValue(m_year, m_month, m_day, m_hour, m_hour);
}

bool Date::operator>=(Date& right)
{
    return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) >= right.uniqueDateValue(m_year, m_month, m_day, m_hour, m_hour);
}

Date& Date::dateOnly(bool dateOnly)
{
    m_dateOnly = dateOnly;
    if(m_dateOnly == true)
    {
        m_hour = 0;
        m_minute = 0;
    }
    return *this;
}

Date::operator bool() const
{
    return !m_errors;
}

const Error& Date::error()
{
    return m_errors;
}

istream& operator>>(istream& istr, Date& right);
{
    return istr;
}
ostream& operator<<(ostream& ostr, const Date& right)
{
    if(right)
    {
        
    }
    return ostr;
}
}
