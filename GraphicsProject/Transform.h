#pragma once
#include "glm/mat4x4.hpp"
#include "glm/vec3.hpp"
#include "glm/gtc/quaternion.hpp"

class Transform
{
public:
	Transform() {}
	~Transform() {}

	glm::vec3 getPosition();
	void setPosition(glm::vec3 position);
	glm::quat getRotation();
	void setRotation(glm::quat rotation);
	glm::vec3 getScale();
	void setScale(glm::vec3 scale);

	glm::vec3 getRight();
	glm::vec3 getUp();
	glm::vec3 getForward();

private:
	glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 m_positionMatrix = glm::mat4(0.0f);
	glm::quat m_rotation = glm::quat();
	glm::mat4 m_rotationMatrix = glm::mat4(0.0f);
	glm::vec3 m_scale = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::mat4 m_scaleMatrix = glm::mat4(1.0f);
	glm::mat4 m_transformMatrix = glm::mat4(1.0f);
};

