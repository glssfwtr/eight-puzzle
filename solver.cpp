#include "solver.hpp"

puzzle_state goal_state = {1, 2, 3, 4, 5, 6, 7, 8, 0};

std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
std::unordered_set<puzzle_state, PuzzleStateHash, PuzzleStateEqual> visited_states;

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

bool CheckRepeated(const puzzle_state& state)
{
  return visited_states.find(state) != visited_states.end();
}

bool InsertState(const puzzle_state& state)
{
  return visited_states.insert(state).second;
}

bool CheckGoalState(const puzzle_state& state)
{
  return ( state == goal_state );
}

puzzle_state UniformCostSearch(puzzle_state start_state)
{
  // todo

  return start_state;
}