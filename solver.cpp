#include "solver.hpp"

puzzle_state goal_state = {1, 2, 3, 4, 5, 6, 7, 8, 0};

bool CheckState(const puzzle_state& state)
{
  return ( state == goal_state );
}

puzzle_state UniformCostSearch(puzzle_state start_state)
{
  // todo

  return start_state;
}