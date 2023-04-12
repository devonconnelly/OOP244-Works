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
    void selectItem();
    
    
};
}
#endif
