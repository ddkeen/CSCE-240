/*
* Name: David Keen (Section H01)
* 
* Date / Time of Colmpletion: 9/17/2020, Noon
* 
* Function: This program reads in integer values from the user or an input file, puts them into a 2D array, then sorts the entire array in matrix order.
* used to practice reading/writing to terminal, functions, 2D arrays, and sorting algorithms.
* 
* Input: Number of rows for the array, an input file may be used for the array elements if desired (Columns are set at 20)
* 
* Output: an Nx20 array sorted in ascending row order
* 
* Additional Comments: This took me a lot longer than it should have. I had lots of trouble with the mySort function, many times getting random numbers
* that don't appear in the input file. When I tried to use 4 for loops to sort the arry, I the code would compile but when I ran it I got a "segmentation fault 11" message.
* Eventually I got it to work by using bubble sort with 2 for loops, and whenever the index was at the end of a row I would check the first element of the next row 
* and swap thsoe two values if needed. I was also a little confused on the best way to use the return type and parameters but I ended up just using void and passed the array and rows
*/

#include <cstdlib>
#include <iostream>
#include "String.h"

int main(int argc, char** argv)
{
	
}
