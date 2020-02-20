#pragma once
#include "Framework/GameObject.h"
class Flyer :
	public GameObject
{
		bool dragging;
		sf::Vector2f dragstart;
		sf::Vector2f dragend;
		sf::Vector2f direction;
		sf::Vector2u _winsize;
		sf::Vector2f currVelocity;
		sf::Vector2f gravity;
		sf::Vector2f drag;
		sf::Vector2f initialVelocity;
		float angle;
		bool dragged;
		float scale;
		float magnitude;

	public:
		Flyer();
		~Flyer();

		void handleInput(float dt) override;
		void update(float dt)  override;
		void getWin(sf::Vector2u winsize);
};

