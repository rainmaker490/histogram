#include <a2support.h>
#define swapFloat(x,y) {float temp = x; x = y; y = temp;}
#define swapInteger(x,y) {int32_t temp = x; x = y; y = temp;}
#define MAX_NUMBER_CHARACTERS_PRINTED 80
#define INTERVAL_WIDTH 50
#define NUMBER_OF_CATEGORIES 10
#define NUMBER_ENTRIES 15
/////////////////////////////////////////////////////////////////////////////////
//
//  File            : a2support.c
//  Description     : This is the '.c' file for the functions for assignment
//                    2 of the CMPSC311 course. This file contains the function
//                    implementations of the functions defined in the 
//                    a2support.h file.
//
//
//  Author          : Varun Patel
//  Created         : Tuesday Sep 16 22:38:00 EST 2013
//
/////////////////////////////////////////////////////////////////////////////////

/* 
*  PrintFArray function prints out an array of floats on a single line
*  Parameters : Reference to the array of floats (*myFloatArray)
*               integer length of myFloatArray
*  OutPut     : On a single line, myFloatArray will be displayed
*/
void printFArray (float *myFloatArray, int32_t lengthOfArray ){
  int32_t i;
  for ( i = 0; i < lengthOfArray; i++){
    printf( "%8.2f" , myFloatArray[i]);
  }
  // new line for spacing
  printf("\n");
}

/*
* PrintIArray function prints out an array of integers on a single line
* Parameters : Reference to the array of integers (*myIntegerArray)
*              integer length of myIntegerArray
* Output     : On a single line, myIntegerArray will be displayed
*/
void printIArray (int32_t *myIntegerArray, int32_t lengthOfArray ){
  int32_t i;
  for( i = 0; i < lengthOfArray; i++){
    printf ("%8i" , myIntegerArray[i]);
  }
  printf("\n");
}

/*
* myRound function rounds to the nearest integer by 0.5
* Parameters : single float value to round by 0.5
* Output     : an integer rounded up at 0.5 respectively
*/
int32_t myRound ( float aSingleNumber){
  if ( aSingleNumber > 0){
    return (int32_t)(aSingleNumber + 0.5);
  } else {
      return (int32_t)(aSingleNumber - 0.5);
    } 
}

/*
* incrementFloat function increments a float value by a specified amount
* Parameters : pointer to a float value, and a float value to increment by
* Output     : a float value that has been incremented by the specified amount
               no output is actually returned, however the values are changed
*/
void incrementFloat (float *valueToFloatPointer, float counter ){
  *valueToFloatPointer += counter;
}

/*
* incrementInt function incrementes an integer value by a specified amount
* Patameters : a pointer to an integer value, and an integer value to increment with
* Output     : an Integer value that has been incremented by the specified amount
               no output is actually returned, the values however, are changed
*/
void incrementInt (int32_t *valueToIntegerPointer, int32_t counter ){
  *valueToIntegerPointer += counter;
}

/*
* largestFloat function analyzes an array of floats and returns the largest value in the array
* Parameters : A reference to an array of floats, and an integer length of the Array
* Output     : the largest float value of myFloatArray
*/
float largestFloat (float *myFloatArray, int32_t lengthOfArray ){
  int32_t i;
  float largestFloatValue = myFloatArray[0];
  for ( i = 0; i < lengthOfArray; i++){
    if (myFloatArray[i] > largestFloatValue){
      largestFloatValue = myFloatArray[i];
    }
  }
  return largestFloatValue;
}

/*
* largestInt function analyzes an array of ints and returns the largest value in the array
* Parameters : A reference to an array of ints, and an int length of the Array
* Output     : the largest int value of myIntegerArray
*/
int32_t largestInt (int32_t *myIntegerArray, int32_t lengthOfArray ){
  int32_t i, largestIntegerValue = myIntegerArray[0];
  for ( i = 0; i < lengthOfArray; i++){
    if (myIntegerArray[i] > largestIntegerValue){
      largestIntegerValue = myIntegerArray[i];
    }
  }
  return largestIntegerValue;
}

/*
* bsortFloat function sorts the array of floats in ascending order using bubble sort
* Parameters : a reference to an array of floats and a integer length of the array
* Output     : the values in the array of floats are sortes, no output is actually returned
*/
void bsortFloat (float *myFloatArray, int32_t lengthOfArray ){
  int32_t i, j;
  for ( i = 0; i < lengthOfArray; i++) {
    for ( j = 0; j < lengthOfArray - 1; j++) {
      if (myFloatArray[j] > myFloatArray[j+1]){
        swapFloat (myFloatArray[j], myFloatArray[j+1]);
      }
    }
  }
}

/*
* bsortInt function sorts the array of ints in ascending order using bubble sort
* Parameters : a reference to an array of ints and an integer length of the array
* Output     : the values in the array of ints are sorted, no output is actually returned
*/
void bsortInt ( int32_t *myIntegerArray, int32_t lengthOfArray ){
  int32_t i,j;
  for ( i = 0; i < lengthOfArray; i++) {
    for ( j = 0; j < lengthOfArray - 1; j++) {
      if (myIntegerArray[j] > myIntegerArray[j+1]){
        swapInteger (myIntegerArray[j] , myIntegerArray[j+1]);
      }
    }
  }
}

