// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Mar 10 2023
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Numbers.h"
using namespace std;
namespace sdds {
void Numbers::sort(double* nums, unsigned int size) {
    unsigned int i, j;
    double temp;
    for(i = size - 1; size && i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(nums[j] > nums[j + 1]) {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

unsigned int Numbers::countLines(const char* filename) { /**/
    unsigned int lines = 0u;
    ifstream nums(filename);
    while(nums) {
        lines += (nums.get() == '\n');
    }
    return lines;
}
Numbers::Numbers(const char filename[])
{
    setEmpty();
    if(filename)
    {
        strcpy(m_filename, filename);
        load();
    }
}
Numbers::Numbers()
{
    setEmpty();
}
Numbers::~Numbers()
{
    if(m_collection)
    {
        if(m_collection[0] == (double) -5)
        {
            save();
        }
    }
    delete[] m_collection;
}
Numbers::Numbers(const Numbers& numbers)
{
    this->setEmpty();
    *this = numbers;
}
Numbers& Numbers::operator=(const Numbers& numbers)
{
    if(this != &numbers)
    {
        save();
        delete[] m_collection;
        this->setEmpty();
        if(numbers)
        {
            strcpy(m_filename, numbers.m_filename);
            m_originalFlag = false;
            m_collection = new double[numbers.m_collectionSize];
            for(unsigned int i = 0; i < numbers.m_collectionSize; i++)
            {
                m_collection[i] = numbers.m_collection[i];
            }
            m_collectionSize = numbers.m_collectionSize;
        }
    }
    return *this;
    
}

void Numbers::setEmpty()
{
    m_collectionSize = 0;
    m_originalFlag = false;
    m_addedFlag = false;
    m_collection = 0;
    m_filename[0] = '\0';
}

bool Numbers::load()
{
    unsigned int size = 0;
    double val = 0;
    if(m_collection != nullptr)
    {
        delete[] m_collection;
    }
    unsigned int numLines = countLines(m_filename);
    if(numLines > 0)
    {
        m_collection = new double[numLines];
        ifstream file(m_filename);
        
        while(file >> val)
        {
            m_collection[size++] = val;
        }
        file.close();
        if(numLines != size)
        {
            delete[] m_collection;
            setEmpty();
        }
        else
        {
            m_collectionSize = numLines;
            m_originalFlag = true;
        }
    }
    return numLines > 0;
}

void Numbers::save()
{
    if(m_originalFlag && m_collectionSize > 0)
    {
        ofstream file(m_filename);
        file << fixed << setprecision(2);
        for(unsigned int i = 0; i < m_collectionSize; i++)
        {
            file << m_collection[i] << endl;
        }
        file.close();
    }
}

double Numbers::max() const
{
    double max = m_collection[0];
    for(unsigned int i = 1; i < m_collectionSize; i++)
    {
        if(m_collection[i] > max)
        {
            max = m_collection[i];
        }
    }
    return max;
}

double Numbers::min() const
{
    double min = m_collection[0];
    for(unsigned int i = 1; i < m_collectionSize; i++)
    {
        if(m_collection[i] < min)
        {
            min = m_collection[i];
        }
    }
    return min;
}

double Numbers::average() const
{
    double avg = 0;
    for(unsigned int i = 0; i < m_collectionSize; i++)
    {
        avg += m_collection[i];
    }
    return avg / m_collectionSize;
}
Numbers::operator bool() const
{
    return m_collection != nullptr;
}
void Numbers::sort()
{
    sort(m_collection, m_collectionSize);
}
Numbers& Numbers::operator+=(double value)
{
    if(*this)
    {
        double *buffer = new double[m_collectionSize + 1];
        for(unsigned int i = 0; i < m_collectionSize; i++)
        {
            buffer[i] = m_collection[i];
        }
        buffer[m_collectionSize] = value;
        delete[] m_collection;
        m_collection = buffer;
        ++m_collectionSize;
    }
    return *this;
}
std::ostream& Numbers::display(std::ostream& ostr) const
{
    if(!*this)
    {
        ostr << "Empty list";
    }
    else
    {
        ostr << fixed << setprecision(2);
        if(!m_originalFlag)
        {
            ostr << "Copy of ";
        }
        ostr << m_filename << endl;
        for(unsigned int i = 0; i < m_collectionSize; i++)
        {
            ostr << m_collection[i];
            if(i + 1 != m_collectionSize)
            {
                ostr << ", ";
            }
        }
        ostr << endl << string(76, '-') << endl;
        ostr << "Total of " << m_collectionSize << " number(s), Largest: " << max() << ", Smallest: " << min() << ", Average: " << average();
        ostr << endl << string(76, '=');
    }
    return ostr;
}

ostream& operator<<(ostream& ostr, const Numbers& right)
{
    right.display(ostr);
    return ostr;
}
istream& operator>>(istream& istr, Numbers& right)
{
    double temp = 0;
    istr >> temp;
    right += temp;
    return istr;
}

}
