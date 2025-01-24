
#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS


#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM

#ifndef TECHIES_GAME
#include "techies_game.hpp"
#define TECHIES_GAME
#endif // !TECHIES_GAME


int main()
{
    int window_size = 1000;

    //sf::Sprite sprite;
    //sf::Texture texture;

    //texture.loadFromFile("textures/fields/ground.jpg");

    //sprite.setTexture(texture);

    //TimerObject timer({ 50,50 }, {60,35},{60,35}, "counters/defolt.png");
    //timer.start();

    //MinesCounterObject counter({ 150,150 }, { 60,35 }, { 60,35 }, "counters/defolt.png");

    //Field field({ 150,15 }, 900, "grid.png", 2);

    Techies techies(1750);

    techies.start();

    
    /*
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased) {
               if (event.mouseButton.button == sf::Mouse::Left){
                   //counter.remove_mine();

                    //sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    //if (!field.click(mouse_pos, false)) field.open_all_mines();
                }
               else if (event.mouseButton.button == sf::Mouse::Right) {
                   //counter.add_mine();
                   //sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                   //field.click(mouse_pos, true);
               }
            }

        }

        //test.setPosition(100, 100);

        window.clear();
        //timer.update();
        //timer.draw(window);
        //window.draw(sprite);
        //field.draw(window);
        //counter.update();
        //counter.draw(window);

        window.display();
    }
    */

    return 0;

}








