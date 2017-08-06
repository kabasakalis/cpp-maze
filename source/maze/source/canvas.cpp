
//#include <memory>  // unique_ptr
#include "maze/canvas.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <boost/optional.hpp>

// #include <VertexArray.hpp>
using namespace maze;
using namespace utils;

namespace maze {

// Constructor
Canvas::Canvas(const Maze& maze, const std::vector<Position>& builder_path,
               const std::vector<Position>& solver_path)
    : _maze{maze}, _builder_path{builder_path}, _solver_path{solver_path}{
  _width = _maze.columns() * ROOM_SIZE;
  _height = _maze.rows() * ROOM_SIZE;
  _rooms = _maze.rooms();

}

void Canvas::draw_path(sf::RenderWindow& window, Position start_position, Position goal_position, Mode mode ) {
   _visited_positions.clear();
  auto path =  (mode == Mode::BUILD) ?  _builder_path : _solver_path;
  while (window.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed) window.close();
    }
    window.clear(sf::Color::Black);
    Position position{NULL_POSITION};
    boost::optional<Room*> room;
    // draw rooms
       if (mode == Mode::SOLVE) {
    draw_solved_maze(window);
    // Paint start and goal rooms blue and red respectively.
    auto start_room = _maze.find_room(start_position);
    auto goal_room = _maze.find_room(goal_position);
    color_room(window, **start_room, ROOM_SIZE, sf::Color::Blue);
    color_room(window, **goal_room, ROOM_SIZE, sf::Color::Red);
       }else {
        draw_built_maze(window);
       };

    // draw builder
    position = !path.empty() ? path.front() : NULL_POSITION;
    if (!is_null(position)) _visited_positions.push_back(position);
    if (!path.empty()) path.erase(path.begin());
    // draw the builder,if position is null it's the last position.
    room = !is_null(position) ? _maze.find_room(position)
                              : _maze.find_room(_visited_positions.back());
    if (room != boost::none) draw_position(window, **room);
    // end the current frame
    window.display();
  }  // window open
}


bool Canvas::is_null(const Position& position) {
  return (position == NULL_POSITION);
}

// Member functions
int Canvas::to_canvas_coordinate(int room_coordinate) {
  return (room_coordinate - 1) * ROOM_SIZE;
}

void Canvas::draw_built_maze(sf::RenderWindow& window) {
  for (auto room : _rooms) {
    draw_room(window, room);
    (std::find(_visited_positions.begin(), _visited_positions.end(),
               room.position()) != _visited_positions.end())
        ? draw_walls(window, room)
        : draw_all_walls(window, room);
  }
}
void Canvas::draw_solved_maze(sf::RenderWindow& window) {
  for (auto room : _rooms) {
    draw_room(window, room);
    draw_walls(window, room);
  }
}

void Canvas::draw_room(sf::RenderWindow& window, const Room& room,
                       const int size, const sf::Color& color) {
  auto canvas_x = to_canvas_coordinate(room.x());
  auto canvas_y = to_canvas_coordinate(room.y());

  sf::VertexArray quad(sf::Quads, 4);

  quad[0].position = sf::Vector2f(canvas_x, canvas_y);
  quad[1].position = sf::Vector2f(canvas_x + size, canvas_y);
  quad[2].position = sf::Vector2f(canvas_x + size, canvas_y + size);
  quad[3].position = sf::Vector2f(canvas_x, canvas_y + size);

  // define its texture area to be a 25x50 rectangle starting at (0, 0)
  quad[0].color = color;
  quad[1].color = color;
  quad[2].color = color;
  quad[3].color = color;

  window.draw(quad);
}

void Canvas::draw_position(sf::RenderWindow& window, const Room& room,
                           const int position_size, const sf::Color& color) {
  auto pointer_x = to_canvas_coordinate(room.x());
  auto pointer_y = to_canvas_coordinate(room.y());

  sf::VertexArray quad(sf::Quads, 4);

  quad[0].position =
      sf::Vector2f(pointer_x + ROOM_SIZE / 2 - position_size / 2,
                   pointer_y + ROOM_SIZE / 2 - position_size / 2);
  quad[1].position =
      sf::Vector2f(pointer_x + ROOM_SIZE / 2 + position_size / 2,
                   pointer_y + ROOM_SIZE / 2 - position_size / 2);
  quad[2].position =
      sf::Vector2f(pointer_x + ROOM_SIZE / 2 + position_size / 2,
                   pointer_y + ROOM_SIZE / 2 + position_size / 2);
  quad[3].position =
      sf::Vector2f(pointer_x + ROOM_SIZE / 2 - position_size / 2,
                   pointer_y + ROOM_SIZE / 2 + position_size / 2);

  // define its texture area to be a 25x50 rectangle starting at (0, 0)
  quad[0].color = color;
  quad[1].color = color;
  quad[2].color = color;
  quad[3].color = color;

  window.draw(quad);
}

