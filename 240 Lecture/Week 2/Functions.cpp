#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//Step 1: function prototype

int main(int argc, char **argv)
{
	int randomNum = -1;
	int number = 0; 
	 
	cout << "Please enter another number: " << endl;
	cin >> number; 
	 
	for(int i = 0; i < number; i++)
	{
		randomNum = rand() % 10 + 1; 
		cout << "Random number " << i << " : " << randomNum << endl;
	}
	
	//~ int i = -1; 
	//~ cout << "Before: " << i << endl; 
	//~ i = changeNum();
	//~ changeNum(i);
	//~ cout << "After: " << i << endl;
	
	
	return 0;
}


//Step 2: function definition



