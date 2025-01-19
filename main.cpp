#include <array>
#include <iostream>
#include <queue>

#include "solver.hpp"

int main()
{
  std::cout << "Hello, World!\n";

  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

  puzzle_state correct_state = {1, 2, 3, 4, 5, 6, 7, 8, 0};
  puzzle_state problem_state = {2, 1, 3, 4, 5, 7, 6, 0, 8};
  puzzle_state hard_state = {8, 7, 1, 6, 0, 2, 5, 4, 3};




  std::cout << CheckState(correct_state) << std::endl;
  std::cout << CheckState(problem_state) << std::endl;
  std::cout << CheckState(hard_state) << std::endl;

  return 0;
}
