#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "BatBlue.h"
#include "Ball.h"
#include "Brick.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <memory>
#include <vector>

using namespace sf;

std::vector <Brick*> bricks;

void CreateLevel0()
{
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			FloatRect r = sf::Rect<FLOAT>(87.0f + 150.0f*i, 200.0f + 50.0f*j, 100.0f, 48.0f);
			int hp = 1;
			Brick* b = new Brick(r, hp);
			bricks.push_back(b);
		}
	}
}

void CreateLevel1()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			FloatRect r = sf::Rect<FLOAT>(87.0f + 200.0f*i, 200.0f + 100.0f*j, 100.0f, 48.0f);
			int hp = 2;
			Brick* b = new Brick(r, hp);
			b->rendY();
			bricks.push_back(b);
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			FloatRect r = sf::Rect<FLOAT>(187.0f + 200.0f*i, 250.0f + 100.0f*j, 100.0f, 48.0f);
			int hp = 1;
			Brick* b = new Brick(r, hp);
			bricks.push_back(b);
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		FloatRect r = sf::Rect<FLOAT>(187.0f + 200.0f*i, 150.0f, 100.0f, 48.0f);
		int hp = 1;
		Brick* b = new Brick(r, hp);
		b->rendR();
		bricks.push_back(b);
	}
}
void CreateLevel2()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			FloatRect r = sf::Rect<FLOAT>(42.0f + 204.0f*i, 200.0f + 50.0f*j, 100.0f, 48.0f);
			int hp = 1;
			Brick* b = new Brick(r, hp);
			//b->rend();
			bricks.push_back(b);
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			FloatRect r = sf::Rect<FLOAT>(144.0f + 204.0f*i, 200.0f + 100.0f*j, 100.0f, 48.0f);
			int hp = 2;
			Brick* b = new Brick(r, hp);
			b->rendY();
			bricks.push_back(b);
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			FloatRect r = sf::Rect<FLOAT>(144.0f + 204.0f*i, 250.0f + 100.0f*j, 100.0f, 48.0f);
			int hp = 2;
			Brick* b = new Brick(r, hp);
			b->rendB();
			bricks.push_back(b);
		}
	}

}
int level;

