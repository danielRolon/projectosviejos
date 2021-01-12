#include <utils/array.h>
#include <functional>

#include <utils/debug.h>

template <typename T>
Array<T>::Array(size_t capacity) : capacity(capacity)
{
    elements = new T*[capacity];
}

template <typename T>
Array<T>::~Array()
{
    for (size_t i = 0; i < numUsed; ++i)
    {
        delete elements[i];
    }

    delete[] elements;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    return *elements[index];
}

template <typename T> template <typename ...Args> T& 
Array<T>::add(Args&& ...args)
{
    if (elements[numUsed])
        //elements[numUsed] = new T(std::forward<Args>(args)...);
        elements[numUsed] = new T(static_cast<Args&&>(args)...);

    return *elements[numUsed++];
}

template <typename T> void
Array<T>::removeIndex(size_t index)
{
    if (!sideBounds(index)) return;

    for (size_t i = index; i < numUsed; ++i)
    {
        if (i == numUsed - 1)
            break;
        *elements[i] = *elements[i + 1];
    }
    --numUsed;
}

template <typename T> void
Array<T>::removeElement(T&& pElementToRemove)
{
    size_t index = indexOf(static_cast<T&&>(pElementToRemove));
    removeIndex(index);
}

template <typename T> void
Array<T>::removeElement(T& pElementToRemove)
{
    size_t index = indexOf(pElementToRemove);
    removeIndex(index);
}


template <typename T> bool
Array<T>::sideBounds(size_t index)
{
    return (index < 0 || index >= numUsed) ? false : true;
}

template <typename T> size_t
Array<T>::indexOf(T&& pElementToFind)
{
    for (size_t i = 0; i < numUsed; ++i)
    {
        if (*elements[i] == pElementToFind) return i;
    }

    return -1;
}

template <typename T> size_t
Array<T>::indexOf(T& pElementToFind)
{
    for (size_t i = 0; i < numUsed; ++i)
    {
        if (&*elements[i] == &pElementToFind) return i;
    }

    return -1;
}