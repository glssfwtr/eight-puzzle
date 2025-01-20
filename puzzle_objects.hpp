#ifndef PUZZLE_OBJECTS_HPP
#define PUZZLE_OBJECTS_HPP

#include <array>
#include <queue>
#include <unordered_set>

#include <array>

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

/*
          CSTOM HASH FUNCTION FOR REPEATED PUZZLE STATE DICTIONARY
*/
struct PuzzleStateHash // hash function obj
{
  std::size_t operator()(const puzzle_state& state) const
  {
    std::size_t hash = 0;

    for ( const auto& row : state ) // iterate through each row
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

using states_dictionary = std::unordered_set<puzzle_state, PuzzleStateHash, PuzzleStateEqual>;

namespace puzzle_container
{
  static states_dictionary visited_states;
  static std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
}

#endif // PUZZLE_OBJECTS_HPP