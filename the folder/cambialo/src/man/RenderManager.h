#pragma once

#include <cmp/RenderComponent.h>
#include <man/ComponentManager.h>

class RenderManager : public ECS::ComponentManager
{
public:
    explicit RenderManager();

    void update() override;

    void addComponent(size_t idEntity) override;
    void destroyComponent(size_t idEntity) override;

    std::vector<ECS::Component*>& getComponents() override;

    RenderComponent& getComponentByIdEntity(size_t idEntity) override;

    size_t getSizeComponent() const override { return sizeof(RenderComponent); }

private:
    //std::vector<RenderComponent> components;
};