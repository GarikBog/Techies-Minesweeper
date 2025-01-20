
#ifndef CELL
#include"cell.hpp"
#define CELL
#endif // !CELL

#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS

#ifndef FIELD
#include"field.hpp"
#define FIEDL
#endif // !FIELD

#ifndef BUTTONS
#include"buttons.hpp"
#define BUTTONS
#endif // !BUTTONS




#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM


int main()
{
    int window_size = 1000;

    sf::Sprite sprite;




    Field field({ 15,15 }, 900, "grid.png", 3);

    sf::RenderWindow window(sf::VideoMode(window_size, window_size), "Techies");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased) {
               if (event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    if (!field.click(mouse_pos, false)) field.open_all_mines();
                }
               else if (event.mouseButton.button == sf::Mouse::Right) {
                   sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                   field.click(mouse_pos, true);
               }
            }

        }

        //test.setPosition(100, 100);

        window.clear();
        //window.draw(sprite);
        field.draw(window);

        window.display();
    }

    return 0;

}








