#include <cstdlib>
#include <iostream>
#include <fstream> //must include this now
#include <string>


using namespace std;
/*
 * 
 */
int main(int argc, char** argv) 
{
	//set up streams
    ifstream inFile; //child of istream
   //ifstream inFile(argv[1]); //alternate constructor
    ofstream outFile; //child of ostream
    
    //Usage statement
    //Usage: ./a.out <input_file> <output_file> or exit(1);
    
    
    //open files
    //inFile.open("./input.txt");
    //inFile.open(argv[1]); 
    
    //outFile.open("./out.txt");
    //outFile.open(argv[2]); //open to overwrite
    //outFile.open(argv[2], ios::app); //open to append
    
    //error checking
    //~ if(inFile.fail())
    //~ {
		//~ cout << "Error reading the input file " << endl; 
		//~ exit(1);
	//~ }
	//~ if(outFile.fail())
    //~ {
		//~ cout << "Error opening the output file " << endl; 
		//~ exit(1);
	//~ }
    
    //reading data using >> 
    //~ int a,b,c;
    //~ inFile >> a >> b >> c;
    
    //~ //writing data using << 
    //~ outFile << "First three numbers: " << a << " " << b << " "<< c << endl;
    
    
    //~ char next(0);
    //~ while(inFile.eof() == false) //! inFile.eof
    //~ {
		//~ inFile.get(next);
		//~ outFile << next; 
		
	//~ }
	
	//Use case #1 covert space delimited to comma delimited. 
    //2 options: 1 - two gets or if logic to check that char is not space
    //~ char next(0), junk(0);
    //~ while(inFile.eof() == false) //! inFile.eof
    //~ {
		
		
	//~ }
	
	
	
	//Reading line by line
	//~ string line("");
	//~ while(!inFile.eof())
	//~ {
		//~ getline(inFile, line);
		//~ cout << line << endl;
		//~ outFile << line << endl;
	//~ }
	
    //Use case #2 stripping the headers off of a FASTA file. 
    
    
    //closing files -- flush the buffer
    inFile.close();
    outFile.close();
       
    return 0;
}
