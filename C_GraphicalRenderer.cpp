#include "C_GraphicalRenderer.h"


void C_GraphicalRenderer::Update(Particle* p)
{
}

void C_GraphicalRenderer::ImGuiBody(Particle* p, int ParticleIndex)
{
	SetColor();
	DrawShape(p->getWidth(), p->getPosition());


	const char* colorString[] = {
		"RED",
		"BLUE",
		"GREEN",
		"WHITE",
		"BLACK"
	};

	ImGui::Text("Couleur");
	ImGui::SameLine();
	string id = "x" + to_string(ParticleIndex);
	ImGui::PushID(id.c_str());
	ImGui::Combo("##Combo", (int*)&ActiveColor, colorString, Color::MaxOptions);
	ImGui::PopID();
}

void C_GraphicalRenderer::DrawShape(float width, glm::vec3 position)
{
	ofDrawCircle(position.x, position.y, width);
}

void C_GraphicalRenderer::SetColor()
{
	switch (ActiveColor)
	{
	case C_GraphicalRenderer::RED:
		ofSetColor(255, 0, 0);
		break;
	case C_GraphicalRenderer::BLUE:
		ofSetColor(0, 0, 255);
		break;
	case C_GraphicalRenderer::GREEN:
		ofSetColor(0, 255, 0);
		break;
	case C_GraphicalRenderer::WHITE:
		ofSetColor(255, 255, 255);
		break;
	case C_GraphicalRenderer::BLACK:
		ofSetColor(0, 0, 0);
		break;
	}
}
