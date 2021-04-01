#include <iostream>

#include <string>

using namespace std;

int main(int argc, char **argv)
{
	//How to output: remember cout...
	//~ cout << "This is output." << endl;
	
	
	
	//Getting input from the terminal: cin
	//~ int a(1), b(0);
	//~ //int a = 1; 
	//~ //int b = 0;
	//~ cout << "Give me two numbers : " << endl;
	//~ std::cin >> a >> b;
	//~ //cin >> b; 
	//~ cout << " The sum is : " << a + b << endl;
	//float num = 1.2;

	//Note about characters... Addition does not work the way that you think...
	//~ char c(' ');
	//~ c = '8';
	//~ c = c+1; 
	//~ cout << c << endl; 
	 
	
	//However... has a cool consequence: 
	//~ c = 'c';
	//~ char d = c + 1; 
	
	//~ cout << "The value of c is: " << c << endl; 
	//~ cout << "The value of d is: " << d << endl;
	
	
	
	//cascaded equals
	int u,v; 
	u = v = 1;
	cout << "u is : " << u << " and v is " << v << endl;
	//~ //string name = "casey";
	
	
	//if/else statements
	//~ int x = 15;	
	//~ if(x == 20)
	//~ { 
		//~ cout << "hello" <<endl;
	//~ }
	//~ else
	//~ {
		//~ cout << "goodbye" << endl;
	//~ }
	
	
	//if/else if/else statements
	//Which one(s) will be executed?
	//~ x = 20; 
	//~ if(x > 10) 
	//~ {
		//~ cout << "x is greater than 10" << endl; 
	//~ }
	//~ if(x > 5) 
	//~ {
		//~ cout << "x is greater than 5" << endl; 
	//~ }
	
	//What about now? What will be printed to the terminal?
	//~ if(x > 10) 
	//~ {
		//~ cout << "x is greater than 10" << endl; 
	//~ }
	//~ if(x > 5) 
	//~ {
		//~ cout << "x is greater than 5" << endl; 
	//~ }
	
	
	//KNOW the difference! 
	
	//YES! There is a switch statement, but ehhh. pg 64-66 if interested. 
	
	
	//What will happen here?
	//~ x = 10; 
	//~ int y; 
	//~ //y = x = 0;
	//~ if(x = 15) //x = 15 
	//~ {
		//~ cout << "X is equal to 15" << endl; 
	//~ }
	
	
	
	//The WHILE Loop
	//~ int i = 0; //initialization
	//~ while(i < 10) //condition
	//~ {
		//~ cout << i << endl;
		//~ i++; //update step i = i + 1
		//++i;
		
		//~ i = i + 1; 
	//~ }
	
	//Breif aside... ever seen it written like ++i? 
	//There is a difference! 
	
	//post increment: 
	//~ int test = 0;
	//~ int test2;
	//~ test2 = ++test; 
	//~ cout << test++ << endl; 
	
	//~ //pre increment: 
	//~ test = 0; 
	//~ cout << ++test << endl;
	
	//In the case of loops you can use either one since it checks the
	//condition before you increment. 
	
	//...Back to class now ... 
	
	//The for loop: 
	for(int i = 0; i < 10; i=i+2)//i is local to for loop
	{
		cout << i << endl;
	}
	
	//Can I access the following?
	//cout << i << endl;
	
	
	//do-while loop
	//~ int m = 20; 
	//~ do{
		//~ //do something
	//~ }while(m < 20);
	
	
	return 0;
}
