#ifndef Particule_h
#define Particule_h

#include "ofMain.h"
#include "src/Component.h"

using namespace glm;
class Component;

class Particle
{
private:
    float m_width;
    float m_inverseMasse;

    vec3 m_position;
    vec3 m_velocity;
    vec3 m_acceleration;
    vec3 m_accumForce;  

    vector<Component*> components;

public:
    Particle(vec3 pos = vec3(0, 0, 0), float w = 10, float Im = 1.0f, vec3 velocity = vec3(), vec3 a = vec3()) :
        m_width(w), m_position(pos), m_velocity(velocity), m_acceleration(a), m_inverseMasse(Im){};
    ~Particle() {};

    void update(float deltaTime);
    void RenderImgui(int index);

    void addComponent(Component* c);

    const vec3& getPosition() const { return m_position; };
    vec3 getVelocity() { return m_velocity; };
    vec3 getAcceleration() const { return m_acceleration; };
    vec3 getForce() const { return m_accumForce; };
    float getInverseMasse() const { return m_inverseMasse; };
    float getWidth() const { return m_width; };

    void setInitialPosition(vec3 p) { m_position = p; };
    void setVelocity(vec3 v) { m_velocity = v; };
    void setAcceleration(vec3 a) { m_acceleration = a; };
    void setInverseMasse(float inverseMasse) { m_inverseMasse = inverseMasse; };
    void addForce(const vec3& force);
    void clearAccum();
    
    //void draw() const;
    
    
};

#endif // Particule_h
