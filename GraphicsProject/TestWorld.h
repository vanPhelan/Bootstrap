#pragma once
#include "World.h"
#include "PlayerCamera.h"
#include "Quad.h"

class TestWorld : public World
{
public:
	void onStart() override;
	void onEnd() override;

private:
	PlayerCamera* m_camera = nullptr;
	Quad* m_quad = nullptr;
};

