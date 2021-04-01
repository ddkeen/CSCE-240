#include <cstdlib>
#include <iostream>
#include <string>
#include "intArray.h"


int main(int argc, char** argv) 
{
	
	//Finding the length of a character array that was 
	//populated with a string (ie: ... ) 
	//~ char test[] = "Test";
	//~ //Null character -> \0
	//~ int length = 0; 
	//~ int i = 0;
	//~ while(test[i] != '\0')
	//~ {
		//~ length++;
		//~ i++;
	//~ }
	//~ cout << "Length of char array: " << length << endl;
	
	
	
	
	
	intArray a1(5, 1);
	cout << "Array 1 Before : " << endl; 
	a1.print(); 
	
	intArray a2(5,2);
	cout << "Array 2 Before: " << endl; 
	a2.print(); 
	
	//a1+a2; //a1 += a2
	//a1.operator+(a2);
	//~ cout << "Array 1 After: " << endl; 
	//~ a1.print(); 
	//~ cout << "Array 2 After: " << endl; 
	//~ a2.print();
	
	intArray a3(5,0); 
	cout << "A3: " << endl; 
	//a1 + a2;
	
	//(a1+a2).print();
	
	a3 = a1 + a2 + a1 + a2;
	cout << "A3: " << endl;
	a3.print();
	cout << "A2: " << endl;
	a2.print();
	cout << "A1: " << endl;
	a1.print();
	
	//a3.operator=(a1.operator+(a2)); 
	
	int x, y, z(10);
	x = y = z; 
	
	
	
	return 0; 
}
