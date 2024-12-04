#include "Particle.h"

void Particle::update(float deltaTime)
{
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
	int value = 0;

	//if (ImGui::InputInt("Position", &value)) {
	//	//std::cout << "Integer entered: " << value << std::endl;
	//}

	ImGui::Text("Particle %d", index);
	for (Component* c : components) {
		c->RenderImGui(this);
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


//void Particle::handleInput()
//{
//    if (IsPlayer) {
//        if (ofGetKeyPressed(OF_KEY_LEFT)) {
//            setVelocity(getVelocity() + Vector(-2, 0, 0));
//        }
//        if (ofGetKeyPressed(OF_KEY_RIGHT)) {
//            setVelocity(getVelocity() + Vector(2, 0, 0));
//        }
//        if (ofGetKeyPressed(OF_KEY_UP)) {
//            setVelocity(getVelocity() + Vector(0, -5, 0));
//        }
//    }
//}