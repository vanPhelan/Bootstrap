#include "TestWorld.h"
#include "glm/ext.hpp"

void TestWorld::onStart()
{
	//Light
	m_light = new Light();
	m_light->setDirection(glm::vec3(-1.0f));
	m_light->setAmbient(glm::vec4(0.6f, 0.6f, 0.0f, 1.0f));
	m_light->setDiffuse(glm::vec4(0.6f, 0.6f, 1.0f, 1.0f));
	m_light->setSpecular(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	m_light->setSpecularPower(2.0f);
	add(m_light);

	//Camera
	m_camera = new PlayerCamera(70.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(1.0f, 1.0f, 1.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	//Action!
	m_quad = new Quad();
	m_quad->setColor(glm::vec4(8.0f, 4.0f, 2.0f, 1.0f));
	add(m_quad);
	//m_obj = new aie::OBJMesh();
	//m_obj->load("Lucy.obj");
}

void TestWorld::onDraw()
{
	//m_obj->draw();
}

void TestWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_quad);
	//delete m_obj;
}


