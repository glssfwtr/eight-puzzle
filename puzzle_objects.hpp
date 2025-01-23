#ifndef PUZZLE_OBJECTS_HPP
#define PUZZLE_OBJECTS_HPP

#include <array>
#include <queue>
#include <unordered_set>

/*
          PUZZLE STATE REPRESENTATION
*/

// rows specify how many std::arrays in each row, columns specify how many elements in each std::array row of the 2D matrix
constexpr int rows = 3; // std::array
constexpr int columns = 3; // int in each std::array
using puzzle_state = std::array<std::array<int, columns>, rows>; // remember off by 1 indexing, 0 is the first, 2 is the last

constexpr puzzle_state goal_state =
{
  {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
  }
};

static puzzle_state bad_state =
{
  {
    {-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, -1}
  }
};

struct Node
{
  Node* parent;
  int heuristic_value = 0;
  int node_depth = 0; // depth of the node in the search space tree
  // int reach_cost; // cost to reach this node from the start node
  puzzle_state current_puzzle_state;


  Node(puzzle_state& state) : current_puzzle_state(state) {}
  Node(Node* p = nullptr, int d = 0, puzzle_state& state = bad_state) : parent(p), node_depth(d), current_puzzle_state(state) {}
  ~Node() = default;
};


// custom hash for repeated puzzle states in dictionary
struct PuzzleStateHash // hash function obj
{
  std::size_t operator()(const puzzle_state& state) const
  {
    std::size_t hash = 0;

    for ( const puzzle_state::value_type& row : state ) // iterate through each row
    {
      for ( const int element : row ) // iterate through each element in the row
      {
        hash ^= std::hash<int>{}(element) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
      }
    }

    return hash;
  }
};


// custom equality comparator for puzzle_state
struct PuzzleStateEqual
{
  bool operator()(const puzzle_state& lhs, const puzzle_state& rhs) const
  {
    return lhs == rhs;
  }
};


// priority queue comparator because std::priority_queue is a max heap by default
struct NodeDepthComparator
{
  bool operator()(const Node* lhs, const Node* rhs) const
  {
    return lhs->node_depth > rhs->node_depth; // Min-heap (smaller cost has higher priority)
  }
};

using states_dictionary = std::unordered_set<puzzle_state, PuzzleStateHash, PuzzleStateEqual>;

namespace puzzle_container
{
  extern states_dictionary visited_states;
  extern std::priority_queue<Node*, std::vector<Node*>, NodeDepthComparator> min_heap;
}

std::vector<Node*> generate_successors(Node* current_node);


#endif // PUZZLE_OBJECTS_HPP