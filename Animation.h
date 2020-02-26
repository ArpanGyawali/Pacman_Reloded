#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void Update(int column, float deltaTime, bool faceRight);
//	void update(sf::Sprite rect, bool gendre);
//	void Move(sf::Sprite& pacman, float deltaTime, Animation& ani, sf::RenderWindow& ingame, bool gendre);

public:
	sf::IntRect uvRect;
/*	char u = 'f';
	float top, bottom, left, right;
	std::vector <sf::Vector2i> tiles;
	int M;
	float speed = 2.0;
	struct canMove {
		bool up = true;
		bool down = true;
		bool right = true;
		bool left = true;
	}CanMove; */
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	float totalTime;
	float switchTime;
};

