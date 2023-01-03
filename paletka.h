#pragma once
#include <SFML/Graphics.hpp>

class paletka {
private:
	sf::Vector2f position;
	sf::RectangleShape rect;

public:
	paletka(float x_in, float y_in);
	void przesun(float x_in);
	sf::RectangleShape getPaletka() { return rect; }
	sf::Vector2f getPosPaletka() { return rect.getPosition(); }
};