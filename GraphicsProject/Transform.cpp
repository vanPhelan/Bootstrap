#include "Transform.h"
#include "glm/gtc/matrix_transform.hpp"

glm::vec3 Transform::getPosition()
{
	return m_position;
}

void Transform::setPosition(glm::vec3 position)
{
	m_position = position;
	m_positionMatrix = glm::translate(glm::mat4(1.0f), position);

}

glm::quat Transform::getRotation()
{
	return m_rotation;
}

void Transform::setRotation(glm::quat rotation)
{
	m_rotation = rotation;
	glm::vec3 eulerAngles = glm::eulerAngles(rotation);
	glm::mat4 matrix = glm::mat4(1.0f);
	matrix = glm::rotate(matrix, rotation.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	matrix = glm::rotate(matrix, rotation.x, glm::vec3(0.0f, 1.0f, 0.0f));
	matrix = glm::rotate(matrix, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	m_rotation = matrix;
}

glm::vec3 Transform::getScale()
{
	return m_scale;
}

void Transform::setScale(glm::vec3 scale)
{
	m_scale = scale;
	m_scaleMatrix = glm::scale(glm::mat4(1.0f), scale);
}

glm::vec3 Transform::getRight()
{
	return glm::vec3();
}

glm::vec3 Transform::getUp()
{
	return glm::vec3();
}

glm::vec3 Transform::getForward()
{
	return glm::vec3();
}
