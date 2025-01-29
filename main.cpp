#include <array>
#include <iostream>

#include "solver.hpp"
#include "test.hpp"

int main()
{
  // InitializerTests();
  // NodePointerReferenceSetTest();
  // PriorityQueueTest();
  // PriorityQueueSizeTest();
  // TestDictionary();
  // TestGeneratingSuccessor();
  puzzle_state puzzle_loader = problem_state1;
  Node* problem_node = new Node(nullptr, 0, 0, puzzle_loader);

  Node* solution = GeneralSearch(problem_node, EvalUniformCostSearch);

  PrintPuzzleState(solution->current_puzzle_state);



  return 0;
}
