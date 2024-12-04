#include "C_GraphicalRenderer.h"

void C_GraphicalRenderer::Update(Particle* p)
{
	SetColor();
	DrawShape(10, p->getPosition());
}

void C_GraphicalRenderer::RenderImGui()
{

}

void C_GraphicalRenderer::DrawShape(float size, glm::vec3 position)
{
	ofDrawCircle(position.x, position.y, size);
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
