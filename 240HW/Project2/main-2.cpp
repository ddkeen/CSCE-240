

#include <cstdlib>
#include <iostream>

using namespace std;

int main (int argc, char **argv)
{   
	if(argc != 2)
	{
		cout << "Usage: ./a.out <num_rows>" << endl;
		exit(0);
	}
	int rows = atoi(argv[1]);
	
	return 0; 
}
