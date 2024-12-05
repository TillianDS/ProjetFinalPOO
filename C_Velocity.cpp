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
    static float tempX = m_velocity.x;
    static float tempY = m_velocity.y;
    /*std::string uniqueID = "Valider##" + std::to_string(reinterpret_cast<std::uintptr_t>(this));*/

    //// Champs de saisie pour X et Y
    ImGui::InputFloat("X", &tempX);
    ImGui::SameLine();
    ImGui::InputFloat("Y", &tempY);

    // Bouton "Valider"
    if (ImGui::Button("Valider"))
    {
        // Appliquer les modifications à m_velocity
        m_velocity.x = tempX;
        m_velocity.y = tempY;
    }

}
