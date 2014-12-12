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
    
    // Affect a new char* to this->data
    String& operator= (const char* s);    

    // Affect a new char to this->data
    String& operator= (char c);                

    // Affect a new String to this
    String& operator= (const String& str);    

    // Add a char * to this->data
    String operator+ (const char*   rhs);  

    // Add a String to this
    String operator+ (const String& rhs);    

    // Add a character to this->data
    String operator+ (char rhs);               

    // Return the element at the p_th position in this->data
    char operator[] (int p) const;            
    

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    
    // Test if the string is empty
    bool Empty(void);             

    // Increase the String capacity if n is greater than the current capacity
    void reserve(size_t n);              

    // clear this->data by setting every character to '\0'
    void clear();   

    // Resize the String by increasing to n characters (by adding c) or removing characters if n<length_
    void resize(int n, char c);            

    // Return the element at the p_th position in this->data
    const char& at(int p) const;               
    

  private :
    // ===========================================================================
    //                                 Private Methods
    // ===========================================================================
    
    // Calculate the size of a c_String
    int c_String_size(const char * s);

    // =======================================================================
    //                             Private Attributes
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



#endif // __STRING_H__

