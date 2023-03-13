// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TOOLS_H_
#define SDDS_TOOLS_H_

namespace sdds {
	int openFile_r(const char filename[]); // Provided
	void closefile(); // Provided
	int noOfTraces(); // Provided

	// ADD: Declare read prototypes (4 prototypes)

int read(char package[]);
int read(int& value);
int read(double& value);
int read(char& letter);
	





	void strCpy(char* des, const char* src); // Provided
	int strLen(const char* s); // Provided
}
#endif 
