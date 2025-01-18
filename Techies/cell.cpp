#ifndef CELL
#include"cell.hpp"
#define CELL
#endif // !CELL


#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM

//SETTERS
void Cell::set_pos(float new_x, float new_y)
{
	this->x = new_x;
	this->y = new_y;

	sprite.setPosition(x, y);
}

void Cell::set_pos(std::pair<float, float> new_coords)
{
	x = new_coords.first, y = new_coords.second;

	sprite.setPosition(x, y);
}

void Cell::set_scale(float scale)
{
	sprite.setScale({
		scale / sprite.getLocalBounds().width,
		scale / sprite.getLocalBounds().height
		});
}

void Cell::set_texture_size(int size)
{
	this->size = size;

	sprite.setTextureRect({ texture_file_pos_x,texture_file_pos_y,size,size });
}

void Cell::set_texture_pos(std::pair<int, int> pos)
{
	this->texture_file_pos_x = pos.first, this->texture_file_pos_y = pos.second;

	sprite.setTextureRect({ texture_file_pos_x ,texture_file_pos_y,size,size });
}

void Cell::set_texture(std::string texture)
{
	this->texture.loadFromFile("textures/cells/"+texture);
	sprite.setTexture(this->texture);
}

bool Cell::set_flag()
{
	flag? flag = false : flag = true;
	return flag;
}



//GETTERS
std::pair<float, float> Cell::get_coords() const
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
	return sprite.getLocalBounds().width;
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

void Cell::open_this_cell()
{
	this->open = true;
}

bool Cell::is_open()
{
	return open;
}

void Cell::set_mine()
{
	mine = true;

}

bool Cell::is_mine()
{
	return mine;
}

bool Cell::is_flag()
{
	return flag;
}

void Cell::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}



//OTHER
Cell::Cell(float x, float y, int scale, std::string texture)
{
	set_pos(x, y);
	set_texture(texture);
	set_texture_size(72);
	set_scale(scale);

}

