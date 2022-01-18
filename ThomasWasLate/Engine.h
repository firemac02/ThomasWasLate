#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "PlayableCharacter.h"
#include "Thomas.h"
#include "Bob.h"
#include "HUD.h"

using namespace sf;

class Engine
{
private:
	TextureHolder th;

	Thomas m_Thomas;
	Bob m_Bob;

	LevelManager m_LM;

	SoundManager m_SM;

	Hud m_Hud;
	int m_FramesSinceLastHUDUpdate = 0;
	int m_TargetFramesPerHUDUpdate = 500;

	const int TILE_SIZE = 50;
	const int VERT_IN_QUAD = 4;

	const int GRAVITY = 300;

	RenderWindow m_Window;

	View m_MainView;
	View m_LeftView;
	View m_RightView;

	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;
	View m_HUDView;

	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	bool m_IsPlaying = false;

	bool m_Character1 = true;

	bool m_SplitScreen = false;

	bool m_NewLevelRequired = true;

	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	VertexArray m_VALevel;

	int** m_ArrayLevel = NULL;

	Texture m_TextureFiles;

	vector <Vector2f> m_FireEmitters;

	void input();
	void update(float dtAsSeconds);
	void draw();
	void loadLevel();
	void populateEmitters(vector<Vector2f>& vSoundEmitters, int** arrayLevel);
	bool detectCollisons(PlayableCharacter& character);

public:
	Engine();
	void run();
};

#endif ENGINE_H