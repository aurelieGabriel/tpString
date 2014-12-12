//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================
#include <string.h>


// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "String.h"




//############################################################################
//                                                                           #
//                           Class String                                    #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================
const size_t String::MAX_SIZE = 100;

// ===========================================================================
//                                 Private Methods
// ===========================================================================
int String::c_String_size(const char * s)
{
  int i=0, l=0;
  while(s[i]!='\0')
    {
      l++;
      i++;
    }
  return l;
} 

// ===========================================================================
//                                  Constructors
// ===========================================================================

// Default constructor
String::String(void)                      
{
  capacity_ = 4;
  length_ = 0;
  data = new char[capacity_];
  
}



// Copy constructor
String::String(const String &s)          
{
  
  data = new char[s.capacity_];

  // Copy s.data into this->data
  memcpy(data,s.data,s.length_);

  length_ = s.length_;
  capacity_ = s.capacity_;
}



// Constructor with a c_string
String::String(const char * s)            
{
  // Calculate the size of s and put it in length_
  int l = c_String_size(s);
  length_ = l;

  //Initialize capacity_ so that it's greater than length_
  capacity_ =l+10;  

  // Test if capacity_ is greater than MAX_SIZE, failure if it is
  if(capacity_>MAX_SIZE)
    {
      printf("Warning : you've tried to create a string whith a capacity greater than the MAX_SIZE, please try again with a char * which size is < %d\n", MAX_SIZE);
      exit(EXIT_FAILURE);
    }

  //Initialize data
  data = new char[capacity_];
  
  //Copy s in data
  memcpy(data,s,l);
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
String::~String(void)
{
  delete [] data;
}


// ===========================================================================
//                                 Public Methods
// ===========================================================================

bool String::Empty(void)   
{
  if(length_==0)
    {
      return true;
    }
  return false;
}



void String::reserve(size_t n)              
{
  // Test if n is greater than MaX_SIZE, failure if it is
  if(n>MAX_SIZE)
    {
      printf("Warning : you've tried to call reserve with a number greater than the MAX_SIZE, please try again with a number < %d \n", MAX_SIZE);
      exit(EXIT_FAILURE);
    }

  // Increase the capacity 
  if(capacity_<n)
    {
      // Copy this->data in a char * which "capacity" is n
      char* str = new char[n];
      memcpy(str,data,length_);
      
      // Replace data
      delete data;
      data=str;

      // Set capacity_
      capacity_=n;		
    }

}



void String::resize(int n, char c)          
{
  int i;

  // Test if n is greater than capacity_
  if(n>capacity_)
    {
      // Test if n+10 is greater than MAX_SIZE, failure if it is
      if(n+10>MAX_SIZE)
        {
           printf("Warning : you've tried to call resize with a number greater than the MAX_SIZE, please try again with a number < %d\n", MAX_SIZE-10);
           exit(EXIT_FAILURE);
	}

      // Modify capacity_ so that it's greater than n
      reserve(n+10);       
    }

  // Up to the n_th position, set the characters to '\0' to decrease length_ to n
  if(n<length_)
    {
      for(i=n;i<length_;i++)
	{
	  data[i]='\0';
	}
    }
    
  // Add n-length_ times the character c to increase length_ to n
  else if(n>length_)
    {
      for(i=length_;i<n;i++)
	{
	  data[i]=c;
	}
    }

  // Set length_ to n
  length_ = n;
}



void String::clear()        
{
  int i;
  
  // Set every character of this->data to '\0'
  for(i=0;i<length_;i++)
    {
      data[i] = '\0';
    }

  length_= 0;
}



const char& String::at(int p) const    
{
  // Test if p is out of range, failure if it is
  if( (p<0) || (p>=length_) )
    {
      printf("Warning : you've tried to get the element %d which is out of range, please try again with a number between 0 and length-1 = %d \n",p,length_-1);
      exit(EXIT_FAILURE);
    } 
  
  // Return the character at the p_th position
  return data[p];
}




// ===========================================================================
//                               Operators
// ===========================================================================

String String::operator+ (const String& rhs)   
{
  int n = this->length_;

  // Test if MAX_SIZE is exceeded, failure if it is
  if(rhs.length_+this->length_+10>MAX_SIZE)
    {
      printf("Warning : you've tried to increase data and the final length is greater than the MAX_SIZE, please try again so that it's  < %d\n", MAX_SIZE-10);
      exit(EXIT_FAILURE);
    }
  
  // Increases capacity_ so that it's greater than the new length_
  this->reserve(rhs.length_+this->length_+10);

  // Calculate the new length_
  this->length_ += rhs.length_;
  int i;

  // Add the new characters to this->data
  for(i=0;i<rhs.length_;i++)
    {
      this->data[n+i]=rhs.data[i];
    }

  return *this;
}



String String::operator+ (const char*   rhs)      
{
  // Calculate the size of rhs
  int l = c_String_size(rhs);

  // Test if capacity_ is excedeed when adding rhs t
  if(this->length_+l>capacity_)
    { 
      // Test if MAX_SIZE is exceeded, failure if it is
      if(length_+l+10>MAX_SIZE)
        {
          printf("Warning : you've tried to increase data and the final length is greater than the MAX_SIZE, please try again so that it's  < %d\n", MAX_SIZE-10);
          exit(EXIT_FAILURE);
        }
      
      // Increase capacity_ so that it's greater than the new length_
      reserve(length_+l+10);
    }
  
  // Add the characters to this->data
  int i;
  for(i=this->length_;i<l+this->length_;i++)
    {
     this->data[i]=rhs[i-length_];

    }
  
  // Calculate the new length_
  length_ +=l;

  return *this;
}



String& String::operator= (const String& str)  
{
  delete [] data;
  
  // Affect str.data to this->data
  data  = new char[str.capacity_];
  
  // Replace length_
  length_=str.length_;
  
  // Copy str.data into this->data
  memcpy(data, str.data, str.length_);
 
  return *this;
}



String& String::operator= (const char* s)     
{
  // Calculate the size of s
  int l = c_String_size(s);

  //  Test if l is greater than capacity_
  if (capacity_<l)
    {
      // Test if MAX_SIZE is exceeded, failure if it is
      if(l+10>MAX_SIZE)
	{
          printf("Warning : you've tried to affect a char* whith a size greater than the MAX_SIZE, please try again with a char * which size is < %d\n", MAX_SIZE-10);
          exit(EXIT_FAILURE);
	}
      
      // Set capacity_ so that it's greater than the new length_
      this->reserve(l+10);   

    }
  
  // Clear this->data
  this->clear();
  
  // Copy s in this->data
  memcpy(this->data, s, l);

  // Set length_
  length_ = l;

  return *this;
}



String String::operator+(char rhs)
{
  // Test if capacity_ is exceeded
  if(this->length_+1>capacity_)
    { 
      // Test if MAX_SIZE is exceeded, failure if it is
      if(length_+1+10>MAX_SIZE)
        {
          printf("Warning : you've tried to increase data and the final length is greater than the MAX_SIZE, please try again so that it's  < %d\n", MAX_SIZE-10);
          exit(EXIT_FAILURE);
        }
      
      // Increase capacity_ so that it's greater than the new length_
      reserve(length_+1+10); 
    }
  
  // Add the character to this->data
  this->data[length_]= rhs;
  
  // Set length_
  length_++;


  return *this;
}



String& String::operator= (char c)
{
  int i;
  
  // Clear this->data
  this->clear();
  
  // Put the character c in positin 0
  this->data[0]=c;

  // Set length_
  length_= 1;

  return *this;
}



char String::operator[](int p) const             
{
  // Test if p is out of range, failure if it is
  if(p<0 || p>=length_)
    {
      printf("Warning : you've tried to get the element %d which is out of range, please try again with a number between 0 and length-1 = %d \n",p,length_-1);
      exit(EXIT_FAILURE);
    }

  // Return the character in the p_th position
  return this->data[p];
}

