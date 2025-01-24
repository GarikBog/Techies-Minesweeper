#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS

class Object {

protected:
	//Pos & size
	float x = 0, y = 0;
	int width = 0, height = 0;

	sf::Texture texture;
	sf::IntRect texture_rect;
	sf::Sprite sprite;


	Object();

public:
	//Setters
	void set_pos(std::pair<float, float> pos);
	void set_pos(float x, float y);
	void set_x(float x);
	void set_y(float y);

	void set_scale(std::pair<int, int> size);
	void set_scale(int width, int height);
	void set_width(int width);
	void set_height(int height);

	void set_texture(std::string texture_file);
	void set_texture_rect(sf::IntRect rect);

	//Getters
	std::pair<float, float> get_pos() const;
	float get_x() const;
	float get_y() const;
	sf::FloatRect get_collision() const;

	std::pair<int, int> get_scale() const;
	int get_width() const;
	int get_height() const;


	//Tech & other
	void draw(sf::RenderWindow& window);

	Object(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file);
	



};


class ClickableObject : public Object {


public:

	bool click(sf::RenderWindow& window);

	ClickableObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file);
};




class CounterObject : public Object {

protected:

	sf::Sprite left_cell, middle_cell,right_cell;


public:

	//Setters
	void set_pos(std::pair<float, float> pos);
	void set_pos(float x, float y);
	void set_x(float x);
	void set_y(float y);

	void set_scale(std::pair<int, int> size);
	void set_scale(int width, int height);
	void set_width(int width);
	void set_height(int height);

	void set_texture(std::string texture_file);
	void set_texture_rect(sf::IntRect rect);



	//Tech & other
	virtual void update() = 0;
	void draw(sf::RenderWindow& window);

	CounterObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file);


};


class TimerObject : public CounterObject {

private:
	bool run = false;
	unsigned int seconds = 0,extra_time = 0;

	sf::Clock timer;
	

public:

	//Setters
	void set_seconds(unsigned int extra_time);
	
	//Getters
	unsigned int get_seconds() const;
	
	
	//Tech & Other
	void reset();
	void start();
	void update();
	
	TimerObject (std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file);
	TimerObject (std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file,unsigned int extra_time);
};




class MinesCounterObject: public CounterObject {
private:

	unsigned int mines = 0;
	bool mine_change = false;

public:
	
	
	//Setters

	void set_mines(unsigned int count);

	//Getters
	unsigned int get_mines() const;

	//Tech
	void add_mine();
	void remove_mine();
	void update();


	MinesCounterObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file);
	MinesCounterObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file,unsigned int mines);

};
