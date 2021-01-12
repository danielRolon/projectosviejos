#pragma once

#include <stddef.h>

template <typename T>
class Array
{
private:
    size_t capacity { 0 };
    size_t numUsed { 0 };
    T** elements { nullptr };
public:
    explicit Array(size_t size);
    ~Array();

    T& operator[](size_t index);
    template <typename ...Args> T& add(Args&& ...args);

    void removeIndex(size_t index);
    void removeElement(T&& pElementToRemove);
    void removeElement(T& pElementToRemove);

    bool sideBounds(size_t index);
    size_t indexOf(T&& pElementToFind);
    size_t indexOf(T& pElementToFind);

    inline void clear() { numUsed = 0; }

    inline size_t size() { return numUsed; }
};

#include <utils/array.tpp>