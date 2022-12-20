#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include "game.h"
#include "settings.h"
#include "Player.h"
#include "bullet.h"
#include "meteor.h"
#include <vector>

using namespace std;
using namespace sf;

void Game::Dt(float dt)
{
	this->dt = dt;
}

Game::~Game()
{
}

void Game::updateDt()
{
	this->dt = this->dtClock.getElapsedTime().asSeconds();
}

bool isCollide(Beeing* a, Beeing* b)
{
	return (b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y) < (a->R + b->R) * (a->R + b->R);
}

 void Game::game() {

	srand(time(0));

	////////////load textures///////////////
	Texture background, player_texture, enemy_texture, bullet_texture, meteor_texture, game_over;
	background.loadFromFile(BACKGROUND);
	player_texture.loadFromFile(PLAYER_TEXTURE);
	enemy_texture.loadFromFile(ENEMY_TEXTURE);
	bullet_texture.loadFromFile(BULLET_TEXTURE);
	meteor_texture.loadFromFile(METEOR_TEXTURE);
	game_over.loadFromFile(GAME_OVER);

	sf::Sprite gover(game_over);

	/////////load sounds///////////////
	Music music,shoot;
	music.openFromFile(MUSIC);
	shoot.openFromFile(SHOOT);

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

	music.setLoop(true);
	music.play();

	//////////////PLAYER/////////////////
	sf::Sprite plr(player_texture);
	plr.setScale(0.25f, 0.25f);
	plr.setPosition(RES_X / 2, RES_Y / 2);

	/////////////Beeings list///////////
	std::list<Beeing*> beeings;

	Meteor* a=nullptr;
	for (int i = 0; i < 15; i++)
	{
		Meteor* a = new Meteor("meteor", METEOR_TEXTURE);
		a->settings( rand()%RES_X, rand()%RES_Y, rand()%360, 25, a->speed);
		beeings.push_back(a);
		a != nullptr;
	}

	Player* p = new Player("player", PLAYER_TEXTURE);
	p->settings(RES_X / 2, RES_Y / 2, 0, 20, p->speed);
	beeings.push_back(p);

	
	while (app.isOpen()) {
		app.setActive(true);
		app.setVisible(true);

	
		//close aplication if user press the escape button
		Event event;
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
					shoot.play();
					Bullet* b = new Bullet("bullet", BULLET_TEXTURE);
					b->settings(p->x, p->y, p->angle, 10, b->speed);
					beeings.push_back(b);
				}
				
		}

		if (Keyboard::isKeyPressed(Keyboard::PLR_UP)) {
			cout << "Engine on" << endl;
			p->thrust = true;
			//p->y -= 3;
		}
		else {
			p->thrust = false;
		}

		/*if (Keyboard::isKeyPressed(Keyboard::PLR_DOW)) {
			//p->y += 3;
			if (p->speed > 0) {
				p->brakes = true;
			}

			else {
		
			}
		}*/

		if (Keyboard::isKeyPressed(Keyboard::PLR_RR)) {
			cout << "Rotate to Right" << endl;
			//p->x += 3;
			p->angle += 3;
		}

		if (Keyboard::isKeyPressed(Keyboard::PLR_RL)) {
			cout << "Rotate to left" << endl;
			//p->x -= 3;
			p->angle -= 3;
		}

		app.draw(bckg);
		if (p->life == false) 
		{
			app.draw(gover);
			p->life == false;
			app.setActive(false);

		}

		for (auto a : beeings)
			for (auto b : beeings)
			{
				if (a->name == "asteroid" && b->name == "bullet")
					if (isCollide(a, b))
					{
						a->life = false;
						b->life = false;

						//for (int i = 0; i < 2; i++)
						//{
							//if (a->R == 15) continue;
							Beeing* a = new Meteor("meteor", METEOR_TEXTURE);
							a->settings(a->x, a->y, rand() % 360, 15, 2);
							beeings.push_back(a);
						//}

					}

				if (p->name == "player" && b->name == "asteroid")
					if (isCollide(p, b))
					{
						b->life = false;
						p->life = false;
						cout << "GAME_OVER" << endl;

						p->x = RES_X/2;
						p->y = RES_Y/2;
						p->dx = 0; 
						p->dy = 0;
					}
			}

		for (auto e : beeings)

			if (rand() % 150 == 0)
			{
				Meteor* a = new Meteor("meteor", METEOR_TEXTURE);
				a->settings(0, rand() % RES_Y, rand() % 360, 25, a->speed=3);
				//beeings.push_back(a);
			}
			for (auto i = beeings.begin(); i != beeings.end();)
			{
				Beeing* e = *i;

				e->update();

				if (e->life == false) { i = beeings.erase(i); delete e; }
				else i++;
			}

			//p->update();

			//if (a != nullptr) 
			// {
			//	 a->update();
			//}

			 //if (b != nullptr)
			 //{
			 // b->update();
			 //}

			//for (auto i : beeings) i->update();
		

		//	app.draw(plr);
		for (auto i : beeings) i->draw(app);

		app.display();


	}
}



