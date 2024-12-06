#include "C_Respawn.h"
#include "ofMain.h"

C_Respawn::~C_Respawn()
{}

void C_Respawn::Update(Particle* particle)
{
    if (bIsActive) {
        m_elapsedTime += ofGetLastFrameTime();

        if (m_mode == RespawnMode::Lifetime) {
            // Respawn bas� sur la dur�e de vie
            if (m_elapsedTime >= m_lifetime) {
                particle->setPosition(particle->getInitialPosition());
                m_elapsedTime = 0.0f;  // R�initialiser le temps �coul�
            }
        }
        else if (m_mode == RespawnMode::ScreenBounds) {
            // Respawn bas� sur les bordures de l'�cran
            vec3 pos = particle->getPosition();
            float screenWidth = ofGetWidth();
            float screenHeight = ofGetHeight();

            if (pos.x < 0 || pos.x > screenWidth || pos.y < 0 || pos.y > screenHeight) {
                particle->setPosition(particle->getInitialPosition());
            }
        }
    }
}

void C_Respawn::ImGuiBody(Particle* p, int ParticleIndex)
{
    std::string lifetimeID = "Lifetime##" + std::to_string(ParticleIndex);
    std::string modeID = "Mode##" + std::to_string(ParticleIndex);

    // Liste d�roulante pour le mode
    ImGui::SetNextItemWidth(150.0f);  // Ajustez la largeur si n�cessaire
    const char* modes[] = { "Lifetime", "Screen Bounds" };
    int currentMode = static_cast<int>(m_mode);
    if (ImGui::Combo(modeID.c_str(), &currentMode, modes, IM_ARRAYSIZE(modes))) {
        m_mode = static_cast<RespawnMode>(currentMode);
    }

    if (m_mode == RespawnMode::Lifetime) {
        ImGui::InputFloat(lifetimeID.c_str(), &m_lifetime); // Champ de saisie pour Lifetime
    }
}
