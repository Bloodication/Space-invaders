#include "Bricks.h"

Bricks::Bricks(float x, float y)
{
	rect->setPosition(sf::Vector2f(x, y + - 150));
	rect->setSize(sf::Vector2f(this->blockWidth, this->blockHeight / 2));
	rect->setFillColor(sf::Color::Yellow);
	rect->setOrigin(this->blockWidth / 2.0f, this->blockHeight / 2.0f);
}
