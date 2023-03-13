// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Feb 6 2023

#ifndef Toys_h
#define Toys_h
#define MAX_TNAME 31
namespace sdds
{
class Toys
{
private:
    char m_tName[MAX_TNAME];
    int m_sku;
    double m_price;
    int m_age;
    bool m_onSale = false;
public:
    void addToys(const char* tname, int sku, double price,int age);
    void isSale(bool sale);
    void calSale();
    void display()const;
    int getSku();
    void clear();
};
}




#endif /* Toys_h */
