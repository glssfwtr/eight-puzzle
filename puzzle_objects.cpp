#include "puzzle_objects.hpp"

std::vector<Node*> generate_successors(Node* current_node)
{
  static const std::array<std::pair<int, int>, 4> possible_puzzle_moves =
  {
    {
      {-1, 0}, // up
      {1, 0}, // down
      {0, -1}, // left
      {0, 1} // right
    }
  };

  std::vector<Node*> successor_nodes;

  const puzzle_state& state = current_node->current_puzzle_state; // load for tile manip

  int zero_row = -1;
  int zero_col = -1;

  // find empty tile to apply moves to
  for ( int i = 0; i < rows; ++i )
  {
    for (int j = 0; j < columns; ++j )
    {
      if ( state[static_cast<std::size_t>(i)][static_cast<std::size_t>(j)] == 0 )
      {
        zero_row = i;
        zero_col = j;
        break;
      }
    }

    if ( zero_row != -1 )
    {
      break; // exit outer loop if blank tile found
    }
  }

  // for each pair of moves in our possible moves list, generate a list of changes onto the current node and store as new nodes
  for ( const auto& [row_change, column_change] : possible_puzzle_moves )
  {
    int new_row = zero_row + row_change;
    int new_col = zero_col + column_change;

    // boundary check each pair of moves instead of having 4 if statements for each possible move
    if ( new_row >= 0 && new_row < rows && new_col >= 0 && new_col < columns )
    {
      puzzle_state new_state = state;
      std::swap(new_state[static_cast<std::size_t>(zero_row)][static_cast<std::size_t>(zero_col)],
                new_state[static_cast<std::size_t>(new_row)][static_cast<std::size_t>(new_col)]); // Move tile

      // Create new node
      Node* new_node = new Node(current_node, current_node->node_depth + 1, new_state);

      successor_nodes.push_back(new_node);
    }
  }

  return successor_nodes;
}