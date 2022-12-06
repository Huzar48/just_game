#include <SFML/Graphics.hpp>

#ifndef openwindow_hpp
#define openwindow_hpp

void openwindow()


{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {

        window.clear();
        window.draw(shape);
        window.display();
    }
}
#endif

