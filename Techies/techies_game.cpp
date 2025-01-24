#ifndef TECHIES_GAME
#include "techies_game.hpp"
#define TECHIES_GAME
#endif // !TECHIES_GAME


void Techies::draw()
{
	background->draw(*window);
	field->draw(*window);

	mine_counter->draw(*window);
	complexity_button->draw(*window);
	timer->draw(*window);

}

void Techies::start()
{
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {

                }
                else if (event.mouseButton.button == sf::Mouse::Right) {

                }
            }

        }

        window->clear();
		draw();
        window->display();
    }
}

Techies::Techies(unsigned int height)
{
	window_height = height;
	window_width = height * 0.86;

	window = new sf::RenderWindow(sf::VideoMode(window_width, window_height),name);
	field = new Field({ window_width * 0.05,window_height*0.185}, window_width * 0.9, "ground.jpg", complexity);


	background = new Object(
		{ 0,0 },
		{ 1500,1750 },
		{ window_width,window_height },
		"backgrounds/test.png");

	mine_counter = new MinesCounterObject(
		{ (window_width * 0.05) ,(window_height * 0.015) },
		{60,35},
		{ (window_width * 0.27),(window_height * 0.16) },
		"counters/defolt.png");

	complexity_button = new ClickableObject(
		{ (window_width /2 - window_width * 0.16), (window_height * 0.015) },
		{ 200,75},
		{(window_width*0.32),(window_height* 0.16)},
		"complexity/defolt.png");

	timer = new TimerObject(
		{(window_width - window_width*0.05 - window_width * 0.27),(window_height * 0.015)},
		{ 60,35 },
		{(window_width * 0.27),(window_height * 0.16) },
		"counters/defolt.png");





}

Techies::~Techies()
{
}
