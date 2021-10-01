#include "World.h"
#include "glm/ext.hpp"

void World::start()
{
	//Create camera transforms
	m_viewMatrix = glm::lookAt(
		glm::vec3(10.0f, 10.0f, 10.0f),
		glm::vec3(0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);

	onStart();
}

void World::update(float deltaTime)
{
	onUpdate(deltaTime);

	//Update the list of entities
	for (Entity* entity : addQueue) {
		entities.push_back(entity);
	}
	for (Entity* entity : removeQueue) {
		entities.remove(entity);
	}
	for (Entity* entity : destroyQueue) {
		entities.remove(entity);
		delete entity;
	}

	//Update the entities
	for (Entity* entity : entities) {
		entity->update(deltaTime);
	}
}

void World::draw()
{
	onDraw();

	for (Entity* entity : entities) {
		entity->draw();
	}
}

void World::end()
{
	onEnd();
}

void World::add(Entity* entity)
{
	removeQueue.remove(entity);
	addQueue.push_back(entity);
}

void World::remove(Entity* entity)
{
	addQueue.remove(entity);
	removeQueue.push_back(entity);
}

void World::destroy(Entity* entity)
{
	addQueue.remove(entity);
	removeQueue.remove(entity);
	destroyQueue.push_back(entity);
}

glm::mat4 World::getViewModel()
{
	return m_viewMatrix;
}
