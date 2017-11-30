#include "Ball.h"
#include <stdlib.h>
#include <time.h>

float Raid;
float pi = 3.1416;

Ball::Ball(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	ballShape.setRadius(15);
	ballShape.setPosition(position);
	ballShape.setFillColor(Color::Red);

	active = false;
	xVelocity = 0.00f;
	yVelocity = 0.00f;

}

FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

CircleShape Ball::getShape()
{
	return ballShape;
}

float Ball::getYAxis()
{
	return position.y;
}

void Ball::shoot()
{
	active = true;
	xVelocity = 0.06f;
	yVelocity = -0.08f;
}

void Ball::speedUp()
{
	xVelocity = xVelocity * 1.5;
	yVelocity = yVelocity * 1.5;
}
void Ball::follow(float x, float y)
{
	active = false;
	position.x = x;
	position.y = y;
	ballShape.setPosition(position);
}
void Ball::reboundTop()
{
	yVelocity = -yVelocity;
}
void Ball::reboundSides()
{
	xVelocity = -xVelocity;
}

void Ball::reboundBat1()
{
	float Velocity = sqrt((xVelocity * xVelocity) + (yVelocity * yVelocity));
	xVelocity = Velocity * cos(1.56*pi);
	yVelocity = Velocity * sin(1.56*pi);
}

void Ball::reboundBat2()
{
	float Velocity = sqrt((xVelocity * xVelocity) + (yVelocity * yVelocity));
	xVelocity = Velocity * cos(0.93*pi);
	yVelocity = Velocity * sin(0.93*pi);
}

void Ball::rebound1()
{
	float Velocity = sqrt((xVelocity * xVelocity) + (yVelocity * yVelocity));
	xVelocity = Velocity * cos(1.25*pi);
	yVelocity = Velocity * sin(1.25*pi);
}
void Ball::rebound2()
{
	float Velocity = sqrt((xVelocity * xVelocity) + (yVelocity * yVelocity));
	xVelocity = Velocity * cos(1.33*pi);
	yVelocity = Velocity * sin(1.33*pi);
}
void Ball::rebound3()
{
	float Velocity = sqrt((xVelocity * xVelocity) + (yVelocity * yVelocity));
	xVelocity = Velocity * cos(1.67*pi);
	yVelocity = Velocity * sin(1.67*pi);
}
void Ball::rebound4()
{
	float Velocity = sqrt((xVelocity * xVelocity) + (yVelocity * yVelocity));
	xVelocity = Velocity * cos(1.75*pi);
	yVelocity = Velocity * sin(1.75*pi);
}
void Ball::hitbrickL()
{
	if (xVelocity > 0)
		xVelocity = -xVelocity;
}
void Ball::hitbrickR()
{
	if (xVelocity < 0)
		xVelocity = -xVelocity;
}

void Ball::hitbrickT()
{
	if (yVelocity > 0)
		yVelocity = -yVelocity;
}

void Ball::hitbrickB()
{
	if (yVelocity < 0)
		yVelocity = -yVelocity;
}

void Ball::reboundblock()
{
	xVelocity = -xVelocity;
}

void Ball::hitBottom()
{
	/*position.y = 384;
	position.x = 512;
	srand(time(0));
	Raid = (rand() % 40 + 80)* 0.01 * pi;
	xVelocity = V * cos(Raid);
	yVelocity = V * sin(Raid);*/
}

void Ball::stop()
{
	position.y = 384;
	position.x = 512;
	xVelocity = 0;
	yVelocity = 0;
}

void Ball::update()
{
	// Update the ball position variables
	position.y += yVelocity;
	position.x += xVelocity;

	// Move the ball
	ballShape.setPosition(position);
}