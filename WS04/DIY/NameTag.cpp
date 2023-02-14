// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Feb 14 2023
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "NameTag.h"
using namespace std;
namespace sdds
{
void NameTag::print()
{
    int size;
    if(m_name != nullptr && (m_extension == 0 || (m_extension > 9999 && m_extension < 100000)))
    {
       if(strlen(m_name) < 20)
       {
           size = 20;
       }
       else
       {
           size = strlen(m_name);
       }
        cout.setf(ios::left);
        cout << "+" << setw(size + 3) << setfill('-') << right << "+" << endl;
        cout << "|" << setw(size + 3) << setfill(' ') << right << "|" << endl;
        if(size == 20)
        {
            cout << "| " << left << setw(size) << m_name << setfill(' ') << " |" << endl;
        }
        else
        {
            cout << "| " << m_name << " |" << endl;
        }
        cout << "|" << setw(size + 3) << setfill(' ') <<  right << "|" << endl;
        if (m_extension != 0 && size == 20)
        {
            cout << "| " << left << "Extension: " << setw(9) <<  m_extension << setfill(' ') << " |" << endl;
        }
        else if(m_extension != 0 && size != 20)
        {
            cout << "| " << left << "Extension: " << setw(size - 11) <<  m_extension << setfill(' ') << " |" << endl;
        }
        else
        {
            cout << "| " << setw(size) << left << "Extension: N/A" << " |" << endl;
        }
        cout << "|" << setw(size + 3) << setfill(' ') << right << "|" << endl;
        cout << "+" << setw(size + 3) << setfill('-') << right << "+" << endl;
        
    }
    else
    {
        cout << "EMPTY NAMETAG!" << endl;
    }
}
NameTag& NameTag::read()
{
    char name[50];
    int extension;
    char prompt;
    
    cout << "Please enter the name: ";
    cin.getline(name, 999);
    name[40] = '\0';
    delete[] m_name;
    if (strlen(name) > 40)
    {
        m_name = new char[41];
        strncpy(m_name, name, 40);
        m_name[40] = '\0';
    }
    else
    {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        m_name[strlen(name)] = '\0';
    }
    
    cout << "Would you like to enter an extension? (Y)es/(N)o: ";
    do {
        cin.get(prompt);
        cin.ignore(999, '\n');
        if(prompt != 'Y' && prompt != 'N' && prompt != 'y' && prompt != 'n')
        {
            cout << "Only (Y) or (N) are acceptable, try again: ";
        }
    }while(prompt != 'Y' && prompt != 'N' && prompt != 'y' && prompt != 'n');
    
    if(prompt == 'Y' || prompt == 'y')
    {
        cout << "Please enter a 5 digit phone extension: ";
        do {
            cin >> extension;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(999, '\n');
                cout << "Bad integer value, try again: ";
            }
            else if(extension < 10000 || extension > 99999)
            {
                cout << "Invalid value [10000<=value<=99999]: ";
            }
        }while(extension < 10000 || extension > 99999 || cin.fail());
        cin.ignore(999, '\n');
        m_extension = extension;
    }
    else
    {
        m_extension = 0;
    }
    
    return *this;
}
NameTag::NameTag()
{
    m_name = nullptr;
    m_extension = 0;
}
NameTag::NameTag(const char* name)
{
    m_name = nullptr;
    m_extension = 0;
    if(name != nullptr)
    {
        delete[] m_name;
        if (strlen(name) > 40)
        {
            m_name = new char[41];
            strncpy(m_name, name, 40);
            m_name[40] = '\0';
        }
        else
        {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_name[strlen(name)] = '\0';
        }
    }
}
NameTag::NameTag(const char* name, int ext)
{
    m_name = nullptr;
    m_extension = 0;
    if(name != nullptr)
    {
        delete[] m_name;
        if (strlen(name) > 40)
        {
            m_name = new char[41];
            strncpy(m_name, name, 40);
            m_name[40] = '\0';
        }
        else
        {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_name[strlen(name)] = '\0';
        }
    }
    if(m_extension > 9999 && m_extension < 100000)
    {
        m_extension = 0;
    }
    else
    {
        m_extension = ext;
    }
    
}
NameTag::~NameTag()
{
    delete[] m_name;
}
}

