#pragma once
#include "World.h"
#include "Camera.h"
#include "Quad.h"

class GraphicsWorld : public World
{
public:
	void onStart() override;
	void onEnd() override;

private:
	Camera* m_camera = nullptr;
	Quad* m_quad = nullptr;
};

