#include <iostream>
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "beeing.h"
#include "player.h"
#include <string>
#include "Meteor.h"

Meteor::Meteor(std::string name, std::string tex) : Beeing(tex) {
    this->dx = rand() % 8 - 4;
    this->dy = rand() % 8 - 4;
    this->name = "asteroid";
   }

void Meteor::update(){
    this->x += this->dx;
    this->y += this->dy;

    if (this->x > RES_X)  this->x = 0;  if (this->x < 0) x = RES_X;
    if (this->y > RES_Y)  this->y = 0;  if (this->y < 0) y = RES_Y;
}