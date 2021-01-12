#include "slist.h"

#include <string.h>

template <typename T>
SList<T>::SList(size_t reserve)
	: reserve(reserve)
{
	ptr = new T*[reserve];
	ptr_aux = new T*[reserve];
}

template <typename T>
SList<T>::~SList()
{
	for (size_t i = 0; i < count; ++i)
	{
		if (ptr[i])
			delete ptr[i];
	}

	delete[]ptr;
}

template <typename T>
void SList<T>::push(T* element)
{
	ptr[count] = element;
	++count;
}

template <typename T>
void SList<T>::push(size_t index, T* element)
{
	//if (count < 1 || index >= count) return;

	if (count > 0 && index < count)
	{
		memcopy(ptr_aux, ptr, index, count);

		for (size_t i = index; i < count-1; ++i)
		{
			delete ptr[i+1];
			ptr[i+1] = ptr_aux[i];
		}

		ptr[count] = ptr_aux[count-1];
		++count;

		ptr[index] = element;
	}
	else if (index == count)
	{
		push(element);
	} 
}

template <typename T>
void SList<T>::memcopy(T** ptr1, T** ptr2, size_t from, size_t to)
{
	for (size_t i = from; i < to; ++i)
	{
		if (ptr1[i]) {
			delete ptr1[i];
		 	ptr1[i] = nullptr;
		}

		memcpy(ptr1[i], ptr2[i], sizeof(T));
	}
}

template <typename T>
void SList<T>::pop()
{
	if (count < 1) return;

	delete ptr[--count];
}

template <typename T>
void SList<T>::pop(size_t index)
{
	if (count < 1 || index >= count) return;

	if (index == count-1)
	{
		delete ptr[--count];
	}
	else
	{
		delete ptr[index];
		for (size_t i = index; i < count-2; ++i)
		{
			ptr[i] = ptr[i+1];
		}

		T *aux = (T*) malloc(sizeof(T));
		memcpy(aux, ptr[count-1], sizeof(T));

		delete ptr[count-1];

		ptr[count-2] = aux;

		--count;
	}

}

template <typename T>
void SList<T>::clear(){
	for (size_t i = 0; i < count; ++i)
	{
		if (ptr[i])
			delete ptr[i];
	}

	delete[]ptr;

	count = 0;
}