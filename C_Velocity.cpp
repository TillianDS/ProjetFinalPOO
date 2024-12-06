#include "C_Velocity.h"

C_Velocity::~C_Velocity()
{
}

void C_Velocity::Update(Particle* particle)
{
    if (bIsActive) {
        particle->setVelocity(m_velocity);
    }
    else {
        particle->setVelocity(vec3(0, 0, 0));
    }
}

void C_Velocity::ImGuiBody(Particle* p, int ParticleIndex)
{
    string velocityId = "##Velocity" + to_string(ParticleIndex);

    static float tempX = m_velocity.x;
    static float tempY = m_velocity.y;

    ImGui::InputFloat(("X" + velocityId).c_str(), &tempX);
    ImGui::SameLine();
    ImGui::InputFloat(("Y" + velocityId).c_str(), &tempY);

    // Bouton "Valider" avec un ID unique
    if (ImGui::Button(("Valider" + velocityId).c_str()))
    {
        // Appliquer les modifications à m_velocity
        m_velocity.x = tempX;
        m_velocity.y = -tempY;
    }

}
