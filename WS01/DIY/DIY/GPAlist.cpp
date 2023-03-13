// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Jan 24 2023
#include <iostream>
#include <iomanip>
#include "GPAlist.h"
#include "UI.h"
#include "File.h"
#include "GPA.h"
using namespace std;
namespace sdds
{
bool gpaQuery(const char* filename)
{
    char op, endP;
    float value;
    int fileVal;
    GPA gpa[100];
    GPA temp;
    fileVal = importFile(gpa, filename);
    for(int i = 0; i < fileVal; i++)
    {
        for(int j = i + 1; j < fileVal; j++)
        {
            if(gpa[i].stno > gpa[j].stno)
            {
                temp = gpa[i];
                gpa[i] = gpa[j];
                gpa[j] = temp;
            }
        }
    }
    if(fileVal > 0)
    {
        cout << fixed << setprecision(1);
        cout << "Enter GPA query..." << endl;
        do {
            do {
                UI(&op, &value);
                int counter = 1;
                switch(op)
                {
                        
                    case '~':
                        for(int i = 0; i < fileVal; i++)
                        {
                            if(gpa[i].gpa <= value + 0.05 && gpa[i].gpa >= value - 0.05)
                            {
                                cout << "[" << counter << "] " << gpa[i].stno << ": " <<  gpa[i].gpa << " (" << gpa[i].name << ")" << endl;
                                counter++;
                            }
                        }
                        break;
                        
                    case '<':
                        for(int i = 0; i < fileVal; i++)
                        {
                            if(gpa[i].gpa < value)
                            {
                                cout << "[" << counter << "] " << gpa[i].stno << ": " << gpa[i].gpa << " (" << gpa[i].name << ")" << endl;
                                counter++;
                            }
                        }
                        break;
                        
                    case '>':
                        for(int i = 0; i < fileVal; i++)
                        {
                            if(gpa[i].gpa > value + 0.05)
                            {
                                cout << "[" << counter << "] " << gpa[i].stno << ": " << gpa[i].gpa << " (" << gpa[i].name << ")" << endl;
                                counter++;
                            }
                        }
                        break;
                        
                    default:
                        break;
                }
                
            }while(op != '!');
            
            cout << "Exit the program? (Y)es/(N)o: ";
            cin >> endP;
        }while(endP != 'y');
        
        
    }
    return fileVal != 0;
}
}

