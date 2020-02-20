#pragma once
#include "Framework/GameObject.h"

class Ball :
	public GameObject
{
		float scale;
		sf::Vector2f gravity;
		sf::Vector2u _winsize;
		sf::Vector2f currVelocity;
		sf::Vector2f jumpVector;
		bool isJumping;

	public:	
		Ball();
		~Ball();

		void update(float dt) override;
		void getWin(sf::Vector2u winsize);
		void handleInput(float dt) override;
};

