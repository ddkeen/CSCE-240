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

using namespace std;

const int COLS = 20;

//don't need to use & because arrays are always call by reference
void readData(int data[][COLS], int rows);
void printData(int data[][COLS], int rows);
void mySort(int data[] [COLS], int rows);

int main (int argc, char **argv)
{   
	//check to see if run command had a rows argument
	if(argc != 2)
	{
		cout << "Usage: ./a.out <num_rows>" << endl;
		exit(0);
	}
	//read in row value from terminal argument
	int rows = atoi(argv[1]);
	//declare 2D array;
	int data [rows][COLS];
	
	//read input file to fill aray or take rxc values from input
	readData(data,rows);
	
	cout << "Before Sorting" << endl;
	
	//print array elements in row oder before sorting
	printData(data, rows);
	
	//sort array using bubble sort
	mySort(data,rows);
	
	cout << "After Sorting" << endl;
	
	//print array elements in row order after sorting
	printData(data, rows);
	
	
	return 0; 
}
//just use a couple for loops to poulate array from user input or input file
void readData(int data[][COLS], int rows)
{
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<COLS; j++)
		{
			cin >> data[i][j];
		}
	}
}
//2 for loops to output the data
void printData(int data[][COLS], int rows)
{
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<COLS; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}
//while loop to keep going through array until all elements are in the right order, usees bubble sort same way as a 1D array,
// but uses another for loop and checks the first element of the next row if the current index is the last element of a row and swaps those two if needed
void mySort(int data[][COLS], int rows)
{ 
	bool hasSwapped = true;
	while(hasSwapped)
	{
		hasSwapped = false;
		for(int i= 0; i<rows;i++)
		{
			for(int j=0; j<COLS;j++)
			{
				if(j==(COLS-1))
				{
					//makes sure that we are not in the last row
					if((data[i][j] > data[i+1][0])&& (i<(rows-1))) 
					{
						int temp = data[i][j];
						data[i][j] = data[i+1][0];
						data[i+1][0] = temp;
						hasSwapped = true;
					}
					//continue to next iteration of the for loop so we don't check an index that is out of bounds
					continue;
				}
				//only runs if column is not already at index 19
				if(data[i][j] > data[i][j+1])
				{
					int temp = data[i][j];
					data[i][j] = data[i][j+1];
					data[i][j+1] = temp;
					hasSwapped = true;
				}
			}
		}
	}
}