/*
* printCharline function prints a character a number of times that is specified
*               if the number specified is greater than 80, then just print 80 
*               times max
* Parameters : a single character and an integer number
* Output     : the single character passed is printed by the specified amount as
*              long as the the number is <= 80
*/
void printCharline ( char myCharacter, int32_t counter ){
  int32_t i;
  if (counter > MAX_NUMBER_CHARACTERS_PRINTED){
    counter = MAX_NUMBER_CHARACTERS_PRINTED;
  }
  for ( i = 0; i < counter; i++){
    printf ("%c", myCharacter);
  }
  printf ("\n");
}

/*
* doHistogramFunction computes and draws the histogram of values
* Parameters : reference to a float array, reference to an int array, 
*              integer length of float array, integer length of int array
* Output     : a histogram is printed. It will display data in a graph
*              that analyzes where the data is clustered (measures 
*              frequencies of data)
*/
void doHistogram (float *myFloatArray, int32_t *myIntegerArray, int32_t lengthOfFloatArray, int32_t lengthOfIntegerArray ){
 // intervals Array and pointsPerInterval are parallel arrays. Both are length of
 // NUMBER_OF_CATEGORIES. intervals will contain the intervals of where the data points lie
 // pointsPerInterval will count how many points are in a particular interval
 int32_t intervals[NUMBER_OF_CATEGORIES], pointsPerInterval[NUMBER_OF_CATEGORIES];
  // i, j are variables used for loops at different times. 
  // largest Integer will be used to store the largest number in the pointsPerIntervalArray.
  // computing the largestInteger will be helpful later in the function with printing the
  // histogram vertically.
  int32_t i , j , largestInteger;

  // Initialize the values of the intervals Array to the specified categories
  // Initialize the values in the pointsPerInterval Array by filling with 0's
  for (i = 0; i < NUMBER_OF_CATEGORIES; i++){
    intervals[i] = (i * INTERVAL_WIDTH);
    pointsPerInterval[i] = 0;
  }
  
  // nested for loops that analyze both of the arrays and counts and stores exactly how
  // many points lie in which interval. The counted values are stored in the pointsPerInterval
  // array accordingly  
  for (i = 0; i < NUMBER_OF_CATEGORIES - 1; i++){
    for (j = 0; j < NUMBER_ENTRIES; j++){
      if ( (myFloatArray[j] >= intervals[i]) && ( myFloatArray[j] < intervals[i+1])){
        pointsPerInterval[i] += 1;
      }
      if ( (myIntegerArray[j] >= intervals[i]) && ( myIntegerArray[j] < intervals[i+1])){
        pointsPerInterval[i] += 1;
      }
    }
  }
  
  // Special Case, endpoints
  // Look for the data that falls outside the lower bounds and upper bounds
  // of the set categories of both of the arrays and count these data points
  // and place accordingly either at the beginning or the end of the 
  // pointsPerInterval parallel array.
  for ( i = 0; i < NUMBER_ENTRIES; i++) {
    if (myFloatArray[i] < intervals[0] ){
      pointsPerInterval[0] +=1;
    }
    if (myIntegerArray[i] < intervals[0]) {
      pointsPerInterval[0] +=1;
    }
    if (myFloatArray[i] >= intervals[NUMBER_OF_CATEGORIES -1]) {
      pointsPerInterval[NUMBER_OF_CATEGORIES - 1] +=1;
    }
    if (myIntegerArray[i] >= intervals[NUMBER_OF_CATEGORIES - 1]) {
      pointsPerInterval[NUMBER_OF_CATEGORIES - 1] +=1;
    }
  }

  // printing the data points vertically. Print in rows. 
  // calculate the largest integer in the pointsPerInterval Array 
  // if there exists a data point at a particular point, then print
  // out a * else print a space. rows are printed left to right and
  // each row then is printed down.
  largestInteger = largestInt(pointsPerInterval , NUMBER_OF_CATEGORIES);
  for ( i = largestInteger + 1; i != 0; --i){
    // handles the left side counter of points to one more than largest data point
    printf("%i", i);
    for ( j = 0; j < NUMBER_OF_CATEGORIES; j++){
      if ( pointsPerInterval[j] < i) {
        printf("%8c" , ' ');
      } else { 
          printf("%8c", '*');
	  --pointsPerInterval[j];
      }
    }
    printf("\n");
  }
  // Printing the Intervals
  // end intervals look different than middle intervals, so
  // handle those exceptions with if statements. to make 
  // code more portable. Spaced accordingly.
  for ( i = 0; i < NUMBER_OF_CATEGORIES; i++ ){
    if ( i == 0) {
      printf("%7c%i", '<' , intervals[i+1]);
    } else if (i == NUMBER_OF_CATEGORIES - 1) {
        printf("%5s%i" , ">=" , intervals[i]);
    } else {
        printf("%7i%c", intervals[i] , '+');
    }
  }
  // new line 
  printf("\n");
}
