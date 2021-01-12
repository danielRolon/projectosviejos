#include <iostream>

#include <std/console.h>
#include <std/input.h>

#include <man/RenderManager.h>
#include <man/EntityManager.h>

int main()
{
    bool running = true;

    ECS::EntityManager em;

    const size_t idPlayer = em.addEntity();
    const size_t idEnt00  = em.addEntity();

    em.addType<RenderManager>();

    em.addComponent<RenderComponent>(idPlayer);
    em.addComponent<RenderComponent>(idPlayer);
    em.addComponent<RenderComponent>(idPlayer);
    em.addComponent<RenderComponent>(idPlayer);

    em.addComponent<RenderComponent>(idPlayer);
    em.addComponent<RenderComponent>(idPlayer);
    em.addComponent<RenderComponent>(idPlayer);
    em.addComponent<RenderComponent>(idPlayer);

    em.addComponent<RenderComponent>(idPlayer);
    em.addComponent<RenderComponent>(idPlayer);
    em.addComponent<RenderComponent>(idPlayer);
    em.addComponent<RenderComponent>(idPlayer);

    auto& component = em.getComponentByIdEntity<RenderComponent>(idPlayer);
    component.x = 20;
    component.y = 20;

    //em.destroyComponent<RenderComponent>(idPlayer);

    em.destroyEntity(idPlayer);

    LOG "components: " << em.managers[0]->components.size() END; exit(0);

    while(running)
    {
        Console::clearConsole();

        component.x += Input::isKeyPressed('D') - Input::isKeyPressed('A');
 
        em.update();

        if (Input::isKeyPressed(VK_ESCAPE))
            running = false;
    }

    return 0;
}

// IMPORTANTE
/*

Che admin, desbaneame mi cuenta "Darth Vader#2583"pls fui baneado por un bot de manera injusta.
Yo estaba poniendo muchas 'A' para seguir el "chiste" y me baneo ;(

*/