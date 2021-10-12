#include "Light.h"
#include "gl_core_4_4.h"

Light::Light(glm::vec3 direction, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular)
{
	setDirection(direction);
	m_ambient = ambient;
	m_diffuse = diffuse;
	m_specular = specular;
}

void Light::onDraw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);

	if (program == -1) {
		printf("No shader bound!\n");
		return;
	}

	int lightDirection = glGetUniformLocation(program, "lightDirection");
	int lightAmbient = glGetUniformLocation(program, "lightAmbient");
	int lightDiffuse = glGetUniformLocation(program, "lightDiffuse");
	int lightSpecular = glGetUniformLocation(program, "lightSpecular");

	if (lightDirection >= 0) {
		glm::vec3 direction = getDirection();
		glUniform3f(lightDirection, direction.x, direction.y, direction.z);
	}
	if (lightAmbient >= 0) {
		glUniform3f(lightAmbient, m_ambient.x, m_ambient.y, m_ambient.z);
	}
	if (lightDiffuse >= 0) {
		glUniform3f(lightDiffuse, m_diffuse.x, m_diffuse.y, m_diffuse.z);
	}
	if (lightSpecular >= 0) {
		glUniform3f(lightSpecular, m_specular.x, m_specular.y, m_specular.z);
	}

	//Bind the global transform matrix as uniform modelMatrix
	int modelMatrix = glGetUniformLocation(program, "modelMatrix");
	if (modelMatrix >= 0)
		glUniformMatrix4fv(modelMatrix, 1, false, &(getTransform()->getGlobalMatrix())[0][0]);
}

glm::vec3 Light::getDirection()
{
	return getTransform()->getForward();
}

void Light::setDirection(glm::vec3 direction)
{
	getTransform()->setRotation(direction);
}
