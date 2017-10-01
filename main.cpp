#include <SFML/Graphics.hpp>
#include <SFML\Window.hpp>
#include <cmath>
#include "Entity.h"
#include "Ball.h"
#include "Paddle.h"
#include "Collision.h"
#include "Bricks.h"

int main()
{
	// Declare object
	Entity ent;
	Ball ball;
	Paddle pad;
	Collision col;

	ent.loadText();

	//constants
	const int countBlockX = 11;
	const int countBlockY = 4;

	// Brick Array
	std::vector<Bricks> brickArray;

	// We fill up our vector via a 2D for loop, creating
	// bricks in a grid-like pattern.
	for (int iX = 0; iX < countBlockX; iX++)
		for (int iY = 0; iY < countBlockY; iY++)
			brickArray.emplace_back((iX + 1) * (ent.blockWidth + 3) + 22, (iY + 2) * (ent.blockHeight + 3));


	// Window
	sf::RenderWindow window(sf::VideoMode(ent.windowWidth, ent.windowHeight), "Game");
	window.setFramerateLimit(30);


	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		window.clear();

		ball.updateBall();
		pad.paddleUpdate();

		col.testCollision(pad, ball);
		ent.updateText();

		window.draw(*pad.rect);
		window.draw(*ball.shape);
		window.draw(ent.text);

		for (auto& iterDelete = brickArray.begin(); iterDelete != brickArray.end(); iterDelete++)
		{
			if (iterDelete->destroyed == true)
			{
				ent.scoreBoard++;
				brickArray.erase(iterDelete);
				break;
			}
		}

		// Draw our bricks and collision
		for (auto& iter = brickArray.begin(); iter != brickArray.end(); iter++)
		{
			col.ballBrickCollision(*iter, ball);
			window.draw(*iter->rect);
		}

		window.display();
	}

	return 0;
}