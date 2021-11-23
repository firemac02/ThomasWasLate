#include "Engine.h"

void Engine::draw()
{
	m_Window.clear(sf::Color::White);

	if (!m_IsSplitScreen)
	{
		m_Window.setView(m_BGMainView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_MainView);
	}
	else
	{
		m_Window.setView(m_BGLeftView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_LeftView);
		
		m_Window.setView(m_BGRightView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_RightView);
	}

	m_Window.setView(m_HUDView);

	m_Window.display();
}