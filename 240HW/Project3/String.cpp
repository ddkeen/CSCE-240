/***************************************************************************
 * Name: David Keen (Section H01)
 * 
 * Date / Time of Completion: 10/1/20 17:00
 * 
 * Function: String object .cpp file for Project 3 that uses only primitive data types, used to practice pointers (dynamic arrays), objects, and operator overloading
 * 			 Has some of the same functionality as the C++ string class
 * 
 * Input: Sequences of characters that will become a a string and / or numbers that indicate the length of the string (this file does not cointatin any I/O, the main.cpp files do
 *                                       
 * Output: String objects that contain character arrays and a size. There Strings have various functions similar to the C++ string class
 * 
 * Additional Comments: To compile, compile both the main.cpp function and String.cpp function at the same time, ex: g++ Main1.cpp String.cpp 
 * Instead of an extra operator overload functino, a helper function getData() was implemented                                                           
 ***************************************************************************/
 
#include "String.h"

/* Default Constructor 
 * No input
 * Creates a default String object and initializes size to 0 and initializes and dynamically allocates space for the data char array
 */
String::String() //Default
{
	size = 0;
	data = new char[0];
}
/* Alternate Constructor 
 * Input parameter is an integer for the size of the String
 * Creates a String object and initializes size to the input value if it is positive and initializes and dynamically allocates space for the data char array with length 0 or the input value
 */
String::String(int _size) //Alternate
{
	//if input is negative set size to 0
	if(_size < 0)
	{
		size = 0;
	}
	else
	{
		size = _size;
	}
	
	data = new char[size];
}
/* Alternate Constructor 
 * Input parameter is a character array that will be what is stored in data in the String object
 * Creates a String object and initializes size to the length of the character array and initializes and dynamically allocates space for the data char array 
 * It then copies elements from the input character array into data
 */
String::String(char str[]) //Alternate
{
	size = 0;
	int i =0;
	//go through every value in the array until the null character is found to find the size
	while(str[i] != '\0')
	{
		size++;
		i++;
	}
	//initialize data and copy elements from str
	data = new char[size]; 
	for(int i=0; i<size; i++)
	{
		data[i] = str[i];
	}
}
/* Copy Constructor
 * Input parameter is a constant String object that is passed by reference, it will not be changed
 * Output is a new String that is identical to the passed String, hence "copy"
 * it using the .length() String method to set their sizes equal, then initialzes the new Strings data array to the same values as the passed String using a for loop
 */
String::String(const String& str) // Copy
{
	size = str.length();
	data = new char[str.length()];
	for(int i = 0 ; i < size; i++) 
	{
		data[i] = str[i];
	}
}
/* Destructor
 * No input or output
 * This is called automatically at the end of the program and dealocates any space created by the character array data for all String objects created in a program
 * This helps prevent memory leaks
 */
String::~String() //Destructor
{
	delete [] data;
}


/* [] operator overload
 * input is an integer that is the index of the array where the user wants to acess information
 * Output is the value at that index of the array, in this case with String objects it is always a char value
 */
char String::operator[](int len) const
{
	return data[len];
}
/* + operator overload
 * input is a constant String object that is passed by reference
 * output is a new String object that is a concatenation of the calling String and the String passed to the function
 */
const String String::operator+(const String& str) const
{
	//length of the new String is the combined length of the caller String and passed String
	int length = str.length() + size;
	//we call this String temp and use the alternate constructor to set its size to length
	String temp(length);
	//for loop to copy elements from the caller String starting at index 0
	for(int i = 0 ; i < size; i++) 
	{
		temp.getData()[i] = data[i];
	}
	//for loop to copy elements from the passed String starting at the length of the first String
	for(int i = size; i < length; i++)
	{
		
		temp.getData()[i] = str.getData()[i-size];
	}
	return temp;
}
/* = operator overload
 * input is a constant String object passed by value
 * output is tje same String that called the function, as it changes the original String
 */
const String& String::operator=(const String str)
{
	//change the size of the original String to equal the input String
	size = str.length(); 
	//for loop to set all elements in the original String equal to the input String
	for(int i = 0; i < size; i++) 
	{
		data[i] = str[i]; 
	}
	//return the original String 
	return *this;
}
/* == operator overload
 * return whether String object is equal to another String object, that is they have the same size and data character arrays
 * input is another String object that is not changed
 * output is either true or false depending on if the Strings are equal
 */
bool String::operator==(const String& str) const
{
	//return false right away if the sizes aren't equal
	if(str.length() != size)
	{
		return false;
	}
	//check every element in both arrays and see if each corresponding element is equal 
	for(int i =0; i<size; i++)
	{
		if(str[i] != data[i])
		{
			return false;
		}
	}
	return true;
}
/* function that returns the size of the string which is the amount of characters it has
 * input is nothing
 * output is an integer representing the length of the String
 */
int String::length() const
{
	return size;
}
/* clear function to set the String to null
 * input is nothing
 * no output since this is a void function
 * first deletes the memory associated with the character array data, then resets the instance variable size to 0, then sets the data character array to this null pointer
 */
void String::clear()
{
	delete [] data;
    size = 0;
    data = nullptr;
}
/* function to check whether a String object is empty, meaning its data character array is null
 * no input
 * output is true if the data array is equal to the null value '\0', false if not
 */
bool String::empty() const
{
	if(data == '\0')
	{
		return true;
	}
	return false;
}
/* function to find a substring withing a String
 * input is a character array that serves as the substring and an integer that indicates the index to start searching for the substring in the caller String
 * output is an integer, -1 if the substring is not found, or the index of the first instance of the substring in the original String if it is found
 */
int String::find(char substr[], int startIndex) const
{
	//create a String and set its data array equal to substr[] just becasue id like to compare two String objects
	String str(substr);
	//initialize an integer that is the length of this substring
	int length = str.length();
	//declare a return value called ret
	int ret;
	//for loop, starting at the specified startindex
	for(int i = startIndex; i < size; i++)
	{
		//for every character in the array, starting at the start index, create a temporay string the same length of the substring
		String temp(length);
		//set an integer k to the current index in the first for loop
		int k = i;
		//a new for loop that will populate this temporary String with characters from the original String, starting from the current index in the for loop, until this temporary String has the same length as the substring
		for(int j = 0; j<length; j++)
		{
			temp.getData()[j] = data[k];
			k++;
		}
		//set the return value to the index currently at in the outer for loop as if the temporary String is the substring meaning the substring was found in the original
		//we don't know this yet
		ret = i;
		//initialize a boolean value to true, as if the substring was found
		bool found = true;
		//loop through the temporary String and check if every element is equal to the correseponding element in the substring, if any element differs, nothing is returned and instead the next instance of the outter for loop runs and we check with the next set of characters in the original String
		for(int m=0; m < length; m++)
		{
			if(!(temp[m]==str[m]))
			{
				found = false;
			}
		}
		if(found == true)
		{
			return ret;
		}
	}
	//if the enitre outter for loop runs and nothing was returned, then the substring was not found in the array and -1 can be returned
	return -1;
}
/* Print function that prints out the character array for the String as one continous element, litteraly a String
 * no input
 * nothing returned, but the output is NULL if the string is empty (length == 0) or every element in data
 * when data is finished printing as output, the cursor moves to the next line
 */ 
void String::print() const
{
	if(length() == 0)
	{
		cout << "NULL" << endl;
	}
	else
	{
		for(int i=0; i<size; i++)
		{
			cout << data[i];
		}
		cout << endl;
	} 
	
}
/* getData function that returns the character array data
 * no input
 * output is the character array that the string is holding
 */
 
char* String::getData() const
{
	return data;
} 
	
