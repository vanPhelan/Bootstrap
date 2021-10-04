#include "GraphicsWorld.h"
#include "glm/ext.hpp"

void GraphicsWorld::onStart()
{
	//Create camera
	Camera* m_camera = new Camera(45.0f, 0.001f, 1000.0f);
	m_camera->setLocalTransform(glm::lookAt(
		glm::vec3(10.0f),
		glm::vec3(0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	));
	setCamera(m_camera);

	add(m_quad = new Quad());
}

void GraphicsWorld::onEnd()
{
	destroy(m_quad);
}


