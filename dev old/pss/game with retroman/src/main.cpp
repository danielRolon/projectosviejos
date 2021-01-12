#include <iostream>
#include <game.h>

int main() {
    std::cout << "Init!\n";

    Game* game = new Game();

    game->MainLoop();

    delete game; game = nullptr;

    std::cout << "The End!\n";
    return 0;
}
