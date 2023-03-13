// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "Tools.h"
#include "Package.h"

FILE* fp;

namespace sdds {
    int openFile_r(const char filename[]) { // Fully provided
        fp = fopen(filename_r, "r");
        return fp != NULL;
    }
    int noOfTraces() {  // Fully provided
        int noOfTraces = 0;
        char ch;
        while (fscanf(fp, "%c", &ch) == 1) {
            noOfTraces += (ch == '\n');
        }
        rewind(fp);
        return noOfTraces;
    }
    

    // To Do: read functions (4 overloaded read functions)
int read(char package[])
{
    int val = 0;
    char temp[60];
    val = fscanf(fp, "%60[^\n]\n", temp);
    strCpy(package, temp);
    return val;
}

int read(int& value)
{
    double number = 0, temp = 0;
    number = fscanf(fp, "%lf,", &temp);
    if(number == 1)
    {
        value = temp;
    }
    return number;
}

int read(double& value)
{
    double number = 0, temp = 0;
    number = fscanf(fp, "%lf,", &temp);
    if(number == 1)
    {
        value = temp;
    }
    return number;
}

int read(char& letter)
{
    int val;
    val = fscanf(fp, "%[^ \t\n\r\v\f,]%*c", &letter);
    return val;
}

    void closefile() { // Fully provided
        if (fp) fclose(fp);
    }
    
    void strCpy(char* str1, const char* str2) { // Fully provided 
        while (*str2) {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
    int strLen(const char* str) {  // Fully provided
        int i = -1;
        while (str[++i]);
        return i;
    }
}
