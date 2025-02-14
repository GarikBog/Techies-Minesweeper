
#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS


#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM

#ifndef TECHIES_GAME
#include "techies.hpp"
#define TECHIES_GAME
#endif // !TECHIES_GAME


int main()
{

    Techies techies(1750);

    techies.start();


    return 0;

}








