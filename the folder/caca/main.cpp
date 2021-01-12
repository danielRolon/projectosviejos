#include <iostream>
#include <vector>

struct E {
	int id;
	explicit E(int id) : id(id) {}
};

struct A : public E
{
	int num = 100;
	A(int num) : E(123), num(num) {}
	~A(){}
	void print() { std::cout << "A num: " << num << "\n"; }
};

struct B : public E
{
	int num = 100;
	B(int num) : E(435), num(num) {}
	~B(){}
	void print() { std::cout << "B num: " << num << "\n"; }
};

std::vector<E*> vectorE; // vector

// No se que coño hace esto pero funciona
template<class T, class... Args>
void createClass(Args&&... args)
{
	//return new T(std::forward<Args>(args)...);
	vectorE.emplace_back(std::forward<Args>(args)...);
}

int main(void) 
{

	
	createClass<E*>(34);

	return 0;
}