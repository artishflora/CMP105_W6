#include "Ball.h"

Ball::Ball()
{
	scale = 100.f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	currVelocity = sf::Vector2f(0, 0);
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = true; 
}

Ball::~Ball()
{

}

void Ball::update(float dt)
{
	sf::Vector2f pos = (currVelocity * dt) + (0.5f * gravity * dt * dt); //u * t + 1/2 * a * t^2
	currVelocity += gravity * dt; //u + a * t
	setPosition(getPosition() + pos);

	if (getPosition().y >= _winsize.y - getSize().y)
	{
		setPosition(getPosition().x, _winsize.y - getSize().y);
		currVelocity = sf::Vector2f(0, 0);
		isJumping = false;
	}
}

void Ball::getWin(sf::Vector2u winsize)
{
	_winsize = winsize;
}

void Ball::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			currVelocity = jumpVector;
			isJumping = true;
		}
	}
	if (input->isMouseRDown())
	{
		setPosition(input->getMouseX(), input->getMouseY());
		currVelocity = sf::Vector2f(0, 0);
		isJumping = true;
	}
}