#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS

#ifndef FIELD
#include"field.hpp"
#define FIEDL
#endif // !FIELD


#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM





class Button {
private:
	float x = 0, y = 0;
	
	int wight = 0, height = 0;


	
	sf::Texture texture;
	sf::Sprite sprite;



public:

};




class Techies {


private:
	unsigned int window_wight = 0, window_height = 0;

	std::string name;

	sf::RenderWindow window;

public:


};