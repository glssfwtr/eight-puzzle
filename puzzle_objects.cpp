#include "puzzle_objects.hpp"

// true global scope
namespace puzzle_container
{
  states_dictionary visited_states;
  std::priority_queue<Node*, std::vector<Node*>, NodeDepthComparator> min_heap;
}

std::vector<Node *> GenerateSuccessors(Node *parent_node)
{
  static const std::array<std::pair<int, int>, 4> blank_movement =
  {
    {
      {-1, 0}, // up
      {1, 0}, // down
      {0, -1}, // left
      {0, 1}, // right
    }
  };

  std::vector<Node *> successor_nodes;

  int zero_row;
  int zero_column;

  const puzzle_state& parent_state = parent_node->current_puzzle_state;

  // find blank tile position in parent_state
  for ( std::size_t i = 0; i < rows; ++i )
  {
    for ( std::size_t j = 0; j < columns; ++j)
    {
      if ( parent_state[i][j] == 0 )
      {
        zero_row = static_cast<int>(i);
        zero_column = static_cast<int>(j);

        break;
      }
    }
  }

  // for each blank tile move, validate move and generate successor node
  for (const std::pair<int, int>& movement : blank_movement)
  {
    int new_zero_row = zero_row + movement.first;
    int new_zero_column = zero_column + movement.second;

    if ( new_zero_row >= 0 && new_zero_row < rows && new_zero_column >= 0 && new_zero_column < columns )
    {
      // new state starting off as parent state
      puzzle_state successor_state = parent_state;

      // swap blank tile with tile that was in the direction of movement
      std::swap(successor_state[static_cast<std::size_t>(zero_row)][static_cast<std::size_t>(zero_column)], successor_state[static_cast<std::size_t>(new_zero_row)][static_cast<std::size_t>(new_zero_column)]);

      Node* successor_node = new Node(parent_node, parent_node->node_depth + 1, successor_state);
      successor_nodes.push_back(successor_node);
    }
  }

  return successor_nodes;
}