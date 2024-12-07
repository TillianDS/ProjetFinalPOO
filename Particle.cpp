#include "Particle.h"
#include "C_GraphicalRenderer.h"
#include "C_Gravity.h"
#include "C_Collisions.h"
#include "C_Velocity.h"
#include "C_Respawn.h"

void Particle::update(float deltaTime)
{
	for (Component* c : components) {
		c->Update(this);
	}

	m_acceleration = m_accumForce * m_inverseMasse;
	m_velocity += m_acceleration * deltaTime;
	m_position += m_velocity * deltaTime;

	if (m_position == m_startPosition) {
		m_position = m_initialPosition;
		m_startPosition = m_initialPosition;
	}

	clearAccum();
}

void Particle::RenderImgui(int index)
{
	ImGui::Text("Particle %d", index);

	ImGui::PushItemWidth(50);

	ImGui::Text("Initial position");

	string Xid = "x" + to_string(index);
	ImGui::PushID(Xid.c_str());
	ImGui::Text("x");
	ImGui::SameLine();
	ImGui::InputFloat("", &m_initialPosition.x, 0.0f, 0.0f, "%.1f");
	ImGui::PopID();

	string Yid = "y" + to_string(index);
	ImGui::PushID(Yid.c_str());
	ImGui::SameLine();
	ImGui::Text("y");
	ImGui::SameLine();
	ImGui::InputFloat("", &m_initialPosition.y, 0.0f, 0.0f, "%.1f");
	ImGui::PopID();

	string Width = "Width" + to_string(index);
	ImGui::PushID(Width.c_str());
	ImGui::Text("Size");
	ImGui::SameLine();
	ImGui::InputFloat("", &m_width, 0.0f, 0.0f, "%.1f");
	ImGui::PopID();

	for (Component* c : components) {
		ImGui::Dummy(ImVec2(0, 10));

		ImGui::BeginGroup();
		c->RenderImGui(this, index);
		ImGui::EndGroup();
	}

	RenderAddComponent(index);
}

void Particle::addComponent(Component* c)
{

	components.push_back(c);
}

void Particle::addForce(const vec3& force) {
    m_accumForce += force;
}

void Particle::clearAccum()
{
    m_accumForce = vec3(0, 0, 0);
}

void Particle::RenderAddComponent(int index)
{
	std::vector<std::string> remainingComponents;

	// Vérification des composants déjà ajoutés
	for (const auto& compName : allComponents) {
		bool alreadyAdded = false;
		for (const auto& comp : components) {
			if (comp->name == compName) {
				alreadyAdded = true;
				break;
			}
		}
		if (!alreadyAdded) {
			remainingComponents.push_back(compName);
		}
	}

	string AddComponent = "AddComponent" + to_string(index);
	ImGui::PushID(AddComponent.c_str());

	ImGui::PushItemWidth(150);

	if (!remainingComponents.empty()) {
		ImGui::Combo("Choisir un composant", &addComponentIndex,
			[](void* data, int idx, const char** out_text) {
				auto& components = *static_cast<std::vector<std::string>*>(data);
				*out_text = components[idx].c_str();
				return true;
			},
			&remainingComponents,
			remainingComponents.size());
	}
	ImGui::PopItemWidth();
	if (ImGui::Button("Ajouter le composant") && addComponentIndex >= 0) {

		const string& selectedComponentName = remainingComponents[addComponentIndex];

		if (selectedComponentName == "Renderer") {
			addComponent(new C_GraphicalRenderer()); cout << selectedComponentName << endl;

		}
		else if (selectedComponentName == "Velocity") addComponent(new C_Velocity());
		else if (selectedComponentName == "Gravity") addComponent(new C_Gravity());
		//else if (selectedComponentName == "Collisions") addComponent(new C_Collisions());
		else if (selectedComponentName == "Respawn") addComponent(new C_Respawn());

		addComponentIndex = -1;
	}

	ImGui::PopID();

}

void Particle::removeComponent(Component* c)
{
	auto it = std::remove(components.begin(), components.end(), c);
	if (it != components.end()) {
		components.erase(it, components.end());
		delete c;
	}
}
