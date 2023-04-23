#include "gameOn.h"


void GameOn::startTheGame()
{

	Player circle(50.f);

	sf::RenderWindow window(sf::VideoMode(500, 500, 32), "Lab Week 9 - Multithreading"); //Draw an SFML window.

	window.setActive(false);

	circle.makePlayer();

	

	const float f_FPS = 60.0f; //The desired FPS. (The number of updates each second).
	bool b_redraw = true;      //Do I redraw everything on the screen?

	window.setFramerateLimit(f_FPS);
	sf::Clock clock;
	
	while (window.isOpen())
	{
		//Wait until 1/60th of a second has passed, then update everything.
		if (clock.getElapsedTime().asSeconds() >= 1.0f / f_FPS)
		{
			b_redraw = true; //We're ready to redraw everything
			circle.mover();
			clock.restart();
		}
		//Check if the window is open or closed.
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					circle.movePlayer(0.0f, -1.f);

				}
				if (event.key.code == sf::Keyboard::S)
				{
					circle.movePlayer(0.0f, 1.f);

				}
				if (event.key.code == sf::Keyboard::A)
				{
					circle.movePlayer(-1.f, 0.0f);

				}
				if (event.key.code == sf::Keyboard::D)
				{
					circle.movePlayer(1.f, 0.0f);

				}

			}
		}


		//Draw to the window.
		if (b_redraw)
		{
			b_redraw = false;
			window.clear();
			circle.drawStuff(window);

			window.display();
		}
	}

	
	
}


void GameOn::getThread()
{

	gameThread = std::thread([&] { startTheGame(); });

}

void GameOn::threadJoiner()
{

	gameThread.join();

}
