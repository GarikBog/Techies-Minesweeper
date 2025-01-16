#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS

#ifndef STD_VECTOR
#include<vector>
#define STD_VECTOR
#endif // !STD_VECTOR

#ifndef CELL
#include"cell.hpp"
#define CELL
#endif // !CELL

#ifndef STRING
#include<string>
#define STRING
#endif // STRING










class Field {

private:
	// COORDS && SIZE
	float sprite_x = 0, sprite_y = 0;
	int sprite_size = 0,cell_size = 0;

	//TEXTURE
	sf::Texture texture;
	sf::Sprite sprite;


	//TECH
	int hidden_cells = 0;
	int hidden_mines = 0;
	
	std::vector<Cell*> cells;
	
	Cell& find_cell_under_mouse(sf::Vector2i mouse_pos);
	bool open_cell(Cell& cell);
	void safe_open_cell(Cell& cell);
	void create_cells(int count);


public:
	//SETTERS
	void set_sprite_coords(std::pair<float,float> coords);
	void set_sprite_coords(float x, float y);
	void set_sprite_x(float x);
	void set_sprite_y(float y);

	void set_sprite_size(int size);

	void set_texture(std::string texture_file);

	//GETTERS
	std::pair<float, float> get_pos() const;
	float get_x() const;
	float get_y() const;

	int get_size() const;

	int get_hidden_cells() const;
	int get_hidden_mines() const;


	//TECH

	void draw(sf::RenderWindow& window);
	void set_mines(int count);
	bool click(sf::Vector2i mouse_pos, bool flag);

	//OTHER


	Field(std::pair<float, float> position, int size,std::string field_texture, int level);





	
};
