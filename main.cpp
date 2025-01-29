#include <array>
#include <iostream>

#include "solver.hpp"
#include "test.hpp"

int main()
{
  int option = 1;
  puzzle_state puzzle_loader = oh_boy;
  Node* problem_node = new Node(nullptr, 0, 0, puzzle_loader);

  Node* solution = nullptr;

  if ( option == 1 ) // UCS
  {
    solution = GeneralSearch(problem_node, EvalUniformCostSearch);
  }
  else if ( option == 2 ) // A* MISPLACED TILE HEURISTIC
  {
    solution = GeneralSearch(problem_node, EvalAStarMisplacedTiles);
  }
  else if ( option == 3 ) // A* MANHATTAN DISTANCE HEURISTIC
  {
    solution = GeneralSearch(problem_node, EvalAStarManhattanDistance);
  }

  if (solution != nullptr)
  {
    std::cout << "solution found: d = " << solution->node_depth << ", nodes checked: " << nodes_popped << ", max Q size: " << max_queue_size << "\n";

    PrintNodeParentTrace(solution);
  }
  else
  {
    std::cout << "No solution found\n";
  }


  return 0;
}
