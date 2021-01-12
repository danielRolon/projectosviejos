#pragma once

#include <windows.h>
#include <iostream>

namespace Console
{
    inline HANDLE hout= GetStdHandle(STD_OUTPUT_HANDLE); 
    inline HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); 
    inline INPUT_RECORD InputRecord; 
    inline DWORD Events; 
    inline COORD coord; 
    inline CONSOLE_CURSOR_INFO cci;
    
    void Update();
}