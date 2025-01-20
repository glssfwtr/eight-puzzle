#include "test.hpp"

void InitializerTests()
{
  std::cout << "first " << InsertState(problem_state) << std::endl;
  std::cout << "second " << InsertState(problem_state) << std::endl;

  std::cout << "first " << InsertState(correct_state) << std::endl;
  std::cout << "second " << InsertState(correct_state) << std::endl;

  std::cout << "first " << InsertState(hard_puzzle_state) << std::endl;
  std::cout << "second " << InsertState(hard_puzzle_state) << std::endl;

  std::cout << "first " << InsertState(some_state) << std::endl;
  std::cout << "second " << InsertState(some_state) << std::endl;

  std::cout << "third " << InsertState(correct_state) << std::endl;
  std::cout << "third " << InsertState(problem_state) << std::endl;
  std::cout << "third " << InsertState(hard_puzzle_state) << std::endl;
  std::cout << "third " << InsertState(some_state) << std::endl;


  std::cout << CheckGoalState(problem_state) << std::endl;
  std::cout << CheckGoalState(correct_state) << std::endl;
  std::cout << CheckGoalState(hard_puzzle_state) << std::endl;
  std::cout << CheckGoalState(some_state) << std::endl;

  // PrintPuzzle(correct_state);
  // PrintPuzzle(problem_state);
  // PrintPuzzle(hard_puzzle_state);
  // PrintPuzzle(some_state);

  PrintComparison(problem_state, problem_state);
  PrintComparison(problem_state, goal_state);
  PrintComparison(hard_puzzle_state, goal_state);
  PrintComparison(correct_state, goal_state);

  return;
}

void NodePointerTests()
{
  Node* node = new Node();

  PrintPuzzle(node->state);

  delete node;

  return;
}

void TestTimer()
{
  ChronoTimer timer;

  return;
}