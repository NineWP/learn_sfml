#include <iostream>
#include "Game.h"
int main()
{
    /* Open window
    sf::RenderWindow window(sf::VideoMode(640, 480), "My first game", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;*/

    //init srandom
    std::srand(static_cast<unsigned>(time(NULL)));

    //Init game engine
    Game game;

    //Game loop
    while (game.running())
    {
       
        //Update
        game.update();

        //Render
        game.render();

    }

    
    return 0;
}