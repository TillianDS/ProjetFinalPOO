#include "Particle.h"

void Particle::update(float deltaTime)
{
	//m_position = m_initialPosition;

	for (Component* c : components) {
		c->Update(this);
	}

	m_acceleration = m_accumForce * m_inverseMasse;
    m_velocity += m_acceleration * deltaTime;
    m_position += m_velocity * deltaTime;

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
	ImGui::InputFloat("", &m_initialPosition.x, 0.0f, 0.0f, "%.2f");
	ImGui::PopID();

	string Yid = "y" + to_string(index);
	ImGui::PushID(Yid.c_str());
	ImGui::SameLine();
	ImGui::Text("y");
	ImGui::SameLine();
	ImGui::InputFloat("", &m_initialPosition.y, 0.0f, 0.0f, "%.2f");
	ImGui::PopID();

	for (Component* c : components) {
		ImGui::Dummy(ImVec2(0, 10));

		ImGui::BeginGroup();
		c->RenderImGui(this, index);
		ImGui::EndGroup();
	}
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