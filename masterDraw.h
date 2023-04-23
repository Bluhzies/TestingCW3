#pragma once

#include <SFML/Graphics.hpp>

class MasterDraw
{

public:

	

	MasterDraw();

	virtual void drawStuff(sf::RenderTarget& target) {};
	



protected:

	sf::Vector2f v2f_movePlayer;
	sf::Color colour;

	float f_FPS;
	bool b_draw;

};