#pragma once
#include "../Particle.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

class Particle;

class Component{

public :
	bool bIsActive = true;
	virtual void Update(Particle* p) = 0;
	virtual void RenderImGui(Particle* p) = 0;
	virtual ~Component() = default;
};