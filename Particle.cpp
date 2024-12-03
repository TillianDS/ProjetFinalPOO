#include "Particle.h"

void Particle::update(float deltaTime)
{
	for (Component* c : components) {
		c->Update();
		c->RenderImGui();
	}
}

void Particle::addComponent(Component* c)
{
	components.push_back(c);
}

//void Particle::update(float deltaTime)
//{
//    m_acceleration = m_accumForce * m_inverseMasse;
//
//    m_velocity += m_acceleration * deltaTime;
//    m_position += m_velocity * deltaTime;
//}




//void Particle::addForce(const vec3& force) {
//    m_accumForce += force;
//}
//
//void Particle::clearAccum()
//{
//    m_accumForce = vec3(0, 0, 0);
//}


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