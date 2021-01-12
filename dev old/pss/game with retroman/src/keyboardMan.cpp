#include <keyboardMan.h>
#include <windows.h>
#include <stdio.h>

#include <conio.h>

char KeyboardMan::m_LastKeyPressed = 'n';
KeyboardMan* KeyboardMan::p_KeyMan = new KeyboardMan();

void KeyboardMan::Update() {
    m_LastKeyPressed = getch();
}