#pragma once

#include "masterDraw.h"
#include "taskAllocator.h"

class Player : virtual public MasterDraw
{

public:

	Player() {};
	Player(float f_radius);

	void drawStuff(sf::RenderTarget& target) override;

	sf::CircleShape makePlayer();
	void movePlayer(float f_valueOne, float f_valueTwo);
	void mover();

	void getThread();

	void threadJoiner();

	void changeColour(sf::Color colour);

protected:



private:

	sf::CircleShape player;

	std::thread playerThread;
	std::thread playerThreadTwo;

};