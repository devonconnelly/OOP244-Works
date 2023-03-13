// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Mar 10 2023
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
   private:
      unsigned int countLines(const char* filename);
      void sort(double* collectionPtr, unsigned int size);
       void setEmpty();
       bool load();
       void save();
       double max() const;
       double min() const;
       double average() const;
       
       
       double *m_collection;
       char m_filename[255];
       unsigned int m_collectionSize;
       bool m_originalFlag;
       bool m_addedFlag;
       
   public:
       Numbers(const char filename[]);
       Numbers();
       ~Numbers();
       Numbers(const Numbers& numbers);
       Numbers& operator=(const Numbers& numbers);
       operator bool() const;
       void sort();
       Numbers& operator+=(double value);
       std::ostream& display(std::ostream& ostr = std::cout) const;
       
   };
std::ostream& operator<<(std::ostream& ostr, const Numbers& right);
std::istream& operator>>(std::istream& istr, Numbers& right);

}
#endif // !SDDS_NUMBERS_H_

