#include <iostream>
#include <vector>
#include <windows.h>

void gotoxy(int x, int y) {

}

using llui = long long unsigned int;

struct Entity {
	explicit Entity(int x, int y) : x(x), y(y) {}
	virtual ~Entity() {}
	virtual print() {
		std::cout << "m_X    : " << x << "\n";
		std::cout << "m_Y    : " << y << "\n";
	}

	virtual void info() {
		std::cout << "this   : " << this << "\n";
		std::cout << "size   : " << GetSize() << "\n";
		std::cout << "m_X    : " << &x << "\n";
		std::cout << "m_Y    : " << &y << "\n";
	}
	virtual llui GetSize() const = 0;
protected:
	int x { 0 }, y { 0 };
};

struct Player : public Entity {
	explicit Player(int x, int y) : Entity(x, y) {}
	~Player() {}
	print() override {
		std::cout << "Soy Player" << "\n";
		Entity::info();
	}
	llui GetSize() const override {
		return sizeof(*this);
	}
};

struct Wall : public Entity {
	explicit Wall(int x, int y) : Entity(x, y) {}
	~Wall() {}
	print() override {
		std::cout << "Soy Wall" << "\n";
		Entity::info();
	}
	llui GetSize() const override {
		return sizeof(*this);
	}
	bool solid { false };
};

int main(int argn, char* args[]) {

	std::vector<Entity*> vEntities;

	vEntities.reserve(128);

	vEntities.emplace_back(new Player(2, 3));

	for (uint32_t i = 0; i < 5; ++i) {
		for (uint32_t j = 0; j < 5; ++i) {
			if (i == j)
				vEntities.emplace_back(new Wall(j, i));
		}
	}


	//Print entities
	for (uint32_t i = 0; i < vEntities.size(); ++i) {
		if (vEntities[i]->GetSize() == sizeof(Player))
			std::cout << vEntities[i]->GetSize() << "\n";

		//vEntities[i]->print();
	}

	return 0;
}