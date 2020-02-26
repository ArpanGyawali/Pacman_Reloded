#pragma once
#include <SFML\Graphics.hpp>
#define NO_OF_ITEMS 5

class Menu
{
private:
	int selectedItemIndex, selectedChooseIndex;
	sf::Font font,fonts;

public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	int getPressedItem();
	int getPressedChoose();
	sf::Text choose[4], player[2], menu[NO_OF_ITEMS];
};

