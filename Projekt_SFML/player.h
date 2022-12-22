#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "beeing.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player: public Beeing {

public:
	Player() {};
	bool thrust;
	bool Brakes;
	float brakes;
	float speed;
	int score = 0;
	std::string name;
	void update();
	Player(std::string, std::string);

	void draw(sf::RenderWindow&);
		
	void draw();

};
#endif
