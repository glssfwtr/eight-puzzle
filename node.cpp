#include "node.hpp"

Node::Node()
{

}

Node::Node(puzzle_state& state)
{
  this->current_puzzle_state = state;
}

Node::~Node()
{

}
