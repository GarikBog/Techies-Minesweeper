#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS

#ifndef OBJECTS
#include"objects.hpp"
#define OBJECTS
#endif // !OBJECTS


#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM




class ClickableObject : public Object{

private:





public:

	virtual bool mouse_on(sf::RenderWindow& window);

	


};