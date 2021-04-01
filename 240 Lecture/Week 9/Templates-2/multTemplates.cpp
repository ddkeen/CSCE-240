

#include <cstdlib>
#include <iostream>


using namespace std;

template <class K, class V>
class myPair
{
	public: 
		myPair(K _key, V _value);
		void print();  
	
	private:
		K key; 
		V value; 
}; 

template <class K, class V>
myPair<K,V>::myPair(K _key, V _value)
{
	key = _key;
	value = _value;
}

template <class K, class V>
void myPair<K,V>::print()
{
	cout << "Key: " << key << endl; 
	cout << "Value: " << value << endl;
}



int main(int argc, char** argv) 
{
    myPair<int,char> pair1(1,'A');
    pair1.print();
	
	myPair<char,char> pair2('A','Z');
	pair2.print();
        
    return 0;
}



