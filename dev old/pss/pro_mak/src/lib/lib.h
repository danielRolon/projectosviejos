#ifndef LIB_H
#define LIB_H

#include <vector>

struct BoxChar;

namespace Lib {
	namespace Canvas {
		void init(int width, int height);
		void draw(const char* text, int x, int y);
		void clear();
		void refresh();
	}
	namespace Console {
		void init(void);
		void gotoxy(int x, int y);
		void setCursorVisible(bool visible);
		void setCursorSize(int tam);
		void setColor(int color);
	}
	namespace Keyboard {
		bool update();
		bool Down(char keyChar);
	}
}

#endif