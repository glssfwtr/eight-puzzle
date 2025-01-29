#include <array>
#include <iostream>

#include "solver.hpp"
#include "test.hpp"

int main()
{
  puzzle_state puzzle_loader = problem_state3;
  Node* problem_node = new Node(nullptr, 0, 0, puzzle_loader);

  Node* solution = GeneralSearch(problem_node, EvalUniformCostSearch);

  if (solution != nullptr)
  {
    std::cout << "Solution found: d = " << solution->node_depth << " f = " << solution->f << "\n";;

    PrintNodeParentTrace(solution);
  }
  else
  {
    std::cout << "No solution found\n";
  }


  return 0;
}
