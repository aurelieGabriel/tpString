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

  String s1; 
  String s2= String(s1);
 
  int i;
  for(i=0; i<4; i++)
    {
    printf("%c ", s2.data[i]);
    }
  printf("\n");

//--------------------------------------------------------------------------
// Test of the constructor with c_String
//--------------------------------------------------------------------------
  String s3 = String(s1.data);
  printf("%d %c\n",s3.length_,s3.data[0]);



  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

