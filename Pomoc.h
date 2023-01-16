#include <SFML/Graphics.hpp>
#pragma once

class Pomoc {
public:
	Pomoc(float width, float height);

	void draw(sf::RenderWindow& window);

private:
	sf::Font czcionka;
	sf::Text tekst;
};