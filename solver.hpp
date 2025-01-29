#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "puzzle_objects.hpp"
#include "print.hpp"

using EvaluationFunction = int(*)(Node*); // define function pointer shorthand

/*
    evaluation functions for queueing based on priority on f(n)
*/
int EvalUniformCostSearch(Node* node);

int HeuristicMisplacedTiles(const puzzle_state& state); // DON'T COUNT BLANK TILE STUPID
int EvalAStarMisplacedTiles(Node* node);

int HeuristicManhattanDistance(const puzzle_state& state); // DON'T COUNT BLANK TILE STUPID
int EvalAStarManhattanDistance(Node* node);

Node* GeneralSearch(Node* initial_node, EvaluationFunction eval);

#endif // SOLVER_HPP