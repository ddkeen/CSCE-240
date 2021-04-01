#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Sequence.h"

using namespace std; 

int main(int argc, char** argv) 
{
	
	string filename = argv[1];
	int num_seqs = atoi(argv[2]); 
	//Sequence *all_seqs = readData(filename, num_seqs)
	Sequence *all_seqs = new Sequence[num_seqs]; 
	
	ifstream inFile; 
	inFile.open(filename);
	if (inFile.fail()) 
	{
		cout << "Error." << endl;
		exit(1);
	}
	int i = 0; 
	string id(""), seq(""); 
	while(i < num_seqs)
	{
		getline(inFile, id); 
		getline(inFile, seq); 
		
		all_seqs[i].setSequence(seq);
		i++;
	}
	all_seqs[0].print();
	//ATG + TGT = ATGT
	
	Sequence *seed = new Sequence(all_seqs[0].getSequence());
	seed->print();
	//Sequence seed = all_seqs[0];
	//~ seed->print(); 
	
	*(seed) += all_seqs[1]; 
	//~ seed->print();
	
	//~ inFile.close();
	
	delete seed;
	delete [] all_seqs;
	return 0; 
}
