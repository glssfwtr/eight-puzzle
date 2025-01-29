#include <array>
#include <iostream>

#include "solver.hpp"
#include "test.hpp"

int main()
{
  int option = 1;
  puzzle_state puzzle_loader = doable;
  Node* problem_node = new Node(nullptr, 0, 0, puzzle_loader);

  Node* solution = nullptr;

  if ( option == 1 )
  {
    solution = GeneralSearch(problem_node, EvalUniformCostSearch);
  }
  else if ( option == 2 )
  {
    solution = GeneralSearch(problem_node, EvalAStarMisplacedTiles);
  }
  else if ( option == 3 )
  {
    solution = GeneralSearch(problem_node, EvalAStarManhattanDistance);
  }



  if (solution != nullptr)
  {
    std::cout << "Solution found: d = " << solution->node_depth << ", f = " << solution->f << "\n";
    std::cout << "nodes popped: " << nodes_popped << ", max queue size: " << max_queue_size << "\n";

    PrintNodeParentTrace(solution);
  }
  else
  {
    std::cout << "No solution found\n";
  }


  return 0;
}
