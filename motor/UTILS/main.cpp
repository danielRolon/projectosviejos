#include <iostream>
#include <stdio.h>
#include "slist.h"

void printArray();

struct P
{
	const char* name = nullptr;
	P(const char* name)
		: name(name)
	{
		std::cout << "Create " << name << "\n";
	}

	~P()
	{
		std::cout << "Destroy " << name << "\n";
		delete[]name;
	}
};

int main()
{
	SList<P> list(10);

	const char* names[] = {"a", "b", "c", "d", "e"};

	for (size_t i = 0; i < 5; ++i)
		list.push(i, new P(names[i]));

	list.pop();
	
	for (size_t i = 0; i < list.size(); ++i)
		std::cout << "name: " << list[i].name << "\n";

	std::cout << list.size() << "\n";

	//system("pause");

	return 0;
}

void printArray()
{
	unsigned int length = 2;
	unsigned int **ptr = new unsigned int*[length];
	ptr[0] = new unsigned int(10);
	ptr[1] = new unsigned int(1);

	for (unsigned int i = 0; i < length; ++i)
	{
		std::cout << ptr << "\n";
		std::cout << "place memory ptr[" << i <<"]" << &ptr[i] << "\n";
		std::cout << "value ptr[" << i <<"]       " <<  ptr[i] << "\n";
		std::cout << "desrf ptr[" << i <<"]       " << *ptr[i] << "\n\n";
	}

}