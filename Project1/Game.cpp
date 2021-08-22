#include "Game.h"

//Private functions
void Game::initVar()
{
	this->window = nullptr;
}

void Game::initwindow()
{
	this->videomode.height = 600;
	this->videomode.width = 800;

	this->window = new sf::RenderWindow(this->videomode, "My first game", sf::Style::Titlebar | sf::Style::Close);
}
//Constructors / Destructors
Game::Game()
{
	this->initVar();
	this->initwindow();
}

Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

//Function
void Game::pollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}


void Game::update()
{
    this->pollEvents();
}

void Game::render()
{
    /*
      @return void

     -clear old frame
     -render objects
     -display frame in window

    render the game object
    */

    this->window->clear(sf::Color::Green);

    //draw game object

    this->window->display();
}
