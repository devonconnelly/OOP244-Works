/* Citation and Sources...
Final Project Milestone 5
Module: PosApp
Filename: PosApp.h
Version 1.0
Author    Devon Connelly
Revision History
-----------------------------------------------------------
Date      Reason
2023/04/14 Submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
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
    void listItems(bool flag);
    void POS();
    void saveRecs();
    void loadRecs();
    void run();
    PosApp(const char filename[]);
    int selectItem();
    ~PosApp();
    
    
};
}
#endif
