#include "menu.h"
#include <SFML/Graphics.hpp>
#include "game.h"
#include "settings.h"
#include "menu.h"
#include <iostream>

using namespace sf;
using namespace std;

bool Menu::menu()
{
	////////////load textures///////////////
	Texture background, menu_grph;
	background.loadFromFile(BACKGROUND);
	menu_grph.loadFromFile(MENU);

	/////////////Antyaliassing///////////
	background.setSmooth(true);
	menu_grph.setSmooth(true);

	//////////making window////////////
	static sf::RenderWindow menu_window;
	menu_window.create(VideoMode(RES_X, RES_Y), "Space Invaders Bieda Edition");
	menu_window.setFramerateLimit(60);

	//////////setting the window icon//////////////
	auto image = sf::Image{};
	if (!image.loadFromFile(ENEMY_TEXTURE)) {}
	menu_window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

	/////////////fixing some input stuff///////////
	menu_window.setKeyRepeatEnabled(false);
	// app_window.setMouseCursorGrabbed(true);
	menu_window.setMouseCursorVisible(false);

	//////////////App Background/////////////////
	sf::Sprite bckg(background);
	bckg.setScale(1, 1);
	bckg.setPosition(0, 0);
	sf::Sprite mgrpg(menu_grph);
	mgrpg.setScale(1, 1);
	mgrpg.setPosition(0, 0);


		
		while (menu_window.isOpen()) {

		menu_window.setActive(true);
		menu_window.setVisible(true);

		//close aplication if user press the escape button
		Event event;
		while (menu_window.pollEvent(event))
		{

			if (event.type == Event::Closed || (Keyboard::isKeyPressed(Keyboard::EXIT))) {
				cout << "Exiting Game" << endl;
				menu_window.close();
				return true;

			};

			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::PLR_SHOOT)
				{
					cout << "Starting Game" << endl;
					return false;
				}

		menu_window.clear();
		menu_window.draw(bckg); 
		menu_window.draw(mgrpg);
		menu_window.display();

		}
	}
}