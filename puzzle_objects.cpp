#include "puzzle_objects.hpp"

// true global scope
namespace puzzle_container
{
  states_dictionary visited_states;
  std::priority_queue<Node*, std::vector<Node*>, NodeDepthComparator> min_heap;
}
