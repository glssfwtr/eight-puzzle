#include "test.hpp"

void InitializerTests()
{
  std::cout << "first " << InsertState(problem_state1) << std::endl;
  std::cout << "second " << InsertState(problem_state1) << std::endl;

  std::cout << "first " << InsertState(correct_state) << std::endl;
  std::cout << "second " << InsertState(correct_state) << std::endl;

  std::cout << "first " << InsertState(hard_puzzle_state) << std::endl;
  std::cout << "second " << InsertState(hard_puzzle_state) << std::endl;

  std::cout << "first " << InsertState(some_state) << std::endl;
  std::cout << "second " << InsertState(some_state) << std::endl;

  std::cout << "third " << InsertState(correct_state) << std::endl;
  std::cout << "third " << InsertState(problem_state1) << std::endl;
  std::cout << "third " << InsertState(hard_puzzle_state) << std::endl;
  std::cout << "third " << InsertState(some_state) << std::endl;


  std::cout << CheckGoalState(problem_state1) << std::endl;
  std::cout << CheckGoalState(correct_state) << std::endl;
  std::cout << CheckGoalState(hard_puzzle_state) << std::endl;
  std::cout << CheckGoalState(some_state) << std::endl;

  // PrintPuzzle(correct_state);
  // PrintPuzzle(problem_state);
  // PrintPuzzle(hard_puzzle_state);
  // PrintPuzzle(some_state);

  PrintComparison(problem_state1, problem_state1);
  PrintComparison(problem_state1, goal_state);
  PrintComparison(hard_puzzle_state, goal_state);
  PrintComparison(correct_state, goal_state);

  return;
}

void NodePointerReferenceSetTest()
{
  ChronoTimer timer;
  Node* node1 = new Node();

  puzzle_state random_state =
  {
    {
      {5, 2, 7},
      {4, 1, 6},
      {0, 8, 3}
    }
  };

  puzzle_state test_state =
  {
    {
      {2, 1, 3},
      {4, 5, 7},
      {6, 0, 8}
    }
  };

  node1->current_puzzle_state = random_state;
  Node* node2 = new Node(test_state);

  PrintPuzzleState(node1->current_puzzle_state);

  random_state[0][0] = 0;
  random_state[2][0] = 5;
  random_state[1][2] = 4;
  random_state[1][0] = 6;

  PrintPuzzleState(random_state);
  PrintPuzzleState(node1->current_puzzle_state);
  PrintComparison(node1->current_puzzle_state, random_state);

  delete node1;
  delete node2;

  return;
}

void PriorityQeueueTest()
{
  puzzle_state problem_state = problem_state1; // load to avoid constexpr issues

  Node* node0 = new Node(problem_state);

  PrintPuzzleState(node0->current_puzzle_state);

  std::vector<Node*> successor_nodes = generate_successors(node0);

  puzzle_container::min_heap.push(node0);
  for ( Node* node : successor_nodes )
  {
    puzzle_container::min_heap.push(node);
  }

  successor_nodes = generate_successors(successor_nodes.back());

  for ( Node* node : successor_nodes )
  {
    puzzle_container::min_heap.push(node);
  }

  Node* node1 = new Node(nullptr, -999, problem_state);

  puzzle_container::min_heap.push(node1);

  std::cout << "\n\n\n\n";

  while ( !puzzle_container::min_heap.empty() )
  {
    Node* node = puzzle_container::min_heap.top();
    puzzle_container::min_heap.pop();

    std::cout << "Node depth: " << node->node_depth << std::endl;
    PrintPuzzleState(node->current_puzzle_state);
  }

  // PrintComparison(node0->current_puzzle_state, node1->current_puzzle_state);

}


void TestTimer()
{
  ChronoTimer timer;

  return;
}
