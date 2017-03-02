#ifndef PLAYER
#define PLAYER

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

#include "Cube.h"

//
class Player
{
public:
	void initialize()
	{
		m_modelP = glm::mat4(1.0f);
		m_position = sf::Vector3f(0, 0, 0);
		jumping = false;
	}

	//
	void MovePlayer()
	{
		//
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			m_position.z -= 1.0f;
			m_modelP = glm::translate(m_modelP, glm::vec3(0, 0, -0.25 * 1));
		}
		//
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_position.z += 1.0f;
			m_modelP = glm::translate(m_modelP, glm::vec3(0, 0, 0.25 * 1));
		}
		//
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			m_position.x -= 1.0f;
			m_modelP = glm::translate(m_modelP, glm::vec3(-0.25 * 1, 0, 0));
		}
		//
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_position.x += 1.0f;
			m_modelP = glm::translate(m_modelP, glm::vec3(0.25 * 1, 0, 0));
		}
		//
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			jumping = true;
		}

	}

	//
	void PlayerJumping()
	{
		//
		if (jumping == true)
		{
			//
			m_modelP = glm::translate(m_modelP, glm::vec3(0, 0.002 * m_gravity.y, 0));
			m_position.y += 1.0f;
			//
			if (m_position.y >= 250)
			{
				m_modelP = glm::translate(m_modelP, glm::vec3(0, -0.002 * m_gravity.y, 0));
				m_position.y = 250;
				//
				falling = true;
				jumping = false;
			}
		}
		//
		if (falling == true)
		{
			//
			m_modelP = glm::translate(m_modelP, glm::vec3(0, -0.002 * m_gravity.y, 0));
			m_position.y -= 1.0f;
			//
			if (m_position.y <= 0)
			{
				m_modelP = glm::translate(m_modelP, glm::vec3(0, 0.002 * m_gravity.y, 0));
				m_position.y = 0;
				falling = false;
			}
		}

	}

	//
	void BoundaryCheck()
	{
		if (m_position.x > 30)
		{
			m_modelP = glm::translate(m_modelP, glm::vec3(-0.25 * 1, 0, 0));
			m_position.x = 30;
		}
		else if (m_position.x < -30)
		{
			m_modelP = glm::translate(m_modelP, glm::vec3(0.25 * 1, 0, 0));
			m_position.x = -30;
		}
	}

	//
	void setModel(glm::mat4 model)
	{
		m_modelP = model;
	}

	//
	glm::mat4 getModel()
	{
		return m_modelP;
	}

	//
	void setPosition(sf::Vector3f position)
	{
		m_position = position;
	}

	//
	sf::Vector3f getPosition()
	{
		return m_position;
	}

private:
	sf::Vector3f m_position;
	sf::Vector3f m_gravity = sf::Vector3f(0.0f, 9.8f, 0.0f);
	glm::mat4 m_modelP;
	bool jumping = false, falling = false;
};


#endif