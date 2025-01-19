#include <array>
#include <iostream>

#include "solver.hpp"

int main()
{
  std::cout << "Hello, World!\n";

  puzzle_state correct_state = {1, 2, 3, 4, 5, 6, 7, 8, 0};
  puzzle_state problem_state = {2, 1, 3, 4, 5, 7, 6, 0, 8};
  puzzle_state hard_state = {8, 7, 1, 6, 0, 2, 5, 4, 3};
  puzzle_state some_state = {2, 1, 3, 4, 5, 7, 6, 0, 8};

  std::cout << "first " << InsertState(correct_state) << std::endl;
  std::cout << "second " << InsertState(correct_state) << std::endl;

  std::cout << "first " << InsertState(problem_state) << std::endl;
  std::cout << "second " << InsertState(problem_state) << std::endl;

  std::cout << "first " << InsertState(hard_state) << std::endl;
  std::cout << "second " << InsertState(hard_state) << std::endl;

  std::cout << "third " << InsertState(correct_state) << std::endl;
  std::cout << "third " << InsertState(problem_state) << std::endl;
  std::cout << "third " << InsertState(hard_state) << std::endl;

  std::cout << CheckGoalState(correct_state) << std::endl;
  std::cout << CheckGoalState(problem_state) << std::endl;
  std::cout << CheckGoalState(hard_state) << std::endl;



  return 0;
}
