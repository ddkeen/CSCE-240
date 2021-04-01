#include "intArray.h"

intArray::intArray()
{
	
}

int intArray::operator[](int index)
{
	//error check for negative index
}

intArray& intArray::operator=(intArray& obj2)
{
	size = obj2.getSize();
	for(int i=0; i<size; i++)
	{
		data[i] = obj2[i];
	}
	return this;
}
