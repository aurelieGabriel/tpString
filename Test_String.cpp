//****************************************************************************
//
//
//
//****************************************************************************
 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <stdlib.h>
#include <stdio.h>



// ===========================================================================
//                             Include Project Files
// ===========================================================================
#include "String.h"


// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================


// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{

//--------------------------------------------------------------------------
//Test for the copy constructor
//--------------------------------------------------------------------------

  printf("Test of the copy constructor\n");

  String s1;
  s1 = "test1";
  String s2= String(s1);
 
 
  printf("%s", s2.c_str());
  printf("  length_ : %d capacity_ : %d",s2.length(),s2.capacity());
  printf("\n");

//--------------------------------------------------------------------------
// Test of the constructor with c_String
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the constructor with c_String\n");

  String s3 = String("test");
  printf("%s", s3.c_str());
  printf(" length_ : %d capacity_ : %d \n",s3.length(),s3.capacity());

//--------------------------------------------------------------------------
// Test of the c_str method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the c_str method\n");

  const char * c1;
  c1 =  s3.c_str();
  printf("%s", c1);
  printf("\n");

//--------------------------------------------------------------------------
// Test of the length method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the length method\n");

  printf("length_ : %d\n",s3.length());


//--------------------------------------------------------------------------
// Test of the size method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the size method\n");

  printf("size : %d\n",s3.size());

//--------------------------------------------------------------------------
//test Empty method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the Empty method\n");

  bool t=s1.Empty();
  printf("%d\n",t);

 
//--------------------------------------------------------------------------
//test capacity method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the capacity method\n");

  printf("capacity_ : %d\n",s1.capacity());

//--------------------------------------------------------------------------
//test reserve method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the reverse method\n"); 

  s1.reserve(40);
  printf("capacity_: %d length_ : %d\n",s1.capacity(), s1.length());

//--------------------------------------------------------------------------
//Test operator=(char *)  
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the operator = \n");

  s1="greatTest";
  printf("%s", s1.c_str());
  printf("\n");
  printf("capacity_ : %d length_ : %d\n",s1.capacity(), s1.length());


//--------------------------------------------------------------------------
// Test of the max_size method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the max_size method\n");

  printf("MAX_SIZE : %d\n",String::max_size());


//---------------------------------------------------------------------------
// Test of the resize method
//---------------------------------------------------------------------------

  printf("\n");
  printf("Test of the resize method\n");

  printf("with n<length_ \n");

  s1.resize(2,'r');
  printf("length : %d\n",s1.length());
  printf("%s", s1.c_str());
  printf("\n");

  printf("with n>length_ \n");

  s1.resize(10,'r');
  printf("length : %d\n",s1.length());
  printf("%s", s1.c_str());
  printf("\n");

//--------------------------------------------------------------------------
// Test of the at method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the at method\n");

  printf("%c\n", s1.at(0));
  
//--------------------------------------------------------------------------
// Test of operator+ (String)
//--------------------------------------------------------------------------

  printf("\n");
  printf("Test of the operator+ method\n");


  s1="itWorks";
  s2="Youpi";
  printf("%s\n",(s1+s2).c_str());
  
 
 
//---------------------------------------------------------------------------
// Test of the clear method
//---------------------------------------------------------------------------
  printf("\n");
  printf("Test of the clear method\n"); 
 
  s1.clear();
  printf("length_ : %d\n capacity_ : %d\n" , s1.length(), s1.capacity());

//---------------------------------------------------------------------------
// Test of the operator= (char)
//---------------------------------------------------------------------------
  printf("\n");
  printf("Test of the operator= (char)\n");

  s2 = 'c';
  printf("%c\n length_ : %d\n",s2[0],s2.length());

//---------------------------------------------------------------------------
// Test of the operator= (const String& str)
//---------------------------------------------------------------------------
  printf("\n");
  printf("Test of the operator = with string\n");

  printf("with s1.length_ > s2.length \n");

  s1="hello";
  printf("length_ s1: %d capacity_ s1: %d\n",s1.length(), s1.capacity());
  printf("length_ s2: %d capacity_ s2: %d\n",s2.length(), s2.capacity());
  s2 = s1; 
  printf("length_ s2: %d capacity_ s2: %d\n",s2.length(), s2.capacity());
  printf("%s", s2.c_str());
  printf("\n");


  printf("with s1.length_ < s2.length \n");
 
  s1 = "hi";
  printf("length_ s1: %d capacity_ s1: %d\n",s1.length(), s1.capacity());
  printf("length_ s2: %d capacity_ s2: %d\n",s2.length(), s2.capacity());

  s2 = s1; 
  printf("length s2: %d capacity s2: %d\n",s2.length(), s2.capacity());
  printf("%s", s2.c_str());
  printf("\n");


  
//---------------------------------------------------------------------------
// Test of the operator+ (char*)
//---------------------------------------------------------------------------
  printf("\n");
  printf("Test of the operator+ (char*)\n");
  
  String s4 = s2+"HowAreYou";
  printf("%s", s4.c_str());
  printf("\n");

//--------------------------------------------------------------------------
// Test for the operator[] method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the operator[] method\n");

  printf("%c %c\n",s1[0], s1[1]);

//---------------------------------------------------------------------------
// Test of the operator+ (char)
//---------------------------------------------------------------------------

  printf("\n");
  printf("Test of the operator+ (char)\n");
  
  s4 = "the End";
  s4 = s4 + '!';
  printf("%s", s4.c_str());
  printf("\ncapacity_ : %d ", s4.capacity());
  printf("\n");


  return 0;
}



