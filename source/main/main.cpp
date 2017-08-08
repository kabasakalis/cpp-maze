
#include <iostream>
#include <sstream>
#include <boost/optional/optional_io.hpp>
#include <baselib/baselib.h>
#include "maze/base.h"
#include "maze/builder.h"
#include "maze/maze.h"
#include "maze/solver.h"
#include "maze/canvas.h"
#include <SFML/Window.hpp>

using namespace std;
using namespace maze;
using namespace utils;

int main(int argc, char* argv[]) {
  // Argument guard, 3 arguments are needed. (The program name is the first argument always).
  if (argc != 4) {
    printf("Invalid number of arguments. \n");
    printf("Example: ./build/cppmaze  40 30 0 \n");
    printf("The above command will build a 40 by 30 maze and draw the built path. \n");
    printf("Change the last argument to 1 to draw the solved path. \n");
  return 0;
  }

  int maze_columns{10}, maze_rows{10}, mode{1};

  std::istringstream columns_stream(argv[1]);
  std::istringstream rows_stream(argv[2]);
  std::istringstream mode_stream(argv[3]);

  bool valid_integers = (columns_stream >> maze_columns) &&
                        (rows_stream >> maze_rows) && (mode_stream >> mode);

  bool valid_column_range =
      (maze_columns >= COLUMNS_MIN) && (maze_columns <= COLUMNS_MAX);
  bool valid_row_range = (maze_rows >= ROWS_MIN) && (maze_rows <= ROWS_MAX);
  bool valid_mode_range = (mode == 0) || (mode == 1);

  if (valid_integers && valid_row_range && valid_column_range &&
      valid_mode_range) {

    // Initialize the maze.
    Maze maze{maze_columns, maze_rows};

    const Position DEFAULT_START_POSITION{1, 1};
    const Position DEFAULT_GOAL_POSITION{maze_columns, maze_rows};

    // I  could make these arguments, so that user can define start and goal.
    // I  just leave it as the two opposite corners of the maze for now.
    auto start_position = DEFAULT_START_POSITION;
    auto goal_position = DEFAULT_GOAL_POSITION;

    Builder builder{maze};
    builder.build_maze();
    Solver solver{builder.maze(), start_position, goal_position};
    solver.solve_maze();

    sf::RenderWindow window{
        sf::VideoMode(static_cast<unsigned int>(maze.columns() * ROOM_SIZE),
                      static_cast<unsigned int>(maze.rows() * ROOM_SIZE)),
        "C++ Maze"};

    // You can control the speed of the animation with this setting.
    window.setFramerateLimit(30);
    // Intialize the canvas.
    Canvas canvas{builder.maze(), builder.path(), solver.path()};
    // Draw solver or builder path based on mode argument.
    canvas.draw_path(window, start_position, goal_position, static_cast<Mode>(mode));

  } else {
    printf( "Invalid arguments, please enter integers in the following range: \n");
    printf("First argument, Columns: From %i to %i.\n", COLUMNS_MIN, COLUMNS_MAX);
    printf("Second argument, Rows: From %i to %i.\n", ROWS_MIN, ROWS_MAX);
    printf("Third argument, Mode:  %i (Build) or %i (Solve).\n", Mode::BUILD, Mode::SOLVE);
  }

  return 0;
}
