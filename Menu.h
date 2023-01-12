#include <SFML/Graphics.hpp>
#pragma once

class Menu {
public:
	Menu(float width, float height);

	void draw(sf::RenderWindow& window);
		void MoveUp();
		void MoveDown();
		int getWybranyElement() { return wybranyElement; }

private:
	int wybranyElement;
	sf::Font czcionka;
	sf::Text tekst[3];
};