#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS

#ifndef FIELD
#include"field.hpp"
#define FIELD
#endif // !FIELD


#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM



#ifndef OBJECTS
#include "objects.hpp"
#define OBJECTS
#endif // !OBJECTS






class Techies {


private:
	unsigned int window_width = 0, window_height = 0, complexity = 2;
	
	std::string name = "Techies";
	sf::RenderWindow* window;
	Field* field;
	TimerObject* timer;
	MinesCounterObject* mine_counter;
	ClickableObject *complexity_button;
	Object* background;

	std::vector<Object*> tmp_objects;
	void draw();

public:

	void start();


	Techies(unsigned int height);
	~Techies();
};