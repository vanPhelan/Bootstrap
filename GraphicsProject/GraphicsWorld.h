#pragma once
#include "World.h"
#include "Quad.h"

class GraphicsWorld : public World
{
public:
	void onStart() override;
	void onEnd() override;

private:
	Quad* m_quad;
};

