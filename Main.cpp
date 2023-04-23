#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <future>
#include <stdio.h>
#include <vector>
#include "fileProcessor.h"
#include "shortTask.h"
#include "longerTask.h"
#include "masterDraw.h"
#include "player.h"
#include "gameOn.h"


int main(){

	FileProcessor proc("steam_games.csv", "steam_games_proc.csv");
	ShortTask shorty(10);
	LongerTask longBoy(10);
	/*GameOn runTheGame;*/
	Player circle(50.f);

	

	

	sf::RenderWindow window(sf::VideoMode(500, 500, 32), "Lab Week 9 - Multithreading"); //Draw an SFML window.
	
	

	std::future<void> process1 = std::async(std::launch::async, [&] { shorty.getThread(); });
	std::future<void> process4 = std::async(std::launch::async, [&] { shorty.getLockThread(); });
	std::future<void> process5 = std::async(std::launch::async, [&] { shorty.getLockThreadTwo(); });
	//longBoy.getThread();
	
	std::future<void> process2 = std::async(std::launch::async, [&] { longBoy.getThread(); });
	std::future<void> process3 = std::async(std::launch::async, [&] { proc.getThread(); });
	std::future<void> process6 = std::async(std::launch::async, [&] { circle.getThread(); });
	
	
	/*circle.getThread();*/
	
	
	

	
	
	
	
	

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

	
	shorty.threadJoiner();
	longBoy.threadJoiner();
	proc.threadJoiner();
	/*runTheGame.threadJoiner();*/
	circle.threadJoiner();
	
	

	return 0;

};