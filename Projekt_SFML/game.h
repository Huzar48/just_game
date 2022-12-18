#pragma once
#include <SFML/Graphics.hpp>

#ifndef GAME_H
#define GAME_H

using namespace std;

class Game {

public:
	Game(float);
	virtual ~Game();

	sf::Clock dtClock;
	float dt;
	void updateDt();
};

#endif