#include "bloki.h"
#include <SFML/Graphics.hpp>

bloki::bloki(float x_in, float y_in) {

	blok.setSize(sf::Vector2f(50,20));
	blok.setFillColor(sf::Color::Green);
	blok.setPosition(x_in , y_in);
}

float bloki::left() {
	return this->blok.getPosition().x - blok.getSize().x / 2.f;
}

float bloki::right() {
	return this->blok.getPosition().x + blok.getSize().x / 2.f;
}

float bloki::top() {
	return this->blok.getPosition().y - blok.getSize().y / 2.f;
}

float bloki::bottom() {
	return this->blok.getPosition().y + blok.getSize().y / 2.f;
}

bool bloki::czyZniszczony() {
	return this->zniszczony;
}

void bloki::zniszcz() {
	this->zniszczony = 1;
}