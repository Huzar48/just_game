#include "menu.h"
#include <SFML/Graphics.hpp>
#include "game.h"
#include "settings.h"
#include "menu.h"

using namespace sf;

menu::menu() {
	this->appLife = true;
}

void menu::Menu(bool appLife) 
{
	while (this->appLife == true) {
		////////////load textures///////////////
		Texture background, player_texture, enemy_texture, bullet_texture, meteor_texture;
		background.loadFromFile(BACKGROUND);

		/////////////Antyaliassing///////////
		player_texture.setSmooth(true);
		background.setSmooth(true);
		enemy_texture.setSmooth(true);
		bullet_texture.setSmooth(false);
		meteor_texture.setSmooth(true);

		//////////making window////////////
		static sf::RenderWindow app;
		app.create(VideoMode(RES_X, RES_Y), "Space Invaders Bieda Edition");
		app.setFramerateLimit(60);

		//////////setting the window icon//////////////
		auto image = sf::Image{};
		if (!image.loadFromFile(ENEMY_TEXTURE)) {}
		app.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

		/////////////fixing some input stuff///////////
		app.setKeyRepeatEnabled(false);
		// app_window.setMouseCursorGrabbed(true);
		app.setMouseCursorVisible(true);

		//////////////App Background/////////////////
		sf::Sprite bckg(background);
		bckg.setScale(1, 1);
		bckg.setPosition(0, 0);
	}

};