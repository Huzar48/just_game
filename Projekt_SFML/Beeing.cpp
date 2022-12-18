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
    //sf::Texture player_texture;
    //player_texture.loadFromFile(PLAYER_TEXTURE);
    sf::Sprite entity(tex);  
    //plr.setScale(0.2f, 0.2f);

    //anim.sprite->setPosition(this->x, this->y);
    //anim.sprite->setRotation(this->angle + 90);
    //app.draw(*anim.sprite);
  
    entity.setPosition(this->x, this->y);
    entity.setScale(0.25f, 0.25f);
    sf::Vector2u textureSize = tex.getSize();
    entity.setOrigin(textureSize.x/2,textureSize.y/2);
    entity.rotate(this->angle);
    sf::Vector2f velocity(10.f, 0.f);
    app.draw(entity);

    //CircleShape circle(this->R);
    //circle.setFillColor(Color(255, 0, 0, 170));
    //plr.setPosition(this->x, this->y);
    //plr.setOrigin(this->R, this->R);
    //app.draw(plr);
}

Beeing::~Beeing() {};
