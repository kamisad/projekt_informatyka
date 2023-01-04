#include <SFML/Graphics.hpp> 
#include "paletka.h"
#include "pilka.h"
#include "bloki.h"
#include <vector>
using namespace sf;
using namespace std;

void testKolizji(bloki& bloki, pilka& pilka) {
	
	

	if ((pilka.left() > bloki.left() - 10) && (pilka.right() < bloki.right() + 10) &&
		(pilka.bottom() > bloki.top()) && (pilka.bottom() < bloki.top()+10)) { //detekcja kolizji pilki i bloku
		pilka.moveUp();
		bloki.zniszcz();
	}
	if ((pilka.left() > bloki.left() - 10) && (pilka.right() < bloki.right() + 10) &&
		(pilka.top() > bloki.bottom() - 10 ) && (pilka.top() < bloki.bottom())) { //detekcja kolizji pilki i bloku
		pilka.moveDown();
		bloki.zniszcz();
	}
	if ((pilka.right() > bloki.left()) && (pilka.right() < bloki.left() + 5) &&
		(pilka.top() > bloki.top() - 10) && (pilka.bottom() < bloki.bottom() + 10)) { //detekcja kolizji pilki i bloku
		pilka.moveLeft();
		bloki.zniszcz();
	}
	if ((pilka.left() > bloki.right() - 5) && (pilka.left() < bloki.right()) && 
		(pilka.top() > bloki.top() - 10) && (pilka.bottom() < bloki.bottom() + 10)) { //detekcja kolizji pilki i bloku
		pilka.moveRight();
		bloki.zniszcz();
	}

}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "projekt sfml");
	pilka p1(400,380);
	paletka p2(350, 750);
	sf::Clock zegar;
	Texture texture;
	texture.loadFromFile("background.png");
	Sprite sprite;
	Vector2u size = texture.getSize();
	sprite.setTexture(texture);
	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(400, 400);
	sprite.setScale(sf::Vector2f(0.25f, 0.25f));

	vector<bloki> Bloki;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			Bloki.emplace_back((j + 1) * (70 + 10), (i + 2) * (40 + 5)); //tworzenie bloków
		}
	}

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (zegar.getElapsedTime().asMilliseconds() > 3.0f) {


			p1.kolizjaSciany();
			p1.przesun(p1.velocity.x, p1.velocity.y);
			
			
			if ((p1.left() > p2.getPosPaletka().x - 10) && (p1.right() < p2.getPosPaletka().x + 110) &&
				(p1.bottom()  > p2.getPosPaletka().y) && (p1.bottom() < p2.getPosPaletka().y + 10)) { //detekcja kolizji pilki i paletki
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

        for (auto& bloki : Bloki) testKolizji(bloki, p1);

		auto iterator = remove_if(begin(Bloki), end(Bloki), [](bloki& bloki) {return bloki.czyZniszczony(); });
		Bloki.erase(iterator, end(Bloki));

		window.draw(sprite);
		window.draw(p1.getPilka());
		window.draw(p2.getPaletka());

		for (auto& bloki : Bloki) {
			window.draw(bloki.getBlok());
		}

		window.display();
	}
	return 0;
}
