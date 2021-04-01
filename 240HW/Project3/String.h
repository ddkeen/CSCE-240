/***************************************************************************
 * Name: David Keen (Section H01)
 * 
 * Date / Time of Completion: 9/29/20 17:00
 * 
 * Function: String object header file
 * 
 * Copyright (C) 2020 by Casey Cole   
 * Modified with permission by David Keen
 * 
 * Additional Comments: I commented each prototype to clarify what each function does                                                                
 ***************************************************************************/

#include <iostream>
using namespace std;

class String {
	public:
		String(); //Default Constructor
		String(int); //Alternate Constructor 1 taking in a length for the String
		String (char[]); //Alternate Constructor 2 taking in a character array that will become the strinf
		String(const String&); // copy constructor that takes in another String and copies it to form a new String
		~String(); //Destructor that is autimatically called at the end of the main function to dealocate data;
		
		int length() const; //returns the length of String
		char* getData() const; //returns the character array instance variable for the String //helper function
		void clear(); // sets size to 0 and data to the null pointer
		bool empty() const; //checks whether the String is empty
		int find(char[], int) const; // searches for a substring in the String starting at a specific index, returning the index where it is found or -1 if not found
		void print() const; // prints the contents of the String
		
		char operator[](int) const; //access the character array using []
		const String& operator=(const String); //set one String equal to another
		const String operator+(const String&) const; //concatenate Strings together
		bool operator==(const String&) const; //check whether two Strings are equal
		
	private:
		char* data; //the character array that the String holds
		int size;  // the number of characters in data
	
	
};

