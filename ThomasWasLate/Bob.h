#ifndef BOB_H
#define BOB_H
#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{
public:
	Bob();

	bool virtual handleInput();
};

#endif Bob_H