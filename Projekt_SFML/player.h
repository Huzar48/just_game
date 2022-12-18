#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "beeing.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player: public Beeing {

public:
	bool thrust;
	std::string name;
	void update();
	Player(std::string, std::string);

};
#endif
