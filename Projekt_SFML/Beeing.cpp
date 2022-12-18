#include <iostream>
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "beeing.h"
#include "./Animation.h"

using namespace std;
using namespace sf;


Beeing::Beeing(std::string tex_path)
{   
    this->tex.loadFromFile(tex_path);
	this->life = 1;
}

void Beeing::settings(Animation& a, int X, int Y, float Angle, int radius)
{
    this->anim = a;
    this->x = X; this->y = Y;
    this->angle = Angle;
    this->R = radius;
}

void Beeing::update()
{
}



void Beeing::draw(sf::RenderWindow& app)
{
    sf::Texture player_texture;
    player_texture.loadFromFile(PLAYER_TEXTURE);
    sf::Sprite plr(player_texture);
    plr.setScale(0.2f, 0.2f);

//    anim.sprite->setPosition(this->x, this->y);
  //  anim.sprite->setRotation(this->angle + 90);
 //   app.draw(*anim.sprite);

  //  CircleShape circle(this->R);
  //  circle.setFillColor(Color(255, 0, 0, 170));
    plr.setPosition(this->x, this->y);
    plr.setOrigin(this->R, this->R);
    app.draw(plr);
}