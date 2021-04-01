#include "intArray.h"

intArray::intArray(){
	data = new int[0];
	size = 0;
} //Default

//init data to _size and set all values to _val
intArray::intArray(int _size, int _val)
{
	data = new int[_size]; 
	for(int i = 0; i < _size; i++) 
	{
		data[i] = _val;
	}
	size = _size;
} //Alternate constructor

intArray::intArray(const intArray& obj2)
{
	//data = obj2.data; //shallow copy
	data = new int[obj2.getSize()];
	size = obj2.getSize();
	for(int i = 0 ; i < size; i++) 
	{
		data[i] = obj2.getData()[i];
		//if operator[] is overloaded
		//data[i] = obj2[i];
	}
	
} //Copy constructor 

intArray::~intArray()
{
	delete [] data;
} //Destructor


intArray intArray::operator+(intArray& obj2) const
{
	intArray temp(obj2);
	if(size == obj2.getSize()) 
	{
		for(int i = 0 ; i < size; i++) 
		{
			temp.getData()[i] += data[i]; 
		}
		return temp;
	}
	return temp;
}

intArray& intArray::operator=(intArray obj2)
{
	size = obj2.getSize(); 
	for(int i = 0; i < size; i++) 
	{
		data[i] = obj2[i]; 
	}
	return *this;
}

int intArray::operator[](int index) const
{
	return data[index];
}


void intArray::operator()(int index, int num)
{
	data[index] = num;
}

int& intArray::operator[](int index)
{
	return data[index];
}

intArray intArray::operator++(int dummy)
{
	intArray temp(*this);
	for(int i = 0; i < size; i++)
	{
		data[i] += 1;
	}
	return temp;
}

intArray& intArray::operator++()
{
	for(int i = 0; i < size; i++)
	{
		data[i] += 1;
	}
	return *this;
}

void intArray::operator<<(ostream& os)
{
	for(int i = 0; i < size; i++)
	{
		os << data[i] << " ";
	}
	os << endl;
}

ostream& operator<<(ostream& os, intArray& rhs)
{
	for(int i = 0; i < rhs.getSize(); i++)
	{
		os << rhs[i] << " ";
	}
	os << endl;
	return os;
}

istream& operator>>(istream& is, intArray& rhs)
{
	for(int i = 0; i < rhs.getSize(); i++)
	{
		is >> rhs[i]; 
	}
	return is;
}

intArray operator+(int val, intArray& rhs)
{
	intArray temp(rhs.getSize()+1, 0);
	temp[0] = val;
	for(int i = 0; i < rhs.getSize(); i++)
	{
		temp[i+1] = rhs[i];
	}
	return temp;
}

void intArray::print() const
{
	for(int i = 0 ; i < size; i++) 
	{
		cout << data[i] << " ";
	}
	cout << endl;
}


int* intArray::getData() const
{
	return data;
} 

int intArray::getSize() const
{
	return size; 
}

void intArray::setData(int* _data)
{
	data = _data;
}

void intArray::setSize(int _size)
{
	if(_size > 0) size = _size;
	else size = 0; //raise error/warning
}

 
