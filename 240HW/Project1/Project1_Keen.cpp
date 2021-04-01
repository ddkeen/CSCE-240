/*
* Name: David Keen (Section H01)
* 
* Date / Time of Colmpletion: 9/1/2020, Noon
* 
* Function: This is a basic C++ program, used to practice reading/writing to terminal, running C++ code, if/else statements, and a basic for loop
* 
* Input: User's first name, last name, and a command being either A, B, or something else
* 
* Output: A greeting to the user, a countdown from 10-1, or an error message for an invalid command
* 
* Additional Comments: C++ is cool
*/

//header files
#include <cstdlib>
#include <iostream>
#include <string> 

//namespace for I/O
using namespace std;

//main function
int main( int argc, char **argv)
{
	//declare variables
	string firstName;
	string lastName;
	char command;
	
	//get input from user
	cout << "Please enter your first name: ";
	cin >> firstName;
	cout << "Please enter your last name: ";
	cin >> lastName;
	cout << "Please enter your command: ";
	cin >> command;
	
	//return output bsaed on whay command was entered
	if(command == 'A')
		cout << "Hello, " << firstName << " " << lastName << "." << endl;
	else if(command == 'B')
	{
		for(int i=10; i>0; i--)
			cout << i << endl;
		cout << "Goodbye!" << endl;
	}
	else
		cout << "Invalid Command!" << endl;
		
	//end of program
	return 0;
		
	
}
	

