#include "Menu.h"

Menu::Menu(float width, float height) {
	font.loadFromFile("Assets/Fonts/MenuList.ttf");
	fonts.loadFromFile("Assets/Fonts/Header.ttf");

	for (int i = 0; i < NO_OF_ITEMS ; i++) {
		menu[i].setFont(font);
		menu[i].setPosition(sf::Vector2f(width / 2 + 35, height / (NO_OF_ITEMS + 1) * (i + 1)));
		menu[i].setCharacterSize(32);
		menu[i].setFillColor(sf::Color::White);
	}

	choose[0].setFont(font);
	choose[0].setPosition(width / 2 - 200, height / (NO_OF_ITEMS + 1) + 200);
	choose[0].setCharacterSize(30);
	choose[0].setFillColor(sf::Color::Red);
	choose[0].setString("Ghost");

	choose[1].setFont(font);
	choose[1].setPosition(width / 2 + 60, height / (NO_OF_ITEMS + 1) + 200);
	choose[1].setCharacterSize(30);
	choose[1].setFillColor(sf::Color::Yellow);
	choose[1].setString("PacMan");

	choose[3].setFont(font);
	choose[3].setPosition(width / 2 - 200, height / (NO_OF_ITEMS + 1) + 500);
	choose[3].setCharacterSize(30);
	choose[3].setFillColor(sf::Color::Red);
	choose[3].setString("Ghost");

	choose[4].setFont(font);
	choose[4].setPosition(width / 2 + 60, height / (NO_OF_ITEMS + 1) + 100);
	choose[4].setCharacterSize(30);
	choose[4].setFillColor(sf::Color::Yellow);
	choose[4].setString("PacMan");

	player[0].setFont(fonts);
	player[0].setPosition(width / 2 - 100, height / (NO_OF_ITEMS + 1) + 400);
	player[0].setCharacterSize(36);
	player[0].setFillColor(sf::Color::White);
	player[0].setString("Player Key");

	player[1].setFont(fonts);
	player[1].setPosition(width / 2 + 100, height / (NO_OF_ITEMS + 1) + 500);
	player[1].setCharacterSize(36);
	player[1].setFillColor(sf::Color::White);
	player[1].setString("Player Arrow");

	menu[0].setFillColor(sf::Color::Blue);
	menu[0].setString("SINGLE PLAYER");

	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("MULTI PLAYER");


	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("INSTRUCTIONS");

	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("CREDITS");

	menu[4].setFillColor(sf::Color::White);
	menu[4].setString("EXIT");

	selectedChooseIndex = 0;
	selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < NO_OF_ITEMS; i++) {
		window.draw(menu[i]);
	}
}

void Menu::moveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}

void Menu::moveDown()
{
	if (selectedItemIndex + 1 < NO_OF_ITEMS) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}

void Menu::moveRight()
{
	if (selectedChooseIndex + 1 < 2) {
		menu[selectedChooseIndex].setFillColor(sf::Color::White);
		selectedChooseIndex++;
		choose[selectedChooseIndex].setFillColor(sf::Color::Yellow);
	}
}

void Menu::moveLeft()
{
	if (selectedChooseIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedChooseIndex--;
		choose[selectedChooseIndex].setFillColor(sf::Color::Red);
	}
}

int Menu::getPressedItem()
{
	return selectedItemIndex;
}

int Menu::getPressedChoose()
{
	return selectedChooseIndex;
}

