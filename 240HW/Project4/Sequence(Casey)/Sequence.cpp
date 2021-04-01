#include "Sequence.h"

Sequence::Sequence()
{
	length = 100; 
	sequence = new char[length]; 
	for(int i = 0; i < length; i++) sequence[i] = '\0';
} 
Sequence::Sequence(string _str)
{
	length = 100; 
	sequence = new char[length]; 
	for(int i = 0; i < length; i++) sequence[i] = _str[i];
}
Sequence::~Sequence()
{
	delete [] sequence;
}

void Sequence::setSequence(string _seq)
{
	for(int i = 0; i < length; i++)
	{
		sequence[i] = _seq[i];
	}
}

string Sequence::getSequence()
{
	string ret(""); 
	for(int i = 0; i < length; i++) ret += sequence[i]; 
	return ret;
	//return sequence;
}

void Sequence::operator+=(Sequence& obj2)
{
	char * temp = sequence; 
	int old_length = length; 
	length = length + obj2.length; 
	sequence = new char[length + obj2.length]; 
	for(int i = 0; i < old_length; i++) 
		sequence[i] = temp[i]; 
	for(int i = old_length; i < length; i++) 
		sequence[i] = obj2.sequence[i-old_length]; 
	delete [] temp;
}

void Sequence::print()
{
	for(int i = 0; i < length; i++)
		cout << sequence[i]; 
	cout << endl;
}
