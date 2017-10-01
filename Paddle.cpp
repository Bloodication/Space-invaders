#include "Paddle.h"

Paddle::Paddle()
{
	// Constructor
	rect->setPosition(sf::Vector2f(static_cast<float>(this->windowWidth / 2), static_cast<float>((this->windowHeight / 2) + 200)));
	rect->setSize(sf::Vector2f(this->paddleWidth, this->paddleHeight));
	rect->setFillColor(sf::Color::Red);
	rect->setOrigin(this->paddleWidth / 2.0f, this->paddleHeight / 2.0f);
	this->paddleVelocity = 12.0f;
	this->paddleHeight = 20.0f;
}

Paddle::~Paddle()
{
	delete this->rect;
}

void Paddle::paddleUpdate()
{
	rect->move(this->direction);

	// If left is more than 0 then we can move. If left is less than 0 then we move outside the border, so we add this check so we stay inside.

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && left() > 0)
		this->direction.x = -paddleVelocity;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && right() < this->windowWidth)
		this->direction.x = paddleVelocity;

	else
		this->direction.x = 0;


}
