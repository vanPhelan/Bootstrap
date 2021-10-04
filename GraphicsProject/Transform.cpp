#include "Transform.h"
#include "glm/gtc/matrix_transform.hpp"

void Transform::lookAt(Transform* target)
{
	m_matrix = glm::lookAt(
		getPosition(),
		target->getPosition(),
		getRight()
	);
}

glm::vec3 Transform::getPosition()
{
	return m_position;
}

void Transform::setPosition(glm::vec3 position)
{
	m_matrix = glm::translate(m_matrix, position - m_position);
	m_position = position;

}

glm::vec3 Transform::getRotation()
{
	return m_rotation;
}

void Transform::setRotation(glm::vec3 rotation)
{
	//m_matrix = glm::rotate(m_matrix, rotation - m_rotation);
	m_rotation = rotation;
}

glm::vec3 Transform::getScale()
{
	return m_scale;
}

void Transform::setScale(glm::vec3 scale)
{
	m_scale = scale, 0.0f;
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
