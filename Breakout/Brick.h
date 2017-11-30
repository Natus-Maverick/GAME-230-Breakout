#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Brick
{
private:
	Vector2f position;
	RectangleShape brickShape;
	int hp;
public:
	Brick(FloatRect r, int h);
	RectangleShape getShape()
	{
		return brickShape;
	}
	FloatRect getPosition()
	{
		return brickShape.getGlobalBounds();
	}
	void hit()
	{
		--hp;
	}
	void rendY()
	{
		Texture tb;
		tb.loadFromFile("Brick.png");
		brickShape.setTexture(&tb);
		brickShape.setTextureRect(IntRect(42,200,100,48));
		brickShape.setOutlineThickness(1);
		brickShape.setOutlineColor(Color::Black);
		brickShape.setFillColor(Color::Yellow);
	}
	void rendR()
	{
		Texture tb;
		tb.loadFromFile("Brick.png");
		brickShape.setTexture(&tb);
		brickShape.setTextureRect(IntRect(42, 200, 100, 48));
		brickShape.setOutlineThickness(1);
		brickShape.setOutlineColor(Color::Black);
		brickShape.setFillColor(Color::Red);
	}
	void rendB()
	{
		Texture tb;
		tb.loadFromFile("Brick.png");
		brickShape.setTexture(&tb);
		brickShape.setTextureRect(IntRect(42, 200, 100, 48));
		brickShape.setOutlineThickness(1);
		brickShape.setOutlineColor(Color::Black);
		brickShape.setFillColor(Color::Blue);
	}
	bool isDead()
	{
		if (hp <= 0)
			return true;
		else
			return false;
	}
};

