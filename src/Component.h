#pragma once
#include "../Particle.h"

class Particle;

class Component{

public :
	virtual void Update(Particle* p) = 0;
	virtual void RenderImGui() = 0;
	virtual ~Component() = default;
};