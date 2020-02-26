#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	pacmanAnimation(texture, imageCount, switchTime)
{
	this->speed = speed;
	column = 2;
	faceRight = true;

	
	body.setTexture(*texture);
	body.setPosition(286.0f, 200.0f);
	
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += speed * deltaTime;

	if (movement.x == 0.0f) {
		column = 2;
	}
	else {
		column = 2;
		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
		
	pacmanAnimation.Update(column, deltaTime, faceRight);
	body.setTextureRect(pacmanAnimation.uvRect);
	body.move(movement); 



}

void Player::draw(sf::RenderWindow & window)
{
	window.draw(body);
}
