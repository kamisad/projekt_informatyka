// projekt na informatyke na podstawie scenariusza  2

#include <SFML/Graphics.hpp>

class kulka {
private:
	sf::Vector2f position;
	float predkoscKulki{ 0.08f };

	sf::Vector2f predkosc{predkoscKulki, predkoscKulki};

	sf::Texture tekstura;
	sf::Sprite pSprite;

public:
	kulka(float x_in, float y_in) {
		position.x = x_in;
		position.y = y_in;
		tekstura.loadFromFile("ball.png");
		pSprite.setTexture(tekstura);
		pSprite.setPosition(position);
		printf("%lf", position.x);
	}

	void przesun() {
		pSprite.move(this->predkosc);

		if (this->left() < 0) {
			predkosc.x = predkoscKulki;
		}
		else if (this->right() > 800) {
			predkosc.x = -predkoscKulki;
		}
		if (this->top() < 0) {
			predkosc.y = predkoscKulki;
		}
		else if (this->bottom() > 800) {
			predkosc.y = -predkoscKulki;
		}
	}

	sf::Sprite pobierzKulke() {
		return pSprite;
	}

	float left() {
		return this->position.x - 50;
	}
	float right() {
		return this->position.x + 50;
	}
	float top() {
		return this->position.y - 50;
	}
	float bottom() {
		return this->position.y + 50;
	}

};


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "projekt sfml");
	sf::Event event;

	kulka pb(100, 50);

	sf::Clock zegar;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		pb.przesun();

		window.clear(sf::Color::White);
		window.draw(pb.pobierzKulke());
		window.display();

	}
	return 0;
}
