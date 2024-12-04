#pragma once

#include "src/Component.h"
#include "ofMain.h"

class C_GraphicalRenderer : public Component
{
public:
	C_GraphicalRenderer() {};
	void Update(Particle* p) override;
	void RenderImGui(Particle* p) override;

private :
	void DrawShape(float width, glm::vec3 position);

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


