#include <iostream>

#include <sys/renderSystem.h>
#include <vector>
#include <math.h>
#include <keyMan.h>

enum class TypeEntities {
    NONE,
    PLAYER,
    WALL,
    ENEMY,
    BULLET
};

struct Box {
    float x { 0 }, y { 0 }, w { 0 }, h { 0 };
    Box(float x, float y, float w, float h)
        : x(x), y(y), w(w), h(h) {}

    bool isCollision(const Box& other) {
        //------------------------------------------------------------
        if (other.x <= x && (other.x + other.w) >= x) {
            if (other.y <= y && (other.y + other.h) >= y) return true;
        }
        else if (other.x <= (x + w) && (other.x + other.w) >= (x + w)) {
            if (other.y <= y && (other.y + other.h) >= y) return true;
        }
        //------------------------------------------------------------
        else if (other.x <= (x + w) && (other.x + other.w) >= (x + w)) {
            if (other.y <= (y + h) && (other.y + other.h) >= (y + h)) return true;
        }
        else if (other.x <= x && (other.x + other.w) >= x) {
            if (other.y <= (y + h) && (other.y + other.h) >= (y + h)) return true;
        }

        return false;
    }
};

struct Entity {
    float x { 0 }, y { 0 }, w { 0 }, h { 0 }, life { 0 };
    static int idCount;
    int id { 0 };
    Box* box { nullptr };
    float vx { 0 }, vy { 0 };
    bool destroy = false;

    TypeEntities typeEntity = TypeEntities::NONE;

    ImageContext* image { nullptr };
    IRenderContext* render { nullptr };

    Entity(float x, float y, float w, float h, float life, const char* path, IRenderContext* render)
        : x(x), y(y), w(w), h(h), life(life) {
        this->image = new Image(path);
        this->render = render;
        id = ++idCount;
        box = new Box(x, y, w, h);
    }

    ~Entity() {}

    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void collision(Entity& other) = 0;
};
 
int Entity::idCount = 0;

std::vector<Entity*> entities;

struct Bullet : public Entity {
    Bullet(float x, float y, IRenderContext* render) 
        : Entity(x, y, 50, 50, 1, "res/images/sheetItems.png", render) {
        typeEntity = TypeEntities::BULLET;
        box->x = 20;
        box->y = 0;
        box->w = 30;
        box->h = 50;
    }

    ~Bullet() {
        delete image; 
        image = nullptr;
    }

    void update() {
        box->x = x + 20 + vx;
        box->y = y + vy;
    }

    void draw() {
        render->drawImage(image, 16, 0, 16, 16, x, y, w, h);
    }

    void collision(Entity& other) override {
    }
};

struct Player : public Entity {


    Player(float x, float y, IRenderContext* render)
        : Entity(x, y, 50, 50, 1, "res/images/sheetItems.png", render) {
        typeEntity = TypeEntities::PLAYER;
    }

    ~Player() {
        delete image; 
        image = nullptr;
    }

    void update() {
        auto& key = KeyMan::P();

        vx = (key.isDown(ALLEGRO_KEY_D) - key.isDown(ALLEGRO_KEY_A)) * 1.5;
        vy = (key.isDown(ALLEGRO_KEY_S) - key.isDown(ALLEGRO_KEY_W)) * 1.5;

        box->x = x + vx;
        box->y = y + vy;

        if (render->isDown(ALLEGRO_KEY_K)) {
            auto bulletIns = entities.emplace_back(new Bullet(x, y-51, render));
            bulletIns->vy = -3;
        }
    }

    void draw() {
        render->drawImage(image, 0, 0, 16, 16, x, y, w, h);
    }

    void collision(Entity& other) override {
        if (other.typeEntity == TypeEntities::BULLET)
            if (--life <= 0) destroy = true;
    }
};


struct Wall : public Entity {

    int shift = 0;

    Wall(float x, float y, IRenderContext* render) 
        : Entity(x, y, 50, 50, 4, "res/images/sheetItems.png", render) {
        typeEntity = TypeEntities::WALL;
    }

    ~Wall() {
        delete image; 
        image = nullptr;
    }

    void update() {}

    void draw() {
        render->drawImage(image, 0, 32, 16, 16, x, y, w, h);
    }

    void collision(Entity& other) override {
        if (other.typeEntity == TypeEntities::BULLET) {
            if (--life <= 0) destroy = true;
            other.destroy = true;
            std::cout << "my life " << life << "\n";
        }
    }
};

class CollisionManager {
public:
    CollisionManager(std::vector<Entity*>& vector) : entitiesCol(vector) {

    }

    void update() {
        for (auto e : entitiesCol) {
            for (auto e2 : entitiesCol) {
                if (e->id == e2->id) continue;
                if (e->box->isCollision(*(e2->box))) {
                    e->collision(*e2);
                }
            } 
            e->x += e->vx; 
            e->y += e->vy; 
        }
    }
private:
    std::vector<Entity*>& entitiesCol;
};

int main(void) {

    auto& renderSys = ECS::RenderSystem::p();
    auto render = renderSys.m_Render;

    bool running = true;

    render->setFuncKeyDown([](unsigned char keyCode) { KeyMan::P().keyDown(keyCode); });
    render->setFuncKeyUp([](unsigned char keyCode)   { KeyMan::P().keyUp(keyCode); });

    render->setFont("res/fonts/arial.ttf", 24);

    entities.emplace_back(new Player(100, 100, render));
    for (uint32_t y = 0; y < 2; y++) {
        for (uint32_t x = 0; x < 10; x++) {
            entities.emplace_back(new Wall(x*50, y*50, render));
        }
    }

    CollisionManager colMan(entities);

    while(running && render->isRunning()) {
        render->update();

        render->clear(0, 0, 0);

        for (auto e : entities){
            e->update();
            e->draw();
        }

        uint32_t length = entities.size();
        for (uint32_t i = 0; i < entities.size(); i++) {
            if (entities[i]->destroy) entities.erase(entities.begin() + i);
            --length;
        }

        colMan.update();

        render->refresh();
    }

    for (auto e : entities) {
        delete e;
        e = nullptr;
    }

    entities.clear();

    return 0;
}
