#pragma once
#include <SFML/Graphics.hpp>

class pilka {
private:
	sf::Vector2f position;
	sf::CircleShape ball;
	sf::Font czcionka;
	sf::Text tekst1;
	sf::Text tekst2;
	int punkty = 0;
	int zycia = 3;

public:
	pilka(float x_in, float y_in);
	void przesun(float x_in, float y_in);
	sf::CircleShape getPilka() { return ball; }
	sf::Vector2f getPosPilka() { return ball.getPosition(); }
	sf::Text getTekst1() { return tekst1; }
	sf::Text getTekst2() { return tekst2; }

	sf::Vector2f velocity{ 1.5f, 1.5f };
	const float ballVelocityX{ 1.5f };
	const float ballVelocityY{ 1.5f };
	void kolizjaSciany();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	float left();
	float right();
	float top();
	float bottom();

	void trafiony();
	void kolizja();

	void koniecGry();
	int getZycia() { return zycia; }
};