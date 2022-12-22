#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "game.h"
#include "settings.h"
#include "menu.h"
#include "GameOver.h"

using namespace std;

bool gamelife = true;
bool menulife = true;
bool playerlife = true;

int main() {

	/////////music///////////////
	sf::Music music;
	music.openFromFile(MUSIC);
	music.setLoop(true);
	music.play();

	while (gamelife == true){
	bool menulife = Menu::menu();

		if (menulife == false)
		{
			bool playerLife = Game::game();

			if (playerLife == false) 
			{
				gamelife = GameOver::gameOver();
			}
		}

	}

	return 0;
}