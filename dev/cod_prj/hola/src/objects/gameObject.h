#pragma once

class GameObject{
public:
    GameObject(int, int, int, bool, char);
    virtual ~GameObject();

    virtual void Update() = 0;
    void Draw() const;
protected:
    int m_X { 0 }, m_Y { 0 }, m_zB { 0 };
    bool m_Solid { false };
    char m_Char { 'n' };
};
