
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

/*int fact(int n){
   //Base case, when n <= 1 return 1
   //else n*fact(n-1)
   
}*/

int main()
{
   //~ cout <<"Factorial of 1 "<< fact(1);
   //~ cout <<"Factorial of 4 "<< fact(4);
   
   //Random number generation
   int randomNumber = rand();
   //~ cout << randomNumber << endl;
   //~ cout << RAND_MAX << endl;
   //srand(999);
   srand(time(0));
   //cout << time(0) << endl;
   randomNumber = -1 ;
	for (int index = 0; index < 10; index++) 
	{
		randomNumber = (rand() % 10); //0 -> 9
		cout << randomNumber << endl;
	}
	
	//Notice not so random?
	//Need a seed
	//~ srand(999);//?
	//~ cout << time(0) << endl;
	//~ srand((unsigned) time(0));
   
   return 0;
}
