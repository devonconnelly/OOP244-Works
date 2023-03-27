#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Item.h"
using namespace std;
namespace sdds
{
Item::Item() {
    m_SKU[0] = '\0';
    m_name = nullptr;
    m_price = 0;
    m_taxed = false;
    m_quantity = 0;
}

Item::Item(const Item &source) {
    *this = source;
}

sdds::Item &Item::operator=(const Item &right) {
    if(this != &right)
    {
        strcpy(m_SKU, right.m_SKU);
        delete[] m_name;
        m_name = new char[strlen(right.m_name) + 1];
        strncpy(m_name, right.m_name, strlen(right.m_name) + 1);
        m_price = right.m_price;
        m_taxed = right.m_taxed;
        m_quantity = right.m_quantity;
        m_displayType = right.m_displayType;
        m_error = right.m_error;
    }
    return *this;
}

Item::~Item() {
    delete[] m_name;
}

bool Item::operator==(const Item &right) {
    return strcmp(m_SKU, right.m_SKU);
}

bool Item::operator==(const char sku[]) {
    return !strcmp(m_SKU, sku);
}

bool Item::operator>(const Item &right) {
    return m_name > right.m_name;
}

int Item::operator+=(int value) {
    m_quantity += value;
    if(m_quantity > MAX_STOCK_NUMBER)
    {
        m_quantity = MAX_STOCK_NUMBER;
        m_error = ERROR_POS_QTY;
    }
    return m_quantity;
}

int Item::operator-=(int value) {
    m_quantity -= value;
    if(m_quantity < 0)
    {
        m_quantity = 0;
        m_error = ERROR_POS_STOCK;
    }
    
    return m_quantity;
}

Item::operator bool() const {
    return !m_error;
}

Item& Item::displayType(int displayType) {
    if(displayType == POS_LIST)
    {
        m_displayType = POS_LIST;
    }
    else if(displayType == POS_FORM)
    {
        m_displayType = POS_FORM;
    }
    return *this;
}

double Item::cost() const {
    return m_taxed ? m_price + (m_price * TAX) : m_price;
}

int Item::quantity() const {
    return m_quantity;
}

Item& Item::clear() {
    m_error.clear();
    return *this;
}

std::ostream& Item::write(std::ostream &ostr) const {
    if(!m_error)
    {
        if(m_displayType == POS_LIST)
        {
            char name[100];
            strcpy(name, m_name);
            name[20] = '\0';
            ostr << setw(7) << left << m_SKU << "|";
            ostr << setw(20) << left << name << "|";
            ostr << setw(7) << fixed << setprecision(2) << right << m_price << "|";
            ostr << " " << (m_taxed ? "X" : " ") << " |";
            ostr << setw(4) << right << m_quantity << "|";
            ostr << setw(9) << fixed << setprecision(2) << right << cost() * quantity() << "|";
        }
        else
        {
            ostr << "=============v" << endl;
            ostr << "Name:        " << m_name << endl;
            ostr << "Sku:         " << m_SKU << endl;
            ostr << "Price:       " << m_price << endl;
            ostr << "Price + tax: ";
            if(m_taxed == true)
            {
                ostr << cost();
            }
            else
            {
                ostr << "N/A";
            }
            ostr << endl;
            ostr << "Stock Qty:   " << m_quantity << endl;
        }
    }
    if(m_error)
    {
        cerr << m_error;
    }
    return ostr;
}

std::istream& Item::read(std::istream &istr) {
    char tax;
    cout << "Sku" << endl;
    do {
        cout << "> ";
        istr.getline(m_SKU, MAX_NAME_LEN + 1);
        if(strlen(m_SKU) > MAX_SKU_LEN)
        {
            cout << "SKU too long" << endl;
        }
    } while(strlen(m_SKU) > MAX_SKU_LEN);
    char buffer[200];
    cout << "Name" << endl;
    do {
        if(istr.fail())
        {
            istr.clear();
        }
        cout << "> ";
        istr.getline(buffer, 200, '\n');
        if(strlen(buffer) > MAX_NAME_LEN)
        {
            cout << "Item name too long" << endl;
        }
        else
        {
            if(m_name) {
                delete[] m_name;
            }
            m_name = new char[MAX_NAME_LEN + 1];
            strncpy(m_name, buffer, MAX_NAME_LEN);
            m_name[MAX_NAME_LEN] = '\0';
        }
    } while(strlen(buffer) > MAX_NAME_LEN || istr.fail());
    cout << "Price" << endl;
    do {
        if(istr.fail())
        {
            istr.clear();
            istr.ignore(10000, '\n');
        }
        cout << "> ";
        istr >> m_price;
        if(istr.fail() || m_price < 0)
        {
            cout << "Invalid price value" << endl;
        }
    } while(istr.fail() || m_price < 0);
    cout << "Taxed?" << endl;
    cout << "(Y)es/(N)o: ";
    istr.ignore();
    do {
        istr.get(tax);
        istr.ignore(10000, '\n');
        if(tax != 'y' && tax != 'n' && tax != 'N' && tax != 'Y')
        {
            cout << "Only 'y' and 'n' are acceptable: ";
        }
    } while(tax != 'y' && tax != 'n' && tax != 'N' && tax != 'Y');
    if(tax == 'y' || tax == 'Y')
    {
        m_taxed = true;
    }
    else
    {
        m_taxed = false;
    }
    cout << "Quantity" << endl;
    do {
        if(istr.fail())
        {
            istr.clear();
            istr.ignore(10000, '\n');
        }
        cout << "> ";
        istr >> m_quantity;
        if(m_quantity > MAX_STOCK_NUMBER || m_quantity < 1 || istr.fail())
        {
            cout << "Invalid quantity value" << endl;
        }
    } while(m_quantity > MAX_STOCK_NUMBER || m_quantity < 1 || istr.fail());
    return istr;
}

std::ofstream& Item::save(std::ofstream &osftr) const {
    osftr << itemType() << ',';
    osftr << m_SKU << ',' << m_name << ',' << fixed << setprecision(2) << m_price << ',' << m_taxed << ',' << m_quantity;
    if(m_error)
    {
        cerr << m_error << endl;
    }
    return osftr;
}

std::ifstream& Item::load(std::ifstream &ifstr) {
    m_error.clear();
    char SKU[100];
    char name[100];
    double price;
    int quantity;
    int taxed = 0;
    
    ifstr.getline(SKU, 100, ',');
    if (ifstr.fail() || strlen(SKU) > MAX_SKU_LEN)
    {
        m_error = ERROR_POS_SKU;
    }
    ifstr.getline(name, 100, ',');
    if (!m_error && (ifstr.fail() || strlen(name) > MAX_NAME_LEN))
    {
        m_error = ERROR_POS_NAME;
    }
    ifstr >> price;
    ifstr.ignore();
    ifstr >> taxed;
    ifstr.ignore();
    ifstr >> quantity;

    if(!m_error)
    {
        if (!ifstr.fail())
        {
            if (price < 0)
            {
                m_error = ERROR_POS_PRICE;
            }
            else if (taxed != 0 && taxed != 1)
            {
                m_error = ERROR_POS_TAX;
            }
            else if (quantity < 0 || quantity > MAX_STOCK_NUMBER)
            {
                m_error = ERROR_POS_QTY;
            }
            else
            {
                strcpy(m_SKU, SKU);
                if (m_name != nullptr)
                {
                    delete[] m_name;
                }
                m_name = new char[strlen(name) + 1];
                strcpy(m_name, name);
                
                m_price = price;
                m_quantity = quantity;
                m_taxed = taxed == 1;
                
            }
        }
    }
    return ifstr;
}

std::ostream& Item::bprint(std::ostream& ostr) {
    char name[100];
    strcpy(name, m_name);
    name[20] = '\0';
    ostr << "| " << setw(20) << left << name << "|";
    ostr << setw(10) << fixed << setprecision(2) << right << cost() << " | ";
    ostr << " " << (m_taxed ? "T" : " ") << "  |" << endl;
    return ostr;
}
double operator+=(double& total, Item& right) {
    total += right.cost() * right.quantity();
    return total;
}
}
