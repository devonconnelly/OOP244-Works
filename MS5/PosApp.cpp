#include "PosApp.h"
#include <iostream>
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
void PosApp::saveRecs()
{
    
}
void PosApp::loadRecs()
{
    
}
PosApp::PosApp(const char filename[])
{
    
}
}
