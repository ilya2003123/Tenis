#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 500), "Tenis");

	window.setFramerateLimit(730);

	sf::RectangleShape line(sf::Vector2f(1, 500));
	line.setFillColor(sf::Color::Black);
	line.setPosition(500, 0);

	sf::RectangleShape man(sf::Vector2f(10, 50));
	man.setFillColor(sf::Color::Blue);
	man.setPosition(990, 200);

	sf::RectangleShape bot(sf::Vector2f(10, 50));
	bot.setFillColor(sf::Color::Red);
	bot.setPosition(0, 200);

	sf::CircleShape ball(10.f);
	ball.setFillColor(sf::Color::Green);
	ball.setPosition(10, 215);
	int kx = 1, ky = 1, stop = 0;

	double speed = 0.3;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (stop == 0) 
		{
			sf::Vector2f m = man.getPosition();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				if (m.y > 0)
					man.move(0, -speed);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				if (m.y < 450)
					man.move(0, speed);

			ball.move(speed / 2 * kx, speed / 2 * ky);
			sf::Vector2f b = ball.getPosition();
			if (b.y < 10 || b.y > 480)
				ky = -ky;
			if (b.x < 10)
				kx = -kx;

			if (b.y >= m.y - 5 && b.y <= m.y + 50)
				if (b.x > 980) 
				{
					kx = -kx;

					ball.move(-0.1, 0);
				}

			sf::Vector2f v = bot.getPosition();
			if (v.y < b.y)
				if (v.y < 450)
					bot.move(0, speed);
			if (v.y > b.y)
				bot.move(0, -speed);

			if (b.x > 1010)
				stop = 1;
		}

		window.clear(sf::Color::White);
		window.draw(line);
		window.draw(man);
		window.draw(bot);
		window.draw(ball);
		window.display();
	}

	return 0;
}