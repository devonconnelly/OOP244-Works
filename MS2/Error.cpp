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

Error::Error(char *errorMessage)
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
        delete[] m_errorMessage;
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
        delete[] m_errorMessage;
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
    m_errorMessage[0] = '\0';
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
