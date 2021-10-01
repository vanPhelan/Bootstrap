#pragma once
#include "Entity.h"
#include "Quad.h"
#include "glm/mat4x4.hpp"
#include <list>

class World
{
public:
	World() {}
	~World() {}

	void start();
	void update(float deltaTime);
	void draw();
	void end();

	virtual void onStart() {}
	virtual void onUpdate(float deltaTime) {}
	virtual void onDraw() {}
	virtual void onEnd() {}

	void add(Entity* entity);
	void remove(Entity* entity);
	void destroy(Entity* entity);

	glm::mat4 getViewModel();

private:
	glm::mat4 m_viewMatrix = glm::mat4(1.0f);

	std::list<Entity*> entities;
	std::list<Entity*> addQueue;
	std::list<Entity*> removeQueue;
	std::list<Entity*> destroyQueue;
};

