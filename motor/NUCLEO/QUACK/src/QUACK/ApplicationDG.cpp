#include <QUACK/ApplicationDG.h>

#include <iostream>

namespace DUCKGAME
{
	ApplicationDG::ApplicationDG() {
		std::cout << "Applicacion DuckGame creada :D" << "\n";
	}

	ApplicationDG::~ApplicationDG(){}

	void ApplicationDG::update()
	{
		std::cout << "Applicacion DuckGame actualizada <;3" << "\n";
	}
}