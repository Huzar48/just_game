#include "GameOver.h"
#include <SFML/Graphics.hpp>
#include "game.h"
#include "settings.h"
#include "menu.h"
#include <iostream>

using namespace sf;
using namespace std;

bool GameOver::gameOver()
{
	cout << "GAME_OVER" << endl;


	////////////load textures///////////////
	Texture background, game_over;
	background.loadFromFile(BACKGROUND);
	game_over.loadFromFile(GAME_OVER);

	sf::Sprite gover(game_over);

	/////////////Antyaliassing///////////
	background.setSmooth(true);
	game_over.setSmooth(true);

	//////////making window////////////
	static sf::RenderWindow gover_window;
	gover_window.create(VideoMode(RES_X, RES_Y), "Space Invaders Bieda Edition");
	gover_window.setFramerateLimit(60);

	//////////setting the window icon//////////////
	auto image = sf::Image{};
	if (!image.loadFromFile(ENEMY_TEXTURE)) {}
	gover_window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

	/////////////fixing some input stuff///////////
	gover_window.setKeyRepeatEnabled(false);
	// app_window.setMouseCursorGrabbed(true);
	gover_window.setMouseCursorVisible(false);

	//////////////App Background/////////////////
	sf::Sprite bckg(background);
	bckg.setScale(1, 1);
	bckg.setPosition(0, 0);



	while (gover_window.isOpen()) {

		gover_window.setActive(true);
		gover_window.setVisible(true);

		//close aplication if user press the escape button
		Event event;
		while (gover_window.pollEvent(event))
		{

			if (event.type == Event::Closed || (Keyboard::isKeyPressed(Keyboard::EXIT))) {
				cout << "Exiting Game" << endl;
				gover_window.close();
				return false;

			};

			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::PLR_SHOOT)
				{
					cout << "Restarting Game" << endl;
					gover_window.close();
					return true;
				}

			gover_window.clear();
			gover_window.draw(bckg);
			gover_window.draw(gover);
			gover_window.display();

		}
	}
}