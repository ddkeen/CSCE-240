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
	
		intArray(); //Default
		intArray(int, int); //Alternate constructor
		intArray(const intArray&); //Copy constructor 
		~intArray(); //Destructor 
		
		void print() const; 
		//void init(); 
		
		//void operator+(int); 
		//void operator+(intArray& obj2);
		
		intArray operator+(intArray& obj2) const; // obj1 + obj2 + obj3
		//void operator=(intArray obj2);
		intArray& operator=(intArray obj2); //obj1 = obj2 = obj3
		int operator[](int) const;
		//const String operator+(const String&) const;  
		//const String & operator=(const String);
		
		int* getData() const; 
		int getSize() const;
		
	private:
	
		int *data; 
		int size;
		void setData(int*); 
		void setSize(int);

};
