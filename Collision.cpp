#include "Collision.h"

void Collision::testCollision(Paddle & mPaddle, Ball & mBall)
{
	// If there's no intersection, get out of the function.
	if (!isIntersecting(mPaddle, mBall)) return;

	// Otherwise let's "push" the ball upwards.
	mBall.direction.y = -mBall.ballMovementSpeed;

	// And let's direct it dependently on the position where the
	// paddle was hit.
	if (mBall.x() < mPaddle.x())
		mBall.direction.x = -mBall.ballMovementSpeed;
	else
		mBall.direction.x = mBall.ballMovementSpeed;
}

void Collision::ballBrickCollision(Bricks & mBrick, Ball & mBall)
{
	// If there's no intersection, get out of the function.
	if(!isIntersecting(mBrick, mBall)) return;

	// Otherwise, the brick has been hit!
	mBrick.destroyed = true;

	// Let's calculate how much the ball intersects the brick
	// in every direction
	float overlapLeft{ mBall.right() - mBrick.left() };
	float overlapRight{ mBrick.right() - mBall.left() };
	float overlapTop{ mBall.bottom() - mBrick.top() };
	float overlapBottom{ mBrick.bottom() - mBall.top() };

	// If the magnitude of the left overlap is smaller than the
	// right one we can safely assume the ball hit the brick
	// from the left.
	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));

	// We can apply the same idea for top/bottom collisions.
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	// Let's store the minimum overlaps for the X and Y axes.
	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

	// If the magnitude of the X overlap is less than the magnitude
	// of the Y overlap, we can safely assume the ball hit the brick
	// horizontally - otherwise, the ball hit the brick vertically.

	// Then, upon our assumptions, we change either the X or Y velocity
	// of the ball, creating a "realistic" response for the collision.
	if (abs(minOverlapX) < abs(minOverlapY))
		mBall.direction.x = ballFromLeft ? -mBall.ballMovementSpeed : mBall.ballMovementSpeed;
	else
		mBall.direction.y = ballFromTop ? -mBall.ballMovementSpeed : mBall.ballMovementSpeed;
}
