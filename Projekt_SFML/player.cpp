#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "beeing.h"
#include "player.h"
#include <string>

using namespace std;
using namespace sf;


Player::Player(std::string name, std::string tex) : Beeing(tex) {
    this->name = name;
    this->thrust = false;
    this->brakes = false;
    this->life = 3;

    this->highScore = this->highScore;
}


void Player::update()
{
   if (thrust == true)
    {
        
        this->dx += cos(this->angle * DEGTORAD) * 0.2;
        this->dy += sin(this->angle * DEGTORAD) * 0.2;
    }
       else
        {
           this->dx *= 0.99;
           this->dy *= 0.99;
       }

   /*if (Brakes == true)
   {
       this->brakes *= -0.1;
   }   
       else {
             this->brakes = 1;
       }*/

    int maxSpeed = 10;
    float speed = sqrt(this->dx * this->dx + this->dy * this->dy * this->brakes);

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