#pragma once
#include <SFML/Graphics.hpp>

class bloki {
public:
	bloki(float x_in, float y_in);
	sf::Vector2f getPosBlok() { return blok.getPosition(); }
	float left();
	float right();
	float top();
	float bottom();

	bool czyZniszczony();
	void zniszcz();


private:
	sf::RectangleShape blok;
	int zniszczony = 0;
};