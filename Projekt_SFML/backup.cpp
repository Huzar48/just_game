/*
#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "game.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "");

     //////////////app window render////////////////

     sf::RenderWindow app_window;
     app_window.create(sf::VideoMode(1920, 1080), "Space Invaders Bieda Edition");
     app_window.setActive(true);
     app_window.setPosition(sf::Vector2i( 10, 10));
     app_window.setFramerateLimit(60);
     app_window.setVisible(true);

     sf::Texture t1,t2,t3, t4, t5;
     t1.loadFromFile("player.png");
     t2.loadFromFile("enemy.png");
     t3.loadFromFile("metero.png");
     t4.loadFromFile("bullet.png");
     t5.loadFromFile("background.png");

    // sf::SoundBuffer

     //////////setting the window icon//////////////
     auto image = sf::Image{};
     if (!image.loadFromFile("enemy.png")){}
     app_window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

     /////////////////Camera//////////////////////

     sf::View main_camera;
     main_camera.setCenter(960, 300);
     main_camera.setSize(960, 540);

     /////////////fixing some input stuff///////////

     app_window.setKeyRepeatEnabled(false);
         // app_window.setMouseCursorGrabbed(true);
     app_window.setMouseCursorVisible(true);

     //adding player graphics

    // sf::SoundBuffer shot;
     //shot.loadFromFile("shot.wav");
     //sf::Sound sound;
     //sound.setBuffer(shot);
     //sound.setVolume(100);

     sf::SoundBuffer buffer;
     sf::Sound sound;
     if (buffer.loadFromFile("shot.wav")) {
         sound.setBuffer(buffer);
     }


     sf::Texture background;
     background.loadFromFile("background.png");
     sf::Sprite sprite2(background);
     sprite2.setScale(1, 1);
     sprite2.setPosition(0, 0);
     app_window.draw(sprite2);

     sf::Texture player_graphic;
     player_graphic.loadFromFile("player.png");
     sf::Sprite sprite(player_graphic);
     sprite.setScale(0.3, 0.3);
     sprite.setPosition(960, 540);
     app_window.draw(sprite);

     sf::Event e;
     sf::Event exit;

     //MAIN game loop

     while (app_window.isOpen()) {

         app_window.clear();
         app_window.draw(sprite2);
         app_window.draw(sprite);
         app_window.display();

         //close aplication if user press the escape button
         while (app_window.pollEvent(exit)) {
             if (exit.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) app_window.close();
         }

         while (app_window.pollEvent(e)) {
             if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Space){
                 if (sound.getStatus() == sf::Sound::Playing)
                     sound.play();
             }
             if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::R) sprite.move(50, 0);
             if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::W) main_camera.setSize(main_camera.getSize().x + 50, main_camera.getSize().y + 30);
         }

     } 

}*/