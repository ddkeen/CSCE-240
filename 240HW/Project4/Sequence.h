/***************************************************************************
 * Name: David Keen
 * 
 * Date and Time: 10/21/20 23:00
 * 
 * Function: Sequence object header file for Project 4. This Project covers Formal File IO, Command Line Arguments, Text Processing, and Objects
 * Sequences are strings of DNA sequences. 
 * In this project we are using text processing to map overlaping DNA sequences together
 * 
 * Input requirements of main function (not in this file): 1) Input file containing DNA sequences on even numbered lines, 
 * ID of each DNA sequence should appear on odd lines. 2) integer symbolizing number of sequences in the file
 * Usage: ./a.out <name of FASTA File> <number of sequences>
 *                                   
 * Output: One long DNA sequence which is the concattenated sequence of all sequences in the input file. The overlap between each subsequent input file is not duplicated, only unique parts. 
 * For example, if the sequences ACTG anf CTGA were in the input file, the final sequence would be ACTGA.
 * 
 * Additional Comments: None
 *                                                                         *
 ***************************************************************************/
#include <iostream>
#include <string> 
using namespace std;

class Sequence{
	//public member functions
	public:
		Sequence(); //default constructor
		Sequence(string); // alternate constructor that takes in a string and sets the sequence char array to that string
		~Sequence(); //destructor

		int getLength() const; //return length of char array 
		bool getFlag() const;	//return whether the flag value of the sequence is true, this value is used in the reconstructSequence() function in main
		string getSequence() const; //return a string which is the sequence array of characters from the Sequence object
		
		void printSequence() const; //print out the sequence char array
		void setSequence(const string seq); // set the sequence char array to the string passed into the function
		
		int isOverlapping(const Sequence &obj2) const; //returns number of characters that overlap between the calling Sequence and the passed Sequence
		void operator+=(const Sequence &rhs); //concatenate both Sequences together, without duplicating overlap
 		
 		void setFlag(bool); //set flag bool variable to either ture or false, used in the reconstructSequence() function in main
 		
 	//private member variables and functions
	private:
		char *sequence; //character pointer array that holds a sequence of the characters “A”, “T”, “C” and “G”
		int length; //length of the sequence array
		bool flag; //flag bool variable used in the reconstructSequence() funtion
		
	};
		
