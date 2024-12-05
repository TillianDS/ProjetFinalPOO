#pragma once
#include "src/Component.h"
#include "ofMain.h"

class C_Collisions :public Component
{
public: 
	C_Collisions() { name = "collisions"; bIsActive = false; };
	~C_Collisions() override;

	void Update(Particle* particle) override;
	void ImGuiBody(Particle* p, int ParticleIndex) override;

};

