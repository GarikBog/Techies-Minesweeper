
#ifndef FIELD
#include"field.hpp"
#define FIELD
#endif // !FIELD

#ifndef CTIME
#include<ctime>
#define CTIME
#endif // !CTIME

#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM




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
	for(int i = 0;i<cells.size();++i){
			cells[i]->draw(window);
	}
}

void Field::set_mines(int count)
{
	hidden_mines = count;

	srand((unsigned)time(0));
	int rand_cell;
	while (count > 0) {
		rand_cell = rand() % cells.size();


		if (!cells[rand_cell]->is_mine()) {

			cells[rand_cell]->set_mine();

			int i = rand_cell / cells_collums_count,
				j = rand_cell % cells_collums_count;

			
			std::cout << "\nMine set on: " << i << ' ' << j << "\nMore: " << count;
			add_mine_count(i, j);

			--count;
		}
	}
}

bool Field::click(sf::Vector2i mouse_pos, bool mouse_flag)
{
	float gabarite_x = sprite_x + sprite_size / 100,
		gabarite_x_max = sprite_x + sprite_size / 100 + cell_size * cells_collums_count,
		gabarite_y = sprite_y + sprite_size / 100,
		gabarite_y_max = sprite_y + sprite_size/100  + cell_size * cells_collums_count;

	std::cout << "\n\nMouse_pos: " << mouse_pos.x << ' ' << mouse_pos.y
		<< "\nGabatite_x: " << gabarite_x << ' ' << gabarite_x_max
		<< "\nGabarite_y: " << gabarite_y << ' ' << gabarite_y_max;

	if (mouse_pos.x < gabarite_x
		|| mouse_pos.y < gabarite_y
		|| mouse_pos.x > gabarite_x_max
		|| mouse_pos.y > gabarite_y_max){
		std::cout << "\nRETURN ";
		return true;
	}

	Cell& cell = find_cell_under_mouse(mouse_pos);

	std::cout << "\nCell_x_max: " << cell.get_x() + cell_size
		<< "\nCell_y_max: " << cell.get_y() + cell_size;

	open_cell(cell);


	return !cell.is_mine();
}

Cell& Field::find_cell_under_mouse(sf::Vector2i mouse_pos)
{


	int i = (mouse_pos.x - sprite_x - sprite_size/100) / cell_size,
		j =  (mouse_pos.y - sprite_y - sprite_size/100) / cell_size;
	
	Cell& cell = *cells[i * cells_collums_count + j];
	
	
	return cell;


}

bool Field::open_cell(Cell& cell)
{
	std::cout << "\nOPEN CELL\n";

	if (cell.is_mine()) std::cout << "MINE!";
	else std::cout << cell.get_mines_near();
	return false;
}

void Field::create_cells(int count)
{
	cells_collums_count = count;
	hidden_cells = count * count;
	cells.clear();
	cells.reserve(count);
	cell_size = (sprite_size - sprite_size / 50) / count;

	sf::Image* image = new sf::Image;
	image->create(cell_size, cell_size, sf::Color(70, 70, 70, 255));

	for (int i = cell_size - 2; i > 0; --i)
		for (int j = cell_size - i; j < cell_size - 2; ++j)
		{
			image->setPixel(cell_size - j, cell_size - 2 - i, { 200,200,200,255 });
		}

	for (int i = cell_size / 10; i < cell_size * 9 / 10; ++i)
		for (int j = cell_size / 10; j < cell_size * 9 / 10; ++j)
		{
			image->setPixel(cell_size - j, cell_size - 2 - i, { 135, 135, 135,255 });
		}



	for(int i = 0; i <count;++i)
		for (int j = 0; j < count; ++j)
		{

			Cell* cell = new Cell(sprite_x + sprite_size / 100 + cell_size * i, sprite_y + sprite_size / 100 + cell_size * j,cell_size, *image);
			cells.push_back(cell);
		}

	set_mines((count* count) * 0.15);

}

void Field::add_mine_count(int i, int j)
{
	int next_cell = (i - 1) * cells_collums_count + j - 1;
	if (next_cell > 0 && next_cell < cells.size())
		cells[next_cell]->new_mine_near();


	next_cell = (i - 1) * cells_collums_count + j;
	if (next_cell > 0 && next_cell < cells.size())
		cells[next_cell]->new_mine_near();

	next_cell = (i - 1) * cells_collums_count + j + 1;
	if (next_cell > 0 && next_cell < cells.size())
		cells[next_cell]->new_mine_near();

	next_cell = i  * cells_collums_count + j - 1;
	if (next_cell > 0 && next_cell < cells.size())
		cells[next_cell]->new_mine_near();

	next_cell = i * cells_collums_count + j;
	if (next_cell > 0 && next_cell < cells.size())
		cells[next_cell]->new_mine_near();

	next_cell = i * cells_collums_count + j + 1;
	if (next_cell > 0 && next_cell < cells.size())
		cells[next_cell]->new_mine_near();

	next_cell = (i + 1) * cells_collums_count + j - 1;
	if (next_cell > 0 && next_cell < cells.size())
		cells[next_cell]->new_mine_near();

	next_cell = (i + 1) * cells_collums_count + j - 1;
	if (next_cell > 0 && next_cell < cells.size())
		cells[next_cell]->new_mine_near();

	next_cell = (i + 1) * cells_collums_count + j - 1;
	if (next_cell > 0 && next_cell < cells.size())
		cells[next_cell]->new_mine_near();
}




//OTHER
Field::Field(std::pair<float, float> position, int size, std::string field_texture, int level)
{
	set_sprite_coords(position);
	set_sprite_size(size);
	set_texture(field_texture);

	create_cells(level * 8);


}


