#include "Engine.h"

Engine::Engine()
{
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	m_Window.create(sf::VideoMode(resolution.x, resolution.y), "Thomas Was Late", sf::Style::Fullscreen);

	m_MainView.setSize(resolution);
	m_HUDView.reset(sf::FloatRect(0, 0, resolution.x, resolution.y));

	m_LeftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_RightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	m_BGLeftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGRightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_BackgroundTexture = TextureHolder::GetTexture("assets/graphics/background.png");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	m_TextureFiles = TextureHolder::GetTexture("assets/graphics/tiles_sheet.png");
}

void Engine::run()
{
	sf::Clock clock;

	while (m_Window.isOpen())
	{
		sf::Time dt = clock.restart();

		m_GameTimeTotal += dt;

		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}
}