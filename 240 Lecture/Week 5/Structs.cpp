#include <iostream> 
#include <string>
using namespace std; 

//Basically an object with no functions and everything is public. 
struct book
{
	int numPages; 
	float price; 
	string title;
	string author;
}; //Note: optionally declare names here. 

  
int main() 
{  
	book greatExp;
	
	//What would we get: 
	//cout << sizeof(greatExp) << endl;
	
	greatExp.title = "Great Expectations"; 
	greatExp.numPages = 400; 
	greatExp.author = "Charles Dickens"; 
	greatExp.price = 10.99;
	
	
	book collection[3]; //create a database of books?
	
	return 0; 
}
