#include "Menu.h"

Menu::Menu(float width, float height) {

	czcionka.loadFromFile("arial.ttf");

	tekst[0].setFont(czcionka);
	tekst[0].setFillColor(sf::Color::Red);
	tekst[0].setString("  Graj");
	tekst[0].setPosition(width / 2 - 50, height / 4 );

	tekst[1].setFont(czcionka);
	tekst[1].setFillColor(sf::Color::White);
	tekst[1].setString("Pomoc");
	tekst[1].setPosition(width / 2 - 50, height * 2/ 4);

	tekst[2].setFont(czcionka);
	tekst[2].setFillColor(sf::Color::White);
	tekst[2].setString(" wyjdz");
	tekst[2].setPosition(width / 2 - 50, height * 3/ 4);

	wybranyElement = 0;

}

void Menu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 3; i++) {
		window.draw(tekst[i]);
	}
}

void Menu::MoveUp() {
	if (wybranyElement - 1 >= 0) {
		tekst[wybranyElement].setFillColor(sf::Color::White);
		wybranyElement--;
		tekst[wybranyElement].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown() {
	if (wybranyElement + 1 < 3) {
		tekst[wybranyElement].setFillColor(sf::Color::White);
		wybranyElement++;
		tekst[wybranyElement].setFillColor(sf::Color::Red);
	}
}