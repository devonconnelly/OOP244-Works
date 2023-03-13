
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;
namespace sdds {


//fully provided for students to display details of a project
void display(const Project& project) {
    cout << "Project " << project.m_topic
    << " will cost a total of " << project.m_cost << " C$." << endl;
}

//fully provided for students to display details of a department
void display(const Department& department) {
    Project* temp = department.fetchProjects();
    int projects = department.fetchNumProjects();
    cout << "Department " << department.fetchName() << " details:" << endl;
    cout << "Budget: " << department.fetchBudget()
    << " and the number of projects in progress is: " << projects << endl;
    cout << "Below are the details of the projects we are currently working on: " << endl;
    for (int i = 0; i < projects; i++) {
        display(temp[i]);
    }
}

void Department::updateName(const char* newname)
{
    if(newname != NULL && newname[0] != '\0')
    {
        if(m_name != NULL)
        {
            delete[] m_name;
            m_name = NULL;
        }
        m_name = new char[strlen(newname) + 1];
        strcpy(m_name, newname);
    }
}

void Department::updateBudget(double change)
{
    m_budget += change;
}

bool Department::addProject(Project &np)
{
    double totalCost = 0;
    double budget = fetchBudget();
    bool flag = false;
    int temp = m_numProjects + 1;
    totalCost = totalexpenses() + np.m_cost;
    if (totalCost <= budget)
    {
        flag = true;
        Project* buffer = new Project[temp];
        for (int i = 0; i < m_numProjects; i++)
        {
            buffer[i] = m_dProjects[i];
        }
        buffer[m_numProjects] = np;
        delete[] m_dProjects;
        m_dProjects = buffer;
        m_numProjects++;
    }
    else
    {
        flag = false;
    }
    
    return flag;
}


void Department::createDepartment(const char* newname, Project& newproject, double change)
{
    updateName(newname);
    addProject(newproject);
    updateBudget(change);
}

Project* Department::fetchProjects() const
{
    return m_dProjects;
}

int Department::fetchNumProjects() const
{
    return m_numProjects;
}

double Department::fetchBudget() const
{
    return m_budget;
}

char* Department::fetchName()const
{
    return m_name;
}

double Department::totalexpenses()
{
    double totalCost = 0;
    int numProjects = fetchNumProjects();
    for (int i = 0; i < numProjects; i++)
    {
        totalCost += m_dProjects[i].m_cost;
    }
    return totalCost;
}

double Department::remainingBudget()
{
    return m_budget - totalexpenses();
}

void Department::clearDepartment()
{
    delete[] m_name;
    m_name = NULL;
    delete[] m_dProjects;
    m_dProjects = NULL;
}
}

