#pragma once

#include <ecs/sys.h>
#include <cmp/renCmp.h>

#include <vector>

class RenSys : public Sys
{
public:
    RenSys();
    ~RenSys();

    void update(EntSys& entSys) override; // Actualiza sus componentes

    // Añadir, obtener y eliminar componntes
    Cmp* addCmp(size_t idEnt) override;
    Cmp* getCmp(size_t idEnt) override;
    void remCmp(size_t idEnt) override;

    std::vector<RenCmp> components;
};