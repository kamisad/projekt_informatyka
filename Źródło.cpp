#include <SFML/Graphics.hpp> 
#include "paletka.h"
#include "pilka.h"
#include "bloki.h"
#include "Menu.h"
#include "Pomoc.h"
#include "Trudnosc.h"
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace sf;
using namespace std;

void testKolizji(bloki& bloki, pilka& pilka) {



	if ((pilka.left() > bloki.left() - 10) && (pilka.right() < bloki.right() + 10) &&
		(pilka.bottom() > bloki.top()) && (pilka.bottom() < bloki.top() + 10)) { //detekcja kolizji pilki i bloku
		pilka.moveUp();
		bloki.zniszcz();
		pilka.trafiony();
	}
	if ((pilka.left() > bloki.left() - 10) && (pilka.right() < bloki.right() + 10) &&
		(pilka.top() > bloki.bottom() - 10) && (pilka.top() < bloki.bottom())) { //detekcja kolizji pilki i bloku
		pilka.moveDown();
		bloki.zniszcz();
		pilka.trafiony();
	}
	if ((pilka.right() > bloki.left()) && (pilka.right() < bloki.left() + 5) &&
		(pilka.top() > bloki.top() - 10) && (pilka.bottom() < bloki.bottom() + 10)) { //detekcja kolizji pilki i bloku
		pilka.moveLeft();
		bloki.zniszcz();
		pilka.trafiony();
	}
	if ((pilka.left() > bloki.right() - 5) && (pilka.left() < bloki.right()) &&
		(pilka.top() > bloki.top() - 10) && (pilka.bottom() < bloki.bottom() + 10)) { //detekcja kolizji pilki i bloku
		pilka.moveRight();
		bloki.zniszcz();
		pilka.trafiony();
	}

}

