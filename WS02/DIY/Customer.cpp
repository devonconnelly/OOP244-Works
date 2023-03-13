// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Jan 20 2023
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"
#include <cstring>

namespace sdds {

void EmptyRecord(Customers& c_rec)
{
    strCpy(c_rec.user_name, "");
    c_rec.user_name[0] = '\0';
    c_rec.likes_count = 0;
    c_rec.replies_count = 0;
    c_rec.retweets_count = 0;
    c_rec.share_videos = '0';
    
}
void EmptyRecord(CustomersRecord& t_rec)
{
    t_rec.ptr_rec = NULL;
    t_rec.noOfRecords = 0;
}

void read(char* str, int len) {  // Fully provided
    if (cin.peek() == '\n') {
        cin.ignore();
    }
    cin.getline(str, len);
}

bool read(Customers& rec)
{
    char temp[21];
    int flag = 1;
    cout << " Enter User name: ";
    
    cin.getline(temp, 21);
    strCpy(rec.user_name, temp);
    if(strlen(rec.user_name) == 0)
    {
        flag = 0;
    }
    if(flag == 1)
    {
        cout << " Enter likes_count: ";
        cin >> rec.likes_count;
        cout << " Enter retweets_count: ";
        cin >> rec.retweets_count;
        cout << " Enter replies_count: ";
        cin >> rec.replies_count;
        cout << " Enter share videos (y/n): ";
        cin >> rec.share_videos;
        cin.ignore(10000, '\n');
    }
    
    return flag;
}

void addCustomer(CustomersRecord& t_rec, const Customers& c_rec)
{
    int temp = t_rec.noOfRecords + 1;
    Customers* buffer = new Customers[temp];
    
    for(int i = 0; i < t_rec.noOfRecords; i++)
    {
        buffer[i] = t_rec.ptr_rec[i];
    }
    
    buffer[t_rec.noOfRecords] = c_rec;
    delete[] t_rec.ptr_rec;
    t_rec.ptr_rec = buffer;
    t_rec.noOfRecords = temp;
}

void display(const Customers& c_rec)
{
    cout << c_rec.user_name << ", " << c_rec.likes_count << ", " << c_rec.retweets_count << ", " << c_rec.replies_count << ", " << c_rec.share_videos << endl;
}

void display(const CustomersRecord& t_rec)
{
    for(int i = 0; i < t_rec.noOfRecords; i++)
    {
        cout << i + 1 << ". ";
        display(t_rec.ptr_rec[i]);
        cout << endl;
    }
}
}

