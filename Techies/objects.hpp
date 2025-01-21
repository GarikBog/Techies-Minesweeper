#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS

class Object {

private:
	//Pos & size
	float x = 0, y = 0;
	int wight = 0, height = 0;

	sf::Texture texture;
	sf::IntRect texture_rect;
	sf::Sprite sprite;

public:
	//Setters
	void set_pos(std::pair<float, float> pos);
	void set_pos(float x, float y);
	void set_x(float x);
	void set_y(float y);

	void set_scale(std::pair<int, int> size);
	void set_scale(int weight, int height);
	void set_wight(int weight);
	void set_height(int height);

	void set_texture(std::string texture_file);
	void set_texture_rect(sf::IntRect rect);

	//Getters
	std::pair<float, float> get_pos() const;
	float get_x() const;
	float get_y() const;
	sf::FloatRect get_collision() const;

	std::pair<int, int> get_scale() const;
	int get_wight() const;
	int get_height() const;


	//Tech & other
	void draw(sf::RenderWindow& window);

	Object(std::pair<float, float> pos, std::pair<int, int> scale, std::string texture_file);
	



};


class ClickableObject : public Object {


public:

	bool click(sf::RenderWindow& window);

	ClickableObject(std::pair<float, float> pos, std::pair<int, int> scale, std::string texture_file);
};




class TimerObject : Object {

private:

	unsigned int seconds = 0;
	sf::Clock timer;
	sf::Sprite left_cell, middle_cell,right_cell;


public:

	//Setters
	void set_seconds(unsigned int seconds);

	//Getters 
	unsigned int get_seconds() const;

	//Tech & other
	void update();
	void draw();

	TimerObject(std::pair<float, float> pos, std::pair<int, int> scale, std::string texture_file);

	TimerObject(std::pair<float, float> pos, std::pair<int, int> scale, std::string texture_file,unsigned int seconds);

};


