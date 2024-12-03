#pragma once
#include "../particle.h"

class Component{

public :
	virtual void Update(Particle *particle) = 0;
	virtual void RenderImGui() = 0;
	virtual ~Component() = default;
};