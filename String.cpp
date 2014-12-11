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
  
  int i=0,l=0;
  while(s[i] != '\0')
    {
      l++;
      i++;
    }
  capacity_ =l+10;  //Initialization of capacity_ so that it's greater than length_
  if(capacity_>MAX_SIZE)
    {
      printf("Warning : your capacity is greater than the MAX_SIZE, try with a char * which size < %d\n", MAX_SIZE);
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
}

// ===========================================================================
//                               Non inline accessors
// ===========================================================================

size_t String::length() const           // return the string length
{
  return length_;
}
//--------------------------------------------------------------------------
size_t String::size() const              // return the string size
{
  return length_;
}
//--------------------------------------------------------------------------
const  char* String::c_str(void) const    // return the string data
 {
   return data;
 }
//--------------------------------------------------------------------------
size_t String::capacity(void)             // return the string capacity
{
	return capacity_;
}
//--------------------------------------------------------------------------
const size_t String::max_size(void)          // return the string MAX_SIZE
{
  return MAX_SIZE;
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
  if(capacity_>MAX_SIZE)
    {
      printf("Warning : your capacity is greater than the MAX_SIZE, try with a number < %d \n", MAX_SIZE);
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
	int i=0;
	while(s[i]!='\0')          // '\0' better than NULL
	{
		i++;
	}
	// i = size of s
	if (capacity_<i)
	{
		this->reserve(i+10);   //Modification of capacity_ so that it's greater than i
	}
        this->clear();
	memcpy(this->data, s, i);
	length_ = i;
	return *this;
}

//--------------------------------------------------------------------------
void String::resize(int n, char c)           //resize the string
{
  int i;
  if(n>capacity_)
    {
      reserve(n+10);       //Modification of capacity_ so that it's greater than n
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
	  data[i]='c';
	}
    }
  length_ = n;
}

//--------------------------------------------------------------------------
String String::operator +(const String& str)   // concatenates 2 strings
{
	int n=this->length_;
	this->reserve(str.length_);
	this->length_ += str.length_;
	this->capacity_ += str.capacity_;
	int i;
	for(i=0;i<str.length_;i++)
	{
		this->data[n+i]=str.data[i];
	}
	return *this;
}


//----------------------------------------------------------------------------
//Clear the data of the String, data becomes Null
//----------------------------------------------------------------------------
void String::clear()
{
  int i;
  for(i=0;i<length_;i++)
    {
      data[i] = '\0';
    }
  length_= 0;
}


const char& String::at(int p)
{
  if( (p<0) || (p>length_) )
    {
      printf("out of range, try with a number between 0 and length = %d \n",length_);
      exit(EXIT_FAILURE);
    }
  return data[p];
}


String& String::operator= (char c)
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
String& String::operator= (const String& str)
{
 
  delete [] data;
  data  = new char[str.capacity_];
  /*
  data = str.data;
  length_ =str.length_;
  */
  length_=str.length_;
  memcpy(data, str.data, str.length_);
 
  return *this;
}



// ===========================================================================
//                                Protected Methods
// ===========================================================================

