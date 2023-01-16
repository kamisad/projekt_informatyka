#include "Trudnosc.h"

Trudnosc::Trudnosc(float width, float height) {

	czcionka.loadFromFile("arial.ttf");

	tekst[0].setFont(czcionka);
	tekst[0].setFillColor(sf::Color::Red);
	tekst[0].setString("  latwy");
	tekst[0].setPosition(width / 2 - 55, height / 4);
	tekst[0].setOutlineColor(sf::Color::Black);
	tekst[0].setOutlineThickness(2);

	tekst[1].setFont(czcionka);
	tekst[1].setFillColor(sf::Color::White);
	tekst[1].setString("trudny");
	tekst[1].setPosition(width / 2 - 40, height * 2 / 4);
	tekst[1].setOutlineColor(sf::Color::Black);
	tekst[1].setOutlineThickness(2);

	wybranyElement = 0;

}

void Trudnosc::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 2; i++) {
		window.draw(tekst[i]);
	}
}

void Trudnosc::MoveUp() {
	if (wybranyElement - 1 >= 0) {
		tekst[wybranyElement].setFillColor(sf::Color::White);
		wybranyElement--;
		tekst[wybranyElement].setFillColor(sf::Color::Red);
	}
}

void Trudnosc::MoveDown() {
	if (wybranyElement + 1 < 2) {
		tekst[wybranyElement].setFillColor(sf::Color::White);
		wybranyElement++;
		tekst[wybranyElement].setFillColor(sf::Color::Red);
	}
}