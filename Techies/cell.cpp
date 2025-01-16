#ifndef CELL
#include"cell.hpp"
#define CELL
#endif // !CELL


//SETTERS
void Cell::set_pos(double new_x, double new_y)
{
	this->x = new_x;
	this->y = new_y;

	sprite.setPosition(x, y);
}

void Cell::set_pos(std::pair<double, double> new_coords)
{
	x = new_coords.first, y = new_coords.second;

	sprite.setPosition(x, y);
}

void Cell::set_size(int size)
{
	this->size = size;

	sprite.setTextureRect({ texture_file_pos_x,texture_file_pos_y,size,size });
}

void Cell::set_texture_pos(std::pair<int, int> pos)
{
	this->texture_file_pos_x = pos.first, this->texture_file_pos_y = pos.second;

	sprite.setTextureRect({ texture_file_pos_x ,texture_file_pos_y,size,size });
}

void Cell::set_texture(sf::Image image)
{
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}



//GETTERS
std::pair<double, double> Cell::get_coords() const
{
	return {x,y};
}

double Cell::get_x() const
{
	return x;
}

double Cell::get_y() const
{
	return y;
}

int Cell::get_size() const
{
	return size;
}

int Cell::get_mines_near() const
{
	return mines_near;
}




//TECH
void Cell::new_mine_near()
{
	mines_near += 1;
}

void Cell::set_mine()
{
	mine = true;

}

bool Cell::is_mine()
{
	return mine;
}

void Cell::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}



//OTHER
Cell::Cell(double x, double y, int size, sf::Image image)
{
	set_pos(x, y);
	set_size(size);
	set_texture(image);

}

