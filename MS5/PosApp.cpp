#include <iostream>
#include <fstream>
#include <cstring>
#include "PosApp.h"
#include "PosIO.h"
#include "POS.h"
#include "Perishable.h"
#include "NonPerishable.h"
#include "Item.h"
using namespace std;
namespace sdds
{
void PosApp::run()
{
    int choice;
    bool flag;
    cout << ">>>> Loading Items..........................................................." << endl;
    loadRecs();
    do
    {
        cout << "The Sene-Store" << endl;
        cout << "1- List items" << endl;
        cout << "2- Add item" << endl;
        cout << "3- Remove item" << endl;
        cout << "4- Stock item" << endl;
        cout << "5- Point of Sale" << endl;
        cout << "0- exit program" << endl;
        cout << "> ";

        do
        {
            cin >> choice;
            flag = true;
            
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout  << "Invalid Integer, try again: ";
                    flag = false;
                }
                else
                {
                    if(choice < 0 || choice > 5)
                    {
                        cout << "[0<=value<=5], retry: > ";
                        flag = false;
                    }
                }
        }while(!flag);
        
        switch(choice)
        {
            case 1:
                cout << ">>>> Listing Items..........................................................." << endl;
                listItems();
                break;
            case 2:
                cout << ">>>> Adding Item to the store................................................" << endl;
                addItem();
                break;
            case 3:
                cout << ">>>> Remove Item............................................................." << endl;
                removeItem();
                break;
            case 4:
                cout << ">>>> Select an item to stock................................................." << endl;
                stockItem();
                break;
            case 5:
                cout << ">>>> Starting Point of Sale.................................................." << endl;
                POS();
                break;
        }
    }while(choice != 0);
    saveRecs();
    cout << ">>>> Saving Data............................................................." << endl << "Goodbye!" << endl;
}

void PosApp::listItems()
{
    int i, j;
    double totalAsset = 0;
    for (i = 0; i < m_nptr - 1; i++)
           for (j = 0; j < m_nptr - i - 1; j++)
               if (*m_iptr[j] > *m_iptr[j+1]) {
                   Item* temp = m_iptr[j];
                   m_iptr[j] = m_iptr[j + 1];
                   m_iptr[j + 1] = temp;
               }
    cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
    cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;
    for (int i = 0; i < m_nptr; i++)
       {
           m_iptr[i] -> displayType(POS_LIST);
           cout << setw(4) << setfill(' ');
           cout.setf(ios::right);
           cout << i + 1;
           cout.unsetf(ios::right);
           cout.setf(ios::left);
           cout << " | ";
           m_iptr[i] -> write(cout);
           cout << endl;
           totalAsset += m_iptr[i]->cost() * m_iptr[i]->quantity();
       }
    cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
    cout << "                               Total Asset: $  |       " << totalAsset << "|" << endl;
    cout << "-----------------------------------------------^--------------^" << endl;
}

void PosApp::addItem()
{
    if(m_nptr != MAX_NO_ITEMS)
    {
        Item* item = nullptr;
        bool flag = false;
        char type;
        cout << "Is the Item perishable? (Y)es/(N)o: ";
        cin >> type;
        if(type == 'y' || type == 'Y') {
            item = new Perishable();
        }
        else if(type == 'n' || type == 'N') {
            item = new NonPerishable();
        }
        while(item && !flag) {
            cin.ignore(10000, '\n');
            cin >> *item;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << item << ", try again..." << endl;
            }
            else {
                flag = true;
            }
        }
        m_iptr[m_nptr] = item;
        m_nptr++;
        cout << ">>>> DONE!................................................................." << endl;
    }
    else
    {
        cout << "Inventory Full!" << endl;
    }
}
void PosApp::removeItem()
{
    cout << "Running removeItem()" << endl;
}
void PosApp::stockItem()
{
    cout << "Running stockItem()" << endl;
}

void PosApp::POS()
{
    cout << "Running POS()" << endl;
}
void PosApp::saveRecs()
{
    ofstream output(m_filename);
    for (int i = 0; i < m_nptr; i++) {
        output << *m_iptr[i] << endl;
        }
    output.close();
}
void PosApp::loadRecs()
{
    ifstream input(m_filename);
    if (!input) {
        ofstream output(m_filename);
        output.close();
    }
    for (int i = 0; i < MAX_NO_ITEMS; i++) {
        m_iptr[i] = nullptr;
    }
    m_nptr = 0;
    
    char type;
    while (input >> type && m_nptr < MAX_NO_ITEMS) {
        input.ignore();
        Item* item = nullptr;
        if (type == 'N') {
            item = new NonPerishable();
        } else if (type == 'P') {
            item = new Perishable();
        }
        input >> *item;
        m_iptr[m_nptr] = item;
        m_nptr++;
    }
}
PosApp::PosApp(const char filename[])
{
    if(filename)
    {
        strcpy(m_filename, filename);
    }
}

}
