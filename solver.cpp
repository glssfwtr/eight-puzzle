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

int EvalUniformCostSearch(Node* node)
{
  return node->node_depth;
}

Node* GeneralSearch(Node* initial_node, EvaluationFunction eval)
{
  Node* top_node = nullptr;
  max_queue_size = 0;
  nodes_popped = 0;

  puzzle_container::min_heap.push(initial_node);

  while ( !puzzle_container::min_heap.empty() )
  {
    top_node = puzzle_container::min_heap.top(); // load the node before popping

    // record size before popping
    if ( max_queue_size < puzzle_container::min_heap.size() )
    {
      max_queue_size = puzzle_container::min_heap.size();
    }

    puzzle_container::min_heap.pop();
    ++nodes_popped;

    if ( CheckGoalState(top_node->current_puzzle_state) )
    {
      return top_node;
    }

    puzzle_container::visited_states.insert(top_node->current_puzzle_state);

    std::vector<Node*> successors = GenerateSuccessors(top_node);

    // for each successor, evaluate f(n)
    // UCS: f(n) = g(n)
    // a* misplaced tile: f(n) = g(n) + h(n) <-- need to define heuristic func to differentiate
    // a* manhattan dist: f(n) = g(n) + h(n) <-- need to define heuristic func to differentiate0
    for (Node* successor : successors)
    {
      successor->f = eval(successor);

      // if the hashed puzzle can't be found, it means it was never evaluated / visited / popped
      if ( puzzle_container::visited_states.find(successor->current_puzzle_state) == puzzle_container::visited_states.end() )
      {
        puzzle_container::min_heap.push(successor);
      }
    }

  }



  return nullptr; // no solution found, receive nullptr
}