////////////////////////////////////////////////////////////////////////////////
//
//  File          : cmpsc311-f13-assign2.c
//  Description   : This is the main code file for the CMPSC311 assignment 2.  
//                  see class assignment for details on what needs to be added.
//
//  Author        : Patrick McDaniel
//  Created       : Mon Sep  9 05:11:24 PDT 2013
//
#include <stdint.h>
#include <stdio.h>
#include <a2support.h>

#define NUMBER_ENTRIES 15

////////////////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : This is the main function for the cmpsc311-f13-assign2 program.
//
// Inputs       : none
// Outputs      : 0 if successful, -1 otherwise

int main( void ) {

  // Declare your variables here
  float myFloats[NUMBER_ENTRIES];
  int32_t i = 0;
  int32_t myFloatToInteger[NUMBER_ENTRIES];

  // Read float values
  for ( i=0; i<NUMBER_ENTRIES; i++ ) {
    scanf( "%f", &myFloats[i] );
  }

  // Compute the integer array
  for ( i=0; i<NUMBER_ENTRIES; i++ ) {
    myFloatToInteger[i] = myRound(myFloats[i] );
  } 

  // Show the list of unsorted values
  printCharline( '*', 69 );
  printf( "Received and computed values\n" );
  printFArray( myFloats, NUMBER_ENTRIES );
  printIArray( myFloatToInteger, NUMBER_ENTRIES );

  // Increment the odd elements of floats by 10.2 and the
  // even elements of integers by 112 (zeroth item is even)
  for ( i = 0; i < NUMBER_ENTRIES; i+=2){
    incrementInt (&myFloatToInteger[i], 112);
    if (i < NUMBER_ENTRIES - 1) {
        incrementFloat (&myFloats[i+1], 10.2);
     }
  }

  // Now print out the largest element in each array
  printf( "The largest element of the float array is %6.2f\n", largestFloat( myFloats, NUMBER_ENTRIES ) );
  printf( "The largest element of the int array is %6d\n", largestInt( myFloatToInteger, NUMBER_ENTRIES ) );

  // Show the list of unsorted values
  printCharline( '*', 69 );
  printf( "Altered values\n" );
  printFArray( myFloats, NUMBER_ENTRIES );
  printIArray( myFloatToInteger, NUMBER_ENTRIES );

  // Now sort the arrays
  bsortFloat( myFloats, NUMBER_ENTRIES );
  bsortInt( myFloatToInteger, NUMBER_ENTRIES );

  // Now call the print functions on the float and integer arrays
  printCharline( '*', 69 );
  printf( "Sorted values\n" );
  printFArray( myFloats, NUMBER_ENTRIES );
  printIArray( myFloatToInteger, NUMBER_ENTRIES );

  // Create a historgram
  printCharline( '*', 69 );
  printf( "Historgram of values\n" );
  doHistogram( myFloats, myFloatToInteger, NUMBER_ENTRIES, NUMBER_ENTRIES );

  // Return successfully
  return( 0 );
}
