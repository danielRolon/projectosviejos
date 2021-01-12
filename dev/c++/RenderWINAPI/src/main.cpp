#include<iostream>

#include <appWindow.h>

int main()
{ 

    AppWindow app;

    if (!app.init())
        return 0;

    while(app.isRun())
    {
        app.broadcast();
    }

    std::cout << "xd\n";

    return 0;
}