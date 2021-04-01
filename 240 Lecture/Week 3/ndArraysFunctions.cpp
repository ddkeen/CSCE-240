/***************************************************************************
 ***************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


//void print1DArray(int arr[],int);
//void print2DArray(int data[][COLS], int rows);


int main (int argc, char **argv)
{ 
	int size = 5;
	int arr[size] = {}; 
	//int arr[5] = {}; //This statement WILL initialize all values to be 0. 
	
	//int size = sizeof(arr)/sizeof(arr[0]); //This will give us the correct size in main()
	//int size = sizeof(arr)/sizeof(int);									   //but not in functions. 
										   
	//Let's implement this function to print out the elements
	//remember... we always have to pass by reference with arrays
	print1DArray(arr,size);

	const int ROWS(2); 
	const int COLS(5);

	//Populating elements of 2d array? 
	int data[ROWS][COLS] = {1,2,3,4,5,6,7,8,9,10};
	//int data[ROWS][COLS] = {{1,2,3,4,5},{6,7,8,9,10}};
	
	//Accessing elements
	//cout << "The value at [0][0] is " << data[0][0] << endl;
	
	//nested for with cin
	//(Manual--scaling issue -- solved by file redirection)
	for(int r = 0; r < ROWS; r++)
	{
		for(int c = 0; c < COLS; c++)
		{
			//cout << "Enter value: " << endl;
			//cin >> data[r][c];
		}
	}
	
	//printing 2D arrays with nested for
	for(int r = 0; r < ROWS; r++)
	{
		for(int c = 0; c < COLS; c++)
		{
			//cout << "The value at [" << r << "]["<< c << "] is " << data[r][c] << endl;
		}
	}
	
	
	//Printing elements of 2D array as function?
	//print2DArray(???);
	
	
	//n dimensions?
	
    return 0;
}

void print1DArray(int arr[],int size){
	for(int i = 0; i <= size; i++)
	{
		cout << "Element at [" << i << "] is " << arr[i] << endl;
	}
}

