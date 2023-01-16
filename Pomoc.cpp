#include "Pomoc.h"

Pomoc::Pomoc(float width, float height) {

	czcionka.loadFromFile("arial.ttf");

	tekst.setFont(czcionka);
	tekst.setFillColor(sf::Color::Green);
	tekst.setOutlineColor(sf::Color::Black);
	tekst.setOutlineThickness(2); 
	tekst.setString("                          Zasady gry\n    celem gry jest zniszczenie wszystkich \n           zielonych blokow na ekranie.\n   Bloki mozna niszczyc za pomoca kulki.\n             kulke mozna odbic paletka.\n  masz 3 zycia. kiedy kulka dotknie podlogi,\n                         tracisz zycie\n\n\n                ESC by wrocic do menu");
	tekst.setPosition(width / 2 - 350, height / 4);
	tekst.setCharacterSize(35);

}

void Pomoc::draw(sf::RenderWindow& window) {
	
		window.draw(tekst);
}
