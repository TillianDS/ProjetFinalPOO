#pragma once

#include "src/Component.h"
#include "ofMain.h"

class C_GraphicalRenderer : public Component
{
public:
	C_GraphicalRenderer() { name = "Renderer"; };

	void Update(Particle* p) override;
	void ImGuiBody(Particle* p, int ParticleIndex) override;

private :
	void DrawShape(float width, glm::vec3 position);

	enum Color {
		RED = 0,
		BLUE,
		GREEN,
		WHITE,
		BLACK,
		MaxOptions
	};

	Color ActiveColor = WHITE;

	void SetColor();

};


