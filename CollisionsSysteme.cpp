#include "CollisionsSysteme.h"

bool CollisionSystem::checkForCollision(const Particle& p1, const Particle& p2) {
    std::cout << "dans check for collosions" << std::endl;
    vec3 distanceVector = p1.getPosition() - p2.getPosition();
    double distance = glm::length(distanceVector);
    double sumOfRadii = p1.getWidth() + p2.getWidth();
    return distance <= sumOfRadii;
}

void CollisionSystem::resolveCollision(Particle& p1, Particle& p2) {
    // Les deux particules appartiennent au même blob, procéder à la résolution de collision
    vec3 normal = glm::normalize((p1.getPosition() - p2.getPosition()));
    vec3 relativeVelocity = p1.getVelocity() - p2.getVelocity();
    double velocityAlongNormal = glm::dot(relativeVelocity, normal);

    // Only resolve if particles are moving towards each other
    if (velocityAlongNormal > 0) return;

    double restitution = 1.0f; // Coefficient de restitution (vous pouvez ajuster cette valeur)
    double impulseMagnitude = -(1 + restitution) * velocityAlongNormal;
    impulseMagnitude /= p1.getInverseMasse() + p2.getInverseMasse();

    vec3 impulse = normal * impulseMagnitude;

    // Appliquer les impulsions
    p1.setVelocity(p1.getVelocity() + impulse * p1.getInverseMasse());
    p2.setVelocity(p2.getVelocity() - impulse * p2.getInverseMasse());
    std::cout << "dans resolve and velocity :" << p1.getVelocity().x << p1.getVelocity().y << std::endl;
}


void CollisionSystem::detectAndResolveCollisions(std::vector<Particle*>& particles) {

    for (size_t i = 0; i < particles.size(); ++i) {
        for (size_t j = i + 1; j < particles.size(); ++j) {
            if (checkForCollision(*particles[i], *particles[j])) {
                resolveCollision(*particles[i], *particles[j]);
            }
        }
    }
}

