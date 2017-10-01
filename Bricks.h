#include "Entity.h"

#pragma once
class Bricks : public Entity
{
public:
	Bricks() {}
	Bricks(float x, float y);
	~Bricks() {}
	

public:
	bool destroyed = false;

public:
	float x() { return rect->getPosition().x; }
	float y() { return rect->getPosition().y; }
	float left() { return x() - rect->getSize().x / 2.f; }
	float right() { return x() + rect->getSize().x / 2.f; }
	float top() { return y() - rect->getSize().y / 2.f; }
	float bottom() { return y() + rect->getSize().y / 2.f; }
};

