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
