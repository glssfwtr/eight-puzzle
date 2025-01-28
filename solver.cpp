#include "solver.hpp"

// possible redundant as InsertState already checks for this by default on insert
bool CheckRepeated(const puzzle_state& state)
{
  return ( puzzle_container::visited_states.find(state) != puzzle_container::visited_states.end() );
}

bool InsertState(const puzzle_state& state)
{
  return puzzle_container::visited_states.insert(state).second; // insert returns a pair, second is bool indicating success
}

bool CheckGoalState(const puzzle_state& state)
{
  return ( state == goal_state );
}

puzzle_state UniformCostSearch(puzzle_state& start_state)
{




  // CHANGE THIS NODE WHEN FINISHED
  return start_state;
}

// Node* GeneralSearch(Node* initial_node)
// {
//   int max_queue_size = 0;
//   int nodes_popped = 0;

//   puzzle_container::min_heap.push(initial_node);

//   // while ( puzzle_container::min_heap.size() )



//   return Node*();
// }