#pragma once
#include "src/Component.h"

enum class RespawnMode {
    Lifetime,
    ScreenBounds
};

class C_Respawn : public Component {
public:
    C_Respawn(float lifetime = 5.0f) : m_lifetime(lifetime), m_elapsedTime(0.0f), m_mode(RespawnMode::Lifetime) {
        name = "Respawn";
        bIsActive = false;
    }
    ~C_Respawn() override;

    void Update(Particle* particle) override;
    void ImGuiBody(Particle* p, int ParticleIndex) override;

private:
    float m_lifetime;           // Durée de vie avant le respawn
    float m_elapsedTime;        // Temps écoulé
    RespawnMode m_mode;         // Mode de respawn
};

