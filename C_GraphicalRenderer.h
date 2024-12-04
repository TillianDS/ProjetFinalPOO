#pragma once

#include "src/Component.h"
#include "ofMain.h"

class C_GraphicalRenderer : Component
{
public:
	void Update(Particle* p) override;
	void RenderImGui() override;

private :
	void DrawShape(float size, glm::vec3 position);

	enum Color {
		RED,
		BLUE,
		GREEN,
		WHITE,
		BLACK
	};

	Color ActiveColor;

	void SetColor();

};


