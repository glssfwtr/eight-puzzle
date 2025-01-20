#include "print.hpp"

void PrintPuzzleState(const puzzle_state& state)
{
  for ( const auto& row : state ) // each row of the state
  {
    for ( const int element : row ) // each element of each row
    {
      std::cout << element << " ";
    }

    std::cout << std::endl;
  }

  std::cout << std::endl;

  return;
}

// i am so bad at print formatting wtf
void PrintComparison(const puzzle_state& lhs, const puzzle_state& rhs)
{
  for (std::size_t i = 0; i < lhs.size(); ++i)
  {
    for (std::size_t j = 0; j < lhs[i].size(); ++j)
    {
      std::cout << lhs[i][j] << " ";
    }

    if (i == lhs.size() / 2)
    {
      if (lhs == rhs)
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

    for (std::size_t j = 0; j < rhs[i].size(); ++j)
    {
      std::cout << rhs[i][j] << " ";
    }

    std::cout << std::endl;
  }

  std::cout << std::endl;

  return;
}