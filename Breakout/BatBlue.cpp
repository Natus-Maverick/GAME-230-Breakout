#include "BatBlue.h"
#include <Windows.h>

BatBlue::BatBlue(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	batShape.setSize(sf::Vector2f(100, 20));
	batShape.setPosition(position);
}

FloatRect BatBlue::getPosition()
{
	return batShape.getGlobalBounds();
}

RectangleShape BatBlue::getShape()
{
	return batShape;
}

void BatBlue::moveLeft()
{
	position.x -= batSpeed;
}

void BatBlue::moveRight()
{
	position.x += batSpeed;
}

void BatBlue::blockUp()
{
	position.y -= blockSpeed;
}

void BatBlue::blockDown()
{
	position.y += blockSpeed;
}

void BatBlue::mouse()
{
	POINT p;
	ShowCursor(FALSE);
	GetCursorPos(&p);
	position.x = p.x - 448;
}

void BatBlue::update()
{
	batShape.setPosition(position);
}