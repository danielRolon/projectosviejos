#include <iostream>

#include <utils/debug.h>
#include <utils/input.h>
#include <utils/console.h>

#include <man/RenderManager.h>
#include <man/PhysicsManager.h>
#include <man/EntityManager.h>

int main()
{   
    EntityManager entityManager;
    entityManager.addManager<RenderManager>();
    entityManager.addManager<PhysicsManager>();

    

    size_t entity0 = entityManager.addEntity();
    size_t* walls = new size_t[10];

    for (size_t i = 0; i < 10; ++i) { entityManager.addEntity(); }
    
    {
        auto& renCmp = entityManager.addComponent<RenderComponent>(entity0);
        renCmp.x = 5;
        renCmp.y = 5;
        renCmp.c = 'P';

        auto& phyCmp = entityManager.addComponent<PhysicsComponent>(entity0);
        phyCmp.x = 5;
        phyCmp.y = 5;
        phyCmp.vx = 0;
    }

    for (size_t i = 0; i < 10; ++i)
    {
        size_t idWall = i + entityManager.idCountManagers;

        auto& renCmp = entityManager.addComponent<RenderComponent>(idWall);
        renCmp.x = 10 + i;
        renCmp.y = 5;
        renCmp.c = 'W';

        auto& phyCmp = entityManager.addComponent<PhysicsComponent>(idWall);
        phyCmp.x = 10 + i;
        phyCmp.y = 5;
        phyCmp.vx = 0;
    }

    auto& phyCmp = entityManager.getComponent<PhysicsComponent>(entity0);

    while (!Input::isKeyPressed(VK_ESCAPE))
    {
        Console::Clear();

        phyCmp.vx = (Input::isKeyPressed('D') - Input::isKeyPressed('A'));
        phyCmp.vy = (Input::isKeyPressed('S') - Input::isKeyPressed('W'));

        entityManager.update();
    }
    
    Console::Clear();

    return 0;
}