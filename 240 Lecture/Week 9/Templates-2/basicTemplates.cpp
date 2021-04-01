

#include <cstdlib>
#include <iostream>


using namespace std;


//~ int add(int,int); 
//~ double add(double, double);
//~ double add(double, int);

template <class T> //typename T
T add(T,T);

template<>

//~ template <class T, class T2> //<typename T>
//~ T add(T,T2);


int main(int argc, char** argv) 
{
	
    int a(10),b(9), int_sum(0);
    double c(5.5), d(6.0), double_sum(0.0);
    
    int_sum = add(a,b); 
	cout << "The sum of a and b is : " << int_sum << endl;
	
	double_sum = add(c,d); 
	cout << "The sum of c and d is : " << double_sum << endl;
	
	int_sum = add(a,c);
	cout << "The sum of a and c is : " << int_sum << endl;

        
    return 0;
}

//~ template <class T, class T2> //always need this and the < > 
//~ T add(T a,T2 b)
//~ {
	//~ return a + b;
//~ }

template <class T> //always need this and the < > 
T add(T a, T b)
{
	return a + b;
}

template <>
char add (char a, char b)
{
	
}
