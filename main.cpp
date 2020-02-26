#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Menu.h"
#include "Animation.h"
#include "Player.h"



using namespace std;

void singlePlayer();
//void multiPlayer();
void credit();
void instructions();
//void Win();

sf::Mutex mutex1;// , mutex2;
sf::Mutex mutex3, mutex4, mutexwin;

//main menu
int main()
{
	sf::Thread thread3(&instructions), thread4(&credit);
	sf::Thread thread1(&singlePlayer); //thread2(&multiPlayer);
	sf::RenderWindow window(sf::VideoMode(800, 600), "PacMan Reloded", sf::Style::Default);
	sf::Texture PAC, logo;
	sf::Sprite clipart, logos;
	sf::Event event;
	
	Menu menu(800, 600);
	window.setPosition(sf::Vector2i(290, 70));
	if (!PAC.loadFromFile("Assets/Images/PacMan_Clipart.png"))
		throw("Error load image");
	PAC.setSmooth(true);
	clipart.setTexture(PAC);
	clipart.setScale(sf::Vector2f(0.5f, 0.5f));
	clipart.setPosition(45, 175);
	if (!logo.loadFromFile("Assets/Images/logo.png"))
		throw("Error load image");
	logo.setSmooth(true);
	logos.setTexture(logo);
	logos.setScale(sf::Vector2f(0.8f, 0.5f));
	logos.setPosition(40, 30);

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type) {
			case  sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.moveUp();
					break;
				case sf::Keyboard::Down:
					menu.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.getPressedItem())
					{
					case 0:
						mutex1.lock();
						window.close();
						thread1.launch();
						mutex1.unlock();
						break;
				/*	case 1:
						mutex2.lock();
						window.close();
						thread2.launch();
						mutex2.unlock();
						break;              */
					case 2:
						mutex3.lock();
						window.close();
						thread3.launch();
						mutex3.unlock();
						break;
					case 3:
						mutex4.lock();
						window.close();
						thread4.launch();
						mutex4.unlock();
						break;
					case 4:
						window.close();
						break;
					default:
						break;
					}
				default:
					break;
				}
			default:
				break;
			}
		}
		window.clear();
		menu.draw(window);
		window.draw(clipart), window.draw(logos);
		window.display();
	}
	return 0;
}

//displays credits
void credit() {
	mutex3.lock();
	sf::Thread thr(&main);
	sf::RenderWindow ingame(sf::VideoMode(800, 600), "PacMan Reloded", sf::Style::Default);
	sf::Event eVent;
	sf::Font font,fonts;
	sf::Text credit,credits,cre;
	string creditfile, s;
	if (!font.loadFromFile("Assets/Fonts/HeadText.ttf"))
		throw("Error load font");
	if (!fonts.loadFromFile("Assets/Fonts/Text.ttf"))
		throw("Error load font");
	credit.setCharacterSize(32), credit.setFillColor(sf::Color::Magenta), credit.setFont(font), credit.setPosition(200, 40), credit.setString("Programmed by: \n***************************");
	cre.setCharacterSize(24), cre.setFillColor(sf::Color::Blue), cre.setFont(fonts), cre.setPosition(6, 100), cre.setString("\n\t\t\t\t\t->Arpan Gyawali(075BCT014) \n \n\t\t\t\t\t->Bijay Shrestha(075BCT020)\n \n\t\t\t\t\t->Bidhan Khatiwada(075BCT018) \n\t\t To Department of Computer Engineering. \n\t\t Daya Sagar Baral \n\n\t\t Release date : 25 / 02 / 2020 ");
	credits.setCharacterSize(26), credits.setFillColor(sf::Color::Cyan), credits.setFont(fonts), credits.setPosition(6, 500), credits.setString("\t\t\t'esc': Go to Home screen \n\t\t\t'Q': Quit the game");
	while (ingame.isOpen()) {
		while (ingame.pollEvent(eVent)) {
			if (eVent.type == sf::Event::Closed) {
				ingame.close();
				thr.launch();
			}
			if (eVent.type == sf::Event::KeyPressed) {
				if (eVent.key.code == sf::Keyboard::Q) {
					ingame.close();
				}
				else if (eVent.key.code == sf::Keyboard::Escape) {
					ingame.close();
					thr.launch();
				}
			}
		}
		ingame.clear();
		ingame.draw(credit);
		ingame.draw(credits);
		ingame.display();
	}
	mutex3.unlock();
}
// display instructions 
void instructions() {
	mutex4.lock();
	sf::RenderWindow ingame(sf::VideoMode(800, 600), "PacMan Reloded", sf::Style::Default);
	sf::Event eVent;
	sf::Text Goal, Controls, Goaltext, Controlstext;
	sf::Font font,fonts;
	sf::Thread th(&main);
	if (!font.loadFromFile("Assets/Fonts/HeadText.ttf"))
		throw("Error load font");
	if (!fonts.loadFromFile("Assets/Fonts/Text.ttf"))
		throw("Error load font");
	Goaltext.setCharacterSize(24), Controlstext.setCharacterSize(24), Goal.setCharacterSize(32), Controls.setCharacterSize(32);
	Goaltext.setFillColor(sf::Color::Blue), Controlstext.setFillColor(sf::Color::Blue), Goal.setFillColor(sf::Color::Magenta), Controls.setFillColor(sf::Color::Cyan);
	Goaltext.setFont(fonts), Controlstext.setFont(fonts), Goal.setFont(font), Controls.setFont(font);
	Goal.setPosition(370, 90), Goaltext.setPosition(10, 140), Controls.setPosition(342, 290), Controlstext.setPosition(10, 340);
	Goal.setString("Goal"), Controls.setString("Controls"), Goaltext.setString(" Guide Pacman around the maze and eat all the little white\ndots whilst avoiding those nasty ghosts. If you eat a Power\n Pill,you can eat the ghosts! Occasionally, a different powerups\n appears which gives you various benifits when eaten."), Controlstext.setString(" 'AWSD' keys for Player key. \n Arrow keys for Player arrow. \n Q : Quit game \n esc : Go back to Home screen \n");
	while (ingame.isOpen()) {
		while (ingame.pollEvent(eVent)) {
			if (eVent.type == sf::Event::Closed) {
				ingame.close();
				th.launch();
			}
			if (eVent.type == sf::Event::KeyPressed) {
				if (eVent.key.code == sf::Keyboard::Q) {
					ingame.close();
				}
				else if (eVent.key.code == sf::Keyboard::Escape) {
					ingame.close();
					th.launch();
				}
			}
		}
		ingame.clear();
		ingame.draw(Goal), ingame.draw(Goaltext), ingame.draw(Controls), ingame.draw(Controlstext);
		ingame.display();
	}
	mutex4.unlock();
}

