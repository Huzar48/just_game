#include "Animation.h"
#include "settings.h"

Animation::Animation(sf::Texture& t, int x, int y, int w, int h, int count, float Speed)
{
    Frame = 0;
    speed = Speed;

    for (int i = 0; i < count; i++)
        frames.push_back(sf::IntRect(x + i * w, y, w, h));

    this->sprite = new sf::Sprite(t);
 //   this->sprite.setTexture(t);
    this->sprite->setOrigin(w/ 2,h/ 2);
    this->sprite->setTextureRect(frames[0]);
}

void Animation::update()
{
    Frame += speed;
    int n = frames.size();
    if (Frame >= n) Frame -= n;
    if (n > 0) sprite->setTextureRect(frames[int(Frame)]);
}

bool Animation::isEnd()
{
    return Frame + speed >= frames.size();
}