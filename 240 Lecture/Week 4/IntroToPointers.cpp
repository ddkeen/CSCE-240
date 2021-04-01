#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	//~ //Introduction to pointers: 
	//~ int x(0);
	//~ x = 100;
	//~ //cout << x << endl;
	//~ int *xPtr;
	//~ xPtr = &x;
	
	//~ *xPtr = 200;
	
	//~ cout << "The location of x: " << &x <<endl; 
	//~ cout << "The value of x: " << x <<endl;
	
	//~ cout << "The location of xPtr: " << &xPtr << endl; 
	//~ cout << "The value of xPtr: " << xPtr <<endl;
	//~ cout << "The value of what xPtr is pointing to is: " << *xPtr << endl;
	
	//~ //Recall: 
	
	//~ int arr[5] = {1,1,1,1,1};
	//~ //{1,1,1,1,1,10}
	
	//~ //How would we increase the size of this array?
	//~ //Step 1: Create a new array that has the right size
	//~ int newArr[6] = {0};
	//~ //Step 2: Copy over the elements from the old array
	//~ for(int i = 0; i < 5; i++)
	//~ {
		//~ newArr[i] = arr[i];
	//~ }
	//~ //Step 3: Set the value of the new value
	//~ newArr[5] = 10;
	
	
	//Problem with this: space?
	//~ int arr[5] = {1,1,1,1,1};
	//~ int *arrPtr;
	//~ arrPtr = arr;
	//~ for(int i = 0; i < 5; i++)
	//~ {
		//~ cout << arrPtr[i] << " ";
	//~ }
	//~ cout << endl;
	
	//~ int *newArry; 
	//~ newArry = new int[6];
	//~ for(int i = 0; i < 5; i++)
	//~ {
		//~ newArry[i] = arr[i] ;
	//~ }
	//~ newArry[6] = 10;
	
	//~ //add another.
	//~ int *temp;
	//~ temp = newArry;
	//~ newArry = new int[7];
	//~ for(int i = 0; i < 6; i++)
	//~ {
		//~ newArry[i] = temp[i] ;
	//~ }
	//~ delete [] temp;
	
	
	
	
	int *arr; 
	//~ int arr1[0]; 
	//~ cout << arr1;
	//~ arr = arr1;
	
	arr = new int[5]; 
	for(int i = 0; i < 5; i++)
	{
		arr[i] = 0;
	} 
	
	int *temp; 
	temp = arr;
	
	arr = new int[6];
	for(int i = 0; i < 5; i++)
	{
		arr[i] = temp[i];
	}
	arr[5] = 0;
	
	//delete [] temp;
	
	temp = arr; 
	arr = new int[7]; 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0; 
}
