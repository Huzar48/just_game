#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


#ifndef GAME_H
#define GAME_H

using namespace std;

class Game {

public:
	static void game();
	void Dt(float);
	virtual ~Game();
	sf::Clock dtClock;
	float dt;
	void updateDt();
};

#endif