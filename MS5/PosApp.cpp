#include <iostream>
#include <fstream>
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
    cout << "Loading data from datafile.csv" << endl;
    
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
    cout << ">>>> Saving Data............................................................." << endl << "Saving data in datafile.csv" << endl << "Goodbye!" << endl;
}
void PosApp::addItem()
{
    cout << "Running addItem()" << endl;
}
void PosApp::removeItem()
{
    cout << "Running removeItem()" << endl;
}
void PosApp::stockItem()
{
    cout << "Running stockItem()" << endl;
}
void PosApp::listItems()
{
    cout << "Running listItems()" << endl;
}
void PosApp::POS()
{
    cout << "Running POS()" << endl;
}
ofstream& PosApp::saveRecs(ofstream& ofstr)
{
    
    return ofstr;
}
ifstream& PosApp::loadRecs(ifstream& ifstr)
{
    ifstream input(m_filename);
    if (!input.is_open()) {
        ofstream output(m_filename);
        output.close();
    }
    for (int i = 0; i < MAX_NO_ITEMS; i++) {
        delete m_iptr[i];
        m_iptr[i] = nullptr;
    }
    m_nptr = 0;
    
    char type;
    while (input >> type && m_nptr < MAX_NO_ITEMS) {
        Item* item = nullptr;
        if (type == 'N') {
            item = new NonPerishable();
        } else if (type == 'P') {
            item = new Perishable();
        }
        ifstr >> *item;
        m_iptr[m_nptr] = item;
        m_nptr++;
    }
    return ifstr;
}
PosApp::PosApp(const char filename[])
{
    
}
}
