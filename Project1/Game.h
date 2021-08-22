#pragma once
#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

//class that act like game engine.

class Game
{
private:
	//variable , window
	
	sf::RenderWindow* window;
	sf::VideoMode videomode;
	sf::Event ev;

	//mouse position
	sf::Vector2i MousePosWindow;

	//Game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int MaxEnemy;

	//Game object
	std::vector<sf::RectangleShape> enemies;  
	sf::RectangleShape enemy;

	//private function
	void initVar();
	void initwindow();
	void initenemy();

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Function
	void spawnenemy();

	void pollEvents();
	void updateMousePosition();
	void updateEnemy();
	void update();
	void renderEnemy();
	void render();
};

