#include "Entity.h"

void Entity::setLocalTransform(glm::mat4 transform)
{
	m_localTransform = transform;
	isGlobalTransformDirty = true;
}

glm::mat4 Entity::getGlobalTransform()
{
	if (!m_parent)
		m_globalTransform = m_localTransform;
	else if (isGlobalTransformDirty)
		m_globalTransform = m_parent->getGlobalTransform() * m_localTransform;

	return m_globalTransform;
}
