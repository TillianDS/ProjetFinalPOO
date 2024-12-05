#pragma once
#include "src/Component.h"
	
class C_Velocity : public Component
{
public:
	C_Velocity(vec3 velocity = vec3(0, 0, 0)) : m_velocity(velocity) { name = "Velocity"; bIsActive = false; };
	~C_Velocity() override;

	void Update(Particle* particle) override;
	void ImGuiBody(Particle* p, int ParticleIndex) override;
private:
	vec3 m_velocity;
};

