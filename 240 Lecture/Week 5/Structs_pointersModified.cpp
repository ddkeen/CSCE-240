#include <iostream> 
#include <string>
using namespace std; 

//Let's make a linked list! 
struct node
{
	int data; 
	node *next;
	node *prev;
};  

//ifstream operator<<(node);
  
int main() 
{  
	node head;
	head.data = 10; 
	node tail;
	tail.data = 100;
	//cout << tail << endl;
	
	cout << &tail << endl;
	head.next = &tail;
	head.prev = &tail;
	tail.prev = &head;
	tail.next = &head;
	
	cout << head.next->data << endl;
	
	return 0; 
}
