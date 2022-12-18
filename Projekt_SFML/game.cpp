#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <ctime>
#include "settings.h"
#include "game.h"

using namespace std;
using namespace sf;

Game::Game(float dt)
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



