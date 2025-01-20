#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <iostream>
#include <queue>
#include <vector>

#include "custom_dictionary.hpp"

using puzzle_state = std::vector<int>;

void Print_Puzzle(const puzzle_state& state);
bool CheckRepeated(const puzzle_state& state); // returns false if
bool InsertState(const puzzle_state& state); // returns false if already exists as insert
bool CheckGoalState(const puzzle_state& state);
puzzle_state UniformCostSearch(puzzle_state start_state);

#endif // SOLVER_HPP