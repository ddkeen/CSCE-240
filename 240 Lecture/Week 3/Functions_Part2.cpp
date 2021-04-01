/***************************************************************************
 * Name: Casey Cole
 * 
 * Date/Time of Completion: 09/03/19 
 * 
 * Function: Demonstrate some useful basic C++ programming.
 * 
 * Input:
 *  
 * Output:
 * 
 * Additional Comments:                                       *
 *                                                                         *
 ***************************************************************************/

#include <cstdlib>
#include <iostream>


using namespace std;

// General form of functions: <return type> <name of function>(<parameters>)
// Question: Why have prototypes?

double average(int,int,int,int);

//adding default values: 
//double average(int x = 1,int,int,int); //NO!
//double average(int,int,int n3 = 10,int n4 = 1);


int main (int argc, char **argv)
{   
	cout << average(1,2,3,4) << endl;
	cout << average(1,2,3) <<endl;
	cout << average(1,2) <<endl;  
	
	
	//~ double avg(0.0); 
	//~ cout << "Value Avg before call: " << avg << endl; 
	//~ average(1,2,3,4,avg);
	//~ cout << "Value Avg after call: " << avg << endl;
	
	return 0;
}


