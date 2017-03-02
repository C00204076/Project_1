#ifndef GOAL
#define GOAL

//
// C00204076
// Brandon Seah-Dempsey
// Started at 09:21 20 February 2017
// Finished at
// Time taken:
// Known bugs:

#include <iostream>
#include <time.h>

#include <GL/glew.h>
#include <GL/wglew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>



//
class Goal
{
public:
	void initialize()
	{
		m_modelG = glm::mat4(1.0f);
		m_positionG = sf::Vector3f(0, 0, 0);
		left = true;
		right = false;
	}

	void setGoal()
	{
		m_modelG = glm::translate(m_modelG, glm::vec3(0, 0, 0.25 * -50));
	}

	void MoveGoal()
	{
		timer += 1;

		//
		if (timer >= 1100)
		{
			m_positionG.z += 0.5f;
			m_modelG = glm::translate(m_modelG, glm::vec3(0, 0, 0.125 * 1));
		}
		//
		else if(timer == 1160)
		{
			timer = 0;
		}
	}

	void GoalBoundary()
	{
		if (m_positionG.z > 60)
		{	
			//
			if (lanePos >= 0)
			{
				lanePos += 1;
			}
			//
			else if (lanePos >= 5)
			{
				lanePos = -5;
			}
			//
			else if (lanePos <= -5)
			{
				lanePos += 1;
			}
			m_modelG = glm::translate(m_modelG, glm::vec3(0.5f * lanePos, 0, 0.25 * -60));
			m_positionG.z = 0;



		}
	}

	void setModelG(glm::mat4 model)
	{
		m_modelG = model;
	}

	glm::mat4 getModelG()
	{
		return m_modelG;
	}

	void setPositionG(sf::Vector3f position)
	{
		m_positionG = position;
	}

	sf::Vector3f getPositionG()
	{
		return m_positionG;
	}

private:
	sf::Vector3f m_positionG;
	glm::mat4 m_modelG;
	bool left = true, right = false;
	int lanePos = -2, timer;
};

#endif