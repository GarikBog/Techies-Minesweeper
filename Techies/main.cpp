#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS

#ifndef CELL
#include"cell.hpp"
#define CELL
#endif // !CELL

#ifndef FIELD
#include"field.hpp"
#define FIEDL
#endif // !FIELD

int main()
{
    Cell cell(100,100,50,"test");


    sf::RenderWindow window(sf::VideoMode(200, 200), "Techies");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        cell.draw(window);
        window.display();
    }

    return 0;

}