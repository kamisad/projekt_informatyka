#pragma once
#include <SFML/Graphics.hpp>

class pilka {
private:
	sf::Vector2f position;
	sf::CircleShape ball;

public:
	pilka(float x_in, float y_in);
	void przesun(float x_in, float y_in);
	sf::CircleShape getPilka() { return ball; }
	sf::Vector2f getPosPilka() { return ball.getPosition(); }
	sf::Vector2f velocity{ 0.6f, 1.0f };
	const float ballVelocityX{ 0.6f };
	const float ballVelocityY{ 1.0f };
	void kolizjaSciany();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};