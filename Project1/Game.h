#pragma once

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

	//private function
	void initVar();
	void initwindow();

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Function
	void pollEvents();
	void update();
	void render();
};

