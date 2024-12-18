#include "World.h"

#include "Global.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

World::World() {
}

void World::addParticle(Particle* p) {
    particles.push_back(p);
}

void World::update(float deltaTime) {

    
    for (Particle* p : particles) {
        p->update(deltaTime);
    }
    collisionSystem.detectAndResolveCollisions(particlePhysics);

}

void World::renderImGui(float ImGuiSize)
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();


    ImVec2 windowSize = ImVec2(00*particles.size()*ImGuiSize, 00*ImGuiSize);
    ImGui::SetNextWindowSize(windowSize);

    ImGui::Begin("Gestionnaire de particle");

    if (ImGui::Button("Ajouter des particles")) {
        addParticle(new Particle());
    }

    ImGui::Separator();

    int index = 1;
    for (Particle* p : particles) {
        ImGui::BeginGroup();
        p->RenderImgui(index);
        ImGui::EndGroup();
        ImGui::SameLine();
        index++;
    }
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}