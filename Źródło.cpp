#include <SFML/Graphics.hpp> 
#include "paletka.h"
#include "pilka.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "projekt sfml");
	pilka p1(0,50);
	paletka p2(350, 750);
	sf::Clock zegar;
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (zegar.getElapsedTime().asMilliseconds() > 2.0f) {


			p1.kolizjaSciany();
			p1.przesun(p1.velocity.x, p1.velocity.y);
			
			if ((p1.getPosPilka().x > p2.getPosPaletka().x - 20) && (p1.getPosPilka().x < (p2.getPosPaletka().x) + 140) &&
				(p1.getPosPilka().y  > p2.getPosPaletka().y - 42) && (p1.getPosPilka().y < p2.getPosPaletka().y + 35)) { //detekcja kolizji pilki i paletki
				p1.moveUp();
			}


			if (event.type == sf::Event::KeyPressed ){//detekcja klawiszy			
				if (event.key.code == sf::Keyboard::Left && p2.getPosPaletka().x > 0) {
					p2.przesun(-2);
				}
				if (event.key.code == sf::Keyboard::Right && p2.getPosPaletka().x < 700) {
					p2.przesun(2);
				}
			}

			zegar.restart();
			printf("rozmiar okna: %d %d\n", window.getSize().x, window.getSize().y);
			printf("x = %lf y=%lf \n\n", p1.getPosPilka().x, p1.getPosPilka().y);
		}
		window.clear(sf::Color::Black);
		window.draw(p1.getPilka());
		window.draw(p2.getPaletka());
		window.display();
	}
	return 0;
}
