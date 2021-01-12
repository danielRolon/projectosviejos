#include <sys/scrSys.h>
#include <ecs/entSys.h>
#include <iostream>
#include <windows.h>

ScrSys::ScrSys()
{
    components.reserve(MAX_ENTITIES); // Reservar espacio para los behavior components
    ScrCmp::idSys = idSys;            // Fijar de los componentes
}

ScrSys::~ScrSys()
{

}


void ScrSys::update(EntSys& entSys)
{
    // Actualizar componentes
    for (size_t i = 0; i < components.size(); ++i)
    {
        ScrCmp& scrCmp = components[i];
        scrCmp.behavior(entSys, scrCmp.idEnt);
    }

    std::cout << "\n";
}

// Añadir, obtener y eliminar componntes
Cmp* ScrSys::addCmp(size_t idEnt)
{  
    return &components.emplace_back(idEnt);
}

Cmp* ScrSys::getCmp(size_t idEnt)
{
    for (size_t i = 0; i < components.size(); ++i)
    {
        if (components[i].idEnt == idEnt)
        {
            return &components[i];
        }
    }

    static ScrCmp scrCmp(0);

    return &scrCmp;
}

void ScrSys::remCmp(size_t idEnt)
{
    for (size_t i = 0; i < components.size(); ++i)
    {
        if (components[i].idEnt == idEnt)
        {
            components.erase(components.begin() + i);
        }
    }
}
