#pragma once
#include "Entity.h"
#include "Mesh.h"
#include "glm/mat4x4.hpp"

class World
{
public:
	World();
	~World() {}

	void start();
	void update(float deltaTime);
	void draw();
	void end();

	glm::mat4 getViewModel();

private:
	Mesh m_quad;
	glm::mat4 m_viewMatrix = glm::mat4(1.0f);

	Entity* entities;
	int entityCount;
};

