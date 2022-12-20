#include <iostream>
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "beeing.h"

using namespace std;
using namespace sf;


Beeing::Beeing(std::string tex_path)
{   
    this->tex.loadFromFile(tex_path);
	this->life = 1;
}

void Beeing::settings(int X, int Y, float Angle, int radius, int Speed)
{
    this->x = X; this->y = Y;
    this->angle = Angle;
    this->R = radius;
    this->speed = Speed;
}

void Beeing::update()
{
    this->dx = cos(this->angle * DEGTORAD) * 6;
    this->dy = sin(this->angle * DEGTORAD) * 6;
    //this->angle += rand() % 7 - 3;  /*try this*/
    this->x += this->dx;
    this->y += this->dy;

}

void Beeing::draw(sf::RenderWindow& app)
{
  

        sf::Sprite entity(tex);
        entity.setScale(0.25f, 0.25f);
        sf::Vector2u textureSize = tex.getSize();
        entity.setOrigin(textureSize.x / 2, textureSize.y / 2);
        entity.setPosition(this->x, this->y);
        entity.rotate(this->angle+90);
        app.draw(entity);
    

    //CircleShape circle(this->R);
    //circle.setFillColor(Color(255, 0, 0, 170));
    //plr.setPosition(this->x, this->y);
    //plr.setOrigin(this->R, this->R);
    //app.draw(circle);
}




Beeing::~Beeing() {};
