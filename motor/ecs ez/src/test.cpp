#include <game.h>
#include <ecs/call/keyEvtCall.h>
#include <ecs/call/phyEventCall.h>
#include <math.h>

constexpr int FPS = 1000/60;

int main()
{
    bool run = true;

    iniciar();

    addRaqueta(5 , 5, TipoRaqueta::TIPO_JUGADOR);
    addRaqueta(85, 5, TipoRaqueta::TIPO_JUGADOR);
    addPelota(40, 5, -0.5, 0.0);

    entSys.eventMan.registerEventSys<PhyEventCall>();
    entSys.eventMan.registerEventSys<KeyEvtCall>();

    auto& phyEventListener = entSys.eventMan.addEventToListener<PhyEventListener>();

    phyEventListener.behavior = [](Event* event)
    {
        auto pPhyyEvent = reinterpret_cast<PhyEvent*>(event);
        auto& phyCmp = entSys.getCmp<PhyCmp>(pPhyyEvent->collideEntId);
        phyCmp.x -= ceil(phyCmp.vx)*2;
        phyCmp.vx *= -1;
    };

    while (run)
    {
        if (GetAsyncKeyState(VK_ESCAPE)) run = false;

        actualizar();

        Sleep(FPS);
    }

    std::cout << "hELLOs DBZ" << "\n";

    return 0;
}