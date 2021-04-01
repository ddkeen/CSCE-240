/***************************************************************************
 * Name: David Keen
 * 
 * Date and Time: 10/21/20 23:00
 * 
 * Function: Sequence object cpp file for Project 4.This Project covers Formal File IO, Command Line Arguments, Text Processing, and Objects.
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
 #include "Sequence.h"

 /*Sequence object default constructor
  * Inputs: None
  * Output: None
  * Function create a Sequence Object and set its length to 0 and set every char to the null char '\0'. Sets flag to false
  */
Sequence::Sequence()
{
	length = 100;
	sequence = new char[length];
	for (int i = 0; i < length; ++i)
	{
		sequence[i] = '\0';
	}
	flag = false;
}
 /*Sequence object alternate constrcutor
  * Inputs: String
  * Output: None
  * Function: create a Sequence object with length equal to the length of the string passed in and set the char array equal to that string. Set flag to fasle
  */
Sequence::Sequence(string str)
{
	int i=0;
	while(str[i]!= '\0')
	{
		i++;
	}
	length = i;
	sequence = new char[length];
	for(int i=0; i< length; i++)
	{
		sequence[i] = str[i];
	}
	flag = false;; //might not need
}
 /*Sequence object Destructor
  * Inputs: None
  * Output: None
  * Function: delete the memory that has been dynamically allocated for the sequence char array automatically at the end of the process
  */
Sequence::~Sequence()
{
	delete [] sequence;
}
 /*Function getLength()
  * Inputs: none
  * Output: int
  * Function: return the length of the sequence object
  */
int Sequence::getLength() const
{
	return length;
}
 /*Function printSequence()
  * Inputs: none
  * Output: none
  * Function: print the contents of the sequence char array to standard output
  */
void Sequence::printSequence() const
{
	for(int i=0; i<length; i++)
	{
		cout << sequence[i];
	}
	cout << endl;
}
 /*Function getSequence()
  * Inputs: none
  * Output: string
  * Function: create a temporay string object and set its content equal to the sequence char array and return the temporary string for use
  */
string Sequence::getSequence() const 
{
	string temp("");
	for(int i=0; i<length; i++)
	{
		temp += sequence[i];
	}
	return temp; //NOTE: this is returning a string, not a sequence
}
 /*Function isOverlapping()
  * Inputs: a constant Sequence Object
  * Output: int
  * Function: compare two Sequence Objects to check if there is any overlapping bewtween the two sequences
  * If there is any overlap, return the maximum char overlap. If there is no overlap, return -1.
  */
int Sequence::isOverlapping(const Sequence& obj2) const
{
	//set overlap and max overlap to 0
	int overlap = 0;
	int max_overlap = 0;
	//for loop to check every char in the first sequence
	for(int i = 0; i<length; i++)
	{
		//check if the current char in the first sequence equals the first char in the second sequence
		if(sequence[i] == obj2.sequence[0]) 
		{
			//if so, that starts the overlap, so set it to one
			overlap = 1;
			//for loop to go through the second sequence
			for(int j=1; j<obj2.length; j++)
			{
				//make sure the first object doesn't go out of bounds, if so break
				if((i+j) > length-1)
				{
					break;
				}
				//check to see if there is a mismatch between the two sequences, if so set overlap back to zero
				if(sequence[i+j] != obj2.sequence[j]) //first mismatch occurs
				{
					overlap = 0;
					break;
				}
				//if not, then we have a match and we increment overlap
				else //mismatch did not occur
				{
					overlap++;
				}
			}
		}
		//still in the outter for loop, if our overlap is greater than the max_overlap, set it to max overlap and repeat the loop with the next value in the first sequence
		if(overlap > max_overlap)
		{
			max_overlap = overlap;
		}
	}
	//return -1 if there is no overlap between sequences
	if(max_overlap == 0)
	{
		return -1; 
	}
	//return the max overlap otherwise
	return max_overlap;
	 
}
 /*Function operator+=
  * Inputs: a Sequence Object
  * Output: none
  * Function add the second sequence to the first sequence without duplicating the overlap
  */
void Sequence::operator+=(const Sequence& rhs) 
{
	//temporary char array to hold the value of the calling sequence array
	char * temp = sequence;
	//get the amount of overlap between the two sequences
	int overlap = isOverlapping(rhs); 
	//maxsize will become the new size of the first sequence object, it is the size of both sequences combined, minus the overlap
	int maxSize = (length + rhs.getLength()) - overlap;
	sequence = new char[maxSize];
	//the original values of the calling object sequence will remain the same
	for(int i =0; i<length; i++)
	{
		sequence[i] = temp[i];
	}
	//the remaining values will be the non overlapping values of the second sequence
	for(int j = length; j < maxSize; j++)
	{
		sequence[j] = rhs.getSequence()[overlap];
		overlap++;
	}
	//set the new length member variable to the size of the new sequence
	length = maxSize;
	//make sure to delete temp so we don't have a memory leak
	delete [] temp;
}
 /*Function setSequence
  * Inputs: string
  * Output: none
  * Function: set the calling object's sequence char array to the string passed in 
  */
void Sequence::setSequence(string seq)
{
	for(int i = 0; i< length; i++)
	{
		sequence[i] = seq[i];
	}
}
 /*Function getFlag()
  * Inputs: none
  * Output: bool
  * Function: return the bool value of the flag member variable of the calling Sequence object
  */
bool Sequence::getFlag() const//might not need
{
	return flag;
}
 /*Function setFlag()
  * Inputs: bool value (true or false)
  * Output:none
  * Function: change the bool value of the flag member variable of the calling Sequence object to either true or false
  */
void Sequence::setFlag(bool b)
{
	flag = b;
}
