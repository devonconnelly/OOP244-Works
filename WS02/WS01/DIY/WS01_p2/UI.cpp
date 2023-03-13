// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Jan 24 2023
#include <iostream>
#include "UI.h"
using namespace std;
namespace sdds
{
void UI(char* op, float* gpa)
{
    
    do {
        cout << "? ";
        cin >> *op;
        if(*op != '!')
        {
            cin >> *gpa;
        }
        if((*op != '~' && *op != '!' && *op != '<' && *op != '>'))
        {
            cout << "Syntax error: ? [Op][value]<ENTER>" << endl;
            cout << "Op: [>,<,~,!]" << endl;
            cout << "value: GPA value" << endl << endl;
        }
    } while((*op != '~' && *op != '!' && *op != '<' && *op != '>'));


}
}
