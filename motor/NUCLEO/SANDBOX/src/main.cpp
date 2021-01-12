#include <QUACK/DUCKGAME.h>

class SandBox : public DUCKGAME::ApplicationDG
{
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}
};

DUCKGAME::ApplicationDG* DUCKGAME::createApplicationDG()
{
	return new SandBox();
}