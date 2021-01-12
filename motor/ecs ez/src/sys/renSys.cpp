#include <sys/renSys.h>
#include <cmp/phyCmp.h>
#include <ecs/entSys.h>
#include <iostream>
#include <windows.h>
#include <console.h>

 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y = y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  

RenSys::RenSys()
{
    components.reserve(MAX_ENTITIES); // Reservar espacio para los physics components
    RenCmp::idSys = idSys;            // Fijar el id aleatorio del sistema al del componente

    // Limpiar pantalla
    system("cls");
}

RenSys::~RenSys()
{

}


void RenSys::update(EntSys& entSys)
{
    // Actualizar componentes
    for (size_t i = 0; i < components.size(); ++i)
    {
        RenCmp& renCmp = components[i];
        PhyCmp& phyCmp =  entSys.getCmp<PhyCmp>(renCmp.idEnt);

        renCmp.lx = renCmp.x;
        renCmp.ly = renCmp.y;

        renCmp.x = phyCmp.x;
        renCmp.y = phyCmp.y;

        // Limpiar caracter anterior
        gotoxy(renCmp.lx, renCmp.ly);
        printf("%c", ' ');

        // Dibujar caracter
        gotoxy(renCmp.x, renCmp.y);
        printf("%c", renCmp.representation);
    }

    std::cout << "\n";
}

// Añadir, obtener y eliminar componntes
Cmp* RenSys::addCmp(size_t idEnt)
{  
    return &components.emplace_back(idEnt);
}

Cmp* RenSys::getCmp(size_t idEnt)
{
    for (size_t i = 0; i < components.size(); ++i)
    {
        if (components[i].idEnt == idEnt)
        {
            return &components[i];
        }
    }

    static RenCmp RenCmp(0);

    return &RenCmp;
}

void RenSys::remCmp(size_t idEnt)
{
    for (size_t i = 0; i < components.size(); ++i)
    {
        if (components[i].idEnt == idEnt)
        {
            components.erase(components.begin() + i);
        }
    }
}
