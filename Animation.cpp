#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;

	totalTime = 0.0f;
	currentImage.y = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{
}

void Animation::Update(int column, float deltaTime, bool faceRight)
{
	currentImage.x = column;
	totalTime += deltaTime;

	if (totalTime >= switchTime )
	{
		totalTime -= switchTime;
		currentImage.y ++;

		if (currentImage.y >= 4)
		{
			currentImage.y = 0;
		}
	}
	uvRect.top = currentImage.y * uvRect.height;
	
	if (faceRight) {
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);

	}
	else {
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}

}
