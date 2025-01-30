#ifndef TEST_HPP
#define TEST_HPP

#include "chrono_benchmark.hpp"
#include "print.hpp"
#include "solver.hpp"

// void InitializerTests();
void NodePointerReferenceSetTest();
void PriorityQueueSizeTest();
void PriorityQueueTest();
// void TestDictionary();
void TestGeneratingSuccessor();
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
    {1, 8, 2},
    {6, 3, 5},
    {4, 7, 0}
  }
};

constexpr puzzle_state problem_state2 = // fails turbo hard
{
  {
    {5, 2, 7},
    {4, 1, 6},
    {0, 8, 3}
  }
};

constexpr puzzle_state problem_state3 =
{
  {
    {3, 1, 2},
    {4, 5, 8},
    {6, 0, 7}
  }
};

constexpr puzzle_state problem_state4 =
{
  {
    {1, 6, 7},
    {5, 0, 3},
    {4, 8, 2}
  }
};

constexpr puzzle_state problem_state5 = // failing parity
{
  {
    {1, 2, 3},
    {4, 5, 6},
    {8, 7, 0}
  }
};

/*
      Taken from Professor's sample report
*/

constexpr puzzle_state trivial =
{
  {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
  }
};

constexpr puzzle_state very_easy =
{
  {
    {1, 2, 3},
    {4, 5, 6},
    {7, 0, 8}
  }
};

constexpr puzzle_state easy =
{
  {
    {1, 2, 0},
    {4, 5, 3},
    {7, 8, 6}
  }
};

constexpr puzzle_state doable =
{
  {
    {0, 1, 2},
    {4, 5, 3},
    {7, 8, 6}
  }
};

constexpr puzzle_state oh_boy =
{
  {
    {8, 7, 1},
    {6, 0, 2},
    {5, 4, 3}
  }
};

constexpr puzzle_state getting_toasty =
{
  {
    {8, 1, 7},
    {2, 6, 3},
    {5, 4, 0},
  }
};



#endif // TEST_HPP