#include <iostream> 
#include <string>
using namespace std; 

//Basically an object with no functions and everything is public. 
struct book
{
	int numPages; //4 bytes
	float price;  //4 bytes
	string title; //8 bytes char*, 4 bytes int size, 8 bytes *this
	string author;
} greatExp, mobyDick; //Note: optionally declare names here. 

void initBook(book&);  
book* addNewBook(book*, book, int&);

int main() 
{  
	book greatExp;
	mobyDick.title = "Moby Dick";
	
	//What would we get: 
	//cout << sizeof(greatExp) << endl;
	
	greatExp.title = "Great Expectations"; 
	greatExp.numPages = 400; 
	greatExp.author = "Charles Dickens"; 
	greatExp.price = 10.99;
	
	
	//~ book collection2[3]; //create a database of books?
	//~ for(int i = 0; i < 3; i++)
	//~ {
		//~ initBook(collection[i]); 
		//~ //cout << "i: " << i << " " <<  &collection[i] << endl;
	//~ }
	//~ for(int i = 0; i < 3; i++)
	//~ {
		//~ cout << collection2[i].title << endl;
	//~ }
	book *collection;
	collection = new book[10];
	int size = 10;
	
	for(int i = 0; i < size; i++)
	{
		initBook(collection[i]); 
		//cout << "i: " << i << " " <<  &collection[i] << endl;
	}
	
	collection = addNewBook(collection, greatExp, size);
	for(int i = 0; i < size; i++)
	{
		//initBook(collection[i]); 
		cout << collection[i].title << endl;
	}
	delete [] collection;
	return 0; 
}

book* addNewBook(book* collection, book b, int& size)
{
	book *ret = new book[size+1];
	for(int i = 0; i< size; i++)
	{
		ret[i].title = collection[i].title;
	}
	ret[size].title = b.title;
	size = size + 1;
	delete [] collection;
	return ret;
}


void initBook(book &b)
{
	//cout << &b << endl;
	cout << "Enter a title: " << endl; 
	cin >> b.title;
}
