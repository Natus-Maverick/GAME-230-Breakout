#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class BatBlue
{

private:
	Vector2f position;
	RectangleShape batShape;

	float batSpeed = .3f;
	float blockSpeed = .08f;

public:
	BatBlue(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	void moveLeft();

	void moveRight();

	void mouse();

	void blockUp();

	void blockDown();

	void update();
};

