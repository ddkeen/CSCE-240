#include <cstdlib>
#include <iostream>
#include <string>
#include "intArray.h"


int main(int argc, char** argv) 
{
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
	
	a3[0] = 100; 
	a3.print();
	
	//a3.operator=(a1.operator+(a2));  
	
	
	
	return 0; 
}
