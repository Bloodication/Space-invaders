#include "Entity.h"
#include "Paddle.h"

#pragma once
class Ball : public Entity
{
public:
	Ball();
	~Ball();

public:
	void updateBall();

	const float ballMovementSpeed = 10.0f;
	sf::Vector2f direction{ -ballMovementSpeed, -ballMovementSpeed };

public:
	// Window border values collision
	float x() { return shape->getPosition().x; }
	float y() { return shape->getPosition().y; }
	float left() { return x() - shape->getRadius(); }
	float right() { return x() + shape->getRadius(); }
	float top() { return y() - shape->getRadius(); }
	float bottom() { return y() + shape->getRadius(); }

protected:
	void collisionBall();

protected:
	const float ballRadius = 10.0f;
protected:
	Paddle paddle;
};

