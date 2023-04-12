// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: April 8 2023
template<typename valType>
bool validate(const valType& min, const valType* testArr, int arraySize, bool* results) {
    bool  valid = true;
    for (int i = 0; i < arraySize; i++)
    {
        results[i] = testArr[i] >= min;
        if(valid)
        {
            valid = results[i];
        }
    }
    
    return valid;
}
