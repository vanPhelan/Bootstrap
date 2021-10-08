#include "Transform.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/euler_angles.hpp"
#include "glm/gtx/transform.hpp"

void Transform::translate(glm::vec3 translation)
{
	m_position += translation;
	m_shouldUpdateLocalMatrix = true;
}

void Transform::translate(float x, float y, float z)
{
	translate(glm::vec3(x, y, z));
}

void Transform::rotate(glm::vec3 rotation)
{
	m_rotation += rotation;
	m_shouldUpdateLocalMatrix = true;
}

void Transform::rotate(float pitch, float yaw, float roll)
{
	glm::toQuat()
}

void Transform::scale(glm::vec3 scale)
{
	m_scale += scale;
	m_shouldUpdateLocalMatrix = true;
}

void Transform::scale(float x, float y, float z)
{
	scale(glm::vec3(x, y, z));
}

void Transform::setPosition(glm::vec3 position)
{
	m_position = glm::vec3(position);
	m_shouldUpdateLocalMatrix = true;

}

void Transform::setPosition(float x, float y, float z)
{
	setPosition(glm::vec3(x, y, z));
}

void Transform::setRotation(glm::quat rotation)
{
	m_rotation = glm::quat(rotation);
	m_shouldUpdateLocalMatrix = true;
}

void Transform::setRotation(float pitch, float yaw, float roll)
{
	
	setRotation(glm::vec3(x, y, z));
}

void Transform::setScale(glm::vec3 scale)
{
	m_scale = glm::vec3(scale);
	m_shouldUpdateLocalMatrix = true;
}

void Transform::setScale(float x, float y, float z)
{
	setScale(glm::vec3(x, y, z));
}

glm::mat4 Transform::getLocalMatrix()
{
	if (m_shouldUpdateLocalMatrix) {
		//glm::mat4 matrix = glm::mat4(1.0f);

		//matrix = glm::translate(matrix, m_position);
		//matrix = glm::rotate(matrix, m_rotation.y, glm::vec3(-1.0f, 0.0f, 0.0f));
		//matrix = glm::rotate(matrix, m_rotation.x, glm::vec3(0.0f, 1.0f, 0.0f));
		//matrix = glm::rotate(matrix, m_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
		//matrix = glm::scale(matrix, m_scale);

		//m_localMatrix = matrix;

		m_localMatrix = glm::translate(m_position) * glm::toMat4(m_rotation) * glm::scale(m_scale);
	}

	return m_localMatrix;
}

glm::mat4 Transform::getGlobalMatrix()
{
	if (!m_parent) {
		m_globalMatrix = getLocalMatrix();
	}
	else if (m_shouldUpdateGlobalMatrix) {
		m_globalMatrix = m_parent->getGlobalMatrix() * getLocalMatrix();
	}

	return m_globalMatrix;
}
