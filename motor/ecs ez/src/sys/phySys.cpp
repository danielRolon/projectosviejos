#include <sys/phySys.h>
#include <ecs/entSys.h>
#include <ecs/event/phyEvent.h>
#include <iostream>
#include <console.h>
#include <math.h>
PhySys::PhySys()
{
    components.reserve(MAX_ENTITIES); // Reservar espacio para los physics components
    PhyCmp::idSys = idSys;            // Fijar el id aleatorio del sistema al del componente
}

PhySys::~PhySys()
{

}


void PhySys::update(EntSys& entSys)
{
    // Cambiar la velocidad
    for (size_t i = 0; i < components.size(); ++i)
    {
        PhyCmp& phyCmpI = components[i];

        for (size_t j = 0; j < components.size(); ++j)
        {  
            PhyCmp& phyCmpJ = components[j];

            if (i == j) continue;

            /* Collide */
            if (ceil(phyCmpI.x) == ceil(phyCmpJ.x) && ceil(phyCmpI.y) == ceil(phyCmpJ.y))
            {
                auto& phyEventI = entSys.eventMan.addEvent<PhyEvent>();
                phyEventI.collideEntId = phyCmpJ.idEnt;
            }

        }
     }

    // Mover componentes
    for (size_t i = 0; i < components.size(); ++i)
    {
        PhyCmp& phyCmp = components[i];

        if (phyCmp.x + phyCmp.vx > 0 && phyCmp.x + phyCmp.vx  < CONSOLE_WIDTH)
            phyCmp.x += phyCmp.vx;

        if (phyCmp.y + phyCmp.vy > 0 && phyCmp.y + phyCmp.vy  < CONSOLE_HEIGHT-2)
            phyCmp.y += phyCmp.vy;
    }
}

// Añadir, obtener y eliminar componntes
Cmp* PhySys::addCmp(size_t idEnt)
{  
    return &components.emplace_back(idEnt);
}

Cmp* PhySys::getCmp(size_t idEnt)
{
    for (size_t i = 0; i < components.size(); ++i)
    {
        if (components[i].idEnt == idEnt)
        {
            return &components[i];
        }
    }

    static PhyCmp phyCmp(0);
    std::cout <<"xd\n"; exit(0);

    return &phyCmp;
}

void PhySys::remCmp(size_t idEnt)
{
    for (size_t i = 0; i < components.size(); ++i)
    {
        if (components[i].idEnt == idEnt)
        {
            components.erase(components.begin() + i);
        }
    }
}