int main()
{
	int windowWidth = 1024;
	int windowHeight = 768;
	// Make a window that is 1024 by 768 pixels
	// And has the title "Breakout"
	RenderWindow window(VideoMode(windowWidth, windowHeight), "Breakout");

	int scoreValue = 0;
	int lifeValue = 2;
	bool die = false;
	bool levelClear = false;

	CreateLevel0();
	// create a bat
	BatBlue bat(windowWidth / 2 - 50.0f, windowHeight - 25.0f);

	// create a ball
	Ball ball(bat.getPosition().left + 50, bat.getPosition().top - 50);

	Texture tt;
	tt.loadFromFile("bg.png");
	Sprite background(tt);

	Text lives;
	Text score;
	Text over;
	//Sounds
	SoundBuffer point;
	SoundBuffer victory;
	SoundBuffer pad_b;
	SoundBuffer wall_b;
	SoundBuffer fallOff;
	SoundBuffer hit_brick;
	SoundBuffer destroy_brick;
	SoundBuffer backgroundMusic;
	point.loadFromFile("Point.wav");
	victory.loadFromFile("Victory.wav");
	pad_b.loadFromFile("paddle_bounce.wav");
	wall_b.loadFromFile("wall_bounce.wav");
	fallOff.loadFromFile("Fall.wav");
	hit_brick.loadFromFile("hit_brick.wav");
	destroy_brick.loadFromFile("destroy_brick.wav");
	backgroundMusic.loadFromFile("bgm.wav");

	Sound sound;
	Sound win;
	Sound bgm;
	// We need to choose a font
	Font font;
	font.loadFromFile("The Led Display St.ttf");

	// Set the font to our message
	lives.setFont(font);
	score.setFont(font);
	over.setFont(font);

	// Make fonts big
	lives.setCharacterSize(75);
	score.setCharacterSize(75);
	over.setCharacterSize(30);

	// Choose color
	lives.setFillColor(sf::Color::White);
	score.setFillColor(sf::Color::White);
	over.setFillColor(sf::Color::Red);

	//Set positions
	lives.setPosition(windowWidth - 400.0f, 20.0f);
	score.setPosition(20.0f, 20.0f);
	over.setPosition(260.0f, 500.0f);

	bgm.setBuffer(backgroundMusic);
	bgm.play();

	while (window.isOpen())
	{
		// create level
		if (levelClear == true)
		{
			if (level % 3 == 0)
			{
				CreateLevel0();
				levelClear = false;
			}
			else if (level % 3 == 1)
			{
				CreateLevel1();
				levelClear = false;
			}
			else if (level % 3 == 2)
			{
				CreateLevel2();
				levelClear = false;
			}
		}
		//level clear
		if (bricks.size() <= 0 || (level%3 ==2 && bricks.size() <= 12))
		{
			win.setBuffer(point);
			win.play();
			levelClear = true;
			ball.active = false;
			level++;
		}
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) && bat.getPosition().left >= 0 && die == false)
		{
			// move left
			bat.moveLeft();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right) && bat.getPosition().left + bat.getShape().getSize().x <= windowWidth && die == false)
		{
			// move right
			bat.moveRight();
		}
		else if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			// quit
			window.close();
		}

		if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getShape().getRadius()*2 > windowWidth)
		{
			ball.reboundSides();
			sound.setBuffer(wall_b);
			sound.play();
		}
		if (ball.getPosition().top < 0)
		{
			ball.reboundTop();
			sound.setBuffer(wall_b);
			sound.play();
		}
		if (ball.getPosition().top + ball.getShape().getRadius() * 2 > windowHeight)
		{
			ball.active = false;
			lifeValue--;
			if (lifeValue < 0)
			{
				die = true;
			}
			sound.setBuffer(fallOff);
			sound.play();
		}
		
		if (ball.active == false)
		{
			ball.follow(bat.getPosition().left + 35, bat.getPosition().top - 30);
		}

		if (Keyboard::isKeyPressed(sf::Keyboard::Space) && ball.active == false && die == false)
		{
			ball.shoot();
			for (int i = 0; i < level; i++)
			{
				ball.speedUp();
			}
		}
		if (die == true)
		{
			over.setString("YOU DIED!\nPress Space\nto Restart");
			if (Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				ball.active = false;
				die = false;
				scoreValue = 0;
				lifeValue = 2;
				bricks.clear();
				CreateLevel0();
				over.setString("");
			}
		}

		// Handle ball hitting top
		if (ball.getPosition().top < 0)
		{
			sound.setBuffer(wall_b);
			sound.play();
		}

		// Has the ball hit the player's bat?
		if (ball.getPosition().intersects(bat.getPosition()))
		{
			//col = false;
			sound.setBuffer(pad_b);
			sound.play();
			if (ball.getPosition().left - bat.getPosition().left < 20)
				ball.rebound1();
			if (ball.getPosition().left - bat.getPosition().left >= 20 && ball.getPosition().left - bat.getPosition().left < 40)
				ball.rebound2();
			if (ball.getPosition().left - bat.getPosition().left >= 40 && ball.getPosition().left - bat.getPosition().left < 60)
				ball.reboundBat1();
			if (ball.getPosition().left - bat.getPosition().left >= 60 && ball.getPosition().left - bat.getPosition().left < 80)
				ball.rebound3();
			if (ball.getPosition().left - bat.getPosition().left >= 60)
				ball.rebound4();
		}
		
		for (int i = 0; i < bricks.size();)
		{
			Brick* b = bricks[i];
			if (ball.getPosition().intersects(b->getPosition()))
			{
				scoreValue += 10;
				if (ball.getPosition().left + ball.getShape().getRadius() <= b->getPosition().left && ball.getPosition().top >= b->getPosition().top - 24 * 0.707f && ball.getPosition().top <= b->getPosition().top + 24 * 2.707f)
				{
					ball.hitbrickL();
				}
				else if (ball.getPosition().left + ball.getShape().getRadius() >= b->getPosition().left + b->getShape().getSize().x && ball.getPosition().top >= b->getPosition().top - 24 * 0.707f && ball.getPosition().top <= b->getPosition().top + 24 * 2.707f)
				{
					ball.hitbrickR();
				}
				else if (ball.getPosition().top + ball.getShape().getRadius() <= b->getPosition().top)
				{
					ball.hitbrickT();
				}
				else if (ball.getPosition().top + ball.getShape().getRadius() >= b->getPosition().top + 48)
				{
					ball.hitbrickB();
				}
				if (b->getShape().getFillColor() == Color::Red)
					ball.speedUp();
				if (b->getShape().getFillColor() != Color::Blue)
					b->hit();
				if (b->isDead() == true)
				{
					bricks.erase(bricks.begin() + i);
					sound.setBuffer(destroy_brick);
					sound.play();
					continue;
				}
				else
				{
					sound.setBuffer(hit_brick);
					sound.play();
				}
			}
			++i;
		}

		//updates
		ball.update();
		bat.update();
		
		//score
		std::stringstream s;
		s << scoreValue;
		score.setString("SCORE:"+ s.str());

		//lives
		std::stringstream l;
		l << lifeValue;
		lives.setString("LIVES:"+ l.str());


		//draw
		window.clear();

		window.draw(background);

		window.draw(bat.getShape());

		window.draw(ball.getShape());

		// Draw our scores
		window.draw(lives);
		window.draw(score);
		window.draw(over);

		for (int i = 0; i < bricks.size(); ++i)
		{
			window.draw(bricks[i]->getShape());
		}


		// Show everything we just drew
		window.display();
	}

	return 0;
}