int main()
{
poczatek:

	sf::RenderWindow GRA(sf::VideoMode(800, 800), "GRA");
	sf::RenderWindow POMOC(sf::VideoMode(800, 800), "POMOC");
	sf::RenderWindow TRUDNOSC(sf::VideoMode(800, 800), "TRUDNOSC");
	sf::RenderWindow MENU(sf::VideoMode(800, 800), "MENU");
	pilka p1(400, 380);
	paletka p2(350, 750);
	Menu menu(800,800);
	Pomoc pomoc(800, 800);
	Trudnosc trudnosc(800, 800);

	sf::Clock zegar;
	Texture texture;
	texture.loadFromFile("background.png");
	Sprite sprite;
	Vector2u size = texture.getSize();
	sprite.setTexture(texture);
	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(380, 400);
	sprite.setScale(sf::Vector2f(0.25f, 0.25f));



	vector<bloki> Bloki;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			Bloki.emplace_back((j + 1) * (70 + 10), (i + 2) * (40 + 5)); //tworzenie bloków
		}
	}

	while (MENU.isOpen())
	{

		sf::Event event;
		while (MENU.pollEvent(event))
		{

			switch (event.type) {
			case sf::Event::KeyReleased:

				switch (event.key.code) //funkcja menu
				{
				case sf::Keyboard::Up: //element w gore
					menu.MoveUp();
					break;

				case sf::Keyboard::Down: //element w dol
					menu.MoveDown();
					break;

				case sf::Keyboard::Return: //wybierz element
					switch (menu.getWybranyElement())
					{
					case 0: // element gra
						
						MENU.close();
						POMOC.close();

						while (TRUDNOSC.isOpen())
						{

							sf::Event cevent;
							while (TRUDNOSC.pollEvent(cevent))
							{
								if (cevent.key.code == Keyboard::Escape) { //wyjscie z gry mozliwe tylko po wcisnieciu ESC
									TRUDNOSC.close();
									goto poczatek;
								}

								switch (cevent.type) {
								case sf::Event::KeyReleased:

									switch (cevent.key.code) //funkcja wybor trudnosci
									{
									case sf::Keyboard::Up: //element w gore
										trudnosc.MoveUp();
										break;

									case sf::Keyboard::Down: //element w dol
										trudnosc.MoveDown();
										break;

									case sf::Keyboard::Return: //wybierz element
										switch (trudnosc.getWybranyElement())
										{

										case 0:

											TRUDNOSC.close();
											while (GRA.isOpen()) { // kod gry latwy
												Event aevent;
												while (GRA.pollEvent(aevent)) {
													if (aevent.type == Event::KeyPressed) {
														if (aevent.key.code == Keyboard::Escape) { //wyjscie z gry mozliwe tylko po wcisnieciu ESC
															GRA.close();
															goto poczatek;
														}
													}
												}											
												if (zegar.getElapsedTime().asMilliseconds() > 3.0f) { //klatkowanie 

													p1.kolizjaSciany();
													p1.przesun(p1.velocity.x, p1.velocity.y);

													for (auto& bloki : Bloki) testKolizji(bloki, p1);

													auto iterator = remove_if(begin(Bloki), end(Bloki), [](bloki& bloki) {return bloki.czyZniszczony(); }); //niszczenie bloków
													Bloki.erase(iterator, end(Bloki));

													if ((p1.left() > p2.getPosPaletka().x - 10) && (p1.right() < p2.getPosPaletka().x + 110) &&
														(p1.bottom() > p2.getPosPaletka().y) && (p1.bottom() < p2.getPosPaletka().y + 10)) { //detekcja kolizji pilki i paletki
														p1.moveUp();
													}

													if (aevent.type == sf::Event::KeyPressed) {//detekcja klawiszy			
														if (aevent.key.code == sf::Keyboard::Left && p2.getPosPaletka().x > 0) {
															p2.przesun(-2);
														}
														if (aevent.key.code == sf::Keyboard::Right && p2.getPosPaletka().x < 700) {
															p2.przesun(2);
														}
													}

													zegar.restart();
													printf("x = %lf y=%lf \n\n", p1.getPosPilka().x, p1.getPosPilka().y);
												}

												GRA.clear(sf::Color::White);
												GRA.draw(sprite);
												GRA.draw(p1.getPilka());
												GRA.draw(p2.getPaletka());
												GRA.draw(p1.getTekst1());
												if (p1.getZycia() == 0) {
													p1.koniecGry();
													GRA.draw(p1.getTekst2());
												}

												for (auto& bloki : Bloki) {
													GRA.draw(bloki.getBlok());
												}

												GRA.display();

											} // koniec kodu gry


										case 1: //trudny
											p1.velocity.x = 2.5;
											p1.velocity.y = 2.5;
											p1.ballVelocityX = 2.5;
											p1.ballVelocityY = 2.5;
											TRUDNOSC.close();
											while (GRA.isOpen()) { // kod gry trudny
												Event aevent;
												while (GRA.pollEvent(aevent)) {
													if (aevent.type == Event::KeyPressed) {
														if (aevent.key.code == Keyboard::Escape) { //wyjscie z gry mozliwe tylko po wcisnieciu ESC
															GRA.close();
															goto poczatek;
														}
													}
												}												
												if (zegar.getElapsedTime().asMilliseconds() > 3.0f) { //klatkowanie 

													p1.kolizjaSciany();
													p1.przesun(p1.velocity.x, p1.velocity.y);

													for (auto& bloki : Bloki) testKolizji(bloki, p1);

													auto iterator = remove_if(begin(Bloki), end(Bloki), [](bloki& bloki) {return bloki.czyZniszczony(); }); //niszczenie bloków
													Bloki.erase(iterator, end(Bloki));

													if ((p1.left() > p2.getPosPaletka().x - 10) && (p1.right() < p2.getPosPaletka().x + 110) &&
														(p1.bottom() > p2.getPosPaletka().y) && (p1.bottom() < p2.getPosPaletka().y + 10)) { //detekcja kolizji pilki i paletki
														p1.moveUp();
													}

													if (aevent.type == sf::Event::KeyPressed) {//detekcja klawiszy			
														if (aevent.key.code == sf::Keyboard::Left && p2.getPosPaletka().x > 0) {
															p2.przesun(-3);
														}
														if (aevent.key.code == sf::Keyboard::Right && p2.getPosPaletka().x < 700) {
															p2.przesun(3);
														}
													}

													zegar.restart();
													printf("x = %lf y=%lf \n\n", p1.getPosPilka().x, p1.getPosPilka().y);
												}

												GRA.clear(sf::Color::White);
												GRA.draw(sprite);
												GRA.draw(p1.getPilka());
												GRA.draw(p2.getPaletka());
												GRA.draw(p1.getTekst1());
												if (p1.getZycia() == 0) {
													p1.koniecGry();
													GRA.draw(p1.getTekst2());
												}

												for (auto& bloki : Bloki) {
													GRA.draw(bloki.getBlok());
												}

												GRA.display();

											} // koniec kodu gry
										}
									}
								}
							}
							TRUDNOSC.clear();
							TRUDNOSC.draw(sprite);
							trudnosc.draw(TRUDNOSC);
							TRUDNOSC.display();
						}
					case 1:

						MENU.close();// element pomoc
						GRA.close();
						TRUDNOSC.close();

						while (POMOC.isOpen()) {
							Event bevent;
							while (POMOC.pollEvent(bevent)) {
								if (bevent.type == Event::KeyPressed) {
									if (bevent.key.code == Keyboard::Escape) { //wyjscie z gry mozliwe tylko po wcisnieciu ESC
										POMOC.close();
										goto poczatek;
									}
								}

							}
							POMOC.clear();
							POMOC.draw(sprite);
							pomoc.draw(POMOC);
							POMOC.display();

						}
					case 2:
						MENU.close();//element wyjœcie
						break;
					}

				}
				break;

			case sf::Event::Closed:
				MENU.close();
				break;

			}
		}
		MENU.clear();
		MENU.draw(sprite);
		menu.draw(MENU);
		MENU.display();

	}
	return 0;
}
