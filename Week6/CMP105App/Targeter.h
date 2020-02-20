#pragma once
#include "Framework/GameObject.h"
class Targeter :
	public GameObject
{
		float speed;
		float acceleration;
		sf::Vector2f target;
		sf::Vector2f velocity;
		sf::Vector2u _winsize;
		sf::Vector2f direction;
		bool reached;

	public:
		Targeter();
		~Targeter();

		void update(float dt) override;
		void getWin(sf::Vector2u winsize);
};

