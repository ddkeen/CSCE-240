// new HashEntry *[buckets];

#include <cstdlib>
#include <iostream>

using namespace std;

class HashEntry{
	public : 
		HashEntry(){
			key = -1; 
			value = 0.0;
			next = null;
		}
		int getKey(){
			return key;
		}
		float getValue(){
			return value;
		}
		void setKeyValue(int _key, float _value){
			//TODO: error check 
			key = _key; 
			value = _value;
		}
		void setNext(HashEntry * _next){
			next = _next;
		}
		HashEntry* getNext()
		{
			return next;
		}
	private : 
		int key; 
		float value;
		HashEntry * next;
	
};

class HashTable {
	public : 
		HashTable(int _buckets){
			buckets = _buckets; 
			t = new HashEntry*[buckets];
			for(int i = 0; i < buckets; i++) 
			{
				t[i] = null;
			}
		}
		~HashTable(){
			delete [] t;
		}
		void insert(int _key, float _value){
			int ind = hash(_key); 
			//If we find the key at the location it should be 
			if(t[ind] != null) {
				//TODO: Set value
				//t[ind].setKeyValue(_key, _value);
				int i = 0; 
				bool found = false;
				HashEntry *curr;
				while(t[ind][i].getNext() != null){
					if(t[ind][i].getKey() == _key)
					{
						t[ind][i].setKeyValue(_key, _value);
						found = true;
						break; 
					}
					curr = t[ind][i].getNext();
					i++;
				}
				if(!found){
					HashEntry * newNode = new HashEntry; 
					newNode.setKeyValue(_key, _value); 
					curr.setNext(newNode);
				}
				
			}
			//If spot empty
			else if(t[ind] == null){
				t[ind] = new HashEntry[1];
				t[ind][0].setKeyValue(_key,_value);
	
			}
			
		}
		void remove(int _key)
		{
			int ind = hash(_key); 
			if(t[ind].getKey() == _key){
				t[ind].setKeyValue(-1,0.0);
			}
			else if(t[ind].getKey() == -1){
				cout << "Key did not exist" << endl;
			}
			else{
				int prev_ind = ind;
				ind = (ind + 1) % buckets;
				while(t[ind].getKey() != -1) {
					if(t[ind].getKey() == _key)
					{
						t[ind].setKeyValue(-1,0.0);
						
						break;
					}
					ind = (ind +1) % buckets;
				}
				
			}
		}
		
		int hash(int _key){
			return _key % buckets;
		}
		
		void print(){
			for(int i = 0; i < buckets; i++)
			{
				if(t[i].getKey() == -1){
					cout << "NULL" << " "; 
				}
				else{
					cout << t[i].getValue() << " "; 
				}
			}
			cout << endl;
		}
	private : 
		int buckets;
		HashEntry **t;
		
};
int main(int argc, char** argv) 
{
	HashTable t(100);
	t.insert(0,2.5); 
	t.insert(0,2.7); 
	t.insert(100,3.5);
	t.insert(100,3.7);
	t.remove(0);
	
	t.print();
	return 0; 
}

