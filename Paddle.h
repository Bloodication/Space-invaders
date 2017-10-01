#include "Entity.h"

#pragma once
class Paddle : public Entity
{
public:
	Paddle();
	~Paddle();

public:
	void paddleUpdate();
	sf::Vector2f direction;

public:
	// Paddle movement
	float x() { return rect->getPosition().x; }
	float y() { return rect->getPosition().y; }
	float left() { return x() - rect->getSize().x / 2.0f; } // We have to divide by 2 so we hit the actual border of screen.
	float right() { return x() + rect->getSize().x / 2.0f; }
	float top() { return y() - rect->getSize().y / 2.0f; }
	float bottom() { return y() + rect->getSize().y / 2.0f; }

protected:
	const float paddleWidth = 60.0f;
	float paddleHeight = 20.0f;
	float paddleVelocity;
};

