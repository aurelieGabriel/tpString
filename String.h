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
    size_t length() const;
    static const size_t max_size(void);

    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
	bool Empty(void); 
	size_t capacity(void);

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

