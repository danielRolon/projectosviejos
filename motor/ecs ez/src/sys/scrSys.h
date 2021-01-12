#pragma once

#include <ecs/sys.h>
#include <cmp/scrCmp.h>

#include <vector>

class ScrSys : public Sys
{
public:
    ScrSys();
    ~ScrSys();

    void update(EntSys& entSys) override; // Actualiza sus componentes

    // Añadir, obtener y eliminar componntes
    Cmp* addCmp(size_t idEnt) override;
    Cmp* getCmp(size_t idEnt) override;
    void remCmp(size_t idEnt) override;

    std::vector<ScrCmp> components;
};