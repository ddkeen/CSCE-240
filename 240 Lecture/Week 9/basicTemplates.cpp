

#include <cstdlib>
#include <iostream>


using namespace std;

//~ int add(int,int); 
//~ double add(double, double);
//double add(double, int);

template <class T> //<typename T>
T* add(T,T);

template <>
char* add(char,char);

//~ template <class T, class T2> //<typename T>
//~ T add(T,T2);


int main(int argc, char** argv) 
{
	
    int a(10),b(9), *int_sum;
    double c(5.5), d(6.0), *double_sum;
    
    int_sum = add(a,b); 
	cout << "The sum of a and b is : " << *int_sum << endl;
	
	double_sum = add(c,d); 
	cout << "The sum of c and d is : " << *double_sum << endl;
	
	char e('e'), f('f'), *char_sum; 
	char_sum = add(e,f);
	cout << "The sum of e and f is : " ; 
	for(int i = 0; i < 2; i++)
	{
		cout << char_sum[i] << " ";

	}
	cout << endl;
	//~ double_sum = add(a,c);
	//~ cout << "The sum of a and c is : " << double_sum << endl;
	
	delete int_sum; 
	delete double_sum; 
	delete [] char_sum;
        
    return 0;
}
//~ int add(int a,int b)
//~ {
	//~ return a + b; 
//~ }
//~ double add(double a, double b)
//~ {
	//~ return a+b; 
//~ }

template <class T> //<typename T>
T* add(T a,T b)
{ 
	static int i = 0;
	i++;
	cout << "i = " << i << endl;
	T* ret = new T; 
	*ret = a+b;
	return ret;
}

template <>
char* add(char a, char b)
{
	char* ret = new char[2]; 
	ret[0] = a; 
	ret[1] = b; 
	return ret;
}

//~ template <class T, class T2>
//~ T add(T a,T2 b)
//~ {
	//~ return a + b;
//~ }


