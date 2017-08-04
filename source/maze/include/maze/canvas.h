
#pragma once

#include <maze/maze_api.h>
#include <Color.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
namespace canvas {

const int WALL_THICKNESS = 2;
const int ROOM_SIZE = 26;
const sf::Color ROOM_COLOR = sf::Color::Black;
const sf::Color WALL_COLOR = sf::Color::Cyan;
const sf::Color BUILDER_COLOR = sf::Color::Black;
const sf::Color CURRENT_ROOM_POINTER_COLOR = sf::Color::Yellow;
const int CURRENT_ROOM_POINTER_SIZE = 6;

class MAZE_API Canvas final {
 public:
  explicit Canvas(const Maze&,
                  const sf::Window&,
                  const std::Vector<Position>&,
                  const std::Vector<Position>&,
                  const std::string);


  // Member functions

void draw_room(const Room& room, const int size = ROOM_SIZE, cont sf::Color& color = ROOM_COLOR );
void draw_position(const Room&, room, const int position_size = CURRENT_ROOM_POINTER_SIZE, cont sf::Color& color = CURRENT_ROOM_POINTER_COLOR );

void color_room(const Room&, room, const int size = ROOM_SIZE, cont sf::Color& color = ROOM_COLOR );
void draw_wall(const Room& room, const Direction side, cont sf::Color& color = WALL_COLOR );
void draw_all_walls(const Room& room,  cont sf::Color& color );
void draw_walls(const Room& room,  cont sf::Color& color );
void draw_builder_path();
void draw_solver_path();
int to_canvas_coordinate(int room_coordinate);
void draw_maze(bool built);

  // private:

  Maze _maze;
  sf::Window  _window;
  std::vector<Room> _rooms;
  std::vector<Position> _builder_path;
  std::vector<Position> _solver_path;
  // Solver _solver;
  // Builder _builder;
  std::string window_title;
  int width;
  int height;
};

}  // namespace maze
