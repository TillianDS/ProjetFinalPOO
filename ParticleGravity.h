#ifndef PARTICLE_GRAVITY_H
#define PARTICLE_GRAVITY_H

#pragma once

#include "ParticleForceGenerator.h"

class ParticleGravity : public ParticleForceGenerator {
	vec3 gravity; // Gravit�

	// Constructeur
public:
	ParticleGravity(const vec3& gravity);

	// Applique la force de gravit� � la particule
	virtual void updateForce(Particle* particle, float duration);

	// Get the vector of gravity
	vec3 getGravity() const;
};

#endif