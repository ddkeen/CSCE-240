/***************************************************************************
 * Name: Casey Cole
 * Email: coleca@email.sc.edu
 * Function: Account object header
 * 
 * Copyright (C) 2020 by Casey Cole                                        *
 *                                                                         *
 ***************************************************************************/
#include <iostream>
using namespace std;

class intArray {
	
	public:
	
		intArray(); //Defailt
		intArray(int, int); //Alternate
		intArray(intArray&);
		~intArray();
		
		void print(); 
		void init(); 
		
		void operator+(int); 
		void operator+(intArray obj2);
		
		intArray operator+(intArray& obj2);
		//void operator=(intArray obj2);
		intArray& operator=(intArray& obj2); //cascading
		int* getData();
		int operator[](int);
		
	private:
	
		int *data; 
		int size;

};
