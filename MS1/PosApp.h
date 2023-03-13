// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Mar 8 2023
#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_
namespace sdds
{
class PosApp
{
public:
    int menu(int choice);
    void addItem();
    void removeItem();
    void stockItem();
    void listItems();
    void POS();
    void saveRecs();
    void loadRecs();
    void run();
    PosApp(const char filename[]);
    
    
};
}
#endif
