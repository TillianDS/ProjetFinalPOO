#include "C_Gravity.h"

void C_Gravity::Update(Particle* particle)
{
	if (particle->getInverseMasse() == 0.0f) return;

	// Apply the force of gravity to the particle
	vec3 force = gravity * 1 / (particle->getInverseMasse());

	particle->addForce(force);
}

void C_Gravity::RenderImGui()
{
	return;
}
