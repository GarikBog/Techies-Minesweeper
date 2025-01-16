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


    Field field({ 15,15 }, 900, "grid.png", 1);

 
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Techies");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //test.setPosition(100, 100);

        window.clear();
        field.draw(window);

        window.display();
    }

    return 0;

}