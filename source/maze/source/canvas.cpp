
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
               const std::vector<Position>& solver_path )
    : _maze{maze}, _builder_path{builder_path}, _solver_path{solver_path} {
  _width = _maze.columns() * ROOM_SIZE;
  _height = _maze.rows() * ROOM_SIZE;
  _rooms = _maze.rooms();
  NULL_POSITION.x = 0;
  NULL_POSITION.y = 0;
}

void Canvas::render(sf::RenderWindow& window) {
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);
  // run the program as long as the window is open

  std::vector<Position> visited_positions;
  while (window.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed) window.close();
    }

    // draw_maze(window, true);
    // clear the window with black color
    window.clear(sf::Color::Black);

    // draw everything here...
    // window.draw(...);

    // window.draw(shape);

    Position previous_position{NULL_POSITION};
    Position position{NULL_POSITION};
    boost::optional<Room*> room;
    previous_position = !visited_positions.empty() ? visited_positions.back() :  NULL_POSITION;
    position = !_builder_path.empty() ? _builder_path.front() : NULL_POSITION;
    if (!is_null(position)) visited_positions.push_back(position);
    if (!_builder_path.empty()) _builder_path.erase(_builder_path.begin());
    if ( is_null(position)) room = _maze.find_room(position);
    if (room != boost::none) {
      draw_room(window, **room);
      draw_walls(window, **room);
      draw_position(window, **room);
    };

    auto previous_room = (!is_null(previous_position)) ? _maze.find_room(previous_position) : boost::none;
    if (previous_room != boost::none) draw_position(window, **previous_room);

  // end the current frame
  window.display();
}//window open
}

// void Canvas::draw_builder_path() {
//   // previous_position = visited_positions.last
//   // visited_positions << position = builder.path.shift
//   // if position
//   //   room = maze.find_room(position)
//   //   draw_room(room, ROOM_SIZE, BUILDER_COLOR)
//   //   draw_walls(room, WALL_COLOR)
//   //   draw_position room
//   //   previous_room = maze.find_room(previous_position)
//   //   draw_position(previous_room,
//   //     CURRENT_ROOM_POINTER_SIZE,
//   //     BUILDER_COLOR) if previous_room
//   //
// }
// def draw_builder_path
//   visited_positions = []
//   update do
//     previous_position = visited_positions.last
//     visited_positions << position = builder.path.shift
//     if position
//       room = maze.find_room(position)
//       draw_room(room, ROOM_SIZE, BUILDER_COLOR)
//       draw_walls(room, WALL_COLOR)
//       draw_position room
//       previous_room = maze.find_room(previous_position)
//       draw_position(previous_room,
//         CURRENT_ROOM_POINTER_SIZE,
//         BUILDER_COLOR) if previous_room
//     end
//     ::Kernel.sleep(@sleep || 0.0)
//   end
// end

// void Canvas::draw_solver_path() {}
// // def draw_solver_path
// //   visited_positions = []
// //   color_room(solver.starting_position, ROOM_SIZE, 'red')
// //   color_room(solver.goal_position, ROOM_SIZE, 'blue')
// //   update do
// //     previous_position = visited_positions.last
// //     visited_positions << position = solver.path.shift
// //     if position
// //       room = maze.find_room(position)
// //       draw_position room
// //       previous_room = maze.find_room(previous_position)
// //       draw_position(previous_room, CURRENT_ROOM_POINTER_SIZE, 'olive') if
// //       previous_room
// //     end
// //     ::Kernel.sleep(@sleep || 0.0)
// //   end
// // end

bool Canvas::is_null(const Position& position) {
  return (position == NULL_POSITION);
}

// Member functions
int Canvas::to_canvas_coordinate(int room_coordinate) {
  return (room_coordinate - 1) * ROOM_SIZE;
};

void Canvas::draw_maze(sf::RenderWindow& window, bool built) {
  for (auto room : _rooms) {
    draw_room(window, room);
    built ? draw_walls(window, room, WALL_COLOR) : draw_all_walls(window, room, WALL_COLOR);
  }
}

void Canvas::draw_room( sf::RenderWindow& window , const Room& room, const int size,
                       const sf::Color& color) {
  auto canvas_x = to_canvas_coordinate(room.x());
  auto canvas_y = to_canvas_coordinate(room.y());

  sf::VertexArray quad(sf::Quads, 4);

  quad[0].position = sf::Vector2f(canvas_x, canvas_y);
  quad[1].position = sf::Vector2f(canvas_x + ROOM_SIZE, canvas_y);
  quad[2].position = sf::Vector2f(canvas_x + ROOM_SIZE, canvas_y + ROOM_SIZE);
  quad[3].position = sf::Vector2f(canvas_x, canvas_y + ROOM_SIZE);

  // define its texture area to be a 25x50 rectangle starting at (0, 0)
  quad[0].color = color;
  quad[1].color = color;
  quad[2].color = color;
  quad[3].color = color;

  window.draw(quad);
}

void Canvas::draw_position( sf::RenderWindow& window, const Room& room, const int position_size,
                           const sf::Color& color) {
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

void Canvas::color_room( sf::RenderWindow& window, const Room& room, const int size,
                        const sf::Color& color) {
  auto pointer_x = to_canvas_coordinate(room.x());
  auto pointer_y = to_canvas_coordinate(room.y());
  draw_room(window, room, size, color);
}

void Canvas::draw_wall( sf::RenderWindow& window, const Room& room, const Direction side,
                       const sf::Color& color) {
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

void Canvas::draw_walls( sf::RenderWindow& window,  const Room& room, const sf::Color& color) {
  for (auto side : DIRECTIONS) {
    auto exits = room.available_exits();
    auto it = find_if(exits.begin(), exits.end(),
                      [side](const Direction& exit) { return exit == side; });
    if (it == exits.end()) draw_wall(window, room, side, color);
  };
}

void Canvas::draw_all_walls( sf::RenderWindow& window, const Room& room, const sf::Color& color) {
  for (auto side : DIRECTIONS) {
    draw_wall(window, room, side, color);
  };
}

}  // namespace maze
