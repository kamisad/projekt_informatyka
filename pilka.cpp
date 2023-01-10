#include "pilka.h"
#include <SFML/Graphics.hpp>
#include <sstream>

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
	if (getPosPilka().x + 20 > 800)// kolizja sciany prawej
		moveLeft();
	if (getPosPilka().x < 0)// kolizja sciany lewej
		moveRight();
	if (getPosPilka().y < 0)// kolizja sciany gornej
		moveDown();
	if (getPosPilka().y + 20 > 800) {// kolizja sciany dolnej
		moveUp();
		kolizja();
	}
}

pilka::pilka(float x_in, float y_in)
{
	position.x = x_in;
	position.y = y_in;
	ball.setRadius(10);
	ball.setFillColor(sf::Color::Red);
	ball.setPosition(position);

	czcionka.loadFromFile("arial.ttf");
	tekst1.setFont(czcionka);
	tekst1.setCharacterSize(20);
	tekst1.setFillColor(sf::Color::Green);
	tekst1.setPosition(30, 30);
	std::stringstream ss; 
	ss << "Punkty: " << punkty << "\n" << "zycia: " << zycia;
	tekst1.setString(ss.str().c_str());

	tekst2.setFont(czcionka);
	tekst2.setCharacterSize(40);
	tekst2.setFillColor(sf::Color::Red);
	tekst2.setPosition(300, 400);
	tekst2.setOutlineColor(sf::Color::Black);
	tekst2.setOutlineThickness(10);
	tekst2.setString("Game Over");
	
}

void pilka::przesun(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	ball.move(pos);
}

void pilka::trafiony() {
	this->punkty = punkty + 1;
	std::stringstream ss;
	ss << "Punkty: " << punkty << "\n" << "zycia: " << zycia;
	tekst1.setString(ss.str().c_str());
}

void pilka::kolizja() {
	this->zycia = zycia - 1;
	std::stringstream ss;
	ss << "Punkty: " << punkty << "\n" << "zycia: " << zycia;
	tekst1.setString(ss.str().c_str());
}

void pilka::koniecGry() {
		this->velocity.y = 0;
		this->velocity.x = 0;
}
