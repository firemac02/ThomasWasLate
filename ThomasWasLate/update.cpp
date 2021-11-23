#include "Engine.h"

void Engine::update(float dtAsSeconds)
{
	if (m_IsPlaying)
	{
		m_TimeRemaining -= dtAsSeconds;

		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}
	}
}