void singlePlayer() {
	mutex1.lock();
	sf::RenderWindow ingame(sf::VideoMode(730, 675), "PACMAN", sf::Style::Default);
	ingame.setPosition(sf::Vector2i(290, 20));
	sf::Event eVent;
	sf::Thread thre(&main);
	
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("Assets/Images/gra.bmp"))
		throw("Error load image");

	Player playerAnimation(&playerTexture, sf::Vector2u(9, 16), 0.13f, 85.0f);

	float deltaTime = 0.0f;
	sf::Clock clock;


	while (ingame.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		while (ingame.pollEvent(eVent)) {
			if (eVent.type == sf::Event::Closed) {
				ingame.close();
				thre.launch();
			}
			if (eVent.type == sf::Event::KeyPressed) {
				if (eVent.key.code == sf::Keyboard::Q) {
					ingame.close();
				}
				else if (eVent.key.code == sf::Keyboard::Escape) {
					ingame.close();
					thre.launch();
				}
			}
		}

		playerAnimation.Update(deltaTime);
		ingame.clear();
		playerAnimation.draw(ingame);
		ingame.display();
	}
	mutex1.unlock();
}
/*	sf::Event eVent;
	//Clock clock;
	sf::Thread th(&main);
	//Sprite mrPacman, msPacman;
	//Texture mrPacmantext, msPacmantext;
	sf::Text title, name1, name2, dis1, dis2;
	//long long score = 0;
	sf::Font font,fonts,fon;
	string name, Gender, display;
	Menu menu(800, 710);
	bool flag = 0, flag2 = 0, flag3 = 0, flag4 = 0,  MsOrMr = 1;
	fon.loadFromFile("Assets/Fonts/MenuList.ttf");
	font.loadFromFile("Assets/Fonts/Header.ttf");
	fonts.loadFromFile("Assets/Fonts/HeadText.ttf");
	title.setFont(fon), title.setPosition(100, 40), title.setCharacterSize(36), title.setFillColor(sf::Color::Blue), title.setString("Choose Avatar? \n");
	name1.setFont(font), name1.setPosition(100, 100), name1.setCharacterSize(32), name1.setFillColor(sf::Color::White), name1.setString("PLAYER KEY \n");
	name2.setFont(font), name2.setPosition(100, 250), name2.setCharacterSize(32), name2.setFillColor(sf::Color::White), name2.setString("PLAYER ARROW \n");
	while (ingame.isOpen()) {
		//deltaTime = clock.restart().asSeconds();
		while (ingame.pollEvent(eVent)) {
			switch ((eVent.type))
			{
			case sf::Event::Closed:
				ingame.close();
				th.launch();
				break;
			case sf::Event::KeyReleased:
				switch (eVent.key.code)
				{
				case sf::Keyboard::Right:
					menu.moveRight();
					break;
				case sf::Keyboard::Left:
					menu.moveLeft();
					break;
				case sf::Keyboard::Q:
					ingame.close();
					break;
				case sf::Keyboard::Return:
					switch (menu.getPressedItem())
					{
					case 0:
						flag = true;
						break;
					case 1:
						flag2 = true;
						break;
					default:
						break;
					}
				default:
					break;
				}
			default:
				break;
			} 
		} */

