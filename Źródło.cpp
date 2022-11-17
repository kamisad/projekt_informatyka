// projekt na informatyke na podstawie scenariusza  2

#include <SFML/Graphics.hpp>

class Pokeball {
private:
	sf::Vector2f position;
	float xVel = 1;
	float yVel = 1;

	sf::Texture tekstura;
	sf::Sprite pSprite;

public:
	Pokeball(float x_in, float y_in) {
		position.x = x_in;
		position.y = y_in;
		tekstura.loadFromFile("pokeball.png");
		pSprite.setTexture(tekstura);
		pSprite.setPosition(position);
	}

	void przesun(float x_in, float y_in) {
		sf::Vector2f pos;
		pos.x = x_in;
		pos.y = y_in;
		pSprite.move(pos);
		position = pSprite.getPosition();
	}

	sf::Sprite pobierzPokeball() {
		return pSprite;
	}

};


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "projekt sfml");
	sf::Event event;

	Pokeball pb(50, 50);

	sf::Clock zegar;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		window.draw(pb.pobierzPokeball());
		window.display();

		if (zegar.getElapsedTime().asMilliseconds() > 5.0f) {
			pb.przesun(1, 1);
			zegar.restart();
		}


	}
	return 0;
}
