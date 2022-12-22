#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

void Animation::gif(std::string)
{
    //////////gif animation////////////
    sf::Clock clock;
    sf::Time elapsedTime = sf::Time::Zero;
    sf::Time frameTime = sf::seconds(1.0f / 10.0f); // update gif every 1/10 seconds
    //int frameWidth = tex.getSize().x / 10; // gif has 10 frames
    int currentFrame = 0;

    elapsedTime += clock.restart();
    while (elapsedTime > frameTime) {
        elapsedTime -= frameTime;
        currentFrame = (currentFrame + 1) % 10; // loop back to the first frame
        // entity.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, tex.getSize().y));

    }
}
