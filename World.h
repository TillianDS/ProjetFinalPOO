#pragma once

#include <vector>
#include "Particle.h"
#include "ParticleForceRegistry.h"
#include "ParticleGravity.h"

class World {
public:
    World();

    // Add a particle to the world
    void addParticle(Particle* p);

    // Update the world (apply forces, update particle positions, handle collisions)
    void update(float deltaTime);

    void draw();

private:
    std::vector<Particle*> particles;
    ParticleForceRegistry forceRegistry; // Force registry to apply forces to particles

    //Gravity
    ParticleGravity* gravity;
};
