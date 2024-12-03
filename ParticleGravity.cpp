#include "ParticleGravity.h"

ParticleGravity::ParticleGravity(const vec3& gravity)
{
	this->gravity = gravity;
}

void ParticleGravity::updateForce(Particle* particle, float duration)
{
	// If the particle has infinite mass (zero mass), do not apply force
	if (particle->getInverseMasse() == 0.0f) return;

	// Apply the force of gravity to the particle
	vec3 force = gravity * 1 / (particle->getInverseMasse());

	particle->addForce(force);
}

vec3 ParticleGravity::getGravity() const
{
	return gravity;
}