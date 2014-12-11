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
    String(void);
    String(const String & s);
    String(const char * s);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    ~String(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    
    const  char* c_str(void) const; 
    size_t length() const;
    static const size_t max_size(void);
    size_t size() const;


    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================
	String& operator= (const char* s);
	String& operator= (char c);
        String& operator= (const String& str);
    
    // =======================================================================
    //                              Public Methods
    // =======================================================================
	bool Empty(void); 
	size_t capacity(void);
	void reserve(size_t n);
	void clear();
	void resize(int n, char c);
	const char& at(int p);
	String operator+ (const char*   rhs);
	String operator+ (const String& rhs);

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

