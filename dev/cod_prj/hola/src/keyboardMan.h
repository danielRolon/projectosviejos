#ifndef KEYBOARD_MAN_H
#define KEYBOARD_MAN_H

class KeyboardMan {
public:
    static void Update();
    inline static char GetLastkeyPressed() { return m_LastKeyPressed; }
    inline static KeyboardMan* GetKeyboardMan() { return p_KeyMan; }
private:
    static char m_LastKeyPressed;
    static KeyboardMan* p_KeyMan;
};

#endif // KEYBOARD_MAN_H
