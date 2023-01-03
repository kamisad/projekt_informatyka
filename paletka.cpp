#include "paletka.h"
#include <SFML/Graphics.hpp>

paletka::paletka(float x_in, float y_in) {
	position.x = x_in;
	position.y = y_in;
	rect.setSize(sf::Vector2f(100, 20));
	rect.setFillColor(sf::Color::White);
	rect.setPosition(position);
}

void paletka::przesun(float x_in) {
	sf::Vector2f pos;
	pos.x = x_in;
	rect.move(pos);
};