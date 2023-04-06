#ifndef SDDS_ERROR_H_
#define SDDS_ERROR_H_
namespace sdds
{

class Error {
private:
    char* m_errorMessage;
public:
    Error();
    Error(const Error& source);
    Error(const char* errorMessage);
    Error& operator=(const Error& source);
    Error& operator=(const char* cString);
    ~Error();
    operator bool() const;
    Error& clear();
    char* getErrorMessage() const;
};
std::ostream& operator<<(std::ostream& ostr, const Error& right);
}
#endif

