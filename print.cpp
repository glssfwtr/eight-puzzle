#include "print.hpp"

void PrintPuzzleState(const puzzle_state& state)
{
  for ( const puzzle_state::value_type& row : state ) // each row of the state
  {
    for ( const int  element : row ) // each element of each row
    {
      std::cout << element << " ";
    }

    std::cout << "\n";
  }

  std::cout << "\n";

  return;
}

void PrintNodeParentTrace(const Node *node)
{
  const Node* node_iter = node;

  while (node_iter != nullptr)
  {
    std::cout << "g = " << node_iter->node_depth << ", h = " << node_iter->heuristic_value << ", f = " << node_iter->f << "\n";
    PrintPuzzleState(node_iter->current_puzzle_state);

    node_iter = node_iter->parent;
  }

  return;
}

// horrendous formatting
void PrintComparison(const puzzle_state& lhs, const puzzle_state& rhs)
{
  for ( std::size_t i = 0; i < lhs.size(); ++i )
  {
    for ( std::size_t  j = 0; j < lhs[i].size(); ++j )
    {
      std::cout << lhs[i][j] << " ";
    }

    if ( i == lhs.size() / 2 ) // check if printing middle row
    {
      if ( lhs == rhs )
      {
        std::cout << "== ";
      }
      else
      {
        std::cout << "!= ";
      }
    }
    else
    {
      std::cout << "   ";
    }

    for ( std::size_t j = 0; j < rhs[i].size(); ++j )
    {
      std::cout << rhs[i][j] << " ";
    }

    std::cout << "\n";
  }

  std::cout << "\n";

  return;
}