#include "Transform.h"
#include "glm/gtc/matrix_transform.hpp"

glm::vec3 Transform::getPosition()
{
	return m_position;
}

void Transform::setPosition(glm::vec3 position)
{
	m_position = glm::vec4(position, 1.0f);

}

void Transform::setPosition(float x, float y, float z)
{
	m_position = glm::vec4(x, y, z, 1.0f);
}

glm::vec3 Transform::getRotation()
{
	return m_rotation;
}

void Transform::setRotation(glm::vec3 rotation)
{
	m_rotation = glm::vec4(rotation, 0.0f);
}

void Transform::setRotation(float x, float y, float z)
{
	m_rotation = glm::vec4(x, y, z, 0.0f);
}

glm::vec3 Transform::getScale()
{
	return m_scale;
}

void Transform::setScale(glm::vec3 scale)
{
	m_scale = glm::vec4(scale, 0.0f);
}

void Transform::setScale(float x, float y, float z)
{
	m_scale = glm::vec4(x, y, z, 0.0f);
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

glm::mat4 Transform::getMatrix()
{
	if (m_isMatrixDirty) {
		glm::mat4 matrix = glm::mat4(1.0f);

		matrix = glm::translate(matrix, m_position);
		matrix = glm::rotate(matrix, m_rotation.y, glm::vec3(-1.0f, 0.0f, 0.0f));
		matrix = glm::rotate(matrix, m_rotation.x, glm::vec3(0.0f, 1.0f, 0.0f));
		matrix = glm::rotate(matrix, m_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
		matrix = glm::scale(matrix, m_scale);

		m_transformMatrix = matrix;
	}

	return m_transformMatrix;
}
