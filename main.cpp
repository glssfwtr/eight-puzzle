#include <array>
#include <iostream>
#include <string>
#include <stdexcept>

#include "solver.hpp"
#include "test.hpp"

void ParsePuzzleStateArg(const std::string& arg_puzzle_string, puzzle_state& state)
{
  if ( arg_puzzle_string.length() != (rows * columns) )
  {
    std::cout << "Invalid puzzle length, must be "<< (rows * columns) << " digits.\n";

    return;
  }

  std::size_t current_string_index = 0;

  for ( std::size_t i = 0; i < rows; ++i )
  {
    for ( std::size_t j = 0; j < columns; ++j )
    {
      if ( !isdigit(arg_puzzle_string[current_string_index]) )
      {
        std::cout << "Invalid character in puzzle state input, must be digits [0-9]."; // actually must be [0-8], too lazy

        return;
      }

      state[i][j] = arg_puzzle_string[current_string_index] - '0'; // diff ascii char

      ++current_string_index;
    }
  }

  return;
}

int main(int argc, char* argv[])
{
  if ( argc != 3 )
  {
    std::cout << "Usage: " << argv[0] << " <9-digit puzzle state> <search option (1-3)>\n";
    return -1;
  }

  std::string puzzle_input = argv[1];

  int option = std::stoi(argv[2]);

  if ( option < 1 || option > 3 )
  {
    std::cout << "Invalid search option. Must be 1 (UCS), 2 (A* Misplaced Tiles), or 3 (A* Manhattan Distance).\n";
    return 1;
  }

  puzzle_state puzzle_loader;

  ParsePuzzleStateArg(puzzle_input, puzzle_loader);


  Node* problem_node = new Node(nullptr, 0, 0, puzzle_loader);
  Node* solution = nullptr;

  switch (option)
  {
  case 1:
    std::cout << "UCS\n";
    solution = GeneralSearch(problem_node, EvalUniformCostSearch);
    break;

  case 2:
    std::cout << "MISPLACED\n";
    solution = GeneralSearch(problem_node, EvalAStarMisplacedTiles);
    break;

  case 3:
    std::cout << "MANHATTAN\n";
    solution = GeneralSearch(problem_node, EvalAStarManhattanDistance);
    break;

  default:
    break;
  }

  if ( solution != nullptr )
  {
    std::cout << "Solution found: d = " << solution->node_depth << ", nodes checked: " << nodes_popped << ", max Q size: " << max_queue_size << "\n";
    PrintNodeParentTrace(solution);
  }
  else
  {
    std::cout << "No solution found :(\n";
  }

  return 0;
}
