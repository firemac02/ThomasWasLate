#include "Engine.h"

void Engine::input()
{
	sf::Event e;

	while (m_Window.pollEvent(e))
	{
		if (e.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				m_Window.close();
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				m_IsPlaying = true;
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				m_Character1 = !m_Character1;
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			{
				m_SplitScreen = !m_SplitScreen;
			}
		}
	}

	if (m_Thomas.handleInput())
	{

	}

	if (m_Bob.handeInput())
	{

	}
}