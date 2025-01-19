#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <iostream>
#include <array>

using puzzle_state = std::array<int, 9>;

bool CheckState(const puzzle_state& state);
puzzle_state UniformCostSearch(puzzle_state start_state);

#endif // SOLVER_HPP