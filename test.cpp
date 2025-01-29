#include "test.hpp"

// void InitializerTests()
// {
//   std::cout << "first " << InsertState(problem_state1) << "\n";
//   std::cout << "second " << InsertState(problem_state1) << "\n";

//   std::cout << "first " << InsertState(correct_state) << "\n";
//   std::cout << "second " << InsertState(correct_state) << "\n";

//   std::cout << "first " << InsertState(problem_state3) << "\n";
//   std::cout << "second " << InsertState(problem_state3) << "\n";

//   std::cout << "first " << InsertState(problem_state4) << "\n";
//   std::cout << "second " << InsertState(problem_state4) << "\n";

//   std::cout << "third " << InsertState(correct_state) << "\n";
//   std::cout << "third " << InsertState(problem_state1) << "\n";
//   std::cout << "third " << InsertState(problem_state3) << "\n";
//   std::cout << "third " << InsertState(problem_state4) << "\n";


//   std::cout << CheckGoalState(problem_state1) << "\n";
//   std::cout << CheckGoalState(correct_state) << "\n";
//   std::cout << CheckGoalState(problem_state3) << "\n";
//   std::cout << CheckGoalState(problem_state4) << "\n";

//   // PrintPuzzle(correct_state);
//   // PrintPuzzle(problem_state);
//   // PrintPuzzle(hard_puzzle_state);
//   // PrintPuzzle(some_state);

//   PrintComparison(problem_state1, problem_state1);
//   PrintComparison(problem_state1, goal_state);
//   PrintComparison(problem_state3, goal_state);
//   PrintComparison(correct_state, goal_state);

//   return;
// }

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

  std::cout << "\n======================\n";

  return;
}

void PriorityQueueSizeTest()
{
  puzzle_state loader = problem_state1;
  std::cout << puzzle_container::min_heap.size() << "\n";
  Node* node0 = new Node(nullptr, 5, 0, loader);
  puzzle_container::min_heap.push(node0);
  std::cout << puzzle_container::min_heap.size() << "\n";

  loader = problem_state2;
  Node* node1 = new Node(nullptr, 3, 0, loader);
  puzzle_container::min_heap.push(node1);
  std::cout << puzzle_container::min_heap.size() << "\n";

  loader = problem_state3;
  Node* node2 = new Node(nullptr, 7, 0, loader);
  puzzle_container::min_heap.push(node2);
  std::cout << puzzle_container::min_heap.size() << "\n";

  Node* popped = puzzle_container::min_heap.top();
  PrintPuzzleState(popped->current_puzzle_state);
  puzzle_container::min_heap.pop();
  std::cout << puzzle_container::min_heap.size() << "\n";

  popped = puzzle_container::min_heap.top();
  PrintPuzzleState(popped->current_puzzle_state);
  puzzle_container::min_heap.pop();
  std::cout << puzzle_container::min_heap.size() << "\n";

  popped = puzzle_container::min_heap.top();
  PrintPuzzleState(popped->current_puzzle_state);
  puzzle_container::min_heap.pop();
  std::cout << puzzle_container::min_heap.size() << "\n";


  return;
}

void PriorityQueueTest()
{
  puzzle_state problem_state = problem_state1; // load to avoid constexpr issues

  Node* node0 = new Node(problem_state);

  PrintPuzzleState(node0->current_puzzle_state);

  std::vector<Node*> successor_nodes = GenerateSuccessors(node0);

  puzzle_container::min_heap.push(node0);
  for ( Node* node : successor_nodes )
  {
    puzzle_container::min_heap.push(node);
  }

  successor_nodes = GenerateSuccessors(successor_nodes.back());

  for ( Node* node : successor_nodes )
  {
    puzzle_container::min_heap.push(node);
  }

  Node* node1 = new Node(nullptr, -999, 0, problem_state);

  puzzle_container::min_heap.push(node1);

  std::cout << "\n\n\n\n";

  while ( !puzzle_container::min_heap.empty() )
  {
    Node* node = puzzle_container::min_heap.top();
    puzzle_container::min_heap.pop();

    std::cout << "Node depth: " << node->node_depth << "\n";
    PrintPuzzleState(node->current_puzzle_state);
  }

  // PrintComparison(node0->current_puzzle_state, node1->current_puzzle_state);

  std::cout << "\n======================\n";


  return;
}

// void TestDictionary()
// {
//   std::cout << "Starting TestDictionary\n";

//   puzzle_state loader = problem_state1;
//   Node* node0 = new Node(loader);
//   PrintPuzzleState(node0->current_puzzle_state);
//   std::cout << "InsertState(node0): " << InsertState(node0->current_puzzle_state) << "\n";

//   loader = problem_state2;
//   Node* node1 = new Node(loader);
//   PrintPuzzleState(node1->current_puzzle_state);
//   std::cout << "InsertState(node1): " << InsertState(node1->current_puzzle_state) << "\n";

//   loader = problem_state3;
//   Node* node2 = new Node(loader);
//   PrintPuzzleState(node2->current_puzzle_state);
//   std::cout << "InsertState(node2): " << InsertState(node2->current_puzzle_state) << "\n";

//   if (InsertState(node0->current_puzzle_state))
//   {
//     std::cout << "node0 inserted\n";
//   }
//   else
//   {
//     std::cout << "node0 not inserted\n";
//   }

//   if (InsertState(node1->current_puzzle_state))
//   {
//     std::cout << "node1 inserted\n";
//   }
//   else
//   {
//     std::cout << "node1 not inserted\n";
//   }

//   if (InsertState(node2->current_puzzle_state))
//   {
//     std::cout << "node2 inserted\n";
//   }
//   else
//   {
//     std::cout << "node2 not inserted\n";
//   }

//   std::cout << "Visited states size: " << puzzle_container::visited_states.size() << "\n";

//   for (const auto& state : puzzle_container::visited_states)
//   {
//     PrintPuzzleState(state);
//   }

//   std::cout << "\n======================\n";

//   std::cout << "Finished TestDictionary\n";
//   return;
// }

void TestGeneratingSuccessor()
{
  puzzle_state loader = problem_state1;

  Node* problem_node = new Node(loader);

  std::vector<Node*> successor_nodes = GenerateSuccessors(problem_node);

  PrintPuzzleState(problem_node->current_puzzle_state);

  for ( const Node* nodes : successor_nodes )
  {
    PrintPuzzleState(nodes->current_puzzle_state);
  }

  loader = problem_state3;

  Node* some_node = new Node(loader);

  successor_nodes = GenerateSuccessors(some_node);


  for ( const Node* nodes : successor_nodes )
  {
    PrintPuzzleState(nodes->current_puzzle_state);
  }

}

void TestTimer()
{
  ChronoTimer timer;



  return;
}
