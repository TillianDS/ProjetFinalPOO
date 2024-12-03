#pragma once

class Component{

public :
	virtual void Update() = 0;
	virtual void RenderImGui() = 0;
	virtual ~Component() = default;
};