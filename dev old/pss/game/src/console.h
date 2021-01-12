#include <stdlib.h>
#include <stdio.h>

#include <iostream> 
#include <cstring> 
#include <cstdarg>

void clear()
{
printf("33[%d;%df", 0, 0);
//fflush(stdout);
}

void move(int x, int y) 
{
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos); 
}