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
const size_t String::MAX_SIZE = 50;

// ===========================================================================
//                                  Constructors
// ===========================================================================
String::String(void)
{
  capacity_ = 4;
  length_ = 0;
  data = new char[capacity_];
}
//--------------------------------------------------------------------------
String::String(const String &s)
{
  
  data = new char[s.capacity_];
  memcpy(data,s.data,s.length_);
  length_ = s.length_;
  capacity_ = s.capacity_;
}
//--------------------------------------------------------------------------
String::String(const char * s)
{
  capacity_ = 20;
  int i=0,l=0;
  while(s[i] != '\0')
    {
      l++;
      i++;
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
}

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
void String::reserve(size_t n)         // increase the string capacity if n is greater than the current capacity
{
	int i;
	if(capacity_<n)
	{
		char* str = new char[capacity_+n];
		memcpy(str,data,length_);
		delete data;
		data=str;
		capacity_+=n;		
	}
}
//--------------------------------------------------------------------------
String& String::operator= (const char* s)       // affect a new value to data
{
	int i=0;
	while(s[i]!='\0')          // '\0' better than NULL
	{
		i++;
	}
	// i = size of s
	if (capacity_<i)
	{
		this->reserve(i);
	}
	memcpy(this->data, s, i);
	length_ = i;
	return *this;
}


void String::resize(int n, char c)
{
  int i;
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
	  data[i]='c';
	}
    }
  length_ = n;
}


//----------------------------------------------------------------------------
//Clear the data of the String, data becomes Null
//----------------------------------------------------------------------------
void String::clear()
{
  data = "\0";
  length_= 0;

const char& String::at(int p)
{
  return data[p];
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================

size_t String::length() const
{
  return length_;
}

size_t String::size() const
{
  return length_;
}

const  char* String::c_str(void) const   
 {
   return data;
 }

size_t String::capacity(void)             // return the string capacity
{
	return capacity_;
}


const size_t String::max_size(void)
{
  return MAX_SIZE;
}
