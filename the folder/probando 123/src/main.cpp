#include <utils/array.h>
#include <utils/debug.h>
#include <vector>

template <typename T> void printArray(Array<T>& array);

struct A { 
    explicit A() = default;
    virtual ~A() {}
    virtual void print() {}
};
struct B : A { 
    explicit B() = default;
    ~B() {}
    void print() override {
        LOG "Soy La clase BB" END;
    }
};

int main(int argv, char* args[])
{
   /* Array<bool> array = Array<bool>(100);

    array.add(true);
    array.add(false);

    LOG array[0] END;

    //printArray<bool>(array);*/
    
    return 0;
}

template <typename T> void printArray(Array<T>& array)
{
    for (size_t i = 0; i < array.size(); ++i)
    {
        LOG array[i] END;
    }

    LOG "size: " << array.size() END;
}