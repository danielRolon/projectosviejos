#include "lib/lib.h"
#include <stdio.h>

int main(void) {

	bool run = true;
	int x = 10, y = 10;

	Lib::Console::init();
	Lib::Console::setCursorSize(5);
	Lib::Console::setCursorVisible(false);

	Lib::Canvas::init(40, 40);

	while (!Lib::Keyboard::Down('q') && run) {
		// UPDATE
		x += (Lib::Keyboard::Down('d') - Lib::Keyboard::Down('a'));
		y += (Lib::Keyboard::Down('s') - Lib::Keyboard::Down('w'));
		// DRAW

		// DRAW PLAYER
		Lib::Canvas::draw("P", x, y);

		Lib::Canvas::refresh();
	}
	

	return 0;
}