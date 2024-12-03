#ifndef Particule_h
#define Particule_h

#include "ofMain.h"
#include "src/Component.h"

class MyBlob;

class Particle
{
private:
    //float m_width;
    //float m_inverseMasse;
    //ofColor m_color;

    //vec3 m_position;
    //vec3 m_velocity;
    //vec3 m_acceleration;
    //vec3 m_accumForce;  

    vector<Component*> components;


public:
    Particle() {};
    ~Particle() {};

    void update(float deltaTime);

    void addComponent(Component* c);

    //vec3 getVelocity() { return m_velocity; };
    //const vec3& getPosition() const { return m_position; };
    //float getInverseMasse() const { return m_inverseMasse; };
    //vec3 getAcceleration() const { return m_acceleration; };
    //vec3 getForce() const { return m_accumForce; };
    //float getWidth() const { return m_width; };

    //void setVelocity(vec3 v) { m_velocity = v; };
    //void setInitialPosition(vec3 v) { m_position = v; };
    //void setColor(ofColor c) { m_color = c; };
    //void setInverseMasse(float inverseMasse) { m_inverseMasse = inverseMasse; };

    
    //void draw() const;
    //void addForce(const vec3& force);
    //void clearAccum();

    //void handleInput();
};

#endif // Particule_h
