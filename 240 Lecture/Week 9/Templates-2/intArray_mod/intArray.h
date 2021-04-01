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
	friend ostream& operator<<(ostream&, intArray&);
	
	friend istream& operator>>(istream&, intArray&);
	
	//a3 = 1 + a2;
	friend intArray operator+(int,intArray&);
	public:
	
		intArray(); //Default
		intArray(int, int); //Alternate constructor
		intArray(const intArray&); //Copy constructor 
		~intArray(); //Destructor 
		
		void print() const; 
		
		intArray operator+(intArray& obj2) const; // obj1 operator= (obj2 + obj3)
		
		intArray& operator=(intArray obj2); //obj1 = obj2 = obj3
		int operator[](int) const;
		
		//TODO: 
		void operator()(int,int);
		
		//BUT I WANT TO USE []!!
		int& operator[](int);
		
		intArray operator++(int); //post x++
		intArray& operator++(); //pre ++x
		
		void operator<<(ostream& os);
		
		int* getData() const; 
		int getSize() const;
		
	private:
	
		int *data; 
		int size;
		void setData(int*); 
		void setSize(int);

};
