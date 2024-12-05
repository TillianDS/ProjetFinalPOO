#include "C_Collisions.h"
#include "Global.h"

void C_Collisions::Update(Particle* particle)
{
	if(bIsActive) {
		particlePhysics.push_back(particle);
	}
    else {
        // Si inactif, retirez la particule de la liste
        auto it = std::find(particlePhysics.begin(), particlePhysics.end(), particle);
        if (it != particlePhysics.end()) {
            particlePhysics.erase(it); // Supprime la particule de la liste
        }
    }
}

void C_Collisions::ImGuiBody(Particle* p, int ParticleIndex)
{}

C_Collisions::~C_Collisions() {}
