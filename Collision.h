#include "Entity.h"
#include "Paddle.h"
#include "Ball.h"
#include "Bricks.h"

#include <iostream>
#pragma once
class Collision : public Entity
{
public:
	void testCollision(Paddle& mPaddle, Ball& mBall);
	void ballBrickCollision(Bricks& mBrick, Ball& mBall);

private:
	template<class FirstCollision, class SecondCollision>
	inline bool isIntersecting(FirstCollision & mP, SecondCollision & mB)
	{
		// Game over!
		if (mB.bottom() >= windowHeight)
		{
			std::cout << "Game over!" << std::endl;
		}

		return mP.right() >= mB.left() && mP.left() <= mB.right() &&
			mP.bottom() >= mB.top() && mP.top() <= mB.bottom();
	}
};