#include "player.h"


Player::Player(float f_radius)
{

	player = sf::CircleShape(f_radius);

}



sf::CircleShape Player::makePlayer()
{

	

	player.setFillColor(colour);
	player.setOrigin(10.f, 10.f);
	player.setPosition(150.f, 150.f);
	
	return player;

}

void Player::changeColour(sf::Color colour)
{

	std::this_thread::sleep_for(std::chrono::seconds(10));
	player.setFillColor(colour);

}

void Player::movePlayer(float f_valueOne, float f_valueTwo)
{

	v2f_movePlayer = sf::Vector2f(f_valueOne, f_valueTwo);

}

void Player::drawStuff(sf::RenderTarget& target)
{

	target.draw(player);

}

void Player::mover()
{

	player.move(v2f_movePlayer);

}

void Player::getThread()
{

	playerThread = std::thread([&] { makePlayer(); });
	playerThreadTwo = std::thread([&] { changeColour(sf::Color::Yellow), changeColour(sf::Color::Blue); });

}

void Player::threadJoiner()
{

	playerThread.join();
	playerThreadTwo.join();

}


