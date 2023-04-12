// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: April 12 2023
#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_
#include <iostream>
#include <fstream>
#include "Item.h"
#include "POS.h"
namespace sdds
{
class PosApp
{
private:
    char m_filename[128];
    Item* m_iptr[MAX_NO_ITEMS];
    int m_nptr;
public:
    int menu(int choice);
    void addItem();
    void removeItem();
    void stockItem();
    void listItems();
    void POS();
    void saveRecs();
    void loadRecs();
    void run();
    PosApp(const char filename[]);
    int selectItem();
    
    
};
}
#endif
