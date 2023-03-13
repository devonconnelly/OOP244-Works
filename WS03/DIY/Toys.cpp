// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Feb 6 2023
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Toys.h"
using namespace std;
namespace sdds
{
void Toys::addToys(const char* tname, int sku, double price,int age)
{
    if(tname != nullptr && sku >= 10000000)
    {
        strcpy(m_tName, tname);
        m_sku = sku;
        m_price = price;
        m_age = age;
    }
    else
    {
        clear();
    }
}
void Toys::isSale(bool sale)
{
    m_onSale = sale;
}
void Toys::calSale()
{
    m_price = m_price * 0.8;
}
void Toys::display()const
{
    if(m_tName[0] != '\0' && m_sku < 100000000 && m_sku > 9999999)
    {
        cout.width(15);
        cout << left << m_tName;

        cout.width(10);
        cout << right << m_sku;

        cout.width(6);
        cout << m_age;

        cout.width(12);
        cout << fixed << setprecision(2) << m_price;

        if(m_onSale) {
            cout.width(11);
            cout << "On Sale ";
        }
        cout << endl;
    }
    else
    {
        cout << "Invalid Toy" << endl;
    }
}
int Toys::getSku()
{
    return m_sku;
}
void Toys::clear()
{
    strcpy(m_tName, "");
    m_sku = 0;
    m_price = 0;
    m_age = 0;
    m_onSale = false;
}
}
