#include <iostream>
#include <cstring>
#include "Date.h"
#include "Pos.h"
using namespace std;
namespace sdds
{
void Date::validation()
{
    <#code#>;
}

void Date::getSystemDate(int &year, int &mon, int &day, int &hour, int &min, bool dateOnly)
{
    <#code#>;
}

int Date::uniqueDateValue(int year, int mon, int day, int hour, int min)
{
    <#code#>;
}

int Date::daysOfMonth(int year, int month)
{
    <#code#>;
}

Date::Date()
{
    <#code#>;
}

Date::Date(int year, int month, int day)
{
    <#code#>;
}

Date::Date(int year, int month, int day, int hour, int minute)
{
    <#code#>;
}

Date::~Date() noexcept
{
    <#code#>;
}

bool Date::operator==(const sdds::Date &right)
{
    <#code#>;
}

bool Date::operator!=(const sdds::Date &right)
{
    <#code#>;
}

bool Date::operator<(const sdds::Date &right)
{
    <#code#>;
}

bool Date::operator>(const sdds::Date &right)
{
    <#code#>;
}

bool Date::operator<=(const sdds::Date &right)
{
    <#code#>;
}

bool Date::operator>=(const sdds::Date &right)
{
    <#code#>;
}

sdds::Date &Date::dateOnly(bool dateOnlyFlag)
{
    <#code#>;
}

Date::operator bool() const
{
    <#code#>;
}

sdds::Error &Date::error()
{
    <#code#>;
}

std::istream& operator>>(std::istream& istr, Date& right);
{
    
}
std::ostream& operator<<(std::ostream& ostr, const Date& right)
{
    
}
}
