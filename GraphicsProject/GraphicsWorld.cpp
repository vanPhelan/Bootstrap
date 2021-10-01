#include "GraphicsWorld.h"

void GraphicsWorld::onStart()
{
	m_quad = new Quad();
	add(m_quad);
}

void GraphicsWorld::onEnd()
{
	destroy(m_quad);
}


