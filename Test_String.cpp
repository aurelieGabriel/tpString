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
//test for the copy constructor
//--------------------------------------------------------------------------

  printf("Test of the copy constructor\n");

  String s1;
  String s2= String(s1);
 
  int i;
  for(i=0; i<4; i++)
    {
    printf("! %c", s2.data[i]);
    }
  printf("%d %d",s2.length_,s2.capacity_);
  printf("\n");

//--------------------------------------------------------------------------
// Test of the constructor with c_String
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the constructor with c_String\n");

  s1.data[0]='t';
  s1.data[1]='e';
  s1.data[2]='s';
  s1.data[3]='t';
  s1.data[4]='o';
  s1.data[5]='o';
  s1.data[6]='o';
  s1.length_ = 7;
 
  //s1.length_=4;
 

  String s3 = String(s1.data);
  for(i=0; i<s3.capacity_; i++)
    {
    printf("%c", s3.data[i]);
    }
  printf("%d %d \n",s3.length_,s3.capacity_);

//--------------------------------------------------------------------------
// Test of the c_str method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the c_str method\n");

  const char * c1;
  c1 =  s1.c_str();
  for(i=0; i<4; i++)
    {
    printf("%c ", c1[i]);
    }
  printf("\n");

//--------------------------------------------------------------------------
// Test of the length method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the length method\n");

  printf("%d\n",s3.length());


//--------------------------------------------------------------------------
// Test of the size method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the size method\n");

  printf("%d\n",s3.size());

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

  printf("%d\n",s1.capacity());

//--------------------------------------------------------------------------
//test reserve method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the reverse method\n"); 

  s1.reserve(40);
  printf("%d %d\n",s1.capacity(), s1.length());

//--------------------------------------------------------------------------
//test operator=  method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the operator = \n");

  s1="blabla";
  for(i=0;i<s1.capacity_;i++)
    {
      printf("%c",s1.data[i]);
    }
  printf("\n");
  printf("%d %d\n",s1.capacity(), s1.length());


//--------------------------------------------------------------------------
// test of the max_size method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the max_size method\n");

  printf("%d\n",String::max_size());


//---------------------------------------------------------------------------
// Test of the resize method
//---------------------------------------------------------------------------

  printf("\n");
  printf("Test of the resize method\n");

// with n<length

  s1.resize(2,'c');
  printf("length : %d\n",s1.length());
  for(i=0; i<s1.length(); i++)
    {
      printf("%c", s1.data[i]);
    }
  printf("\n");

// with n>length

  s1.resize(10,'c');
  printf("length : %d\n",s1.length());
  for(i=0; i<s1.length(); i++)
    {
    printf("%c", s1.data[i]);
    }
  printf("\n");

//--------------------------------------------------------------------------
// Test for the at method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the at method\n");

  printf("%c\n", s1.at(0));
  
//--------------------------------------------------------------------------
// test of operator+ (String)
//--------------------------------------------------------------------------

  printf("\n");
  printf("Test of the operator+ method\n");


  s1="blabla";
  s2="hello";
  printf("%s\n",(s1+s2).data);
  
 
 
//---------------------------------------------------------------------------
// Test of the clear method
//---------------------------------------------------------------------------
  printf("\n");
  printf("Test of the clear method\n"); 
 
  s1.clear();
  printf("%c\n %d\n %d\n" , s1.data[0], s1.length_, s1.capacity_);

//---------------------------------------------------------------------------
// Test of the operator= (char)
//---------------------------------------------------------------------------
  printf("\n");
  printf("Test of the operator= (char)\n");

  s2 = 'c';
  printf("%c\n %c\n %d\n",s2.data[0],s2.data[1],s2.length());

//---------------------------------------------------------------------------
// Test of the operator= (const String& str)
//---------------------------------------------------------------------------
  printf("\n");
  printf("Test de l'opérateur = avec string\n");

  printf("cas où s1.length_ > s2.length \n");

  s1="blabla";
  printf("length s1: %d capacity s1: %d\n",s1.length(), s1.capacity());
  printf("length s2: %d capacity s2: %d\n",s2.length(), s2.capacity());
  s2 = s1; 
  printf("length s2: %d capacity s2: %d\n",s2.length(), s2.capacity());
  for(i=0; i<s2.capacity_; i++)
    {
      printf("%c", s2.data[i]);
    }
  printf("\n");


  printf("cas où s1.length_ < s2.length \n");
 
  s1 = "bla";
  s2 = "blabla";
  printf("length s1: %d capacity s1: %d\n",s1.length(), s1.capacity());
  printf("length s2: %d capacity s2: %d\n",s2.length(), s2.capacity());

  s2 = s1; 
  printf("length s2: %d capacity s2: %d\n",s2.length(), s2.capacity());
  for(i=0; i<s2.capacity_; i++)
    {
      printf("%c", s2.data[i]);
    }
  printf("\n");


  
//---------------------------------------------------------------------------
// Test of the operator+ (char*)
//---------------------------------------------------------------------------
  printf("\n");
  printf("Test of the operator+ (char*)\n");
  
  String s4 = s2+"coucou";
  for(i=0;i<s4.length_;i++)
    {
      printf("%c",s4.data[i]);
    }
  printf("\n");

//--------------------------------------------------------------------------
// Test for the operator[] method
//--------------------------------------------------------------------------
  printf("\n");
  printf("Test of the operator[] method\n");

  printf("%c  %c  %c\n",s1[0], s1[1], s1[2]);

//---------------------------------------------------------------------------
// Test of the operator+ (char)
//---------------------------------------------------------------------------

  printf("\n");
  printf("Test of the operator+ (char)\n");
  
  s4 = "blabla";
  s4 = s4 + 'r';
  for(i=0;i<s4.capacity_;i++)
    {
      printf(" %c",s4.data[i]);
    }
  printf("capacity : %d ", s4.capacity_);
  printf("\n");


  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

