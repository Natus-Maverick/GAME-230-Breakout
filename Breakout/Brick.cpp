#include "Brick.h"

Brick::Brick(FloatRect r, int h)
{
	brickShape.setSize(sf::Vector2f(r.width,r.height));
	brickShape.setPosition(r.left, r.top);
	hp = h;
	position.x = r.left;
	position.y = r.top;
}


