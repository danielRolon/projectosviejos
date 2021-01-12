#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <ecs/entSys.h>
#include <sys/renSys.h>
#include <sys/phySys.h>
#include <sys/scrSys.h>

EntSys entSys(2);

enum class TipoRaqueta
{
    TIPO_JUGADOR,
    TIPO_PC
};

void iniciar()
{
    entSys.addSys<RenSys>();
    entSys.addSys<PhySys>();
    entSys.addSys<ScrSys>();
}

void addRaqueta(int x, size_t y, TipoRaqueta tipo)
{
    size_t idRaqueta = entSys.addEnt();

    auto& renCmp = entSys.addCmp<RenCmp>(idRaqueta);
    auto& phyCmp = entSys.addCmp<PhyCmp>(idRaqueta);
    auto& scrCmp = entSys.addCmp<ScrCmp>(idRaqueta);

    renCmp.representation = '|';

    phyCmp.x = x;
    phyCmp.y = y;

    switch (tipo)
    {
        case TipoRaqueta::TIPO_JUGADOR:
        {
            scrCmp.behavior = [](EntSys& entSys, size_t idEnt)
            {
                auto& phyCmp = entSys.getCmp<PhyCmp>(idEnt);

                phyCmp.vy = bool(GetAsyncKeyState('S')) - bool(GetAsyncKeyState('W'));
            };
            break;
        }
        case TipoRaqueta::TIPO_PC:
        {
            scrCmp.behavior = [](EntSys& entSys, size_t idEnt)
            {
                auto& phyCmp = entSys.getCmp<PhyCmp>(idEnt);
                
                phyCmp.vy = bool(rand() % 2) - bool(rand() % 2);
            };
            break;
        }
    }

}

void addPelota(int x, int y, float vx, float vy)
{
    size_t idPelota = entSys.addEnt();

    auto& renCmp = entSys.addCmp<RenCmp>(idPelota);
    auto& phyCmp = entSys.addCmp<PhyCmp>(idPelota);
    auto& scrCmp = entSys.addCmp<ScrCmp>(idPelota);

    renCmp.representation = '*';

    phyCmp.x = x;
    phyCmp.y = y;
    phyCmp.vx = vx;
    phyCmp.vy = vy;

    scrCmp.behavior = [](EntSys& entSys, size_t idEnt)
    {

    };
}

void actualizar()
{
    entSys.update();
}