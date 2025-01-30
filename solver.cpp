#include "solver.hpp"

int EvalUniformCostSearch(Node* node)
{
  return node->node_depth;
}

int HeuristicMisplacedTiles(const puzzle_state& state)
{
  int total_misplaced_tiles = 0;

  for ( std::size_t i = 0; i < rows; ++i )
  {
    for ( std::size_t j = 0; j < columns; ++j )
    {
      // compare current state tile to goal state tile, if not matching, ++misplaced
      // skip if current tile is blank
      if ( (state[i][j] != 0) && state[i][j] != goal_state[i][j] )
      {
        ++total_misplaced_tiles;
      }

    }
  }

  return total_misplaced_tiles;
}

int EvalAStarMisplacedTiles(Node *node)
{
  node->heuristic_value = HeuristicMisplacedTiles(node->current_puzzle_state);
  return node->node_depth + node->heuristic_value;
}

int HeuristicManhattanDistance(const puzzle_state& state)
{
  int total_distance = 0;
  int goal_row = 0;
  int goal_column = 0;

  for ( int i = 0; i < rows; ++i )
  {
    for ( int j = 0; j < columns; ++j ) // HOLY SHT
    {

      int problem_value = state[static_cast<std::size_t>(i)][static_cast<std::size_t>(j)];

      if ( problem_value == 0 )
      {
        continue; // next loop
      }

      goal_row = goal_position_pairs[problem_value].first;
      goal_column = goal_position_pairs[problem_value].second;

      total_distance += abs(i - goal_row) + abs(j - goal_column); // how far away is (where found) to (where need to be)
    }
  }

  return total_distance;
}

int EvalAStarManhattanDistance(Node *node)
{
  node->heuristic_value = HeuristicManhattanDistance(node->current_puzzle_state);
  return node->node_depth + node->heuristic_value;
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

    if ( top_node->current_puzzle_state == goal_state )
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