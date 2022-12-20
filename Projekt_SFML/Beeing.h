#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"


#ifndef BEEING_H
#define BEEING_H

class Beeing {


public:

	float x, y, dx, dy, R, angle, speed;
	bool life;
	std::string name;
	sf::Texture tex;
	Beeing() {};
	Beeing(std::string);
	void settings(int, int, float, int, int);
	virtual void update();
	void draw(sf::RenderWindow&);
	virtual ~Beeing();

};
#endif
