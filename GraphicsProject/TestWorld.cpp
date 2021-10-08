#include "TestWorld.h"
#include "glm/ext.hpp"

void TestWorld::onStart()
{
	//Create camera
	Camera* m_camera = new Camera(45.0f, 0.001f, 1000.0f);
	m_camera->setLocalTransform(glm::lookAt(
		glm::vec3(10.0f),
		glm::vec3(0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	));
	m_camera->getTransform()->setPosition(0.0f, 10.0f, 0.0f);
	m_camera->getTransform()->rotate(0.0f, 0.0f, -180.0f);
	setCamera(m_camera);

	add(m_quad = new Quad());
}

void TestWorld::onEnd()
{
	delete m_camera;
	destroy(m_quad);
}


