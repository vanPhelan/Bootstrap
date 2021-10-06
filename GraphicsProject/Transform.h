#pragma once
#include "glm/mat4x4.hpp"
#include "glm/vec3.hpp"

class Transform
{
public:
	Transform() {}
	~Transform() {}

	glm::vec3 getPosition();
	void setPosition(glm::vec3 position);
	void setPosition(float x, float y, float z);
	glm::vec3 getRotation();
	void setRotation(glm::vec3 rotation);
	void setRotation(float x, float y, float z);
	glm::vec3 getScale();
	void setScale(glm::vec3 scale);
	void setScale(float x, float y, float z);

	glm::vec3 getRight();
	glm::vec3 getUp();
	glm::vec3 getForward();

	glm::mat4 getMatrix();

private:
	glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 m_rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 m_scale = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::mat4 m_transformMatrix = glm::mat4(1.0f);
	bool m_isMatrixDirty = true;
};

