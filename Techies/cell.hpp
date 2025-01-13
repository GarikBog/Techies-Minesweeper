#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS


class Cell {

private:
	// COORDS && SIZE
	float x = 0, y = 0;
	int size = 0;

	//TEXTURE
	int texture_file_pos_x = 0;
	int texture_file_pos_y = 0;
	sf::Texture texture;
	sf::Sprite sprite;


	//TECH
	int mines_near = 0;
	bool mine = false;

public:

	//SETTERS
	void set_pos(double new_x, double new_y);
	void set_pos(std::pair<double,double> new_coords);

	void set_size(int size);
	void set_texture_pos(std::pair<int, int> pos);
	void set_texture(std::string new_texture);


	//GETTERS
	std::pair<double, double> get_coords() const;
	double get_x() const;
	double get_y() const;

	int get_size() const;

	int get_mines_near() const;

	
	//TECH
	void new_mine_near();
	bool is_mine();
	void draw(sf::RenderWindow& window);



	//OTHER
	Cell(double x, double y, int size, std::string texture_file);

};


