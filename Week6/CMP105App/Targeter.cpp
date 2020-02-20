#include "Targeter.h"
#include "Framework/Vector.h"

Targeter::Targeter()
{
	speed = 150.f;
	acceleration = 100.f;
	target = sf::Vector2f(400, 400);
	reached = false;
}

Targeter::~Targeter()
{

}

void Targeter::update(float dt)
{
	if (!reached)
	{
		target = (sf::Vector2f(input->getMouseX(), input->getMouseY()));
		direction = target - getPosition();
		direction = Vector::normalise(direction);
		acceleration += 0.2f;
		velocity = (direction * acceleration);
		setPosition(getPosition() + (velocity * dt));

		if (Vector::magnitude(target - getPosition()) < 1.f)
		{
			setPosition(target);
			reached = true;
		}
	}
}

void Targeter::getWin(sf::Vector2u winsize)
{
	_winsize = winsize;
}