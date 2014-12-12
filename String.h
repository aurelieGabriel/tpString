//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __STRING_H__
#define __STRING_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>



// ===========================================================================
//                                Project Files
// ===========================================================================




// ===========================================================================
//                              Class declarations
// ===========================================================================






class String
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    String(void);                            // constructor by default
    String(const String & s);                // constructor by copy
    String(const char * s);                  // constructor with a char* parameter

    // =======================================================================
    //                                Destructor
    // =======================================================================
    ~String(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    
    const  char* c_str(void) const;           // return the string data
    size_t length() const;                    // return the string length
    static const size_t max_size(void);       // return the string MAX_SIZE
    size_t size() const;                      // return the string size
	size_t capacity(void);                    // return the string capacity


    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================
	String& operator= (const char* s);         // affects a new char* to data
	String& operator= (char c);                // affects a new char to data
    String& operator= (const String& str);     // affects a new value to the String
    
    // =======================================================================
    //                              Public Methods
    // =======================================================================
	bool Empty(void);                          // test if the string is empty
	void reserve(size_t n);                    // increase the string capacity if n is greater than the current capacity
	void clear();                              // Clear the data of the String, data becomes Null
	void resize(int n, char c);                // resize the string
	const char& at(int p);                     // gives the element at the pth place in the string
	String operator+ (const char*   rhs);      // concatenates data with a character
	String operator+ (const String& rhs);      // concatenates 2 strings
	char operator[] (int p);                   // gives the element at the pth place in the string

    // =======================================================================
    //                             Public Attributes
    // =======================================================================
    




  public :

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    char * data;
    size_t length_;
    size_t capacity_;
    static const size_t MAX_SIZE;
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================

// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================



// ===========================================================================
//                          Inline functions' definition
// ===========================================================================



#endif // __STRING_H__

