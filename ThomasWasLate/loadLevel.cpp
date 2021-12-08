#include "Engine.h"

void Engine::loadLevel()
{
	m_IsPlaying - false;

	for (int h = 0; h < m_LM.getLevelSize().y; ++h)
	{
		delete[] m_ArrayLevel[h];
	}

	delete[] m_ArrayLevel;

	m_ArrayLevel = m_LM.nextLevel(m_VALevel);

	m_TimeRemaining = m_LM.getTimeLimit();

	m_Thomas.spawn(m_LM.getStartPosition(), GRAVITY);
	m_Bob.spawn(m_LM.getStartPosition(), GRAVITY);

	m_NewLevelRequired = false;
}