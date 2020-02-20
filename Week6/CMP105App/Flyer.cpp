#include "Flyer.h"
#include "Framework/Vector.h"

Flyer::Flyer()
{
	dragstart = sf::Vector2f(0, 0);
	dragend = sf::Vector2f(0, 0);
	direction = sf::Vector2f(0, 0);
	currVelocity = sf::Vector2f(0, 0);
	drag = sf::Vector2f(0, 0);
	scale = 50;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	magnitude = 0;
	dragged = false;
	initialVelocity = sf::Vector2f(0, 0);
	angle = 0;
}

Flyer::~Flyer()
{

}

void Flyer::handleInput(float dt)
{
	if (input->isMouseLDown() && !dragged)
	{
		if (!dragging)
		{
			dragstart.x = input->getMouseX();
			dragstart.y = input->getMouseY();
			dragging = true;
		}
	}
	else if (!input->isMouseLDown() && dragging)
	{
		dragend.x = input->getMouseX();
		dragend.y = input->getMouseY();
		dragging = false;
		drag = dragend - dragstart;
		magnitude = Vector::magnitude(drag);
		direction = Vector::normalise(drag);
		dragged = true;
		currVelocity = (direction * magnitude);
	}
}

void Flyer::update(float dt)
{
	if (dragged)
	{
		sf::Vector2f pos = ((currVelocity * dt) + (0.5f * gravity * dt * dt));
		currVelocity += gravity * dt;
		setPosition(getPosition() + pos);
	}
}

void Flyer::getWin(sf::Vector2u winsize)
{
	_winsize = winsize;
}