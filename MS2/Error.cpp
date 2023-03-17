// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Mar 17 2023
#include <iostream>
#include <cstring>
#include "Error.h"
using namespace std;
namespace sdds
{
Error::Error()
{
    m_errorMessage = nullptr;
}

Error::Error(const char *errorMessage)
{
//    m_errorMessage = new char[strlen(errorMessage) + 1];
//    strcpy(m_errorMessage, errorMessage);
    *this = errorMessage;
}

Error::Error(const Error& source)
{
    *this = source;
}

Error& Error::operator=(const Error &source)
{
    if(source && this != &source)
    {
        int len = (int)strlen(source.m_errorMessage);
        m_errorMessage = new char[len + 1];
        m_errorMessage[len] = '\0';
        strcpy(m_errorMessage, source.m_errorMessage);
    }
    return *this;
}

Error::~Error()
{
    delete[] m_errorMessage;
}


Error& Error::operator=(const char *cString)
{
    if(cString != nullptr && cString[0] != '\0')
    {
        int len = (int)strlen(cString);
        m_errorMessage = new char[len + 1];
        m_errorMessage[len] = '\0';
        strcpy(m_errorMessage, cString);
    }
    else
    {
        m_errorMessage = nullptr;
    }
    return *this;
}

Error::operator bool() const
{
    return m_errorMessage != nullptr;
}

Error& Error::Error::clear()
{
    m_errorMessage = nullptr;
    return *this;
}

char* Error::getErrorMessage() const
{
    return m_errorMessage;
}

ostream& operator<<(ostream& ostr, const Error& right)
{
    if(right)
    {
        ostr << right.getErrorMessage();
    }
    return ostr;
}

}
