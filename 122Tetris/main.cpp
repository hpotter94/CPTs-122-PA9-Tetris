#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tetris.h"

int main()
{
	int p = 0; 
	sf::RenderWindow window(sf::VideoMode(512, 750), "Tetris Rip-Off");

	///music///
	sf::Music music;
	if (!music.openFromFile("music.ogg"))
		return -1; // error
	music.setVolume(10); //10% max volume.  
	music.play();	
	///End of Music///


	srand(time(0));

	double dropInterval = 1;
	time_t nextDrop = time(0) + dropInterval;

	Block block;
	
	randomBlock(block);

	int release_key = 1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (release_key == 1)
			{
				block.moveR();
				release_key = 0;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (release_key)
			{
				block.moveL();
				release_key = 0;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			if (release_key)
			{
				block.rotateL();
				release_key = 0;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			if (release_key)
			{
				block.rotateR();
				release_key = 0;
			}
		}
		else
		{
			release_key = 1;
		}

		if (time(0) >= nextDrop)
		{
			nextDrop += dropInterval;
			block.drop();
		}

		window.clear();
		block.draw(window);
		window.display();
	}
	
	return 0;
}