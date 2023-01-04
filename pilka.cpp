#include "pilka.h"
#include <SFML/Graphics.hpp>

float pilka::left() {
	return this->ball.getPosition().x;
}

float pilka::right() {
	return this->ball.getPosition().x + 20;
}

float pilka::top() {
	return this->ball.getPosition().y;
}

float pilka::bottom() {
	return this->ball.getPosition().y + 20;
}

void pilka::moveUp() {
	this->velocity.y = -ballVelocityY;
}

void pilka::moveDown() {
	this->velocity.y = ballVelocityY;
}

void pilka::moveLeft() {
	this->velocity.x = -ballVelocityX;
}

void pilka::moveRight() {
	this->velocity.x = ballVelocityX;
}

void pilka::kolizjaSciany() {
	if (getPosPilka().x + 20 > 800)// kolizja sciany boczne
		moveLeft();
	if (getPosPilka().x < 0)// kolizja sciany boczne
		moveRight();
	if (getPosPilka().y < 0)// kolizja sciany gorna i dolna
		moveDown();
	if (getPosPilka().y + 20 > 800)// kolizja sciany gorna i dolna
		moveUp();
}

pilka::pilka(float x_in, float y_in)
{
	position.x = x_in;
	position.y = y_in;
	ball.setRadius(10);
	ball.setFillColor(sf::Color::Red);
	ball.setPosition(position);
}

void pilka::przesun(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	ball.move(pos);
}
