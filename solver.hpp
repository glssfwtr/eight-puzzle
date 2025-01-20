#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <iostream>
#include <queue>
#include <vector>

#include "custom_dictionary.hpp"

constexpr puzzle_state goal_state =
{
  {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
  }
};

bool CheckRepeated(const puzzle_state& state); // returns false if
bool InsertState(const puzzle_state& state); // returns false if already exists as insert
bool CheckGoalState(const puzzle_state& state);
puzzle_state UniformCostSearch(puzzle_state& start_state);

#endif // SOLVER_HPP