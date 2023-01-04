#include "bloki.h"
#include <SFML/Graphics.hpp>

bloki::bloki(float x_in, float y_in) {

	blok.setSize(sf::Vector2f(70,40));
	blok.setFillColor(sf::Color::Green);
	blok.setPosition(x_in , y_in);
}

float bloki::left() {
	return this->blok.getPosition().x;
}

float bloki::right() {
	return this->blok.getPosition().x + 70;
}

float bloki::top() {
	return this->blok.getPosition().y;
}

float bloki::bottom() {
	return this->blok.getPosition().y + 40;
}

bool bloki::czyZniszczony() {
	return this->zniszczony;
}

void bloki::zniszcz() {
	this->zniszczony = 1;
}

