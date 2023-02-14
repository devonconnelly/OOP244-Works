// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Feb 6 2023
#include <iostream>
#include <cstring>
#include "Store.h"
#include "Toys.h"
using namespace std;
namespace sdds
{
void Store::setStore(const char* sName, int no)
{
    setEmpty();
    if(sName != nullptr && no > 0)
    {
        strcpy(m_sName, sName);
    }
    else
    {
        setEmpty();
    }
}
void Store::setToys(const char* tname, int sku, double price,int age)
{
    if(m_addToys < MAX_NUM_TOYS)
    {
        m_toy[m_addToys].addToys(tname, sku, price, age);
        m_addToys++;
    }
}
void Store::display()const
{
    cout.width(60);
    cout << "************************************************************" << endl << m_sName << endl << "************************************************************" << endl << "list of the toys" << endl;
    cout.width(30);
    cout << right << "SKU";
    cout.width(10);
    cout << "Age";
    cout.width(11);
    cout << "Price";
    cout.width(10);
    cout << "Sale" << endl;
    cout << left;
    
    for(int i = 0; i < m_addToys; i++)
    {
        cout << "Toy[" << i + 1 << "] :";
        
        m_toy[i].display();
    }
    
}
void Store::find(int sku)
{
    for(int i = 0; i < m_addToys; i++)
    {
        if(m_toy[i].getSku() == sku)
        {
            m_toy[i].isSale(true);
            m_toy[i].calSale();
            i = MAX_NUM_TOYS;
        }
    }
}
void Store::setEmpty()
{
    strcpy(m_sName, "");
    m_addToys = 0;
    m_noOfToys = 0;
    for(int i = 0; i < MAX_NUM_TOYS; i++)
    {
        m_toy[i].clear();
    }
    
}
}
