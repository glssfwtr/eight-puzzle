#include <iostream>

#include "print.hpp"

void Print_Puzzle(const puzzle_state& state)
{
  for ( std::size_t i = 0; i < state.size(); ++i )
  {
    if ( i % 3 == 0 )
    {
      std::cout << std::endl;
    }

    std::cout << state[i] << " ";
  }

  std::cout << "\n";

  return;
}
