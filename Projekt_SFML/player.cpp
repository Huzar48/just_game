#include <iostream>
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "beeing.h"
#include "player.h"
#include <string>

using namespace std;
using namespace sf;


Player::Player(std::string name, std::string tex) : Beeing(tex) {
    this->name = name;
}


void Player::update()
{
    if (thrust)
    {
        this->dx += cos(angle * DEGTORAD) * 0.2;
        this->dy += sin(angle * DEGTORAD) * 0.2;
    }
    else
    {
        this->dx *= 0.99;
        this->dy *= 0.99;
    }

    int maxSpeed = 15;
    float speed = sqrt(dx * dx + dy * dy);
    if (speed > maxSpeed)
    {
        this->dx *= maxSpeed / speed;
        this->dy *= maxSpeed / speed;
    }

    this->x += this->dx;
    this->y += this->dy;

    if (x > RES_X) x = 0; if (x < 0) x = RES_X;
    if (y > RES_Y) y = 0; if (y < 0) y = RES_Y;
}