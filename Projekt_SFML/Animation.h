#pragma once
#include <SFML/Graphics.hpp>


class Animation
{
public:
	float Frame, speed;
	sf::Sprite *sprite;
	std::vector<sf::IntRect> frames;
	Animation() {};
	Animation(sf::Texture& , int , int , int , int , int , float );
	void update();
	bool isEnd();


};

