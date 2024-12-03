#include "World.h"

World::World() {
}

void World::addParticle(Particle* p) {
    particles.push_back(p);
}

void World::update(float deltaTime) {

    for (Particle* p : particles) {
        p->update(deltaTime);
    }
}


