#ifndef CUSTOM_DICT_HPP
#define CUSTOM_DICT_HPP

#include <unordered_set>
#include <vector>

using puzzle_state = std::vector<int>;

struct PuzzleStateHash
{
  std::size_t operator()(const puzzle_state& state) const
  {
    std::size_t hash = 0;

    for ( int pos : state ) // iterate linearly through the puzzle and hash each position
    {
      hash ^= std::hash<int>{}(pos) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
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


#endif // CUSTOM_DICT_HPP