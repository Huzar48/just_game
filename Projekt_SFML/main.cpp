#include <iostream>
#include <list>
#include "game.h"
#include "settings.h"
#include "Player.h"
#include <vector>

using namespace std;
using namespace sf;


int main() {

	srand(time(0));

	////////////load textures///////////////
	Texture background, player_texture, enemy_texture, bullet_texture, meteor_texture;
	background.loadFromFile(BACKGROUND);
	player_texture.loadFromFile(PLAYER_TEXTURE);
	enemy_texture.loadFromFile(ENEMY_TEXTURE);
	bullet_texture.loadFromFile(BULLET_TEXTURE);
	meteor_texture.loadFromFile(METEOR_TEXTURE);


	//Animation sRock(meteor_texture, 0, 0, 64, 64, 16, 0.2);
	//Animation sBullet(bullet_texture, 0, 0, 32, 64, 16, 0.8);
	Animation sPlayer(player_texture, 40, 0, 40, 40, 1, 0);
	Animation sPlayer_go(player_texture, 40, 40, 40, 40, 1, 0);

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

	//////////////App Background/////////////////
	sf::Sprite plr(player_texture);
	plr.setScale(0.25f, 0.25f);
	plr.setPosition(RES_X/2, RES_Y/2);

	Player* p = new Player("player", PLAYER_TEXTURE);
	p->settings(sPlayer, 950, 480, 0, 20);
	std::list<Beeing*> beeings;
	beeings.push_back(p);

	while (app.isOpen()) {
		
		//close aplication if user press the escape button
		Event event;
		Event exit;

		while (app.pollEvent(event))
		{
			if (event.type == Event::Closed || (Keyboard::isKeyPressed(Keyboard::EXIT))) {
				app.close();
				cout << "Your score is" << endl;

			};
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::PLR_SHOOT)
				{
					cout << "Shoot" << endl;
					//bullet* b = new bullet();
					//b->settings(sBullet, p->x, p->y, p->angle, 10);
					//.push_back(b);
				}
		}

		if (Keyboard::isKeyPressed(Keyboard::PLR_UP)) {
			cout << "Engine on" << endl;
			p->thrust = true;
		}
		else p->thrust = false;

		if (p->thrust)  p->anim = sPlayer_go;
		else   p->anim = sPlayer;

		//	if (Keyboard::isKeyPressed(Keyboard::PLR_DOW)) {
		//
		//	}

		if (Keyboard::isKeyPressed(Keyboard::PLR_RR)) {
			cout <<"Rotate to Right"<< endl;
			p->angle += 3;
		}
	
		if (Keyboard::isKeyPressed(Keyboard::PLR_RL)) {
			cout <<"Rotate to left"<< endl;
			p->angle -= 3;
		}

		app.setActive(true);
		app.setVisible(true);
		app.clear();
		app.draw(bckg);
		//	app.draw(plr);
		for (auto i : beeings) i->draw(app);
		//p->draw(app);
		app.display();
		
		
	}

	return 0;
}