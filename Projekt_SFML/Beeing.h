#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "Animation.h"


#ifndef BEEING_H
#define BEEING_H

class Beeing {


public:

	float x, y, dx, dy, R, angle;
	bool life;
	std::string name;
	Animation anim;
	sf::Texture tex;
	Beeing(std::string);
	void settings(Animation&, int, int, float, int);
	virtual void update();
	void draw(sf::RenderWindow&);

};
#endif
