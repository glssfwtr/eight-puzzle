#ifndef PRINT_HPP
#define PRINT_HPP

#include <array>

using puzzle_state = std::array<int, 9>;

void print_puzzle(const puzzle_state& state);

#endif // PRINT_HPP