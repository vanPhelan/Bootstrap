#include "World.h"
#include "glm/ext.hpp"

World::World()
{
}

void World::start()
{
	//Initialize the quad
	m_quad.start();

	//Create camera transforms
	m_viewMatrix = glm::lookAt(
		glm::vec3(10.0f, 10.0f, 10.0f),
		glm::vec3(0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);
}

void World::update(float deltaTime)
{
}

void World::draw()
{
	m_quad.draw();
}

void World::end()
{
}

glm::mat4 World::getViewModel()
{
	return m_viewMatrix * m_quad.getTransform();
}