void Canvas::color_room(sf::RenderWindow& window, const Room& room,
                        const int size, const sf::Color& color) {
  draw_room(window, room, size, color);
  draw_walls(window, room);
}

void Canvas::draw_wall(sf::RenderWindow& window, const Room& room,
                       const Direction side, const sf::Color& color) {
  auto canvas_x = to_canvas_coordinate(room.x());
  auto canvas_y = to_canvas_coordinate(room.y());
  sf::Vector2f top_left, top_right, bottom_right, bottom_left;

  switch (side) {
    case Direction::LEFT: {
      top_left = sf::Vector2f(canvas_x, canvas_y);
      top_right = sf::Vector2f(canvas_x + WALL_THICKNESS, canvas_y);
      bottom_right =
          sf::Vector2f(canvas_x + WALL_THICKNESS, canvas_y + ROOM_SIZE);
      bottom_left = sf::Vector2f(canvas_x, canvas_y + ROOM_SIZE);
      break;
    }
    case Direction::RIGHT: {
      top_left = sf::Vector2f(canvas_x + ROOM_SIZE - WALL_THICKNESS, canvas_y);
      top_right = sf::Vector2f(canvas_x + ROOM_SIZE, canvas_y);
      bottom_right = sf::Vector2f(canvas_x + ROOM_SIZE, canvas_y + ROOM_SIZE);
      bottom_left = sf::Vector2f(canvas_x + ROOM_SIZE - WALL_THICKNESS,
                                 canvas_y + ROOM_SIZE);

      break;
    }
    case Direction::DOWN: {
      top_left = sf::Vector2f(canvas_x, canvas_y + ROOM_SIZE - WALL_THICKNESS);
      top_right = sf::Vector2f(canvas_x + ROOM_SIZE,
                               canvas_y + ROOM_SIZE - WALL_THICKNESS);
      bottom_right = sf::Vector2f(canvas_x + ROOM_SIZE, canvas_y + ROOM_SIZE);
      bottom_left = sf::Vector2f(canvas_x, canvas_y + ROOM_SIZE);

      break;
    }
    case Direction::UP: {
      top_left = sf::Vector2f(canvas_x, canvas_y);
      top_right = sf::Vector2f(canvas_x + ROOM_SIZE, canvas_y);
      bottom_right =
          sf::Vector2f(canvas_x + ROOM_SIZE, canvas_y + WALL_THICKNESS);
      bottom_left = sf::Vector2f(canvas_x, canvas_y + WALL_THICKNESS);
      break;
    }
    default: { break; }
  }

  sf::VertexArray quad(sf::Quads, 4);

  quad[0].position = top_left;
  quad[1].position = top_right;
  quad[2].position = bottom_right;
  quad[3].position = bottom_left;

  // define its texture area to be a 25x50 rectangle starting at (0, 0)
  quad[0].color = color;
  quad[1].color = color;
  quad[2].color = color;
  quad[3].color = color;

  window.draw(quad);
}

void Canvas::draw_walls(sf::RenderWindow& window, const Room& room,
                        const sf::Color& color) {
  for (auto side : DIRECTIONS) {
    auto exits = room.available_exits();
    auto it = find_if(exits.begin(), exits.end(),
                      [side](const Direction& exit) { return exit == side; });
    if (it == exits.end()) draw_wall(window, room, side, color);
  };
}

void Canvas::break_walls(sf::RenderWindow& window, const Room& room,
                         const sf::Color& color) {
  for (auto side : DIRECTIONS) {
    auto exits = room.available_exits();
    auto it = find_if(exits.begin(), exits.end(),
                      [side](const Direction& exit) { return exit == side; });
    if (it != exits.end()) draw_wall(window, room, side, color);
  };
}

void Canvas::draw_all_walls(sf::RenderWindow& window, const Room& room,
                            const sf::Color& color) {
  for (auto side : DIRECTIONS) {
    draw_wall(window, room, side, color);
  };
}

}  // namespace maze
