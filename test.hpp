#ifndef TEST_HPP
#define TEST_HPP

#include "chrono_benchmark.hpp"
#include "print.hpp"
#include "solver.hpp"

void InitializerTests();
void NodePointerReferenceSetTest();
void TestTimer();

constexpr puzzle_state correct_state =
{
  {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
  }
};

constexpr puzzle_state problem_state1 =
{
  {
    {2, 1, 3},
    {4, 5, 7},
    {6, 0, 8}
  }
};

constexpr puzzle_state problem_state2 =
{
  {
    {5, 2, 7},
    {4, 1, 6},
    {0, 8, 3}
  }
};

constexpr puzzle_state hard_puzzle_state =
{
  {
    {8, 7, 1},
    {6, 0, 2},
    {5, 4, 3}
  }
};

constexpr puzzle_state some_state =
{
  {
    {3, 1, 2},
    {4, 5, 8},
    {6, 0, 7}
  }
};

#endif // TEST_HPP