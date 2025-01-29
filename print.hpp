#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>
#include <vector>

#include "puzzle_objects.hpp"

void PrintComparison(const puzzle_state& lhs, const puzzle_state& rhs);
void PrintPuzzleState(const puzzle_state& state);
void PrintNodeParentTrace(const Node* node);

#endif // PRINT_HPP