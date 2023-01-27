/***********************************************************************
// OOP244 Workshop 2 p1: tester program
//
// File    main.cpp
// Version 1.0
// Date Fall 2022
// Author  Yosef Ashibani
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

// Please don't change this file
// This file is to test your full program

#include<iostream>
#include "Package.h"

using namespace std;
using namespace sdds;
const bool APP_OS_WINDOWS = true;

int main() {
    
    loadTraces();
    cout << "Records were retrieved successfully" << endl;

    grouptTraces();
    cout << "Data records were grouped by the user id successfully" << endl;

    cout<< "User id, timeinhours, Fctime, Fwifitime, Package Name" << endl
        << "....................................................." << endl;

    display();
    cout << "\nData was successfully printed" << endl;
    
    deallocateMemory();
    cout << "Dynamically allocated memory was successfully deallocated"<<endl;
    return 0;
}

