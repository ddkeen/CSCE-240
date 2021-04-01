#include <iostream>
#include <string>
using namespace std;

class Sequence {
	
	public: 
		Sequence(); 
		Sequence(string); 
		~Sequence();
		
		void setSequence(string); 
		string getSequence(); 
		
		void operator+=(Sequence&); 
		void print(); 
		
	private: 
		char *sequence; 
		int length; 
};
