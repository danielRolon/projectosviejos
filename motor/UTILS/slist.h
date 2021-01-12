#pragma once

template <typename T>
class SList
{
public:
	inline SList(size_t reserve);
	inline ~SList();

	inline T& operator[](size_t index)
	{
		return *ptr[index];
	}

	inline void push(T* element);
	inline void push(size_t index, T* element);
	inline void pop();
	inline void pop(size_t index);
	inline void clear();

	inline size_t size()     { return count; }
	inline size_t reserved() { return reserve;  }

private:
	inline void memcopy(T** ptr1, T** ptr2, size_t from, size_t to);

private:
	T** ptr = nullptr;
	T** ptr_aux = nullptr;
	size_t reserve = 0;
	size_t count = 0;
};

#include "slist.tpp"