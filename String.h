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
    
    inline const  char* c_str(void) const;          
    inline size_t length() const;                   
    inline static const size_t max_size(void);      
    inline size_t size() const;                      
    inline size_t capacity(void);                    


    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================
    String& operator= (const char* s);         // affects a new char* to this->data
    String& operator= (char c);                // affects a new char to this->data
    String& operator= (const String& str);     // affects a new String to this
    String operator+ (const char*   rhs);      // adds a a char * to this->data
    String operator+ (const String& rhs);      // adds a String to this
    String operator+ (char rhs);               // adds a character to this->data
    char operator[] (int p) const;             // gives the element at the p_th place in this->data
    
    // =======================================================================
    //                              Public Methods
    // =======================================================================
    bool Empty(void);                          // tests if the string is empty
    void reserve(size_t n);                    // increases the string capacity if n is greater than the current capacity
    void clear();                              // clears this->data setting every character to '\0'
    void resize(int n, char c);                // resizes the string by increasing to n characters (by adding c) or remove characters
                                               // if n<length_
    const char& at(int p) const;               // gives the element at the p_th place in this->data
    


  private :

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
inline size_t String::length() const                
{
  return length_;
}

inline size_t String::size() const                  
{
  return length_;
}

inline const  char* String::c_str(void) const       
 {
   return data;
 }

inline size_t String::capacity(void)                
{
  return capacity_;
}

inline const size_t String::max_size(void)         
{
  return MAX_SIZE;
}
// ===========================================================================
//                              Setters' definitions
// ===========================================================================



#endif // __STRING_H__

