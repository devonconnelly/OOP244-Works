// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Feb 6 2023
#ifndef Store_h
#define Store_h
#include "Toys.h"
#define MAX_NUM_TOYS 10
#define MAX_SNAME 31
namespace sdds
{
class Store
{
private:
    char m_sName[MAX_SNAME];
    int m_noOfToys;
    int m_addToys;
    Toys m_toy[MAX_NUM_TOYS];
public:
    void setStore(const char* sName, int no);
    void setToys(const char* tname, int sku, double price,int age);
    void display()const;
    void find(int sku);
    void setEmpty();
};
}

#endif /* Store_h */
