#pragma once
#include "../Particle.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

class Particle;

class Component{

public :
	bool bIsActive = true;
	string name = "Component";

	virtual void Update(Particle* p) = 0;
	virtual void ImGuiHead(Particle* p, int ParticleIndex) final
	{
		ImGui::Text(name.c_str());
		ImGui::SameLine();

		string id = "Activate" + to_string(ParticleIndex);
		ImGui::PushID(id.c_str());
		ImGui::Checkbox("Activate", &bIsActive);
		ImGui::PopID();
	}

	virtual void ImGuiBody(Particle* p, int ParticleIndex) = 0;

	virtual void RenderImGui(Particle* p, int ParticleIndex) final
	{
		ImGuiHead(p, ParticleIndex);
		if (bIsActive) {
			ImGuiBody(p, ParticleIndex);
		}
	}

	virtual ~Component() = default;
};