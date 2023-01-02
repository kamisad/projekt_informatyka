 //projekt na informatyke na podstawie scenariusza  2

//#include <SFML/Graphics.hpp>
//
//class kulka {
//private:
//	sf::Vector2f position;
//	float predkoscKulki{ 0.08f };
//
//	sf::Vector2f predkosc{predkoscKulki, predkoscKulki};
//
//	sf::Texture tekstura;
//	sf::Sprite pSprite;
//
//public:
//	kulka(float x_in, float y_in) {
//		position.x = x_in;
//		position.y = y_in;
//		tekstura.loadFromFile("ball.png");
//		pSprite.setTexture(tekstura);
//		pSprite.setPosition(position);
//		printf("%lf", position.x);
//	}
//
//	void przesun() {
//		pSprite.move(this->predkosc);
//	}
//
//	void kolizja() {
//
//		if (800 > this->position.x < 0) {
//			this->predkosc.x = -predkoscKulki;
//		}
//
//		if (800 > this->position.y < 0) {
//			this->predkosc.y = -predkoscKulki;
//		}
//	}
//
//
//	sf::Sprite pobierzKulke() {
//		return pSprite;
//	}
//
//};
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(800, 800), "projekt sfml");
//	sf::Event event;
//
//	kulka pb(100, 50);
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		pb.przesun();
//
//		window.clear(sf::Color::White);
//		window.draw(pb.pobierzKulke());
//		window.display();
//
//	}
//	return 0;
//}
#include <SFML/Graphics.hpp> // projekt bez tekstur

class paletka {
private:
	sf::Vector2f position;
	sf::RectangleShape rect;

public:
	paletka(float x_in, float y_in);
	void przesun(float x_in);
	sf::RectangleShape getPaletka(){return rect; }
	sf::Vector2f getPosPaletka() { return rect.getPosition(); }
};

paletka::paletka(float x_in, float y_in) {
	position.x = x_in;
	position.y = y_in;
	rect.setSize(sf::Vector2f(100, 20));
	rect.setFillColor(sf::Color::White);
	rect.setPosition(position);
}

void paletka::przesun(float x_in) {
	sf::Vector2f pos;
	pos.x = x_in;
	rect.move(pos);
};



class pilka {
private:
	sf::Vector2f position;
	sf::CircleShape ball;

public:
	pilka(float x_in, float y_in);
	void przesun(float x_in, float y_in);
	sf::CircleShape getPilka() { return ball; }
	sf::Vector2f getPosPilka() { return ball.getPosition(); }
	sf::Vector2f velocity{ 2.0f, 2.8f };
	const float ballVelocityX{ 2.0f };
	const float ballVelocityY{ 2.8f };
	void kolizjaSciany();
	
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

void pilka::moveUp() {
	this->velocity.y = -ballVelocityY;
}

void pilka::moveDown() {
	this->velocity.y = ballVelocityY;
}

void pilka::moveLeft() {
	this->velocity.x = -ballVelocityX;
}

void pilka::moveRight() {
	this->velocity.x = ballVelocityX;
}

void pilka::kolizjaSciany() {
	if (getPosPilka().x + 40 > 800)// kolizja sciany boczne
		moveLeft();
	if (getPosPilka().x < 0)// kolizja sciany boczne
		moveRight();
	if (getPosPilka().y < 0)// kolizja sciany gorna i dolna
		moveDown();
	if (getPosPilka().y + 40 > 800)// kolizja sciany gorna i dolna
		moveUp();
}

pilka::pilka(float x_in, float y_in)
{
	position.x = x_in;
	position.y = y_in;
	ball.setRadius(20);
	ball.setFillColor(sf::Color::Red);
	ball.setPosition(position);
}

void pilka::przesun(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	ball.move(pos);
}



//template <class T1, class T2> bool czyPrzecina(T1& A, T2& B) {
//	return A.right() >= B.left() && A.left() <= B.right()
//		&& A.bottom() >= B.top() && A.top() <= B.bottom();
//}
//
//bool testKolizji(paletka& paletka, pilka& pilka) {
//	if (!czyPrzecina(paletka, pilka)) return false;
//
//	pilka.moveUp();
//
//	if (pilka.getPosPilka().x < paletka.getPosPaletka().x) {
//		pilka.moveLeft();
//	}
//	if (pilka.getPosPilka().x > paletka.getPosPaletka().x) {
//		pilka.moveRight();
//	}
//}



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

		if (zegar.getElapsedTime().asMilliseconds() > 10.0f) {


			p1.kolizjaSciany();
			p1.przesun(p1.velocity.x, p1.velocity.y);
			/*testKolizji(p2, p1);*/


			if (event.type == sf::Event::KeyPressed )//detekcja klawiszy
			{
				if (event.key.code == sf::Keyboard::Left && p2.getPosPaletka().x > 0)
				{
					p2.przesun(-10);
				}

				if (event.key.code == sf::Keyboard::Right && p2.getPosPaletka().x < 700)
				{
					p2.przesun(10);
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
