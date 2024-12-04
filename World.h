#pragma once

#include <vector>
#include "Particle.h"
#include "ParticleForceRegistry.h"
#include "ParticleGravity.h"
#include "CollisionsSysteme.h"

class World {
public:
    World();

    // Add a particle to the world
    void addParticle(Particle* p);

    void update(float deltaTime);

    void renderImGui(float ImGuiSize);

private:
    std::vector<Particle*> particles;
    CollisionSystem collisionSystem;
};
