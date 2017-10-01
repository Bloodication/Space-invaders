#include "Ball.h"

Ball::Ball()
{
	// Constructor
	shape->setPosition(sf::Vector2f(static_cast<float>(this->windowWidth / 2), static_cast<float>((this->windowHeight / 2) + 200)));
	shape->setRadius(ballRadius);
	shape->setFillColor(sf::Color::Green);
	shape->setOrigin(ballRadius, ballRadius); 
}

Ball::~Ball()
{
	delete this->shape;
}

void Ball::updateBall()
{
	// Keep updating our ball and keep moving it
	collisionBall();
	shape->move(this->direction);
}

void Ball::collisionBall()
{
	/* How it works:
	
	If ball is heading direction left and its position is less than 0 then set it right diagnol.
	If ball direction right position is more than windowWidth then set it left diagnol;
	
	If ball is heading direction top and its position is less than 0 then set it bottom diagnol.
	If ball direction bottom is more than windowHeight then set it top diagnol.
	
	*/

	if (left() < 0)
		this->direction.x = ballMovementSpeed;

	else if (right() > this->windowWidth)
		this->direction.x = -ballMovementSpeed;

	if (top() < 0)
		this->direction.y = ballMovementSpeed;
	else if (bottom() > this->windowHeight)
		this->direction.y = -ballMovementSpeed;
}
