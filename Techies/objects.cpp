#ifndef OBJECTS
#include "objects.hpp"
#define OBJECTS
#endif // !OBJECTS

#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM



// OBJECT
Object::Object() {}



void Object::set_pos(std::pair<float, float> pos)
{
	x = pos.first;
	y = pos.second;

	sprite.setPosition({ x,y });
}

void Object::set_pos(float x, float y)
{
	this->x = x;
	this->y = y;

	sprite.setPosition({ x,y });
}

void Object::set_x(float x)
{

	this->x = x;

	sprite.setPosition({ x,y });
}

void Object::set_y(float y)
{

	this->y = y;

	sprite.setPosition({ x,y });
}

void Object::set_scale(std::pair<int, int> size)
{
	width = size.first;
	height = size.second;

	sprite.setScale({
		width / sprite.getLocalBounds().width,
		height / sprite.getLocalBounds().height});
}

void Object::set_scale(int width, int height)
{
	this->width = width;
	this->height = height;

	sprite.setScale({
		width / sprite.getLocalBounds().width,
		height / sprite.getLocalBounds().height});
}

void Object::set_width(int width)
{
	this->width = width;

	sprite.setScale({
		width / sprite.getLocalBounds().width,
		height / sprite.getLocalBounds().height});
}

void Object::set_height(int height)
{
	this->height = height;

	std::cout << sprite.getLocalBounds().width << ' ' << sprite.getLocalBounds().height;
	sprite.setScale({
		width / sprite.getLocalBounds().width,
		height / sprite.getLocalBounds().height});
}

void Object::set_texture(std::string texture_file)
{
	if (!texture.loadFromFile("textures/objects/" + texture_file)) {
		texture.loadFromFile("textures/tech/error.jpg");
	}
	
	sprite.setTexture(texture);
}

void Object::set_texture_rect(sf::IntRect rect)
{

	sprite.setTextureRect(rect);
}

std::pair<float, float> Object::get_pos() const
{
	return {x,y};
}

float Object::get_x() const
{
	return x;
}

float Object::get_y() const
{
	return y;
}

sf::FloatRect Object::get_collision() const
{
	return sprite.getGlobalBounds();
}

std::pair<int, int> Object::get_scale() const
{
	return {width,height};
}

int Object::get_width() const
{
	return width;
}

int Object::get_height() const
{
	return height;
}

void Object::draw(sf::RenderWindow& window)
{
	window.draw(sprite);

}

Object::Object(std::pair<float, float> pos,std::pair<int,int> size, std::pair<int, int> scale, std::string texture_file)
{
	set_pos(pos);
	set_texture_rect({ 0,0,size.first,size.second });
	set_scale(scale);
	set_texture(texture_file);

}
// OBJECT




//ClickableObject
bool ClickableObject::click(sf::RenderWindow& window)
{
	sf::Vector2i mouse_pos = sf::Mouse::getPosition();
	
	return (
		mouse_pos.x > x &&
		mouse_pos.x < x + sprite.getGlobalBounds().width &&
		mouse_pos.y > y &&
		mouse_pos.y > y + sprite.getGlobalBounds().height
		);
}

ClickableObject::ClickableObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file): Object(pos,size,scale,texture_file)
{

}
//ClickableObject




//CounterObject
void CounterObject::set_pos(std::pair<float, float> pos)
{
	x = pos.first;
	y = pos.second;

	sprite.setPosition({ x,y });
	left_cell.setPosition({ x,y });
	middle_cell.setPosition({ x + width  / 3,y });
	right_cell.setPosition({ x + width * 2 / 3,y });

}

void CounterObject::set_pos(float x, float y)
{
	this->x = x;
	this->y = y;

	sprite.setPosition({ x,y });
	left_cell.setPosition({ x,y });
	middle_cell.setPosition({ x + width / 3,y });
	right_cell.setPosition({ x + width * 2 / 3,y });
}

void CounterObject::set_x(float x)
{

	this->x = x;

	sprite.setPosition({ x,y });
	left_cell.setPosition({ x,y });
	middle_cell.setPosition({ x + width / 3,y });
	right_cell.setPosition({ x + width * 2 / 3,y });
}

void CounterObject::set_y(float y)
{

	this->y = y;

	sprite.setPosition({ x,y });
	left_cell.setPosition({ x,y });
	middle_cell.setPosition({ x + width / 3,y });
	right_cell.setPosition({ x + width * 2 / 3,y });
}

void CounterObject::set_scale(std::pair<int, int> size)
{
	width = size.first;
	height = size.second;

	float local_width = sprite.getLocalBounds().width, local_height = sprite.getLocalBounds().height;
	sprite.setScale({
		width / local_width,
		height / local_height });

	left_cell.setScale({
		width / local_width,
		height / local_height });

	
	middle_cell.setScale({
		width / local_width,
		height / local_height });

	right_cell.setScale({
		width / local_width,
		height / local_height });
}

