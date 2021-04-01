#include <cstdlib>
#include <iostream>

using namespace std;

//Function that takes in a pointer
void test(int*);

//Function that returns a pointer
int* test_return(int); 

int main(int argc, char **argv)
{
	int *iPtr = new int[5];
	
	for(int i = 0; i < 5; i++){
		iPtr[i] = 0;
	}
	
	cout << iPtr << " " << &iPtr << endl;
	
	test(iPtr);
	

	//~ int *ptr2; 
	//~ ptr2 = test_return(5);
	//~ cout << ptr2 << endl;
	//~ //delete [] ptr2;
	//~ ptr2 = test_return(6, ptr2);

	//Must have a delete with each new. 
	
	
	return 0;
}

void test(int*& ptr)
{
	cout << ptr << " " << &ptr << endl;
	//Can I edit elements in iPtr?
	ptr[0] = 100;
	//Can I resize iPtr?
	//ptr = new int[6];
}

int* test_return(int n, int* old)
{
	delete [] old;
	int *temp = new int[n];
	return temp;
}
