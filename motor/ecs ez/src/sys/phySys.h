#pragma once

#include <ecs/sys.h>
#include <cmp/phyCmp.h>

#include <vector>

class PhySys : public Sys
{
public:
    PhySys();
    ~PhySys();

    void update(EntSys& entSys) override; // Actualiza sus componentes

    // Añadir, obtener y eliminar componntes
    Cmp* addCmp(size_t idEnt) override;
    Cmp* getCmp(size_t idEnt) override;
    void remCmp(size_t idEnt) override;

    std::vector<PhyCmp> components;
};