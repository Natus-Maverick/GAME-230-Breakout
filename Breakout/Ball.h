#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace sf;

class Ball
{
private:
	Vector2f position;

	CircleShape ballShape;

	
public:
	Ball(float startX, float startY);

	float xVelocity;
	float yVelocity;

	FloatRect getPosition();

	CircleShape getShape();

	float getYAxis();
	
	void stop();

	bool active;

	void shoot();

	void follow(float x, float y);

	void reboundSides();

	void reboundTop();

	void reboundblock();

	void reboundBat1();

	void reboundBat2();

	void rebound1();

	void rebound2();

	void rebound3();

	void rebound4();

	void hitbrickL();

	void hitbrickR();

	void hitbrickT();

	void hitbrickB();

	void speedUp();

	void hitBottom();

	void update();

};
