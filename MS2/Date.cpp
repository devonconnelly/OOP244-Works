// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Mar 17 2023
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Error.h"
#include "Date.h"
#include "POS.h"
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
        m_errors = "Invlid Minute";
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
    m_dateOnly = false;
    getSystemDate(m_year, m_month, m_day, m_hour, m_minute, m_dateOnly);
}

Date::Date(const int& year, const int& month, const int& day)
{
    m_dateOnly = true;
    m_year = year;
    m_month = month;
    m_day = day;
    dateOnly(m_dateOnly);
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
    
}

bool Date::operator==(Date& right)
{
    return (uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) == right.uniqueDateValue(right.m_year, right.m_month, right.m_day, right.m_hour, right.m_minute));
}

bool Date::operator!=(Date& right)
{
    return (uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) != right.uniqueDateValue(right.m_year, right.m_month, right.m_day, right.m_hour, right.m_minute));
}

bool Date::operator<(Date& right)
{
    return (uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) < right.uniqueDateValue(right.m_year, right.m_month, right.m_day, right.m_hour, right.m_minute));
}

bool Date::operator>(Date& right)
{
    return (uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) > right.uniqueDateValue(right.m_year, right.m_month, right.m_day, right.m_hour, right.m_minute));
}

bool Date::operator<=(Date& right)
{
    return (uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) <= right.uniqueDateValue(right.m_year, right.m_month, right.m_day, right.m_hour, right.m_minute));
}

bool Date::operator>=(Date& right)
{
    return (uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) >= right.uniqueDateValue(right.m_year, right.m_month, right.m_day, right.m_hour, right.m_minute));
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

std::istream& Date::read(std::istream& istr)
{
    m_errors.clear();
    istr >> m_year;
    if(!istr.fail())
    {
        istr.ignore();
        istr >> m_month;
        if(!istr.fail())
        {
            istr.ignore();
            istr >> m_day;
            if(!istr.fail())
            {
                if(!m_dateOnly)
                {
                    istr.ignore();
                    istr >> m_hour;
                    if(!istr.fail())
                    {
                        istr.ignore();
                        istr >> m_minute;
                        if(istr.fail())
                        {
                            m_errors = "Cannot read minute entry";
                        }
                    }
                    else
                    {
                        m_dateOnly = true;
                        m_errors = "Cannot read hour entry";
                    }
                }
            }
            else
            {
                m_dateOnly = true;
                m_errors = "Cannot read day entry";
            }
        }
        else
        {
            m_dateOnly = true;
            m_errors = "Cannot read month entry";
        }
    }
    else
    {
        m_dateOnly = true;
        m_errors = "Cannot read year entry";
    }


    
    validation();
    
    return istr;
}
std::ostream& Date::display(std::ostream& ostr) const
{
    if(*this)
    {
        if(m_dateOnly)
        {
            ostr << m_year << "/" << setw(2) << setfill('0') << m_month << "/" << setw(2) << m_day;
        }
        else
        {
            ostr << m_year << "/" << setw(2) << setfill('0') << m_month << "/" << setw(2) << m_day << ", " << setw(2) << m_hour << ":" << setw(2) << m_minute;
        }
    }
    else
    {
        if(!m_dateOnly)
        {
            ostr << m_errors << "(" << m_year << "/" << setw(2) << setfill('0') << m_month << "/" << setw(2) << m_day << ", " << setw(2) << m_hour << ":" << setw(2) << m_minute << ")";
        }
        else
        {
            ostr << m_errors << "(" << m_year << "/" << setw(2) << setfill('0') << m_month << "/" << setw(2) <<  m_day << ")";
        }
    }
    return ostr;
}

istream& operator>>(istream& istr, Date& right)
{
    right.read(istr);
    return istr;
}
ostream& operator<<(ostream& ostr, const Date& right)
{
    right.display(ostr);
    return ostr;
}
}
