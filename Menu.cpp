#include "Menu.h"
#include <sstream>


Menu::Menu(float width, float height) {

	czcionka.loadFromFile("arial.ttf");

	tekst[0].setFont(czcionka);
	tekst[0].setFillColor(sf::Color::Red);
	tekst[0].setString("  Graj");
	tekst[0].setPosition(width / 2 - 50, height / 4 );
	tekst[0].setOutlineColor(sf::Color::Black);
	tekst[0].setOutlineThickness(2);

	tekst[1].setFont(czcionka);
	tekst[1].setFillColor(sf::Color::White);
	tekst[1].setString("Pomoc");
	tekst[1].setPosition(width / 2 - 50, height * 2/ 4);
	tekst[1].setOutlineColor(sf::Color::Black);
	tekst[1].setOutlineThickness(2);

	tekst[2].setFont(czcionka);
	tekst[2].setFillColor(sf::Color::White);
	tekst[2].setString(" wyjdz");
	tekst[2].setPosition(width / 2 - 50, height * 3/ 4);
	tekst[2].setOutlineColor(sf::Color::Black);
	tekst[2].setOutlineThickness(2);

	tekst[3].setFont(czcionka);
	tekst[3].setCharacterSize(20);
	tekst[3].setFillColor(sf::Color::White);
	tekst[3].setString("resetuj rekord");
	tekst[3].setPosition(width / 2 - 70, 750);
	tekst[3].setOutlineColor(sf::Color::Black);
	tekst[3].setOutlineThickness(2);

	std::fstream plik;
	plik.open("rekord.txt", std::ios::in);
	int rekord;
	plik >> rekord;
	tekst[4].setFont(czcionka);
	tekst[4].setFillColor(sf::Color::White);
	std::stringstream ss;
	ss << "rekord: " << rekord;
	tekst[4].setString(ss.str().c_str());
	tekst[4].setPosition(600, 700);
	tekst[4].setOutlineColor(sf::Color::Black);
	tekst[4].setOutlineThickness(2);

	wybranyElement = 0;

}

void Menu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 5; i++) {
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
	if (wybranyElement + 1 < 4) {
		tekst[wybranyElement].setFillColor(sf::Color::White);
		wybranyElement++;
		tekst[wybranyElement].setFillColor(sf::Color::Red);
	}
}