#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "puzzle_objects.hpp"
#include "print.hpp"

using EvaluationFunction = int(*)(Node*);

int EvalUniformCostSearch(Node* node);
bool CheckGoalState(const puzzle_state& state);
bool CheckRepeated(const puzzle_state& state); // returns false if
bool InsertState(const puzzle_state& state); // returns false if already exists as insert
Node* GeneralSearch(Node* initial_node, EvaluationFunction eval);

#endif // SOLVER_HPP