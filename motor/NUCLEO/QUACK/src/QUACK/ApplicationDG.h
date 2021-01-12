#pragma once

#include <QUACK/Core.h>

namespace DUCKGAME
{
	class DG_API ApplicationDG
	{
	public:
		ApplicationDG();
		virtual ~ApplicationDG();

		void update();
	};

	ApplicationDG* createApplicationDG();
}