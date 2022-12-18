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
        this->dx += cos(this->angle * DEGTORAD) * 0.2;
        this->dy += sin(this->angle * DEGTORAD) * 0.2;
    }
    else
    {
        this->dx *= 0.99;
        this->dy *= 0.99;
    }

    int maxSpeed = 15;
    float speed = sqrt(this->dx * this->dx + this->dy * this->dy);
    if (speed > maxSpeed)
    {
        this->dx *= maxSpeed / speed;
        this->dy *= maxSpeed / speed;
    }

    this->x += this->dx;
    this->y += this->dy;


    if (this->x > RES_X) this->x = 0; if (this->x < 0) this->x = RES_X;
    if (this->y > RES_Y) this->y = 0; if (this->y < 0) this->y = RES_Y;
}