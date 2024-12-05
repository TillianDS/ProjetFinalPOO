#include "C_Gravity.h"

C_Gravity::~C_Gravity()
{
}

void C_Gravity::Update(Particle* particle)
{
	if (bIsActive) {
		if (particle->getInverseMasse() == 0.0f) return;

		// Apply the force of gravity to the particle
		vec3 force = gravity * 1 / (particle->getInverseMasse());

		particle->addForce(force);
	}
}

void C_Gravity::ImGuiBody(Particle* p, int ParticleIndex)
{}
