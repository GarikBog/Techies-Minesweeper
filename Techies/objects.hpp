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
	std::pair<float, float> get_pos;
	float get_x();
	float get_y();
	sf::FloatRect get_collision();

	std::pair<int, int> get_scale();
	int get_wight();
	int get_height();


	//Tech & other
	void draw(sf::RenderWindow& window);

	Object(std::pair<float, float> pos, std::pair<int, int> scale, std::string texture_file);
	



};