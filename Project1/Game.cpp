#include "Game.h"

//Private functions
void Game::initVar()
{
	this->window = nullptr;

    //Game logic
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int MaxEnemy;

    this->points = 0;
    this->enemySpawnTimerMax = 1000.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax ;
    this->MaxEnemy = 5;

}

void Game::initwindow()
{
	this->videomode.height = 600;
	this->videomode.width = 800;

	this->window = new sf::RenderWindow(this->videomode, "My first game", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}
void Game::initenemy()
{
    this->enemy.setPosition(10.f, 10.f); //it's move 10 px from the top-left
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);


}

//Constructors / Destructors
Game::Game()
{
	this->initVar();
	this->initwindow();
    this->initenemy();
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
 void Game::spawnenemy()
{
     // spawn enemies and set their color and positions.
     // set a random position.
     // set a random color. 
     // add ememy to the vector.

     this->enemy.setPosition(
         static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
         0.f
     );

     this->enemy.setFillColor(sf::Color::Green);

     //spawn enemy
     this->enemies.push_back(this->enemy);

     //Remove the enemies at the end of the screen
}


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

void Game::updateMousePosition()
{
    this->MousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::updateEnemy()
{
    /*
    *   @return void
        update the enemies spawn timer and spawn enemies
        when the total amount of enemies is smaller than the maximum. 
        -move the enemies downwards.
        -remove the enemies at the edge of the screen. **TODO   
    */

    //Update the timer for enemies spawning 
    if (this->enemies.size() < this->MaxEnemy)
    {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            //spawn the enemies and reset the timer
            this->spawnenemy();
            this->enemySpawnTimer = 0.f;
        }
        else
            this->enemySpawnTimer += 1.f;
    }

    //Move the enemies
    for (auto &e : this->enemies)
    {
        e.move(0.f, 1.f);
    }
}


void Game::update()
{
    this->pollEvents();

    this->updateMousePosition();

    //update mouse position
    //std::cout << "Mouse position : " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << "\n"; //Relative to the screen
    //std::cout << "Mouse position : " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << "\n";// Relative to the window
    
    this->updateEnemy();

}

void Game::renderEnemy()
{
    //Rendering all the enemies 
    for (auto& e : this->enemies)
    {
        this->window->draw(e);
    }
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

    this->window->clear(sf::Color::Black);

    //draw game object
    this->renderEnemy(); 
    this->window->display();
}
