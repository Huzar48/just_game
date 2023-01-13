#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
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

Game::Game() {
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

 bool Game::game() {
	srand(time(0));
	std::ifstream inputFile("highscore.txt");
	std::ofstream outputFile("highscore.txt");

	////////////load textures///////////////
	Texture background, player_texture, enemy_texture, bullet_texture, meteor_texture, game_over;
	background.loadFromFile(BACKGROUND);
	player_texture.loadFromFile(PLAYER_TEXTURE);
	enemy_texture.loadFromFile(ENEMY_TEXTURE);
	bullet_texture.loadFromFile(BULLET_TEXTURE);
	meteor_texture.loadFromFile(METEOR_TEXTURE);
	game_over.loadFromFile(GAME_OVER);

	sf::Sprite gover(game_over);

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

	////////////TEXT////////////////
	Font font;
	font.loadFromFile(FONT);
	Text addpoints;
	addpoints.setFont(font);
	addpoints.setCharacterSize(16);
	addpoints.setFillColor(sf::Color::Magenta);
	addpoints.setPosition(1920 + 10, 1080 + 10);
	Text points;
	points.setFont(font);
	points.setCharacterSize(24);
	points.setFillColor(sf::Color::Yellow);
	points.setPosition(RES_X/3,50);
	Text livepoints;
	livepoints.setFont(font);
	livepoints.setCharacterSize(24);
	livepoints.setFillColor(sf::Color::Red);
	livepoints.setPosition(0, 50);



	/////////Sound effects///////////////
	Music shoot, explosion, plr_explosion;

	//////////////PLAYER/////////////////
	sf::Sprite plr(player_texture);
	plr.setScale(0.25f, 0.25f);
	plr.setPosition(RES_X / 2, RES_Y / 2);

	/////////////Beeings list///////////
	std::list<Beeing*> beeings;
	std::list<Beeing*> beeingsend;


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


	
		inputFile >> p->highScore;
		inputFile.close();


	
		while (app.isOpen()) {
			app.setActive(true);
			app.setVisible(true);
			app.draw(bckg);

			std::string scoreString = "Your Scores is: " + std::to_string(p->score);
			points.setString(scoreString);
			app.draw(points);

			std::string liveString = "You still have: " + std::to_string(p->life) + " lives";
			livepoints.setString(liveString);
			app.draw(livepoints);

	
			//close aplication if user press the escape button
			Event event;
			while (app.pollEvent(event))
			{
				if (event.type == Event::Closed || (Keyboard::isKeyPressed(Keyboard::EXIT))) {
					app.close();
					return false;


				};
				if (event.type == Event::KeyPressed)
					if (event.key.code == Keyboard::PLR_SHOOT)
					{
						cout << "Shoot" << endl;
						shoot.openFromFile(SHOOT);
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


			for (auto a : beeings)
				for (auto b : beeings)
				{
					if (a->name == "asteroid" && b->name == "bullet")
						if (isCollide(a, b))
						{	
							addpoints.setPosition(a->x + 10, a->y + 10);
							explosion.openFromFile(EXPLOSION);
							explosion.play();
							a->isAlive = false;
							//beeings.remove(a);

							b->isAlive = false;
							//beeings.remove(b);


							addpoints.setString("+100.pts");
							p->score = p->score+100;
							cout << "+100" << endl;
							a -> tpoints = 240;
							
							//for (int i = 0; i < 2; i++)
							//{
								//if (a->R == 15) continue;
								Beeing* a = new Meteor("meteor", METEOR_TEXTURE);
								a->settings(a->x, a->y, rand() % 360, 15, 2);
								beeings.push_back(a);
							//}

						}  

					a->tpoints =240;
					if (a->tpoints > 0)
					{
						a->tpoints = a->tpoints - 1;
						app.draw(addpoints);
					}
					else 
					{
						addpoints.setString("");
					}

					if (p->name == "player" && b->name == "asteroid")
						if (isCollide(p, b))
						{
							plr_explosion.openFromFile(PLR_EXPLOSION);
							plr_explosion.play();

							b->isAlive = false;
							//beeings.remove(b);
							p->life = p->life-1;

							cout << "Yoy're loosing 1 life" << endl;

							p->x = RES_X/2;
							p->y = RES_Y/2;
							p->dx = 0; 
							p->dy = 0;

							if (p->score > p->highScore)
							{

								if (outputFile.is_open())
								{
									outputFile << p->highScore;
									outputFile.close();
								}

							}

								if (p->life < 1)
								{
									cout << "You're deaad!" << endl;
									cout << "Your highScore is "<<p->highScore << endl;
									cout << "Your score is "<<p->score << endl;
									p->isAlive = false;
									app.close();
								}
						}
				}

	
				for (auto b : beeings) 
				{
					if (b->x > RES_X || b->x<0 || b->y>RES_Y || b->y < 0) 
					{
						b->life = 0;
						//delete b;
						//b = nullptr;
					};

				}

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

					if (e->isAlive == false) { i = beeings.erase(i); delete e; e = nullptr; }
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

	if (p->isAlive == false) 
	{
		return false;
	}

}




