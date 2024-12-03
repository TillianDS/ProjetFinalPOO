#include "World.h"

World::World() {
    // Initialize the gravity force generator
    //gravity = new ParticleGravity(vec3(0, 9.81, 0));
}

void World::addParticle(Particle* p) {
    particles.push_back(p);
}

void World::update(float deltaTime) {

    /*for (Particle* p : particles) {
        forceRegistry.add(p, gravity);
    }*/

    // Apply forces to all particles
  /*  forceRegistry.updateForces(deltaTime);
    forceRegistry.clear();*/

   // Update each particle's position based on forces applied
    for (Particle* p : particles) {
        p->update(deltaTime);
        /*p->clearAccum();*/
    }


}

void World::draw()
{
   /* for (Particle* p : particles) {
        p->draw();
    }*/
}


