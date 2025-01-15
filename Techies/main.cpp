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
    int cell_size = 100;

    sf::Image im;
    im.create(cell_size, cell_size, sf::Color(214, 214, 214, 255));


    for (int i = 0; i < cell_size; ++i)
        for (int j = 0; j < 2; ++j) {
            im.setPixel(i, j, { 255,255,255 });
    }
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < cell_size; ++j) {
            im.setPixel(i, j, { 255,255,255 });
        }
    for (int i = 0; i < cell_size; ++i)
        for (int j = cell_size-1; j < cell_size; ++j) {
            im.setPixel(i, j, { 255,255,255 });
        }
    for (int i = cell_size; i < cell_size+1; ++i)
        for (int j = 0; j < 2; ++j) {
            im.setPixel(i, j, { 255,255,255 });
        }

    for (int i = 0; i < cell_size; i++)
        for (int j = 0; j < cell_size / std::min(cell_size, cell_size / 15); ++j) {
            im.setPixel(i, j, { 255 , 255 , 255  });
        }
    for (int i = 0; i < cell_size / std::min(cell_size, cell_size / 15); i++)
        for (int j = 0; j < cell_size; ++j) {
            im.setPixel(i, j, { 255 , 255 , 255  });
        }
    for (int i = cell_size - cell_size / std::min(cell_size, cell_size / 15); i<cell_size; i++)
        for (int j = 0; j < cell_size-1; ++j) {
            im.setPixel(i, j, { 82 , 82 , 82  });
        }
    for (int i = 0; i < cell_size; i++)
        for (int j = cell_size - cell_size / std::min(cell_size, cell_size / 15); j < cell_size ; ++j) {
            im.setPixel(i, j, { 82 , 82 , 82  });
        }

    sf::Sprite test;
    sf::Texture texture;
    texture.loadFromImage(im);
    test.setTexture(texture);
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
        for(int i = 0;i<8;++i)
            for (int j = 0; j < 8;++j) {
                test.setPosition(25 + cell_size * i, 25 + cell_size *j);
                window.draw(test);
        }

        window.display();
    }

    return 0;

}