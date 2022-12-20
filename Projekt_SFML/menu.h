#pragma once
#include <SFML/Graphics.hpp>
#include "game.h"

class menu: public Game
{
public:
	bool appLife;
	menu();

	void Menu(bool);

};

