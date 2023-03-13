// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Jan 24 2023
#include<iostream>
#include<cstdio>
#include "File.h"
#include"GPA.h"
namespace sdds
{
FILE* fp;

void closeFile()
{
    if (fp) fclose(fp);
}

bool openFile(const char filename[])
{
    fp = fopen(filename, "r");
    return fp != NULL;
}

int importFile(GPA gpa[], const char filename[])
{
    int i = 0, count = 0;
    if(openFile(filename))
    {
        while(fscanf(fp, "%[^,],%d,%lf\n", gpa[i].name, &gpa[i].stno, &gpa[i].gpa) != EOF)
        {
            i++;
            count++;
        }
    }
    closeFile();
    return count;
    
}
}
