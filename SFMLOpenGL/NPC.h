#ifndef N_PC
#define N_PC
//
// C00204076
// Brandon Seah-Dempsey
// Started at 09:21 20 February 2017
// Finished at
// Time taken:
// Known bugs:

#include <iostream>

#include <GL/glew.h>
#include <GL/wglew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

//
class NPC
{
public:
	void initialize()
	{
		m_modelN = glm::mat4(1.0f);
		m_positionN = sf::Vector3f(30, 0, 0);
		left = true;
		right = false;
	}

	void startCubePosition(int i)
	{
		m_modelN = glm::translate(m_modelN, glm::vec3(-3.0f * i, 0, 0.25 * -50));
		m_modelN = glm::translate(m_modelN, glm::vec3(12.0f, 0, 0));
		m_positionN.x = -3.0f * i;
	}

	void MoveCube()
	{
		//
		timer += 1;
		//
		if (timer >= 400)
		{
			m_positionN.z += 0.5f;
			m_modelN = glm::translate(m_modelN, glm::vec3(0, 0, 0.125 * 1));
			side *= -1;
		}
		//
		if (timer >= 420)
		{
			timer = 0;
		}
	}

	void NPCBoundaryCheck()
	{
		if (m_positionN.z > 60)
		{
			//
			if (side == 1)
			{
				m_modelN = glm::translate(m_modelN, glm::vec3(12.0f * side, 0, 0.25 * -60));
				m_positionN.z = 0;
			}
			
			//
			else if (side == -1)
			{
				m_modelN = glm::translate(m_modelN, glm::vec3(14.0f * side, 0, 0.25 * -60));
				m_positionN.z = 0;
			}

		}
	}

	void setModelN(glm::mat4 model)
	{
		m_modelN = model;
	}

	glm::mat4 getModelN()
	{
		return m_modelN;
	}

	void setPositionN(sf::Vector3f position)
	{
		m_positionN = position;
	}

	sf::Vector3f getPositionN()
	{
		return m_positionN;
	}

private:
	sf::Vector3f m_positionN;
	glm::mat4 m_modelN;
	bool left = false, right = true;
	int timer = 0;
	int newX, side = 1;
};

#endif