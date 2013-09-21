#ifndef A2SUPPORT_INCLUDED
#define A2SUPPORT_INCLUDED
#include <stdint.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
//
//  File          : a2support.h
//  Description   : This is the header file for the functions for assignment
//                  2 of the CMPSC311 course.  Students are required to define 
//                  the following functions and implement them in another
//                  file, a2support.c.
//
//  Author        : Patrick McDaniel
//  Created       : Mon Sep  9 05:11:24 PDT 2013 
//

void  printFArray( float *myFloatArray, int32_t  lengthOfArray );
void  printIArray( int32_t *myIntegerArray, int32_t lengthOfArray );
int32_t  myRound( float aSingleNumber );
void  incrementFloat( float *valueToFloatPointer, float counter );
void  incrementInt( int32_t *valueToIntegerPointer, int32_t counter );
float  largestFloat( float *myFloatArray, int32_t lengthOfArray );
int32_t  largestInt( int32_t *myIntegerArray, int32_t lengthOfArray );
void  bsortFloat( float *myFloatArray, int32_t lengthOfArray );
void  bsortInt( int32_t *myIntegerArray, int32_t lengthOfArray );
void  printCharline( char myCharacter, int32_t counter );
void  doHistogram( float *myFloatArray, int32_t *myIntegerArray, int32_t lengthOfFloatArray, int32_t lengthOfIntegerArray );

#endif
