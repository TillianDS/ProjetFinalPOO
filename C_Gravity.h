#pragma once
#include "src/Component.h"
#include "ofMain.h"
using namespace glm;

class C_Gravity : public Component
{
public:
	C_Gravity(vec3 gravity = vec3(0, 9.81, 0)) : gravity(gravity) {};
	~C_Gravity() override;

	void Update(Particle* particle) override;
	void RenderImGui() override;

private:
	vec3 gravity;
};

