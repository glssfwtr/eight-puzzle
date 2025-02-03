# Complete Installation and Usage Instructions

1. clone the github repo

2. go to project's root directory and run `make`

3. to run the program, pass in two command line arguments like so:

`./a.out <initial_state> <solution_approach>`

<initial_state> is entered as a 9-Digit input representing the Eight Puzzle's initial state, where the 0 represents the blank tile. 

<solution_approach> is entered as a value between [1, 3], 1 = UCS, 2 = A* Misplaced Tile Heuristic, 3 = A* Manhattan distance.

Example execution:

`./a.out 817263540 2`

The above will result in a puzzle with the following properties:

[8 1 7]

[2 6 3]

[5 4 0]

and solved using A* with Misplaced Tile Heuristics.
