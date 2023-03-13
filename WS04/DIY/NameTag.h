// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Feb 14 2023
#ifndef NameTag_h
#define NameTag_h
namespace sdds
{
class NameTag
{
private:
    int m_extension;
    char* m_name;
public:
    void print();
    NameTag& read();
    NameTag();
    NameTag(const char* name);
    NameTag(const char* name, int ext);
    ~NameTag();
    
};
}

#endif /* NameTag_h */
