
#ifndef FIELD
#include"field.hpp"
#define FIELD
#endif // !FIELD




//SETTERS
void Field::set_sprite_coords(std::pair<float, float> coords)
{
	sprite_x = coords.first;
	sprite_y = coords.second;

	sprite.setPosition(sprite_x, sprite_y);
}

void Field::set_sprite_coords(float x, float y)
{
	sprite_x = x;
	sprite_y = y;

	sprite.setPosition(sprite_x, sprite_y);
}

void Field::set_sprite_x(float x)
{
	sprite_x = x;

	sprite.setPosition(sprite_x, sprite_y);
}

void Field::set_sprite_y(float y)
{
	sprite_y = y;

	sprite.setPosition(sprite_x, sprite_y);
}

void Field::set_sprite_size(int size)
{
	sprite_size = size;

	sprite.setTextureRect({ 0,0,size,size });
}

void Field::set_texture(std::string texture_file)
{
	if (!texture.loadFromFile("textures/fields/" + texture_file)) {
		texture.loadFromFile("textures/tech/error.jpg");
	}

	sprite.setTexture(texture);
}




//GETTERS
std::pair<float, float> Field::get_pos() const
{
	return {sprite_x,sprite_y};
}

float Field::get_x() const
{
	return sprite_x;
}

float Field::get_y() const
{
	return sprite_y;
}

int Field::get_size() const
{
	return sprite_size;
}

int Field::get_hidden_cells() const
{
	return hidden_cells;
}

int Field::get_hidden_mines() const
{
	return hidden_mines;
}


//TECH
void Field::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	for(int i = 0;i<cells.size();++i)
		for (int j = 0; j < cells.size(); ++j) {
			cells[i][j].draw(window);
	}
}

void Field::create_cells(int count, std::string texture)
{
	cell_size = (sprite_size - sprite_size / 20) / count;

	sf::Image* image = new sf::Image;
	image->create(cell_size, cell_size, { 145,145,145 });

	for (int i = 0; i < cell_size; i++)
		for (int j = 0; j < cell_size / std::max(cell_size, cell_size / 10); ++j) {
			image->setPixel(i, j, { 255, 255, 255 });
		}
	for (int i = 0; i < cell_size / std::max(cell_size, cell_size / 10); i++)
		for (int j = 0; j < cell_size; ++j) {
			image->setPixel(i, j, { 255, 255, 255 });
		}
	for (int i = cell_size - cell_size / std::max(cell_size, cell_size / 10); i < cell_size; i++)
		for (int j = 0; j < cell_size - 1; ++j) {
			image->setPixel(i, j, { 255, 255, 255 });
		}
	for (int i = 0; i < cell_size; i++)
		for (int j = cell_size - cell_size / std::max(cell_size, cell_size / 10); j < cell_size; ++j) {
			image->setPixel(i, j, { 255, 255, 255 });
		}


}




//OTHER
Field::Field(std::pair<float, float> position, int size, std::string field_texture, std::string cell_texture, int level)
{
	set_sprite_coords(position);
	set_sprite_size(size);
	set_texture(field_texture);



}


