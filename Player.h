#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update(float deltaTime);
	void draw(sf::RenderWindow & window);


private:
	sf::Sprite body;
	Animation pacmanAnimation;
	unsigned int column;
	float speed;
	bool faceRight;
	
};

