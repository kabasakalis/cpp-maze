
#pragma once

#include <maze/maze_api.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include  "maze/maze.h"

using namespace maze;
using namespace utils;

namespace maze {

const int WALL_THICKNESS = 2;
const int ROOM_SIZE = 26;
const sf::Color ROOM_COLOR = sf::Color::Black;
const sf::Color WALL_COLOR = sf::Color::Cyan;
const sf::Color BUILDER_COLOR = sf::Color::Black;
const sf::Color CURRENT_ROOM_POINTER_COLOR = sf::Color::Yellow;
const int CURRENT_ROOM_POINTER_SIZE = 6;
const Position NULL_POSITION = Position{0,0};

class MAZE_API Canvas final {
 public:
  explicit Canvas(const Maze&,
                  const std::vector<Position>&,
                  const std::vector<Position>&);

  void draw_path( sf::RenderWindow&, Position start_position , Position goal_position, Mode mode = Mode::SOLVE );

  private:
  void draw_room( sf::RenderWindow&,   Room& room, const int size = ROOM_SIZE, const sf::Color& color = ROOM_COLOR );
  void draw_position(sf::RenderWindow&, const Room& room, const int position_size = CURRENT_ROOM_POINTER_SIZE,
      const sf::Color& color = CURRENT_ROOM_POINTER_COLOR );
  void color_room( sf::RenderWindow&, Room& room, const int size = ROOM_SIZE, const sf::Color& color = ROOM_COLOR );
  void draw_wall( sf::RenderWindow&, Room& room, const Direction side, const sf::Color& color = WALL_COLOR );
  void draw_all_walls(sf::RenderWindow&, Room& room, const sf::Color& color = WALL_COLOR );
  void draw_walls(sf::RenderWindow&, Room& room, const sf::Color& color = WALL_COLOR );
  void break_walls(sf::RenderWindow&, Room& room, const sf::Color& color = ROOM_COLOR );
  void draw_builder_path();
  void draw_solver_path();
  int to_canvas_coordinate(int room_coordinate);
  void draw_built_maze(sf::RenderWindow&);
  void draw_solved_maze(sf::RenderWindow&);
  bool is_null(const Position& position);
  Maze _maze;
  std::vector<Room> _rooms;
  std::vector<Position> _builder_path;
  std::vector<Position> _solver_path;
  std::vector<Position> _visited_positions;
  int _width;
  int _height;

};

}  // namespace maze
