#include "C_Collisions.h"
#include "Global.h"

void C_Collisions::Update(Particle* particle)
{
	particlePhysics.push_back(particle);
}
