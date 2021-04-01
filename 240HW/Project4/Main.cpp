/***************************************************************************
 * Name: David Keen
 * 
 * Date and Time: 10/21/20 23:00
 * 
 * Function: Sequence object Main file for Project 4.This Project covers Formal File IO, Command Line Arguments, Text Processing, and Objects
 * Sequences are strings of DNA sequences. 
 * In this project we are using text processing to map overlaping DNA sequences together
 * 
 * Input requirements: 1) Input file containing DNA sequences on even numbered lines, 
 * ID of each DNA sequence should appear on odd lines. 2) integer symbolizing number of sequences in the file
 * Usage: ./a.out <name of FASTA File> <number of sequences>
 *                                   
 * Output: One long DNA sequence which is the concattenated sequence of all sequences in the input file. The overlap between each subsequent input file is not duplicated, only unique parts. 
 * For example, if the sequences ACTG anf CTGA were in the input file, the final sequence would be ACTGA.
 * 
 * Additional Comments: None
 *                                                                         *
 ***************************************************************************/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "Sequence.h"

//Nonmember Function readData() that reads in a file to create an array of sequences
Sequence* readData(string file_handle, int& size);
//Nonmember function reconstructSequences that takes in an array of sequences and concateates them into one long contiguous sequence
Sequence* reconstructSequences(Sequence * all_seqs, int size);

int main(int argc, char** argv) 
{
	//if argument count is not equal to 3, tell user the input requirements and exit the program
	if(argc != 3)
	{
			cout << "Usage: ./a.out <name of FASTA File> <number of sequences>" << endl;
			exit(0);
	}
		
	string fileName = argv[1]; //first argument is the input file
	int num_seqs = atoi(argv[2]); //2nd argument is the number of sequences
	Sequence * all_seqs = readData(fileName, num_seqs); //reads all sequences from the file and puts them into a Sequence array
	Sequence * long_seq = reconstructSequences(all_seqs, num_seqs); //long sequence is the final reconstructed sequence, made from concatenating all sequences in the Sequence array
	cout << "Final Reconstructed Sequence: " << endl;
	long_seq -> printSequence(); //print out the final reconstructed sequence to standard output
	delete long_seq; //delete the final long sequence 
	delete [] all_seqs; //delete the array of sequences
	return 0; //end of program
	
}

/* Nonmember Function readData()
 * Inputs: string of the input file, integer which is the number of sequences in the input file
 * Output: an array of Sequence objects
 * Function: read the input FASTA file and take every sequence string in the file and use it to create a Sequence object and put that object into an array of Sequences with size equal to the integer passed in by refrerence
 */
Sequence* readData(string file_handle, int& size)
{
	//create new array of Sequences 
	Sequence *genes = new Sequence[size];
	//declare input file stream
	ifstream inFile;
	//open file stream using input file passed into the function
	inFile.open(file_handle);
	//error checking for file
	if(inFile.fail())
	{
		cout << "Error" << endl;
		exit(1);
	}
	//loop through input file, moving past each ID and taking in each sequence and setting each character array in the array of sequences to that sequence string from the file
	int i =0;
	while (i < size) 
	{
		string next(""), junk("");
		getline(inFile,junk);
		getline(inFile, next);
		genes[i].setSequence(next);
		i++; 
	}
	//close the input file
	inFile.close();
	//returns a Sequence array
	return genes;
	
}

 
 /* Nonmember Function recontructSequences
  * Inputs: an array of Sequences, an integer which is the length of the array of Sequences
  * Output: One long sequence which is the concatenation of all the sequences in the array together, without adding overlap
  * Function: loops through all Sequences in the array and uses an achor sequence which defaults as the first sequence in the arrray
  * Then each subsequent sequence is compared to this sequence and the one with the most overlap is concatenated to the anchor sequence. 
  * This process is repeated until every Sequence in the array is concatedated to the anchor Sequence
  */
Sequence* reconstructSequences(Sequence * all_seqs, int size)
{
	//anchor sequence is created and is simply the first sequence in the sequence array
	Sequence * anchor = new Sequence(all_seqs[0].getSequence());
	//flag the first sequence, this is not necessary because we start the for loop at i=1
	all_seqs[0].setFlag(true);
	//run the inner loop until every sequence is concatenated onto the anchor sequence
	int all_seqs_not_used = size-1;
	while(all_seqs_not_used != 0)
	{
		//we are looking for the sequence with the most overlap with current the anchor sequence
		int max_overlap = -1;
		int max_ind = -1; 
		//loop through all elements 
		for(int i=1; i<size; i++)
		{
			//a true flag means the sequence has already been concatenated to our anchor sequence, if it hasn't we check if the sequence has the most overlap out of all the sequences tested in this run of the foor loop
			if(all_seqs[i].getFlag() == false && ((anchor->isOverlapping(all_seqs[i]))>max_overlap))
			{
				//if so set the max_overlap (this variable is mainly used for testing purposes, we really just need the index
				max_overlap = anchor->isOverlapping(all_seqs[i]);
				//and set the max_index
				max_ind = i;
			}
		}
		//after looping through all the elements, concatenate the sequence with the most overlap to the anchor sequence
		*(anchor) += all_seqs[max_ind]; 
		//flag the sequence in the array that has already been concatenated so it is not concatenated again
		all_seqs[max_ind].setFlag(true);
		//we have used a sequence so we subtract 1 from our count
		all_seqs_not_used--;
		//repeat until all sequences in array have been concatenated
	}
	//return the one long contiguous sequence
	return anchor;

}



