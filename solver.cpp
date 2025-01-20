#include "solver.hpp"

std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
states_dictionary visited_states;

// possible redundant as InsertState already checks for this by default on insert
bool CheckRepeated(const puzzle_state& state)
{
  return visited_states.find(state) != visited_states.end();
}

bool InsertState(const puzzle_state& state)
{
  return visited_states.insert(state).second; // insert returns a pair, second is bool indicating success
}

bool CheckGoalState(const puzzle_state& state)
{
  return ( state == goal_state );
}

puzzle_state UniformCostSearch(puzzle_state& start_state)
{
  // todo

  return start_state;
}