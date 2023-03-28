#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include <iostream>
#include "POS.h"
#include "PosIO.h"
#include "Error.h"
namespace sdds
{
class Item: public PosIO
{
private:
    char m_SKU[MAX_SKU_LEN];
    char* m_name;
    double m_price;
    bool m_taxed;
    int m_quantity;
protected:
    int m_displayType;
    Error m_error;
public:
    Item();
    Item(const Item& source);
    Item& operator=(const Item& right);
    ~Item();
    bool operator==(const Item& right);
    bool operator==(const char sku[]);
    bool operator>(const Item& right);
    int operator+=(int value);
    int operator-=(int value);
    operator bool() const;
    virtual char itemType() const = 0;
    Item& displayType(int displayType);
    double cost() const;
    int quantity() const;
    Item& clear();
    std::ostream& write(std::ostream& ostr) const;
    std::istream& read(std::istream& istr);
    std::ofstream& save(std::ofstream& ofstr) const;
    std::ifstream& load(std::ifstream& ifstr);
    std::ostream& bprint(std::ostream& ostr);
    
};
double operator+=(double& total, Item& right);
}
#endif
