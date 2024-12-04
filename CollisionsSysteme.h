#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include "Particle.h"
#include "ParticleGravity.h"
#include <vector>


class CollisionSystem {
public:
    void detectAndResolveCollisions(std::vector<Particle*>& particles);

private:
    bool checkForCollision(const Particle& p1, const Particle& p2);
    void resolveCollision(Particle& p1, Particle& p2);
};

#endif // COLLISION_SYSTEM_H
