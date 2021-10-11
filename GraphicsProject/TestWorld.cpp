#include "TestWorld.h"
#include "glm/ext.hpp"

void TestWorld::onStart()
{
	//Create camera
	m_camera = new PlayerCamera(70.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(1.0f, 1.0f, 1.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);

	add(m_camera);
	add(m_quad = new Quad());
	//add(m_obj = new aie::OBJMesh());
	//m_obj->load("Lucy.obj");
}

void TestWorld::onEnd()
{
	destroy(m_camera);
	//destroy(m_obj);
	destroy(m_quad);
}


