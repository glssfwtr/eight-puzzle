#ifndef NODE_HPP
#define NODE_HPP

#include "puzzle_objects.hpp"

struct Node
{
  Node* parent;
  int heuristic_value;
  int node_depth; // depth of the node in the search space tree
  puzzle_state state;

  Node();
  ~Node();
};

#endif // NODE_HPP