void CounterObject::set_scale(int width, int height)
{
	this->width = width;
	this->height = height;

	float local_width = sprite.getLocalBounds().width, local_height = sprite.getLocalBounds().height;
	sprite.setScale({
		width / local_width,
		height / local_height });

	left_cell.setScale({
		width / local_width,
		height / local_height });


	middle_cell.setScale({
		width / local_width,
		height / local_height });

	right_cell.setScale({
		width / local_width,
		height / local_height });
}

void CounterObject::set_width(int width)
{
	this->width = width;

	float local_width = sprite.getLocalBounds().width, local_height = sprite.getLocalBounds().height;
	sprite.setScale({
		width / local_width,
		height / local_height });

	left_cell.setScale({
		width / local_width,
		height / local_height });


	middle_cell.setScale({
		width / local_width,
		height / local_height });

	right_cell.setScale({
		width / local_width,
		height / local_height });
}

void CounterObject::set_height(int height)
{
	this->height = height;

	float local_width = sprite.getLocalBounds().width, local_height = sprite.getLocalBounds().height;
	sprite.setScale({
		width / local_width,
		height / local_height });

	left_cell.setScale({
		width / local_width,
		height / local_height });


	middle_cell.setScale({
		width / local_width,
		height / local_height });

	right_cell.setScale({
		width / local_width,
		height / local_height });
}

void CounterObject::set_texture(std::string texture_file)
{
	if (!texture.loadFromFile("textures/objects/" + texture_file)) {
		texture.loadFromFile("textures/tech/error.jpg");
	}

	sprite.setTexture(texture);
	left_cell.setTexture(texture);
	middle_cell.setTexture(texture);
	right_cell.setTexture(texture);

}
void CounterObject::set_texture_rect(sf::IntRect rect)
{
	Object::set_texture_rect(rect);

	left_cell.setTextureRect({ 0,0,20,35 });
	middle_cell.setTextureRect({ 0,0,20,35 });
	right_cell.setTextureRect({ 0,0,20,35 });

}

void CounterObject::draw(sf::RenderWindow& window) 
{
	//Object::draw(window);
	window.draw(left_cell);
	window.draw(middle_cell);
	window.draw(right_cell);

}


CounterObject::CounterObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file)
{
	set_texture(texture_file);
	set_texture_rect({ 0,0,size.first,size.second });
	set_scale(scale);
	set_pos(pos);
	
}

//CounterObject



//TimerObject
void TimerObject::set_seconds(unsigned int extra_time)
{
	this->extra_time = extra_time;
	seconds += extra_time;
}

unsigned int TimerObject::get_seconds() const
{
	return seconds;
}

void TimerObject::reset()
{
	extra_time = 0;
	seconds = 0;
	timer.restart();
}
void TimerObject::start()
{
	run = true;
}

void TimerObject::update()
{

	if (seconds > 998 || !run ) return;

	if (seconds != int(timer.getElapsedTime().asSeconds()) + extra_time) {
		std::cout <<seconds<<'\t' << "UPDATED!\n";
		seconds = int(timer.getElapsedTime().asSeconds()) + extra_time;

		right_cell.setTextureRect({ 60 + (seconds % 10) * 20,0,20,35 });

		if (seconds < 10) return;

		middle_cell.setTextureRect({ 60 + ((seconds/10) % 10) * 20,0,20,35 });

		if (seconds < 100) return;

		left_cell.setTextureRect({ 60 + ((seconds / 100) % 10) * 20,0,20,35 });

	}
}

TimerObject::TimerObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file): CounterObject(pos,size,scale,texture_file) {
	reset();
}
TimerObject::TimerObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, unsigned int extra_time):TimerObject(pos,size,scale,texture_file)
{
	set_seconds(extra_time);
}
//TimerObject



// MinesCounterObject
void MinesCounterObject::set_mines(unsigned int count)
{
	std::cout << "\nMines: " << count;
	mines = count;
	mine_change = true;
}

unsigned int MinesCounterObject::get_mines() const
{
	return mines;
}

void MinesCounterObject::add_mine()
{
	std::cout << "\nMine_Add\n";
	++mines;
	mine_change = true;
	std::cout << "\nMines: " << mines;
}

void MinesCounterObject::remove_mine()
{
	if (mines > 0) {
		std::cout << "\nMine_Remove\n";

		--mines;
		mine_change = true;
	}
	std::cout << "\nMine_not_Remove\n";

}

void MinesCounterObject::update()
{

	if (mines > 998 || !mine_change) return;
		std::cout << mine_change << '\t' << "CHANGE!\n";
		mine_change = false;

		right_cell.setTextureRect({ 60 + (mines % 10) * 20,0,20,35 });

		if (mines < 10) return;

		middle_cell.setTextureRect({ 60 + ((mines / 10) % 10) * 20,0,20,35 });

		if (mines < 100) return;

		left_cell.setTextureRect({ 60 + ((mines / 100) % 10) * 20,0,20,35 });


}

MinesCounterObject::MinesCounterObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file): CounterObject(pos,size,scale,texture_file)
{
}

MinesCounterObject::MinesCounterObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, unsigned int mines): MinesCounterObject(pos,size,scale,texture_file)
{
	set_mines(mines);
}

//MinesCounterObject