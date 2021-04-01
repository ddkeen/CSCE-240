#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


int main (int argc, char **argv)
{   
	//print out argc 
	//cout << "The value of argc is: " << argc << endl;
	
	//print out one of the arguments
	//cout << "The value of argv[0] is: " << argv[0] << endl;
	
	//loop through all the arguments 
	
	
	//Remember argv is a char array. We need to convert it to an integer...
	int real_num = atoi(argv[1]);
	cout << "The value of real_num is: " << real_num << endl;
	
	//Usage statements: 
	
	
    return 0;
}
