#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballNo1Text.loadFromFile("gfx/Beach_Ball.png");
	ballNo1.setSize(sf::Vector2f(100, 100));
	ballNo1.setTexture(&ballNo1Text);
	ballNo1.setPosition(sf::Vector2f(500, 0));
	ballNo1.getWin(window->getSize());
	ballNo1.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	ballNo1.update(dt);
	ballNo1.handleInput(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(ballNo1);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}