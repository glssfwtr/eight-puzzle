#include <iostream>

#include "print.hpp"

void PrintPuzzle(const puzzle_state& state)
{
  for ( int i = 0; i < 9; ++i )
  {
    if ( i % 3 == 0 )
    {
      std::cout << "\n";
    }

    std::cout << state[i] << " ";
  }

  std::cout << "\n";

  return;
}
