#include <iostream>
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "beeing.h"
#include "bullet.h"



Bullet::Bullet(std::string name, std::string tex) : Beeing(tex)
{
    this->name = name;
}

void Bullet::update(){
    this->dx = cos(this->angle * DEGTORAD) * 6;
    this->dy = sin(this->angle * DEGTORAD) * 6;
    //angle+=rand()%7-3;  /*try this*/
    this->x += this->dx;
    this->y += this->dy;

    if (this->x > RES_Y || this->x<0 || this->y>RES_X || y < 0) this->life = 0;
}