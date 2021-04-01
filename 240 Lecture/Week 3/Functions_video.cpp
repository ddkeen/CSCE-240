#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//Step 1: function prototype
int returnNum(int); 
void callByRef(int&);

int main(int argc, char **argv)
{
	//Step 3: Function Call
	int ret = 0;
	int val = 1;
	ret = returnNum(val);
	cout << "Return is: " << ret << endl;
	cout << "Val is: " << val << endl;
	cout << "Mem Location of val: " << &val << endl;
	
	//~ callByRef(val);
	//~ cout << "Val is: " << val << endl;
	//~ cout << "Mem Location of val: " << &val << endl;
	
	return 0;
}


//Step 2: function definition
//call-by-value
int returnNum(int n)
{
	// n is local
	// if modified there will be no change in main. 
	cout << "Mem Location of n: " << &n << endl;
	n = 10;
	return n; 
}

//call-by-reference
void callByRef(int & n)
{
	//cout << "Mem Location of n: " << &n << endl;
	n = 10;
}
