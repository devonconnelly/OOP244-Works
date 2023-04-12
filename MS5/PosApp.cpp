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
                else if(choice < 0 || choice > 5)
                    {
                        cout << "[0<=value<=5], retry: > ";
                        flag = false;
                    }
        }while(!flag);
        
        switch(choice)
        {
            case 1:
                listItems();
                break;
            case 2:
                addItem();
                break;
            case 3:
                removeItem();
                break;
            case 4:
                stockItem();
                break;
            case 5:
                POS();
                break;
        }
    }while(choice != 0);
    saveRecs();
    cout << ">>>> Saving Data............................................................." << endl << "Goodbye!" << endl;
}

void PosApp::listItems()
{
    cout << ">>>> Listing Items..........................................................." << endl;
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
    for (int i = 0; i < m_nptr; i++) {
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
    cout << ">>>> Adding Item to the store................................................" << endl;
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
        do {
            flag = true;
            cin.ignore(10000, '\n');
            cin >> *item;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << item << ", try again..." << endl;
                flag = false;
            }
        } while (!flag);
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
    int selected;
    cout << ">>>> Remove Item............................................................." << endl;
    selected = selectItem() - 1;
    cout << "Removing...." << endl;
    m_iptr[selected]->displayType(POS_FORM);
    cout << *m_iptr[selected];
    delete m_iptr[selected];
    m_iptr[selected] = nullptr;
    for(int i = selected; i < m_nptr - 1; i++) {
        m_iptr[i] = m_iptr[i + 1];
    }
    m_nptr--;
    cout << ">>>> DONE!................................................................." << endl;
}
void PosApp::stockItem()
{
    int selected;
    bool flag;
    int quantity;
    cout << ">>>> Select an item to stock................................................." << endl;
    selected = selectItem() - 1;
    cout << "Selected Item:" << endl;
    m_iptr[selected]->displayType(POS_FORM);
    cout << *m_iptr[selected];
    cout << "Enter quantity to add: ";
    do
    {
        cin >> quantity;
        flag = true;
        
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000,'\n');
                cout  << "Invalid Integer, try again: ";
                flag = false;
            }
            else if(quantity < 1 || quantity > m_nptr) {
                    cout << "[1<=value<=" << MAX_STOCK_NUMBER << "], retry: Enter quantity to add: ";
                    flag = false;
                }
    }while(!flag);
    *m_iptr[selected] += quantity;
    cout << ">>>> DONE!................................................................." << endl;
}

void PosApp::POS()
{
    char sku[MAX_SKU_LEN];
    int index = -1;
    double total = 0;
    Item* orders[MAX_NO_ITEMS];
    int numOrders = 0;
    cout << ">>>> Starting Point of Sale.................................................." << endl;
    cin.ignore(10000, '\n');
    do {
        cout << "Enter SKU or <ENTER> only to end sale..." << endl;
        do {
            cout << "> ";
            cin.getline(sku, MAX_NAME_LEN + 1);
            if(strlen(sku) > MAX_SKU_LEN) {
                cout << "SKU too long" << endl;
            }
        }while(strlen(sku) > MAX_SKU_LEN);
        if(strlen(sku) != 0)
        {
            for(int i = 0; i < m_nptr && index == -1; i++) {
                if(*m_iptr[i] == sku) {
                    index = i;
                }
            }
            if(index != -1) {
                if(m_iptr[index]->quantity() > 0) {
                    total += *m_iptr[index];
                    *m_iptr[index] -= 1;
                    m_iptr[index]->displayType(POS_FORM);
                    orders[numOrders++] = m_iptr[index];
                    cout << *m_iptr[index] << endl;
                    cout << ">>>>> Added to bill" << endl;
                    cout << ">>>>> Total: " << total << endl;
                    index = -1;
                }
                else
                {
                    cout << "Item out of stock" << endl;
                }
            }
            else
            {
                cout << "!!!!! Item Not Found !!!!!" << endl;
            }
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
    }while(strlen(sku) != 0 && !cin.fail());
    for(int i=0; i < numOrders; i++)
    {
        orders[i]->bprint(cout);
    }
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

int PosApp::selectItem()
{
    bool flag;
    int rowChoice;
    int i, j;
    double totalAsset = 0;
    for (i = 0; i < m_nptr - 1; i++)
           for (j = 0; j < m_nptr - i - 1; j++)
               if (*m_iptr[j] > *m_iptr[j+1]) {
                   Item* temp = m_iptr[j];
                   m_iptr[j] = m_iptr[j + 1];
                   m_iptr[j + 1] = temp;
               }
    cout << ">>>> Item Selection by row number............................................" << endl << "Press <ENTER> to start....";
    cin.ignore(10000, '\n');
    cin.get();
    cout << ">>>> Listing Items..........................................................." << endl;
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
    cout << "Enter the row number: ";
    do
    {
        cin >> rowChoice;
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
                if(rowChoice < 1 || rowChoice > m_nptr)
                {
                    cout << "[1<=value<=" << m_nptr << "], retry: Enter the row number: ";
                    flag = false;
                }
            }
    }while(!flag);
    return rowChoice;
}
}
