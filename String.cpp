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
  memcpy(data,s.data,s.length_);
  length_ = s.length_;
  capacity_ = s.capacity_;
}

//Constructor with a c_string
String::String(const char * s)            
{
  
  int i=0,l=0;
  while(s[i] != '\0')
    {
      l++;
      i++;
    }
  capacity_ =l+10;  //Initialization of capacity_ so that it's greater than length_
  if(capacity_>MAX_SIZE) // Capacity can't be greater than MAX_SIZE
    {
      printf("Warning : you've tried to create a string whith a capacity greater than the MAX_SIZE, please try again with a char * which size is < %d\n", MAX_SIZE);
      exit(EXIT_FAILURE);
    }
  data = new char[capacity_];
  memcpy(data,s,l);
  length_ = l;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
String::~String(void)
{
  delete [] data;
}

// ===========================================================================
//                               Non inline accessors
// ===========================================================================



// ===========================================================================
//                                 Public Methods
// ===========================================================================

bool String::Empty(void)                     // test if the string is empty
{
  if(length_==0)
    {
      return true;
    }
    else
    {
      return false;
    }
}


//--------------------------------------------------------------------------
void String::reserve(size_t n)              // increase the string capacity if n is greater than the current capacity
{
  if(n>MAX_SIZE)
    {
      printf("Warning : you've tried to call reserve with a number greater than the MAX_SIZE, please try again with a number < %d \n", MAX_SIZE);
      exit(EXIT_FAILURE);
    }
  int i;
  if(capacity_<n)
    {
      char* str = new char[n];
      memcpy(str,data,length_);
      delete data;
      data=str;
      capacity_=n;		
    }

}
//--------------------------------------------------------------------------
String& String::operator= (const char* s)       // affect a new value to data
{
  int i=0;    // i = size of s
  while(s[i]!='\0')         
    {
      i++;
    }
   
  if (capacity_<i)
    {
      if(i+10>MAX_SIZE)
	{
          printf("Warning : you've tried to affect a char* whith a size greater than the MAX_SIZE, please try again with a char * which size is < %d\n", MAX_SIZE-10);
          exit(EXIT_FAILURE);
	}
      this->reserve(i+10);   // Modification of capacity_ so that it's greater than i

    }
  this->clear();
  memcpy(this->data, s, i);
  length_ = i;
  return *this;
}

//--------------------------------------------------------------------------
void String::resize(int n, char c)             // resize the string
{
  int i;
  if(n>capacity_)
    {
      if(n+10>MAX_SIZE)
        {
           printf("Warning : you've tried to call resize with a number greater than the MAX_SIZE, please try again with a number < %d\n", MAX_SIZE-10);
           exit(EXIT_FAILURE);
	}
      reserve(n+10);       // Modification of capacity_ so that it's greater than n
    }
  if(n<length_)
    {
      for(i=n;i<length_;i++)
	{
	  data[i]='\0';
	}
    }
    
    else if(n>length_)
    {
      for(i=length_;i<n;i++)
	{
	  data[i]=c;
	}
    }
  length_ = n;
}

//--------------------------------------------------------------------------
String String::operator+ (const String& rhs)   // concatenates 2 strings
{
  int n = this->length_;
  if(rhs.length_+this->length_+10>MAX_SIZE)
    {
      printf("Warning : you've tried to increase data and the final length is greater than the MAX_SIZE, please try again so that it's  < %d\n", MAX_SIZE-10);
      exit(EXIT_FAILURE);
    }
  this->reserve(rhs.length_+this->length_+10);
  this->length_ += rhs.length_;
  int i;
  for(i=0;i<rhs.length_;i++)
    {
      this->data[n+i]=rhs.data[i];
    }
  return *this;
}


//----------------------------------------------------------------------------
void String::clear()                // Clear the data of the String, data becomes Null
{
  int i;
  for(i=0;i<length_;i++)
    {
      data[i] = '\0';
    }
  length_= 0;
}

//----------------------------------------------------------------------------
const char& String::at(int p) const      // gives the element at the pth place in the string
{
  if( (p<0) || (p>=length_) )
    {
      printf("Warning : out of range, you've tried with %d, please try again with a number between 0 and length = %d \n",p,length_);
      exit(EXIT_FAILURE);
    }
  return data[p];
}

//----------------------------------------------------------------------------
String& String::operator= (char c)   // affects a new char type value to data
{
  int i;
  for(i=0;i<length_;i++)
    {
      data[i] = '\0';
    }
  this->data[0]=c;
  length_= 1;
  return *this;
}

//----------------------------------------------------------------------------
String& String::operator= (const String& str)  // affects a new value to the String
{
 
  delete [] data;
  data  = new char[str.capacity_];
  length_=str.length_;
  memcpy(data, str.data, str.length_);
 
  return *this;
}


//----------------------------------------------------------------------------
String String::operator+ (const char*   rhs)      // concatenates data with a character
{
  int l=0, i=0;
  while(rhs[i]!='\0')
    {
      l++;
      i++;
    }
  if(this->length_+l>capacity_)
    { 
      if(length_+l+10>MAX_SIZE)
        {
          printf("Warning : you've tried to increase data and the final length is greater than the MAX_SIZE, please try again so that it's  < %d\n", MAX_SIZE-10);
          exit(EXIT_FAILURE);
        }
      reserve(length_+l+10);
    }
  for(i=this->length_;i<l+this->length_;i++)
    {
     
     this->data[i]=rhs[i-length_];

    }

  length_ +=l;
  return *this;
}

//----------------------------------------------------------------------------
char String::operator[](int p) const              // gives the element at the pth place in the string
{
  if(p<0 || p>=length_)
    {
      printf("out of range, you've tried with %d, please try again with a number between 0 and length = %d \n",p,length_);
      exit(EXIT_FAILURE);
    }
  return this->data[p];

}

String String::operator+(char rhs)
{

  if(this->length_+1>capacity_)
    { 
      if(length_+1+10>MAX_SIZE)
        {
          printf("Warning : you've tried to increase data and the final length is greater than the MAX_SIZE, please try again so that it's  < %d\n", MAX_SIZE-10);
          exit(EXIT_FAILURE);
        }
      reserve(length_+1+10); 
    }
  this->data[length_]= rhs;
  length_++;
  return *this;

}
