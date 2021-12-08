#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "LevelManager.h"
#include "PlayableCharacter.h"
#include "Thomas.h"
#include "Bob.h"

using namespace sf;

class Engine
{
private:
	TextureHolder th;

	Thomas m_Thomas;
	Bob m_Bob;

	LevelManager m_LM;

	const int TILE_SIZE = 50;
	const int VERT_IN_QUAD = 4;

	const int GRAVITY = 300;

	sf::RenderWindow m_Window;

	sf::View m_MainView;
	sf::View m_LeftView;
	sf::View m_RightView;

	sf::View m_BGMainView;
	sf::View m_BGLeftView;
	sf::View m_BGRightView;
	sf::View m_HUDView;

	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	bool m_IsPlaying = false;

	bool m_Character1 = true;

	bool m_SplitScreen = false;

	bool m_NewLevelRequired = true;

	float m_TimeRemaining = 10;
	sf::Time m_GameTimeTotal;

	VertexArray m_VALevel;

	int m_ArrayLevel = NULL;

	Texture m_TextureFiles;

	void input();
	void update(float dtAsSeconds);
	void draw();
	void loadLevel();
	bool detectCollisons(PlayableCharacter& character);

public:
	Engine();
	void run();
};

#endif ENGINE_H