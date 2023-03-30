class Error {
   char* m_message;
public:
   Error() = default;
   Error& operator(const char* message);
};



int foo() {
   Error err;

   // overloading the assignment operator for Error
   err = nullptr; // set the error to a no error state m_message = nullptr

   err = "";  // set the m_message to nullptr and to a no error state

   cout << err << endl; // this should print nothing (only newline)

   err = "Invalid Date";  // will in an Error state

   cout << err << endl; // this should print 'Invalid Date' and newline

}