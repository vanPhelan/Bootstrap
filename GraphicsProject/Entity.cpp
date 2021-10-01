#include "Entity.h"

void Entity::start()
{
	onStart();
	m_started = true;
}

void Entity::update(float deltaTime)
{
	if (!m_started)
		start();

	onUpdate(deltaTime);
}

void Entity::draw()
{
	onDraw();
}

void Entity::end()
{
	onEnd();
	m_started = false;
}

void Entity::setLocalTransform(glm::mat4 transform)
{
	m_localTransform = transform;
	m_isGlobalTransformDirty = true;
}

glm::mat4 Entity::getGlobalTransform()
{
	if (!m_parent)
		m_globalTransform = m_localTransform;
	else if (m_isGlobalTransformDirty)
		m_globalTransform = m_parent->getGlobalTransform() * m_localTransform;

	return m_globalTransform;
}
